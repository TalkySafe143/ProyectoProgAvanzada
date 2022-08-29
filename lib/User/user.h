#ifndef USER_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define USER_H

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "..\\..\\utils.h"
#define CHAR_ARRAY_LENGTH 30
/*
 * TXT FORMAT
 *
 * username;password;isAdmin
 *
 * isAdmin -> 0/false or 1/true
 * */
struct User {
    char *username;
    char *password;
    bool isAdmin;
};

int registerUser(User user);

int checkUser(User user);

User getActualUser();

#endif
