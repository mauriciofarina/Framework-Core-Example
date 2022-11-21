/**
 * @file lib_status_led.c
 * @author Mauricio Dall Oglio Farina
 * @brief Status LED Control Library
 */
#include "lib_status_led.h"

#include "gpio/mid_gpio.h"

#include "rtos/lib_rtos.h"

void lib_status_led_blink(uint32_t blinks, uint32_t time_on, uint32_t time_off) {

    mid_gpio_set_pin(MID_GPIO_STATUS_LED, false);

    for (uint32_t i = 0; i < blinks; ++i) {
        lib_rtos_delay(time_off);
        mid_gpio_set_pin(MID_GPIO_STATUS_LED, true);
        lib_rtos_delay(time_on);
        mid_gpio_set_pin(MID_GPIO_STATUS_LED, false);
    }
}
