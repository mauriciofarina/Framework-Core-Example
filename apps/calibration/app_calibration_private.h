/**
 * @file app_calibration_private.h
 * @author Mauricio Dall Oglio Farina
 * @brief Auto Calibration System Application Private Header
 */
#ifndef __APP_CALIBRATION_PRIVATE_H__
#define __APP_CALIBRATION_PRIVATE_H__

#include "app_calibration.h"

/**
 * @brief Get Raw Sample Request Callback
 *
 * @param topic[in] Topic
 * @param data[in] Request Data
 * @param length[in] Data Size (Bytes)
 */
static void get_raw_sample_callback(char *topic, uint8_t *data, uint32_t length);

/**
 * @brief Sensor Predict Request Callback
 *
 * @param topic[in] Topic
 * @param data[in] Request Data
 * @param length[in] Data Size (Bytes)
 */
static void predict_callback(char *topic, uint8_t *data, uint32_t length);

/**
 * @brief Set Model Request Callback
 *
 * @param topic[in] Topic
 * @param data[in] Request Data
 * @param length[in] Data Size (Bytes)
 */
static void set_model_callback(char *topic, uint8_t *data, uint32_t length);

/**
 * @brief Scan Devices Request Callback
 *
 * @param topic[in] Topic
 * @param data[in] Request Data
 * @param length[in] Data Size (Bytes)
 */
static void scan_devices_callback(char *topic, uint8_t *data, uint32_t length);

/**
 * @brief Subscribe Calibration Topics
 *
 */
static void subscribe_topics(void);

/**
 * @brief Application Task
 *
 * @param context[in] Not Used
 */
static void app_calibration_task(void *context);

#endif
