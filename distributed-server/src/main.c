#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

#include "uart.h"
#include "i2c.h"
#include "lcd.h"
#include "pid.h"
#include "pwm.h"
#include "csv.h"

void close_connections();

volatile int do_continue = 1;

int main(){
    signal(SIGINT, close_connections); // close connections with Ctrl+c

    // initializes connections
    open_uart();
    init_i2c();
    lcd_init();
    enable_gpio();

    float internal_temperature;
    float potentiometer;
    float external_temperature;

    write_columns(); // start writing log in csv

    int write_log = 0; // flag for write in csv

    while(do_continue){
        // get temperatures 
        internal_temperature = get_temperature(INTERNAL_TEMPERATURE);
        printf("TI = %f\n", internal_temperature);

        potentiometer = get_temperature(POTENTIOMETER_TEMPERATURE);
        printf("TR = %f\n", potentiometer);

        external_temperature = get_external_temperature();
        printf("TE = %f\n", external_temperature);

        print_on_lcd(internal_temperature, external_temperature, potentiometer); //

        float reference_temperature = potentiometer;

        // make control of temperature with pid
        double kp = 5.0, ki = 1.0, kd = 5.0; 
        pid_configura_constantes(kp, ki, kd);
        pid_atualiza_referencia(reference_temperature);

        double control = pid_controle(internal_temperature);
        printf("PID: %f\n", control);

        control_temperature(control);

        if (write_log == 0){
            write_log = 1;
        }
        else{
            write_values(internal_temperature, external_temperature, reference_temperature, control); // write in csv
            write_log = 0;
        }

        sleep(1);
    }

    printf("Finalizando...\n");
    sleep(1);
    printf("Finalizado!");

    return 0;
}

void close_connections(){
    close_uart();
    disable_gpio();
    sleep(1);
    do_continue = 0;
}
