# Core Library

This library contains all hardware independent implementations for the Project

# Disclosure

This project was implemented as a non-functional example.
The project can be successfully compiled. 
However, no verification was made to ensure the correct behavior of this library.

# Configurations

## Macros

The following Macros are expected to be defined:

### Debug Only
|        Macro        | Value |         Description          |
| :-----------------: | :---: | :--------------------------: |
|       `DEBUG`       |       | Enable Debug Implementations |
|  `USE_RTOS_KERNEL`  |       |     Enable RTOS Features     |
| `USE_RTOS_FREERTOS` |       |    Select FreeRTOS Kernel    |



### Library Configurations

- [lib_rtos](libraries/rtos/README.md)
- [lib_wifi](libraries/wifi/README.md)
- [lib_mqtt](libraries/mqtt/README.md)


---

**Note**

Hardware Specific Macros may be required. Check Hardware Specific Project Documentation for More Information.

---


## Include Paths

The following Include Paths are expected to be known by the compiler

```
${CORE_LIBRARY}/apps
${CORE_LIBRARY}/classes
${CORE_LIBRARY}/interfaces
${CORE_LIBRARY}/libraries
```

# Development Guidelines

## Code Formatting Style

`.clang-format` provides the set of formatting style rules for this project. Make sure to configure your IDE to enforce this format. Also, it is highly advised to also import this file to the MCU specific project.

## Development Labels

```c
// TODO: Something That Needs to Be Implemented
// WARING: Important Comment
// FIXME: Bug That Needs to Be Fixed
// FUTURE: Something That Should Be Implemented in the Future 

```

## Portability Domain

This project was design to be ported to MCUs with the following requirements:

| Requirement  |            Specification             |
| :----------: | :----------------------------------: |
| Architecture |               32-bits                |
|  Endianness  |            Little Endian             |
| Peripherals  | WiFi Module (Station + Access Point) |
|  RAM Memory  |      Check Sensor Requirements       |
| Flash Memory |                512 KB                |
|  Frequency   |      Check Sensor Requirements       |


Regarding implementation, the project has the following requirements:

|  Requirement   |         Specification         |
| :------------: | :---------------------------: |
| Implementation | Real-Time Multi-Thread (RTOS) |


## Sensor Inclusion

To include a new sensor, just create a new `sensor` child class and Add it to `system` app initialization

