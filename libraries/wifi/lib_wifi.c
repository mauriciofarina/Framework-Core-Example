/**
 * @file lib_wifi.c
 * @author Mauricio Dall Oglio Farina
 * @brief WiFi Library Library
 */
#include "lib_wifi.h"

#include "wifi/mid_wifi.h"

void lib_wifi_init(void) {

    mid_wifi_config_t station_config = {
        .ssid = WIFI_STATION_SSID,
        .password = WIFI_STATION_PASSWORD,
    };

    mid_wifi_start_station(&station_config);

    mid_wifi_config_t access_point_config = {
        .ssid = WIFI_ACCESS_POINT_SSID,
        .password = WIFI_ACCESS_POINT_PASSWORD,
    };

    mid_wifi_start_access_point(&access_point_config);
}

void lib_wifi_scan(char *buffer) {

    uint32_t items = MAX_SCAN_ITEMS;
    mid_wifi_scan_t info[MAX_SCAN_ITEMS];
    mid_wifi_scan(info, &items);

    for (uint32_t i = 0; i < items; ++i) {
        sprintf(&buffer[strlen(buffer)], "%s,%d\n", info[i].ssid, info[i].rssi);
    }
}