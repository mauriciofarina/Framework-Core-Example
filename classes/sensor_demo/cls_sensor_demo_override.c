/**
 * @file cls_sensor_demo_override.c
 * @author Mauricio Dall Oglio Farina
 * @brief Demonstration Sensor Class Override Methods
 */
#include "cls_sensor_demo_override.h"

uint32_t cls_sensor_demo_get_raw_sample(sensor_t *const handler, uint8_t *data) {

    uint32_t size = 0;

    if (cls_rtos_mutex_lock_default(&handler->lock)) {
        // TODO: Read Sensor Data
        cls_rtos_mutex_unlock(&handler->lock);
    }

    return size;
}
