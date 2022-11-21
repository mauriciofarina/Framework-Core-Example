/**
 * @file lib_mqtt.h
 * @author Mauricio Dall Oglio Farina
 * @brief MQTT Interface Library Library
 */
#ifndef __LIB_MQTT_H__
#define __LIB_MQTT_H__

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "rtos/lib_rtos.h"

#if defined(USE_ESP_MQTT)
#include "esp_mqtt/lib_esp_mqtt.h"
#else
#error "No MQTT Client Library Selected"
#endif

#ifndef MQTT_SERVER
#define MQTT_SERVER "mqtt://localhost" /** MQTT Server URL */
#endif

#ifndef MQTT_PORT
#define MQTT_PORT 1883 /** MQTT Server Port */
#endif

#define MQTT_KEEP_ALIVE 30 /** Keep Alive Time (seconds) */

#define MQTT_MAX_TOPIC_LENGTH  32 /** Maximum Topic Length (Bytes) */
#define MQTT_MAX_SUBSCRIPTIONS 5  /** Maximum number of Topic Subscriptions */

/**
 * @brief MQTT Subscription Parameters
 */
typedef struct {

    char topic[MQTT_MAX_TOPIC_LENGTH]; /** Topic Name */
    uint8_t qos;                       /** QoS */

    /**
     * @brief Publish Received Callback
     *
     * @param topic[in] Topic
     * @param data[in] Data
     * @param length[in] Data Size (Bytes)
     */
    void (*callback)(char *topic, uint8_t *data, uint32_t length);

} mqtt_subscription_t;

/**
 * @brief Library Initialization
 */
void lib_mqtt_init(void);

/**
 * @brief Publish to Topic
 *
 * @param topic[in] Topic
 * @param data[in] Data
 * @param length[in] Data Size (Bytes)
 * @param qos[in] QoS
 */
void lib_mqtt_publish(char *topic, uint8_t *data, uint32_t length, uint8_t qos);

/**
 * @brief Subscribe Topic
 *
 * @param subscription[in] Subscription Parameters
 */
void lib_mqtt_subscribe(mqtt_subscription_t *subscription);

#endif
