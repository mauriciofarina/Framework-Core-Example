/**
 * @file lib_wifi.h
 * @author Mauricio Dall Oglio Farina
 * @brief WiFi Library Library
 */
#ifndef __LIB_WIFI_H__
#define __LIB_WIFI_H__

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "rtos/lib_rtos.h"

#ifndef WIFI_STATION_SSID
#define WIFI_STATION_SSID "DEFAULT_STA" /** WiFi Station SSID */
#endif

#ifndef WIFI_STATION_PASSWORD
#define WIFI_STATION_PASSWORD "DEFAULT" /** WiFi Station Password */
#endif

#ifndef WIFI_ACCESS_POINT_SSID
#define WIFI_ACCESS_POINT_SSID "DEFAULT_AP" /** WiFi Access Point SSID */
#endif

#ifndef WIFI_ACCESS_POINT_PASSWORD
#define WIFI_ACCESS_POINT_PASSWORD "DEFAULT" /** WiFi Access Point Password */
#endif

#define MAX_SCAN_ITEMS 10 /** Maximum Number of Scan Items */

/**
 * @brief Library Initialization
 */
void lib_wifi_init(void);

/**
 * @brief Scan WiFi Networks
 *
 * @param buffer[out] Output String
 */
void lib_wifi_scan(char *buffer);

#endif
