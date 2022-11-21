/**
 * @file cls_sensor_demo_override.h
 * @author Mauricio Dall Oglio Farina
 * @brief Demonstration Sensor Class Override Methods
 */
#ifndef __CLS_SENSOR_DEMO_OVERRIDE_H__
#define __CLS_SENSOR_DEMO_OVERRIDE_H__

#include "cls_sensor_demo.h"

uint32_t cls_sensor_demo_get_raw_sample(sensor_t *const handler, uint8_t *data); /** @ref cls_sensor_get_raw_sample */

#endif