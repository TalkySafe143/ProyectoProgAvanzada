#ifndef AUTH_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define AUTH_H

#include <iostream>
#include <string.h>
#include "..\\lib\\User\\user.h"

struct PublicUser {
    char username[40];
    bool isAdmin;
};

int createUser();

PublicUser loginUser();

#endif
