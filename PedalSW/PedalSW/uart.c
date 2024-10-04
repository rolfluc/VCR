#include "uart.h"
#include "PinDefs.h"

static const uint32_t uartPinMode = GPIO_MODE_AF_PP;
static const uint32_t uartPinPull = GPIO_NOPULL;
static const uint32_t uartPinSpeed = GPIO_SPEED_FREQ_HIGH;
static const uint32_t uartTimeout_ms = 10;

UART_HandleTypeDef Uart1Port;


static void InitUartPins()
{
	GPIO_InitTypeDef init;
	init.Speed = uartPinSpeed;
	init.Mode = uartPinMode;
	init.Pull = uartPinPull;
	init.Alternate = GPIO_AF1_USART1; 
	init.Pin = UART_TX.pinNumber;
	HAL_GPIO_Init(UART_TX.pinPort, &init);
	init.Pin = UART_RX.pinNumber;
	HAL_GPIO_Init(UART_RX.pinPort, &init);
}

void InitializeUartPorts()
{
	__HAL_RCC_USART1_CLK_ENABLE();
	InitUartPins();
	Uart1Port.Instance = USART1;
	Uart1Port.Init.BaudRate = 9600;
	Uart1Port.Init.WordLength = UART_WORDLENGTH_8B;
	Uart1Port.Init.StopBits = UART_STOPBITS_1;
	Uart1Port.Init.Parity = UART_PARITY_NONE;
	Uart1Port.Init.Mode = UART_MODE_TX_RX;
	Uart1Port.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	Uart1Port.Init.OverSampling = UART_OVERSAMPLING_16;
	Uart1Port.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
	
	if (HAL_UART_Init(&Uart1Port) != HAL_OK)
	{
		//Error_Handler();
	}
}



void WriteUartData(uint8_t* data, uint32_t length)
{
	HAL_UART_Transmit(&Uart1Port, data, length, uartTimeout_ms);	
}
