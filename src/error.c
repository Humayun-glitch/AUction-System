// src/error.c
#include <stdio.h>
#include <stdlib.h>
#include "error.h"

void handle_error(const char* message) {
    perror(message);
    exit(EXIT_FAILURE);
}
