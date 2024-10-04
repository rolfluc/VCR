#pragma once
#include <stm32f0xx.h>
void InitializeI2C();
HAL_StatusTypeDef I2CWrite(uint16_t addr, uint8_t* dat, uint8_t length);