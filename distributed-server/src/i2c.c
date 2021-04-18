#include "i2c.h"

void init_i2c(){
    bme280Init(1, BME_ADDR);
}

temp_humidity get_temperature_humidity(){
    int temperature, pressure, humidity;

    bme280ReadValues(&temperature, &pressure, &humidity);

    temp_humidity th;

    th.temperature = temperature/100;
    th.humidity = humidity/100;

    return th;
}
