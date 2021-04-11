#include <pwm.h>

void enable_gpio(){
    wiringPiSetup();		   
    pinMode(RESISTOR_PIN, OUTPUT);
    pinMode(FAN_PIN, OUTPUT);

    softPwmCreate(RESISTOR_PIN, 1, 100);
    softPwmCreate(FAN_PIN, 1, 100);
}

void control_temperature(double value){
    if (value > 0){
        softPwmWrite(RESISTOR_PIN, value);
        softPwmWrite(FAN_PIN, 0);
    }
    else if (value < -40){
        softPwmWrite(FAN_PIN, value * -1);
        softPwmWrite(RESISTOR_PIN, 0);
    }
    else{
        disable_gpio();
    }
}

void disable_gpio(){
    softPwmWrite(RESISTOR_PIN, 0);
    softPwmWrite(FAN_PIN, 0);
    printf("Ventoinha e resistor desligados.\n");
}
