#include "serializer.h"

char *make_json(data *server){
    char *json = (char*) malloc(400*sizeof(char));

    sprintf(
        json,
        "{"
            "\"lamp_01\": %d,"
            "\"lamp_02\": %d,"
            "\"lamp_03\": %d,"
            "\"lamp_04\": %d,"
            "\"air_cond_01\": %d,"
            "\"air_cond_02\": %d,"
            "\"living_room\": %d,"
            "\"kitchen\": %d,"
            "\"kitchen_door\": %d,"
            "\"kitchen_window\": %d,"
            "\"living_room_door\": %d,"
            "\"living_room_window\": %d,"
            "\"room_window_01\": %d,"
            "\"room_window_02\": %d,"
            "\"temperature\": %.2f,"
            "\"humidity\": %.2f"
        "}",
        server->devices->lamp_1,
        server->devices->lamp_2,
        server->devices->lamp_3,
        server->devices->lamp_4,
        server->devices->air_cond_1,
        server->devices->air_cond_2,
        server->sensors->presence_sensor_1,
        server->sensors->presence_sensor_2,
        server->sensors->opening_sensor_1,
        server->sensors->opening_sensor_2,
        server->sensors->opening_sensor_3,
        server->sensors->opening_sensor_4,
        server->sensors->opening_sensor_5,
        server->sensors->opening_sensor_6,
        server->th->temperature,
        server->th->humidity);

    return json;
}
