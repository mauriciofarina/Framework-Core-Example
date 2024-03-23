/**
 * @file lib_esp_mqtt.c
 * @author Mauricio Dall Oglio Farina
 * @brief ESP MQTT Client Library
 */
// #ifdef USE_ESP_MQTT
#include "lib_esp_mqtt.h"

#include "mqtt/lib_mqtt.h"

#include "esp_log.h"
#include "mqtt_client.h"

static esp_mqtt_client_handle_t mqtt_client = NULL;                         /** MQTT Client Handler */
static mqtt_subscription_t mqtt_subscription[MQTT_MAX_SUBSCRIPTIONS] = {0}; /** Subscription Parameters */

/**
 * @brief MQTT Event Handler
 *
 * @param handler_args[in] Handler Arguments (Not Used)
 * @param base[in] Event Base (Not Used)
 * @param event_id[in] Event ID
 * @param event_data[in] Event Data
 */
static void mqtt_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data);

/**
 * @brief MQTT Data Event Handler
 *
 * @param event[in] MQTT event
 */
static void mqtt_data_event_handler(esp_mqtt_event_handle_t *event);

static void mqtt_data_event_handler(esp_mqtt_event_handle_t *event) {

    for (uint32_t i = 0; i < MQTT_MAX_SUBSCRIPTIONS; ++i) {
        if (strlen(mqtt_subscription[i].topic) == event->topic_len) {
            if (0 == memcmp(event->topic, mqtt_subscription[i].topic, event->topic_len)) {
                mqtt_subscription[i].callback(event->topic, (uint8_t *)event->data, (uint32_t)event->data_len);
                break;
            }
        }
    }
}

static void mqtt_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data) {

    esp_mqtt_event_handle_t event = event_data;

    switch ((esp_mqtt_event_id_t)event_id) {
        case MQTT_EVENT_DATA:
            ESP_LOGI("MQTT_CLIENT", "GOT DATA %s %d", event->topic, event->topic_len);
            mqtt_data_event_handler(&event);
            break;
        case MQTT_EVENT_ERROR:
            ESP_LOGE("MQTT_CLIENT", "MQTT_EVENT_ERROR");
            esp_restart();
            break;
        default:
            // Ignore
            break;
    }
}

void lib_mqtt_init(void) {

    esp_mqtt_client_config_t mqtt_config = {
        .uri = MQTT_SERVER,
        .port = MQTT_PORT,
        .keepalive = MQTT_KEEP_ALIVE,
    };

    mqtt_client = esp_mqtt_client_init(&mqtt_config);
    esp_mqtt_client_register_event(mqtt_client, ESP_EVENT_ANY_ID, mqtt_event_handler, NULL);
    esp_mqtt_client_start(mqtt_client);
}

void lib_mqtt_publish(char *topic, uint8_t *data, uint32_t length, uint8_t qos) {
    esp_mqtt_client_publish(mqtt_client, topic, (char *)data, length, qos, 0);
}

void lib_mqtt_subscribe(mqtt_subscription_t *subscription) {

    for (uint32_t i = 0; i < MQTT_MAX_SUBSCRIPTIONS; ++i) {

        if (NULL == mqtt_subscription[i].callback) {
            memcpy(&mqtt_subscription[i], subscription, sizeof(mqtt_subscription_t));
            break;
        }
        assert(i != (MQTT_MAX_SUBSCRIPTIONS - 1)); // Check if Buffer is full
    }

    esp_mqtt_client_subscribe(mqtt_client, subscription->topic, subscription->qos);
}
#endif