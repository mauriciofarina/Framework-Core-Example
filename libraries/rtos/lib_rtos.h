/**
 * @file lib_rtos.h
 * @author Mauricio Dall Oglio Farina
 * @brief RTOS Interface Library
 */
#ifndef __LIB_RTOS_H__
#define __LIB_RTOS_H__

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#ifndef USE_RTOS_KERNEL
#define USE_RTOS_KERNEL /** Add RTOS Support */
#endif

// Library Configurations
#ifndef RTOS_DEFAULT_TIMEOUT
#define RTOS_DEFAULT_TIMEOUT 100 /** Default Timeout Time (ms) */
#endif

// FreeRTOS
#ifdef USE_RTOS_FREERTOS

#include "FreeRTOS.h"
#include "event_groups.h"
#include "queue.h"
#include "semphr.h"
#include "task.h"

// Other
#else
#error "None or Invalid RTOS Selected"
#endif

#include "classes/rtos_mutex/cls_rtos_mutex.h"
#include "classes/rtos_task/cls_rtos_task.h"

/**
 * @brief Delay Task
 *
 * @param time[in] Delay Time (ms)
 */
static inline void lib_rtos_delay(uint32_t time) {
#ifdef USE_RTOS_FREERTOS
    vTaskDelay(time);
#endif
}

/**
 * @brief Kernel Heap Allocation
 *
 * @param size[in] Allocation Size (Bytes)
 *
 * @return void* Pointer to Allocation Address
 * @return NULL Failed to Allocate Memory
 */
static inline void *lib_rtos_malloc(uint32_t size) {
#ifdef USE_RTOS_FREERTOS
    return pvPortMalloc(size);
#else
    return NULL;
#endif
}

/**
 * @brief Kernel Heap Free
 *
 * @param pointer[in] Allocation Memory Address
 */
static inline void lib_rtos_free(void *pointer) {
#ifdef USE_RTOS_FREERTOS
    return vPortFree(pointer);
#endif
}

#endif
