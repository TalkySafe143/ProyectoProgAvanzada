#ifndef ADMIN_H
#define ADMIN_H

#include "..\\lib\\User\\user.h"
#include "..\\auth\\auth.h"
#include "..\\admin\\questions\\bench.h"
#include <iostream>

void showAdminMenu(PublicUser actualUser, bool &isLogged);

void createExam(PublicUser actualUser);

void updateExam(PublicUser actualUser);

void deleteExam(PublicUser actualUser);

#endif
