#include <wiringPi.h>
#include <softPwm.h>


// output devices
#define LAMP_1 0 // kitchen
#define LAMP_2 1 // living room
#define LAMP_3 2 // room 1
#define LAMP_4 3 // room 2
#define AIR_COND_1 23 // room 1
#define AIR_COND_2 24 // room 2

// input sensors
#define PRESENCE_SENSOR_1 6  // living room
#define PRESENCE_SENSOR_2 25 // kitchen
#define OPENING_SENSOR_1 21  // kitchen's door
#define OPENING_SENSOR_2 22  // kitchen's window
#define OPENING_SENSOR_3 26  // living room's door
#define OPENING_SENSOR_4 27  // living room's window
#define OPENING_SENSOR_5 28  // room1's door
#define OPENING_SENSOR_6 29  // room1's window

void enable_gpio();
void disable_gpio();
