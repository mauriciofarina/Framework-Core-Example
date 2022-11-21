/**
 * @file cls_sensor_demo.c
 * @author Mauricio Dall Oglio Farina
 * @brief Demonstration Sensor Class
 */
#include "cls_sensor_demo.h"
#include "cls_sensor_demo_override.h"

void cls_sensor_demo_init(sensor_demo_t *const handler, sensor_demo_init_t *const init) {

    cls_sensor_init(&handler->super, &init->super);

    static const struct sensor_api api = {
        .get_raw_sample = cls_sensor_demo_get_raw_sample,
    };
    handler->super.api = &api;
}
