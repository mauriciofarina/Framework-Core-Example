/**
 * @file cls_sensor_demo.h
 * @author Mauricio Dall Oglio Farina
 * @brief Demonstration Sensor Class
 */
#ifndef __CLS_SENSOR_DEMO_H__
#define __CLS_SENSOR_DEMO_H__

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "sensor/cls_sensor.h"

/**
 * @brief Initialization Parameters
 */
typedef struct {
    sensor_init_t super; /** Super Class Initialization */
} sensor_demo_init_t;

/**
 * @brief Class Handler
 */
typedef struct {
    sensor_t super; /** Super Class */
} sensor_demo_t;

/**
 * @brief Create Class Object
 *
 * @param handler[out] Handler
 * @param init[in] Initialization Parameters
 */
void cls_sensor_demo_init(sensor_demo_t *const handler, sensor_demo_init_t *const init);

#endif
