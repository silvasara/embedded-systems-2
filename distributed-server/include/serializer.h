#ifndef _SERIALIZER_H_ 
#define _SERIALIZER_H_ 

#include "i2c.h"
#include "gpio.h"
#include <stdlib.h>

typedef struct data {
	int send_socket;	
	int recv_socket;	
    temp_humidity *th;
    gpio_out *devices;
    gpio_in *sensors;
} data;

char *make_json(data *devices_states);

#endif // _SERIALIZER_H_
