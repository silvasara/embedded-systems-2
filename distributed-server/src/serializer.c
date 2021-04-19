#include "serializer.h"

char *make_json(data *server){
    char *json = (char*) malloc(400*sizeof(char));

    sprintf(
        json,
        "{"
            "\"lamp_1\": %d,"
            "\"lamp_2\": %d,"
            "\"lamp_3\": %d,"
            "\"lamp_4\": %d,"
            "\"air_cond_1\": %d,"
            "\"air_cond_2\": %d,"
            "\"presence_sensor_1\": %d,"
            "\"presence_sensor_2\": %d,"
            "\"opening_sensor_1\": %d,"
            "\"opening_sensor_2\": %d,"
            "\"opening_sensor_3\": %d,"
            "\"opening_sensor_4\": %d,"
            "\"opening_sensor_5\": %d,"
            "\"opening_sensor_6\": %d,"
            "\"temperature\": %.2f,"
            "\"humidity\": %.2f,"
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
