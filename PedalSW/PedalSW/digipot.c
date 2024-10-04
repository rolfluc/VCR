#include "digipot.h"
#include "i2c.h"

static const uint8_t DigipotAddr = 0x58;
static const uint8_t DefaultValue = 0x00;

static void DriveDigipotI2C(uint8_t cmdValue)
{
	uint8_t cmdData[2] = { 0x00, cmdValue };
	I2CWrite(DigipotAddr, cmdData, sizeof(cmdData));
}

void InitDigipot()
{
	DriveDigipotI2C(DefaultValue);
}

void DriveDigipot(uint8_t count)
{
	DriveDigipotI2C(count);
}
