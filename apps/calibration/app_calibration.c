/**
 * @file app_calibration.c
 * @author Mauricio Dall Oglio Farina
 * @brief Auto Calibration System Application
 */
#include "app_calibration.h"
#include "app_calibration_private.h"

#include "sensor_demo/cls_sensor_demo.h"

#include "mqtt/lib_mqtt.h"
#include "wifi/lib_wifi.h"

static rtos_task_t task_handler = {0};                       /** Task Handler */
static uint8_t task_stack[APP_CALIBRATION_STACK_SIZE] = {0}; /** Task Stack Buffer */

static sensor_t *sensor = NULL;       /** Sensor Handler */
static char response_topic[32] = {0}; /** Response Topic */

static void get_raw_sample_callback(char *topic, uint8_t *data, uint32_t length) {
    uint8_t buffer[128] = {0};
    uint32_t size = cls_sensor_get_raw_sample(sensor, buffer);
    lib_mqtt_publish(response_topic, buffer, size, 0);
}
static void predict_callback(char *topic, uint8_t *data, uint32_t length) {
    uint32_t label = cls_sensor_predict(sensor);
    lib_mqtt_publish(response_topic, (uint8_t *)&label, sizeof(uint32_t), 0);
}
static void set_model_callback(char *topic, uint8_t *data, uint32_t length) {
    cls_sensor_set_model(sensor, data, length);
}
static void scan_devices_callback(char *topic, uint8_t *data, uint32_t length) {
    char buffer[512] = {0};
    lib_wifi_scan(buffer);
    lib_mqtt_publish(response_topic, (uint8_t *)buffer, strlen(buffer), 0);
}

static void subscribe_topics(void) {

    mqtt_subscription_t subscribe = {
        .qos = 0,
    };

    sprintf(subscribe.topic, "/%d/raw", SENSOR_ID);
    subscribe.callback = get_raw_sample_callback;
    lib_mqtt_subscribe(&subscribe);

    sprintf(subscribe.topic, "/%d/predict", SENSOR_ID);
    subscribe.callback = predict_callback;
    lib_mqtt_subscribe(&subscribe);

    sprintf(subscribe.topic, "/%d/model", SENSOR_ID);
    subscribe.callback = set_model_callback;
    lib_mqtt_subscribe(&subscribe);

    sprintf(subscribe.topic, "/%d/scan", SENSOR_ID);
    subscribe.callback = scan_devices_callback;
    lib_mqtt_subscribe(&subscribe);
}

static void app_calibration_task(void *context) {

    (void)context;

    subscribe_topics();

    while (1) {
        lib_rtos_delay(1000); // TODO: Future Maintenance Implementations
    }
}

void app_calibration_init(void) {

    sprintf(response_topic, "/%d/response", SENSOR_ID);

    sensor_type_t type = SENSOR_DEMO; // TODO: Load Sensor Type

    switch (type) {

        case SENSOR_DEMO: {
            sensor_demo_init_t init = {
                .super = {
                    // Just a demonstration value
                    .size = 1024,
                    .data = lib_rtos_malloc(1024),
                },
            };
            sensor = lib_rtos_malloc(sizeof(sensor_demo_t));
            cls_sensor_demo_init((sensor_demo_t *)sensor, &init);
        } break;

        default:
            assert(0); // Invalid
            break;
    }

    lib_mqtt_init();
}

void app_calibration_start(void) {

    rtos_task_init_t init = {
        .name = "calibration",
        .stack_size = APP_CALIBRATION_STACK_SIZE,
        .task_function = app_calibration_task,
        .argument = NULL,
        .priority = APP_CALIBRATION_PRIORITY,
        .stack = task_stack,
    };

    cls_rtos_task_init(&task_handler, &init);
}