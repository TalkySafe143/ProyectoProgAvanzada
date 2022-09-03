#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <fstream>
#include ".\\lib\\User\\user.h"
#include ".\\lib\\Exams\\exam.h"

void checkIfFileExists(char *name);

int resizeOptionArray(Option *&arr, int length);

int resizeQuestionArray(Question *&arr, int length);

int resizeExamArray(Exam *&arr, int length);

#endif
