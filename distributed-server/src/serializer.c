#include "serializer.h"

void make_json(states *devices_states){
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

        devices_states->devices.lamp_1,
        devices_states->devices.lamp_2,
        devices_states->devices.lamp_3,
        devices_states->devices.lamp_4,
        devices_states->devices.air_cond_1,
        devices_states->devices.air_cond_2,
        devices_states->sensors.presence_sensor_1,
        devices_states->sensors.presence_sensor_2,
        devices_states->sensors.opening_sensor_1,
        devices_states->sensors.opening_sensor_2,
        devices_states->sensors.opening_sensor_3,
        devices_states->sensors.opening_sensor_4,
        devices_states->sensors.opening_sensor_5,
        devices_states->sensors.opening_sensor_6,
        devices_states->th.temperature,
        devices_states->th.humidity
    );
}
