#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#include "i2c.h"
#include "gpio.h"
#include "serializer.h"
#include "server.h"


pthread_mutex_t bme280_mutex, sensors_mutex, send_mutex;
pthread_cond_t bme280_cond, sensors_cond, send_cond;

volatile int run = 1,
			 read_bme280 = 0,
			 read_sensors = 0,
			 run_sender = 0,
			 th_counter = 0,
			 sender_counter = 0;


void *send_data(void* args){
    pthread_mutex_lock(&send_mutex);

    while(!run_sender && run){
        pthread_cond_wait(&send_cond, &send_mutex);

        if(sender_counter == 5){
            data *server = (data*) args;
            char *payload = (char*) malloc(400*sizeof(char));

            payload = make_json(server);

            send(server->send_socket, payload, strlen(payload), 0 );

            printf("%s\n", payload);
            sender_counter = 0;
        }

        run_sender = 0;
        sender_counter++;
    }
    pthread_mutex_unlock(&send_mutex);
    pthread_exit( NULL );
}

void *get_states(void *args){
    pthread_mutex_lock(&sensors_mutex);

    while(!read_sensors && run){
        pthread_cond_wait(&sensors_cond, &sensors_mutex);
        data *server = (data*) args;

        get_gpio_states(server->devices, server->sensors);

        read_sensors = 0;
    }
    pthread_mutex_unlock(&sensors_mutex);
    pthread_exit( NULL );
}


void *get_temp_hum(void* args){
    pthread_mutex_lock(&bme280_mutex);

    while(!read_bme280 && run){
        pthread_cond_wait(&bme280_cond, &bme280_mutex);

        if(th_counter == 5){
            data *server = (data*) args;
            get_temperature_humidity(server->th);
            th_counter = 0;
        }

        read_bme280 = 0;
        th_counter++;
    }

    pthread_mutex_unlock(&bme280_mutex);
    pthread_exit( NULL );
}

int main(){
    data *server = malloc(sizeof(data));
    temp_humidity *th = malloc(sizeof(temp_humidity));
    gpio_out *devices = malloc(sizeof(gpio_out));
    gpio_in *sensors = malloc(sizeof(gpio_in));

    if(config_sender(server) == -1){
        exit(1);
    }

    server->th = th;
    server->devices = devices;
    server->sensors = sensors;

	init_i2c();
	enable_gpio();

    pthread_mutex_init(&bme280_mutex, NULL);
    pthread_mutex_init(&send_mutex, NULL);
    pthread_mutex_init(&sensors_mutex, NULL);

    pthread_cond_init(&bme280_cond, NULL);
    pthread_cond_init(&send_cond, NULL);
    pthread_cond_init(&sensors_cond, NULL);

    pthread_t threads[3];
    pthread_create(&threads[0], NULL, send_data, (void *)server);
    pthread_create(&threads[1], NULL, get_temp_hum, (void *)server);
    pthread_create(&threads[2], NULL, get_states, (void *)server);

    while(run){}

    pthread_mutex_destroy(&bme280_mutex);
    pthread_mutex_destroy(&send_mutex);
    pthread_mutex_destroy(&sensors_mutex);

    pthread_cond_destroy(&bme280_cond);
    pthread_cond_destroy(&send_cond);
    pthread_cond_destroy(&sensors_cond);

    close(server->send_socket);
    close(server->recv_socket);
	disable_gpio();

    return 0;
}
