#include "bme280.h"
#define BME_ADDR 0x76


struct temp_hum{
	float temperature;
	float humidity;
} typedef temp_humidity;

void init_i2c();
temp_humidity get_temperature_humidity();
