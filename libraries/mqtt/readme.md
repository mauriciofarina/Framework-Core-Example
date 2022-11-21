# MQTT Client Library

MQTT Client Implementation


## Available Clients:

- [ESP-MQTT](esp_mqtt/readme.md)


## Configuration Macros

|     Macro     |   Default Value    |   Description    |
| :-----------: | :----------------: | :--------------: |
| `MQTT_SERVER` | "mqtt://localhost" | MQTT Broker URL  |
|  `MQTT_PORT`  |        1883        | MQTT Broker Port |


# How to use it

1. Configure MQTT Client by defining the required preprocessor macros on `lib_mqtt.h`
2. Setup network connection
3. After network connection is established, connect to MQTT broker by calling `lib_mqtt_init`


