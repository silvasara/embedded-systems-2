#include <gpio.h>

void enable_gpio(){
    wiringPiSetup();

    // output devices
    pinMode(LAMP_1, OUTPUT);
    pinMode(LAMP_2, OUTPUT);
    pinMode(LAMP_3, OUTPUT);
    pinMode(LAMP_4, OUTPUT);
    pinMode(AIR_COND_1, OUTPUT);
    pinMode(AIR_COND_2, OUTPUT);

    // input sensors
    pinMode(PRESENCE_SENSOR_1, INPUT);
    pinMode(PRESENCE_SENSOR_2, INPUT);
    pinMode(OPENING_SENSOR_1, INPUT);
    pinMode(OPENING_SENSOR_2, INPUT);
    pinMode(OPENING_SENSOR_3, INPUT);
    pinMode(OPENING_SENSOR_4, INPUT);
    pinMode(OPENING_SENSOR_5, INPUT);
    pinMode(OPENING_SENSOR_6, INPUT);
}

void turn_on_device(int pin){
    digitalWrite(pin, HIGH);
    printf("turning on pin %d\n", pin);
}

void turn_off_device(int pin){
    digitalWrite(pin, LOW);
    printf("turning off pin %d\n", pin);
}

void disable_gpio(){
    turn_off_device(LAMP_1);
    turn_off_device(LAMP_2);
    turn_off_device(LAMP_3);
    turn_off_device(LAMP_4);
    turn_off_device(AIR_COND_1);
    turn_off_device(AIR_COND_2);
}

void gpio(int pin, int mode){
    printf("pin %d: %d\n", pin, digitalRead(pin));

    if(mode == OUTPUT){
        turn_on_device(pin);
        sleep(2);
        turn_off_device(pin);
    }
}

