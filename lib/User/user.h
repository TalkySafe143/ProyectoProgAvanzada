#ifndef USER_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define USER_H

#include <iostream>
#include <fstream>
#include <string.h>
#include "..\\..\\utils.h"

struct User {
    char *username;
    char *password;
    bool isAdmin;
};

int registerUser(User user);

int checkUser(User user);

void getActualUser();

#endif
