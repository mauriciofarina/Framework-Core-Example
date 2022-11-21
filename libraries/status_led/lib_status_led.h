/**
 * @file lib_status_led.c
 * @author Mauricio Dall Oglio Farina
 * @brief Status LED Control Library
 */
#ifndef __LIB_STATUS_LED_H__
#define __LIB_STATUS_LED_H__

#include <stdbool.h>
#include <stdint.h>

/**
 * @brief Run blinking code
 *
 * @param blinks[in] Number of blinks
 * @param time_on[in] Time on (ms)
 * @param time_off[in] Time off (ms)
 */
void lib_status_led_blink(uint32_t blinks, uint32_t time_on, uint32_t time_off);

#endif
