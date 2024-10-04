#pragma once
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAPPING_SIZE 9
typedef struct
{
	uint16_t ADCValue;
	uint8_t DigiPotCount;
}Mapping;

// 500k ~= 3.2V
// 375k ~= 2.84V
// 250k ~= 2.48V
// 175k ~= 1.98V
// 100k ~= 1.49V
// 75k ~= 1.12V
// 50k ~= 0.9V
// 30k ~= 0.56V
// 10k ~= 0.21

//0.000781v per count
//129 counts per 100mV
Mapping TotalMap[MAPPING_SIZE] = { 
	{0x0FFA, 0x82}, // 500k, 4090 - 3.2
	{0x0E21, 0xA1}, // 375k, 3617 - 2.84
	{0x0C49, 0xc1}, // 250k, 3145 - 2.48
	{0x09DE, 0xd3}, // 175k, 2515 ~= 1.98V
	{0x0773, 0xe6}, // 100k, 1907 - 1.49
	{0x05F9, 0xed}, // 75k, 1529  - 1.12
	{0x0480, 0xf4}, // 50k, 1152 - 0.9
	{0x02c6, 0xf8}, // 30k, 710 - 0.55
	{0x010C, 0xfd}, // 10k, 268 - 0.21
};

static inline uint8_t GetDigipotValue(uint16_t adcVal)
{
	uint16_t distance = 0xffff;
	uint8_t index = 0;
	for (int i = 0; i < MAPPING_SIZE; i++)
	{
		uint16_t tmpDist = abs(TotalMap[i].ADCValue -  adcVal);
		if (tmpDist < distance)
		{
			distance = tmpDist;
			index = i;
		}
	}
	return TotalMap[index].DigiPotCount;
}
