#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

#include "i2c.h"
#include "gpio.h"
#include "serializer.h"

void close_connections();

volatile int do_continue = 1;

int main(){
    signal(SIGINT, close_connections); // close connections with Ctrl+c

    init_i2c();
    enable_gpio();

    gpio(LAMP_1, OUTPUT);
    gpio(LAMP_2, OUTPUT);
    gpio(LAMP_3, OUTPUT);
    gpio(LAMP_4, OUTPUT);
    gpio(AIR_COND_1, OUTPUT);
    gpio(AIR_COND_2, OUTPUT);
    gpio(PRESENCE_SENSOR_1, INPUT);
    gpio(PRESENCE_SENSOR_2, INPUT);
    gpio(OPENING_SENSOR_1, INPUT);
    gpio(OPENING_SENSOR_2, INPUT);
    gpio(OPENING_SENSOR_3, INPUT);
    gpio(OPENING_SENSOR_4, INPUT);
    gpio(OPENING_SENSOR_5, INPUT);
    gpio(OPENING_SENSOR_6, INPUT);

    while(do_continue){
        // get temperature and humidity

        temp_humidity th;
        th = get_temperature_humidity();
        printf("Temperature: %.2f; Humidity: %2.f\n", th.temperature, th.humidity);
        sleep(1);
    }


    return 0;
}

void close_connections(){
    disable_gpio();
    sleep(1);
    do_continue = 0;
}
