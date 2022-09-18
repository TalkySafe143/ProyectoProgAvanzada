#ifndef ADMIN_H
#define ADMIN_H

#include "..\\lib\\User\\user.h"
#include "..\\auth\\auth.h"
#include <iostream>

void createExam(PublicUser actualUser);

void updateExam(PublicUser actualUser);

void deleteExam(PublicUser actualUser);

#endif
