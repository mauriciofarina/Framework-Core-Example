/**
 * @file app_system.c
 * @author Mauricio Dall Oglio Farina
 * @brief System Application
 */
#include "app_system.h"

#include "status_led/lib_status_led.h"
#include "wifi/lib_wifi.h"

#include "calibration/app_calibration.h"

static rtos_task_t task_handler = {0};                  /** Task Handler */
static uint8_t task_stack[APP_SYSTEM_STACK_SIZE] = {0}; /** Task Stack Buffer */

static void app_system_task(void *context) {

    (void)context;

    cls_rtos_task_set_priority(&task_handler, RTOS_PRIORITY_GOD);

    // Library Initialization
    lib_wifi_init();
    lib_rtos_delay(5000); // A delay to wait wifi connection

    // Application Initializations
    app_calibration_init();

    // Start Applications
    app_calibration_start();

    // From this point forward system just controls the status LED
    cls_rtos_task_set_priority(&task_handler, RTOS_PRIORITY_IDLE);
    while (1) {
        lib_status_led_blink(1, 500, 500);
    }
}

void app_system_start(void) {

    rtos_task_init_t init = {
        .name = APP_SYSTEM_NAME,
        .stack_size = APP_SYSTEM_STACK_SIZE,
        .task_function = app_system_task,
        .argument = NULL,
        .priority = APP_SYSTEM_PRIORITY,
        .stack = task_stack,
    };

    cls_rtos_task_init(&task_handler, &init);
}
