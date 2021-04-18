#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

#include "i2c.h"
#include "gpio.h"

void close_connections();

volatile int do_continue = 1;

int main(){
    signal(SIGINT, close_connections); // close connections with Ctrl+c

    // initializes connections
    //    open_uart();
    init_i2c();
    //    lcd_init();
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

    //    float internal_temperature;
    //    float potentiometer;
    //    float external_temperature;

    //    write_columns(); // start writing log in csv

    //    int write_log = 0; // flag for write in csv

    while(do_continue){
        // get temperature and humidity

        temp_humidity th;
        th = get_temperature_humidity();
        printf("Temperature: %.2f; Humidity: %2.f\n", th.temperature, th.humidity);
        //        if (write_log == 0){
        //            write_log = 1;
        //        }
        //        else{
        //            write_values(internal_temperature, external_temperature, reference_temperature, control); // write in csv
        //            write_log = 0;
        //        }
        //
        sleep(1);
    }


    return 0;
}

void close_connections(){
    //    close_uart();
    disable_gpio();
    sleep(1);
    do_continue = 0;
}
