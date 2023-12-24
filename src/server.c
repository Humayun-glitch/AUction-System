// server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Include the necessary header file for strlen
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "server.h"

#define PORT 8080

void handle_client(int client_socket) {
    char welcome_message[] = "Welcome to the auction server!\n";
    send(client_socket, welcome_message, strlen(welcome_message), 0);

    printf("Sent welcome message to client\n");

    char buffer[1024];
    ssize_t received_bytes __attribute__((unused)) = recv(client_socket, buffer, sizeof(buffer), 0);

    // Handle received data as needed
    printf("Received %zd bytes from client\n", received_bytes);

    // Close the client socket when done
    close(client_socket);

    printf("Closed client socket\n");
}

void start_auction_server(Auction *auction) {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error binding server socket");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 3) < 0) {
        perror("Error listening on server socket");
        exit(EXIT_FAILURE);
    }

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket < 0) {
            perror("Error accepting client connection");
            exit(EXIT_FAILURE);
        }

        // Handle the client in a separate function
        handle_client(client_socket);
    }
}
