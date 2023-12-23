// auth.h
#ifndef AUTH_H
#define AUTH_H

#include <stdbool.h>

void register_user(const char* username, const char* password);
bool login_user(const char* username, const char* password);
bool authenticate_user(); // Declare authenticate_user function

#endif  // AUTH_H
