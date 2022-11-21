/**
 * @file mid_wifi.h
 * @author Mauricio Dall Oglio Farina
 * @brief WiFi Peripheral and Stack Interface Middleware Interface
 */
#ifndef __MID_WIFI_H__
#define __MID_WIFI_H__

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MID_WIFI_MAX_SSID_SIZE     32 /** Max SSID Size (Bytes) */
#define MID_WIFI_MAX_PASSWORD_SIZE 64 /** Max Password Size (Bytes) */

/**
 * @brief WiFi Network Configurations
 */
typedef struct {
    char ssid[MID_WIFI_MAX_SSID_SIZE];         /** SSID */
    char password[MID_WIFI_MAX_PASSWORD_SIZE]; /** Password */
} mid_wifi_config_t;

/**
 * @brief Device Scan Information
 */
typedef struct {

    char ssid[MID_WIFI_MAX_SSID_SIZE + 1]; /** SSID */
    int8_t rssi;                           /** Signal Strength (db) */

} mid_wifi_scan_t;

/**
 * @brief Start WiFi Station
 *
 * @details Starting a station should initialize all required
 * peripherals and stacks. After the initialization is completed,
 * the device should connect to the provided network automatically
 *
 * @param config[in] WiFi Station Configuration
 */
void mid_wifi_start_station(mid_wifi_config_t *const config);

/**
 * @brief Start WiFi Access Point
 *
 * @note The access point network should reject all connection requests.
 *
 * @param config[in] WiFi Access Point Configuration
 */
void mid_wifi_start_access_point(mid_wifi_config_t *const config);

/**
 * @brief Scan WiFi Networks
 *
 * @param buffer[in] Scan Information Buffer
 * @param items[in/out] Max Number of Networks / Networks Found
 */
void mid_wifi_scan(mid_wifi_scan_t *buffer, uint32_t *items);

#endif
