/**
 * @file app_calibration.h
 * @author Mauricio Dall Oglio Farina
 * @brief Auto Calibration System Application
 */
#ifndef __APP_CALIBRATION_H__
#define __APP_CALIBRATION_H__

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "app_calibration_types.h"

#include "rtos/lib_rtos.h"

#define APP_CALIBRATION_STACK_SIZE (1024 * 2)         /** Task Stack Size (Bytes) */
#define APP_CALIBRATION_PRIORITY   RTOS_PRIORITY_IDLE /** Task Priority */

#define SENSOR_ID 1 /** Sensor ID */

/**
 * @brief App Initialization
 *
 */
void app_calibration_init(void);

/**
 * @brief Start Application
 *
 */
void app_calibration_start(void);

#endif
