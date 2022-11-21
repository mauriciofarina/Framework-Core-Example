/**
 * @file mid_gpio.h
 * @author Mauricio Dall Oglio Farina
 * @brief GPIO Interface
 */
#ifndef __MID_GPIO_H__
#define __MID_GPIO_H__

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

/**
 * @brief GPIO Pins
 */
typedef enum {
    MID_GPIO_STATUS_LED = 0, /** Device Status LED */

} mid_gpio_pin_t;

/**
 * @brief Set GPIO Output Pin
 *
 * @param instance[in] Instance
 * @param enable[in] true -> High, false -> Low
 */
void mid_gpio_set_pin(mid_gpio_pin_t instance, bool enable);

#endif
