#include <stdlib.h>

struct states {
    int socket_;
    temp_humidity th;
    gpio_out devices;
    gpio_in sensors;
} typedef states;

void make_json(states *devices_states);
