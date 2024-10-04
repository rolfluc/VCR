#include <stm32f0xx_hal.h>
#include <stm32_hal_legacy.h>
#include "i2c.h"
#include "digipot.h"
#include "uart.h"
#include "adc.h"
#include "adcMapping.h"

void SysTick_Handler(void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}

int main(void)
{
	char writeBuffer[8];
	HAL_Init();
	__GPIOA_CLK_ENABLE();
	
	InitializeI2C();
	InitializeUartPorts();
	InitADCs();
	InitDigipot();

	for (;;)
	{
		// Sample at 50hz
		HAL_Delay(20);
		uint16_t val = ReadPedal();
		uint8_t digiVal = GetDigipotValue(val);
		uint8_t len = snprintf(writeBuffer, sizeof(writeBuffer), "0x%x\r\n", digiVal);
		WriteUartData((uint8_t*)writeBuffer, len);
		DriveDigipot(digiVal);
	}
}
