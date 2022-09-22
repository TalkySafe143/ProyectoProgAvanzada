#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <fstream>
#include ".\\lib\\User\\user.h"
#include ".\\lib\\Exams\\exam.h"
#include ".\\auth\\auth.h"

void checkIfFileExists(char *name);

int resizeQuestionArray(struct Question *&arr, int length);

int resizeExamArray(struct Exam *&arr, int length);

void prepareAdminFileName(struct PublicUser admin, char* fileName);

void generateUniqueID(char* ID);

int resizeIdArray(char *&Id, int lenght);

void Mayuscula(char &letra);

#endif
