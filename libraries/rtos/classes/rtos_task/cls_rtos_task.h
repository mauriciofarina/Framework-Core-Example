/**
 * @file cls_rtos_task.h
 * @author Mauricio Dall Oglio Farina
 * @brief RTOS Task Class
 */
#ifndef __CLS_RTOS_TASK_H__
#define __CLS_RTOS_TASK_H__

#include <stdbool.h>
#include <stdint.h>

#include "rtos/lib_rtos.h"

#define RTOS_TASK_MAX_NAME 16 /** Max Task Name */

/**
 * @brief Task Priorities
 *
 * @note God priority is intended for
 * providing temporary scheduler control
 * of tasks. No task should be instantiated
 * in God mode.
 *
 */
typedef enum {

    RTOS_PRIORITY_IDLE = 0,    /** Idle Priority */
    RTOS_PRIORITY_LOWEST = 1,  /** Lowest Priority */
    RTOS_PRIORITY_LOW = 2,     /** Low Priority */
    RTOS_PRIORITY_MID = 3,     /** Mid/Normal Priority */
    RTOS_PRIORITY_HIGH = 4,    /** High Priority */
    RTOS_PRIORITY_HIGHEST = 5, /** Highest Priority */
    RTOS_PRIORITY_GOD = 6,     /** God Mode Priority (Read Note Above) */

} rtos_priority_t;

typedef struct {

    char name[RTOS_TASK_MAX_NAME]; /** Task Name */
    uint32_t stack_size;           /** Task Stack Size (Bytes) */
    void (*task_function)(void *); /** Task Function */
    void *argument;                /** Task Argument (Optional) */
    rtos_priority_t priority;      /** Task Priority */

#ifdef USE_RTOS_FREERTOS
    uint8_t *stack; /** Task Stack Buffer */
#endif

} rtos_task_init_t;

typedef struct {

#ifdef USE_RTOS_FREERTOS
    TaskHandle_t handler; /** Task Handler */
    StaticTask_t buffer;  /** Task Static Allocation */
    StackType_t *stack;   /** Task Stack Buffer */
#endif

} rtos_task_t;

/**
 * @brief Create Class Object
 *
 * @param handler[out] Handler
 * @param init[in] Initialization Parameters
 */
void cls_rtos_task_init(rtos_task_t *const handler, rtos_task_init_t *const init);

/**
 * @brief Set Task Priority
 *
 * @param handler[in] Handler
 * @param priority[in] Priority
 */
static inline void cls_rtos_task_set_priority(rtos_task_t *const handler, rtos_priority_t priority) {
#ifdef USE_RTOS_FREERTOS
    vTaskPrioritySet(handler->handler, priority);
#endif
}

#endif
