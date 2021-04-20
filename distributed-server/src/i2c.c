#include "i2c.h"

void init_i2c(){
    if(bme280Init(1, BME_ADDR) < 0){
        fprintf(stderr, "Failed init i2c!\n");
        exit(-1);
    }
    fprintf(stderr, "Init i2c!\n");
}

void get_temperature_humidity(temp_humidity *th){
    int temperature, pressure, humidity;

    bme280ReadValues(&temperature, &pressure, &humidity);

    th->temperature = temperature/100;
    th->humidity = humidity/100;
}
