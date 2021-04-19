#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "serializer.h"

#define DISTRIBUTED_HOST "192.168.0.4"
#define DISTRIBUTED_PORT 10119
#define CENTRAL_HOST "192.168.0.53"
#define CENTRAL_PORT 10019

int config_sender(data *server);
int config_receiver(data *server);
