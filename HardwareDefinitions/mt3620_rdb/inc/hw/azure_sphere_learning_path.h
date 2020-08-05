/* Copyright (c) Microsoft Corporation. All rights reserved.
   Licensed under the MIT License. */

// This file defines the mapping from the MT3620 reference development board (RDB) to the
// 'sample hardware' abstraction used by the samples at https://github.com/Azure/azure-sphere-samples.
// Some peripherals are on-board on the RDB, while other peripherals must be attached externally if needed.
// https://docs.microsoft.com/en-us/azure-sphere/app-development/manage-hardware-dependencies
// to enable apps to work across multiple hardware variants.

// This file is autogenerated from ../../azure_sphere_learning_path.json.  Do not edit it directly.

#pragma once
#include "mt3620_rdb.h"

// MT3620 RDB: LED 1
#define LED1 MT3620_RDB_LED1_GREEN

// MT3620 RDB: LED 2
#define LED2 MT3620_RDB_LED4_BLUE

// MT3620 RDB: Network Connected
#define NETWORK_CONNECTED_LED MT3620_RDB_NETWORKING_LED_GREEN

// HCSR04 Left
#define HCSR04_LEFT MT3620_RDB_HEADER1_PIN4_GPIO

// HCSR04 Right
#define HCSR04_RIGHT MT3620_RDB_HEADER1_PIN12_GPIO

// MT3620 RDB: UART for Seeed Studio Grove Board
#define UART0 MT3620_ISU0_UART

// AVNET Start Kit Definition
#define I2cMaster2 MT3620_RDB_HEADER2_ISU0_I2C

// MT3620 RDB: LED 1
#define LED_RED MT3620_RDB_LED1_RED

// MT3620 RDB: LED 1
#define LED_GREEN MT3620_RDB_LED1_GREEN

// MT3620 RDB: LED 1
#define LED_BLUE MT3620_RDB_LED1_BLUE

// MT3620 RDB: LED 1
#define LED_RED_RIGHT MT3620_RDB_LED4_RED

// MT3620 RDB: LED 1
#define LED_GREEN_RIGHT MT3620_RDB_LED4_GREEN

// MT3620 RDB: LED 1
#define LED_BLUE_RIGHT MT3620_RDB_LED4_BLUE
