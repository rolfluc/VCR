#include "i2c.h"
#include "PinDefs.h"

static const uint32_t i2cPinMode = GPIO_MODE_AF_OD;
static const uint32_t i2cPinPull = GPIO_NOPULL;
static const uint32_t i2cPinSpeed = GPIO_SPEED_FREQ_LOW;
static const uint32_t I2CTimeout_ms = 50;


I2C_HandleTypeDef hi2c;

static void InitializeI2CPins()
{
	GPIO_InitTypeDef init;
	init.Speed = i2cPinSpeed;
	init.Mode = i2cPinMode;
	init.Pull = i2cPinPull;
	init.Alternate = GPIO_AF4_I2C1; 
	init.Pin = I2C_SDA.pinNumber;
	HAL_GPIO_Init(I2C_SDA.pinPort, &init);
	init.Pin = I2C_SCL.pinNumber;
	HAL_GPIO_Init(I2C_SCL.pinPort, &init);
}

void InitializeI2C()
{
	__HAL_RCC_I2C1_CLK_ENABLE();
	InitializeI2CPins();
	I2C_InitTypeDef init;
	init.Timing = 0x0000DDDE;
	init.OwnAddress1 = 0;
	init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	init.OwnAddress2 = 0;
	init.OwnAddress2Masks = I2C_OA2_NOMASK;
	init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
	hi2c.Instance = I2C1;
	hi2c.Init = init;
	HAL_I2C_Init(&hi2c);
}

HAL_StatusTypeDef I2CWrite(uint16_t addr, uint8_t* dat, uint8_t length)
{
	return HAL_I2C_Master_Transmit(&hi2c, addr, dat, length, I2CTimeout_ms);
}