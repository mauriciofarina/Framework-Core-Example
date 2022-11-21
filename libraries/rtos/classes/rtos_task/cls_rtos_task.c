/**
 * @file cls_rtos_task.c
 * @author Mauricio Dall Oglio Farina
 * @brief RTOS Task Class
 */
#include "cls_rtos_task.h"

void cls_rtos_task_init(rtos_task_t *const handler, rtos_task_init_t *const init) {

    assert(init->task_function != NULL);
    assert(init->priority < RTOS_PRIORITY_GOD);

#ifdef USE_RTOS_FREERTOS

    assert(0 == (init->stack_size % sizeof(StackType_t))); // FreeRTOS stack must be a multiple of @ref StackType_t items
    uint32_t stack_depth = (init->stack_size / sizeof(StackType_t));

    handler->handler = NULL;
    memset(&handler->buffer, 0, sizeof(StaticTask_t));
    assert(init->stack != NULL);
    handler->stack = (StackType_t *)init->stack;

    handler->handler = xTaskCreateStatic(init->task_function, init->name, stack_depth, init->argument, init->priority, handler->stack, &handler->buffer);
    assert(handler->handler);

#endif
}
