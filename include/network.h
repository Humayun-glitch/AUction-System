// include/network.h

#ifndef NETWORK_H
#define NETWORK_H

void send_message(int sockfd, const char* message);
void receive_message(int sockfd, char* buffer, int buffer_size);

#endif
