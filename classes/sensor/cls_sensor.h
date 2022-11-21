/**
 * @file cls_sensor.h
 * @author Mauricio Dall Oglio Farina
 * @brief Sensor Interface Class
 */
#ifndef __CLS_SENSOR_H__
#define __CLS_SENSOR_H__

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "rtos/lib_rtos.h"

/**
 * @brief Initialization Parameters
 */
typedef struct {
    void *data;    /** Model Data Buffer */
    uint32_t size; /** Data Size (Bytes) */
} sensor_init_t;

/**
 * @brief Class Handler
 */
typedef struct {

    rtos_mutex_t lock; /** Lock Mutex */

    void *data;                   /** Model Data */
    uint32_t size;                /** Data Size (Bytes) */
    const struct sensor_api *api; /** Overridable API */
} sensor_t;

/**
 * @brief Class Overridable API
 */
struct sensor_api {
    uint32_t (*get_raw_sample)(sensor_t *const handler, uint8_t *data); /** @ref cls_sensor_get_raw_sample */
};

/**
 * @brief Create Class Object
 *
 * @param handler[out] Handler
 * @param init[in] Initialization Parameters
 */
void cls_sensor_init(sensor_t *const handler, sensor_init_t *const init);

/**
 * @brief Get Sensor Raw Sample
 *
 * @param handler[in] Handler
 * @param data[out] Raw Sample Data
 *
 * @return uint32_t Data Size (Bytes)
 */
static inline uint32_t cls_sensor_get_raw_sample(sensor_t *const handler, uint8_t *data) {
    return handler->api->get_raw_sample(handler, data);
}

/**
 * @brief Set Sensor Model
 *
 * @details Receives a list of layers
 *
 * @param handler[in] Handler
 * @param model[in] Model Data
 * @param size[in] Size (Bytes)
 */
void cls_sensor_set_model(sensor_t *const handler, void *model, uint32_t size);

/**
 * @brief Predict Sensor Sample
 *
 * @param handler[in] Handler
 *
 * @return uint32_t Prediction Label ID
 */
uint32_t cls_sensor_predict(sensor_t *const handler);

#endif
