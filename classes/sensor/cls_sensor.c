/**
 * @file cls_sensor.c
 * @author Mauricio Dall Oglio Farina
 * @brief Sensor Interface Class
 */
#include "cls_sensor.h"

/** @ref cls_sensor_get_raw_sample */
static inline uint32_t get_raw_sample(sensor_t *const handler, void *data) {
    assert(0); // Missing Implementation
    return 0;
}

void cls_sensor_init(sensor_t *const handler, sensor_init_t *const init) {

    cls_rtos_mutex_init(&handler->lock);

    handler->data = init->data;
    handler->size = init->size;

    static const struct sensor_api api = {
        .get_raw_sample = get_raw_sample,
    };
    handler->api = &api;
}

void cls_sensor_set_model(sensor_t *const handler, void *model, uint32_t size) {

    if (cls_rtos_mutex_lock_default(&handler->lock)) {
        // TODO: Update Prediction Model
        cls_rtos_mutex_unlock(&handler->lock);
    }
}

uint32_t cls_sensor_predict(sensor_t *const handler) {

    uint32_t label = 0;
    if (cls_rtos_mutex_lock_default(&handler->lock)) {
        // TODO: Use handler->api.get_raw_sample to read sensor raw data
        // TODO: The prediction Algorithm
        cls_rtos_mutex_unlock(&handler->lock);
    }

    return label;
}