/**
 * @file app_system.h
 * @author Mauricio Dall Oglio Farina
 * @brief System Application
 */
#ifndef __APP_SYSTEM_H__
#define __APP_SYSTEM_H__

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "rtos/lib_rtos.h"

#define APP_SYSTEM_STACK_SIZE (1024 * 2)            /** Task Stack Size (Bytes) */
#define APP_SYSTEM_PRIORITY   RTOS_PRIORITY_HIGHEST /** Task Priority */
#define APP_SYSTEM_NAME       "SYSTEM"              /** Task Name */

/**
 * @brief Start System Task
 */
void app_system_start(void);

#endif