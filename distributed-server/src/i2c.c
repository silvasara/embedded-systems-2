#include "i2c.h"

void init_i2c(){
    bme280Init(1, BME_ADDR);
}

void get_temperature_humidity(temp_humidity *th){
    int temperature, pressure, humidity;

    bme280ReadValues(&temperature, &pressure, &humidity);

    th->temperature = temperature/100;
    th->humidity = humidity/100;
}
