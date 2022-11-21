/**
 * @file cls_rtos_mutex.h
 * @author Mauricio Dall Oglio Farina
 * @brief RTOS Mutex Class
 */
#ifndef __CLS_RTOS_MUTEX_H__
#define __CLS_RTOS_MUTEX_H__

#include <stdbool.h>
#include <stdint.h>

#include "rtos/lib_rtos.h"

typedef struct {

#ifdef USE_RTOS_FREERTOS
    SemaphoreHandle_t handler; /** FreeRTOS Mutex Handler */
    StaticSemaphore_t buffer;  /** FreeRTOS Mutex Static Allocation */
#endif

} rtos_mutex_t;

/**
 * @brief Create Class Object
 *
 * @param handler[out] Handler
 */
static inline void cls_rtos_mutex_init(rtos_mutex_t *const handler) {
#ifdef USE_RTOS_FREERTOS
    handler->handler = xSemaphoreCreateMutexStatic(&handler->buffer);
    assert(handler->handler);
#endif
}

/**
 * @brief Destroy Class Object
 *
 * @param handler[in] Handler
 */
static inline void cls_rtos_mutex_deinit(rtos_mutex_t *const handler) {
#ifdef USE_RTOS_FREERTOS
    vSemaphoreDelete(handler->handler);
#endif
}

/**
 * @brief Lock Mutex With default timeout ( @ref RTOS_DEFAULT_TIMEOUT )
 *
 * @param handler[in] Handler
 *
 * @return true Success
 * @return false Fail
 */
static inline bool cls_rtos_mutex_lock_default(rtos_mutex_t *const handler) {

#ifdef USE_RTOS_FREERTOS
    return (bool)xSemaphoreTake(handler->handler, RTOS_DEFAULT_TIMEOUT);
#endif
}

/**
 * @brief Lock Mutex
 *
 * @param handler[in] Handler
 * @param timeout[in] Timeout (ms)
 *
 * @return true Success
 * @return false Fail
 */
static inline bool cls_rtos_mutex_lock(rtos_mutex_t *const handler, uint32_t timeout) {

#ifdef USE_RTOS_FREERTOS
    return (bool)xSemaphoreTake(handler->handler, timeout);
#endif
}

/**
 * @brief Unlock Mutex
 *
 * @param handler[in] Handler
 */
static inline void cls_rtos_mutex_unlock(rtos_mutex_t *const handler) {

#ifdef USE_RTOS_FREERTOS
    xSemaphoreGive(handler->handler);
#endif
}

#endif