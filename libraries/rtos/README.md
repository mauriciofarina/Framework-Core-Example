# RTOS Library

RTOS Interface Library.


## Supported Operational Systems

|                          RTOS                           | Configuration Macro |
| :-----------------------------------------------------: | :-----------------: |
| [FreeRTOS](https://github.com/FreeRTOS/FreeRTOS-Kernel) | `USE_RTOS_FREERTOS` |

## Library Configurations

|         Macro          |        Description        |
| :--------------------: | :-----------------------: |
| `RTOS_DEFAULT_TIMEOUT` | Default Timeout Time (ms) |
|  `USE_RTOS_FREERTOS`   |    Use FreeRTOS Kernel    |

## FreeRTOS Configurations

|                   Macro                   |    Value     |           Description            |
| :---------------------------------------: | :----------: | :------------------------------: |
|     `configCHECK_FOR_STACK_OVERFLOW`      |              |    Enable Stack Overflow Hook    |
| `configUSE_PORT_OPTIMISED_TASK_SELECTION` |              | Enable Port Optimized Scheduler  |
|    `configSUPPORT_DYNAMIC_ALLOCATION`     |              | Enable Dynamic Memory Allocation |
|          `configTOTAL_HEAP_SIZE`          | DESIRED SIZE |     Kernel Heap Size (Bytes)     |
|            `configUSE_MUTEXES`            |              |          Enable Mutexes          |
|          `configMAX_PRIORITIES`           |      7       |    Number of Priority Levels     |
|           `configTICK_RATE_HZ`            |     1000     |            RTOS Tick             |

## Dependencies

|                          Name                           |    Type     |         Observation         |
| :-----------------------------------------------------: | :---------: | :-------------------------: |
| [FreeRTOS](https://github.com/FreeRTOS/FreeRTOS-Kernel) | Third-Party | Only if `USE_RTOS_FREERTOS` |


# Development Guidelines

## Naming Convention

API Functions should be named according with the convention below:

|   Suffix   |               Description               |
| :--------: | :-------------------------------------: |
| `_default` | Use `RTOS_DEFAULT_TIMEOUT` timeout time |
|   `_isr`   |              ISR Safe Call              |

---
**Waring**

ISR should only use ISR Safe Function Calls

---


