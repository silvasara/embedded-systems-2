#ifndef _I2C_H_ 
#define _I2C_H_ 

#include "bme280.h"
#define BME_ADDR 0x76


typedef struct temp_hum{
	float temperature;
	float humidity;
} temp_humidity;

void init_i2c();
void get_temperature_humidity(temp_humidity *th);

#endif // _I2C_H_
