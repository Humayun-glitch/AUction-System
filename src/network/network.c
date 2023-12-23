// src/network/network.c
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "network.h"

void send_message(int sockfd, const char* message) {
    write(sockfd, message, strlen(message));
}

void receive_message(int sockfd, char* buffer, int buffer_size) {
    memset(buffer, 0, buffer_size);
    read(sockfd, buffer, buffer_size - 1);
}
