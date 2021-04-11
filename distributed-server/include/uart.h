#include <stdio.h>
#include <unistd.h>         //Used for UART
#include <fcntl.h>          //Used for UART
#include <termios.h>        //Used for UART
#include <string.h>
#include <crc16.h>

#define INTERNAL_TEMPERATURE 0xC1
#define POTENTIOMETER_TEMPERATURE 0xC2

void open_uart();
float get_temperature(char code);
int write_on_uart(char code);
float read_from_uart();
void close_uart();
