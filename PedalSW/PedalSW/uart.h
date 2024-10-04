#pragma once
#include <stm32f0xx.h>
void InitializeUartPorts();
void WriteUartData(uint8_t* data, uint32_t length);