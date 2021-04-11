#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>

#define RESISTOR_PIN 4
#define FAN_PIN 5

void enable_gpio();
void control_temperature(double value);
void disable_gpio();
