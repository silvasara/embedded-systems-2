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

void get_gpio_states(gpio_out *devices, gpio_in *sensors){
   devices->lamp_1 = digitalRead(LAMP_1);
   devices->lamp_2 = digitalRead(LAMP_2);
   devices->lamp_3 = digitalRead(LAMP_3);
   devices->lamp_4 = digitalRead(LAMP_4);
   devices->air_cond_1 = digitalRead(AIR_COND_1);
   devices->air_cond_2 = digitalRead(AIR_COND_2);

   sensors->presence_sensor_1 = digitalRead(PRESENCE_SENSOR_1);
   sensors->presence_sensor_2 = digitalRead(PRESENCE_SENSOR_2);
   sensors->opening_sensor_1 = digitalRead(OPENING_SENSOR_1);
   sensors->opening_sensor_2 = digitalRead(OPENING_SENSOR_2);
   sensors->opening_sensor_3 = digitalRead(OPENING_SENSOR_3);
   sensors->opening_sensor_4 = digitalRead(OPENING_SENSOR_4);
   sensors->opening_sensor_5 = digitalRead(OPENING_SENSOR_5);
   sensors->opening_sensor_6 = digitalRead(OPENING_SENSOR_6);
}


void switch_state(char *pin, struct gpio_out *device){
    int state = 0;
    int gpio_pin = 0;
    
    if(strcmp(pin, "lamp_1") == 0){
            gpio_pin = LAMP_1;
            state = digitalRead(gpio_pin);
    }
    else if(strcmp(pin, "lamp_2") == 0){
            gpio_pin = LAMP_2;
            state = digitalRead(gpio_pin);
    }
    else if(strcmp(pin, "lamp_3") == 0){
            gpio_pin = LAMP_3;
            state = digitalRead(gpio_pin);
    }
    else if(strcmp(pin, "lamp_4") == 0){
            gpio_pin = LAMP_4;
            state = digitalRead(gpio_pin);
    }
    else if(strcmp(pin, "air_cond_1") == 0){
            gpio_pin = AIR_COND_1;
            state = digitalRead(gpio_pin);
    }
    else if(strcmp(pin, "air_cond_2") == 0){
            gpio_pin = AIR_COND_2;
            state = digitalRead(gpio_pin);
    }

    if(state){
        turn_off_device(gpio_pin);
    }
    else{
        turn_on_device(gpio_pin);
    }
}
