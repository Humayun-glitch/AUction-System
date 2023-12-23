// auth.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "auth.h"

#define DATABASE_FILE "database.txt"
#define MAX_USERNAME_LEN 50
#define MAX_PASSWORD_LEN 50


void register_user(const char* username, const char* password) {
    FILE* file = fopen(DATABASE_FILE, "a+"); // Open for reading and appending

    if (file == NULL) {
        perror("Error opening database file");
        exit(EXIT_FAILURE);
    }

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        char db_username[50];
        // char db_password[50]; // Not needed for registration

        sscanf(line, "%s", db_username);

        if (strcmp(username, db_username) == 0) {
            fclose(file);
            fprintf(stderr, "Username already exists. Choose a different username.\n");
            exit(EXIT_FAILURE);
        }
    }

    fprintf(file, "%s %s\n", username, password);
    fclose(file);
}


bool login_user(const char* username, const char* password) {
    FILE* file = fopen(DATABASE_FILE, "a+"); // Open for reading and appending

    if (file == NULL) {
        perror("Error opening database file");
        exit(EXIT_FAILURE);
    }

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        char db_username[50];
        char db_password[50];

        sscanf(line, "%s %s", db_username, db_password);

        if (strcmp(username, db_username) == 0 && strcmp(password, db_password) == 0) {
            fclose(file);
            return true;
        }
    }

    fclose(file);
    return false;
}

bool authenticate_user() {
  char username[MAX_USERNAME_LEN];
  char password[MAX_PASSWORD_LEN];

  // Prompt the user for username
  printf("Enter your username: ");
  scanf("%s", username);

  // Prompt the user for password (Note: In a real application, use secure   methods for password input)
  printf("Enter your password: ");
  scanf("%s", password);

  // Check if the provided credentials are valid by using login_user
  if (login_user(username, password)) {
    printf("Authentication successful. Welcome, %s!\n", username);
    return true;
  } else {
    printf("Authentication failed. Invalid username or password.\n");
    return false;
  }
}
