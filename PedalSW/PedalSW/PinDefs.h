#pragma once
#include <stm32f0xx.h>
typedef struct
{
	uint32_t pinNumber;
	GPIO_TypeDef* pinPort;
}PinDef;


static const PinDef I2C_SCL = { .pinNumber = GPIO_PIN_9, .pinPort = GPIOA };
static const PinDef I2C_SDA = { .pinNumber = GPIO_PIN_10, .pinPort = GPIOA };

static const PinDef UART_RX = { .pinNumber = GPIO_PIN_3, .pinPort = GPIOA };
static const PinDef UART_TX = { .pinNumber = GPIO_PIN_2, .pinPort = GPIOA };

static const PinDef Pedal_ADC = { .pinNumber = GPIO_PIN_0, .pinPort = GPIOA };