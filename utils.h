#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <fstream>
#include <string.h>
#include ".\\lib\\User\\user.h"
#include ".\\lib\\Question\\question.h"
#include ".\\lib\\Exams\\exam.h"

void checkIfFileExists(char *name);

int resizeOptionArray(Option *arr, int length);

int resizeQuestionArray(Question *arr, int length);

int resizeExamArray(Exam *arr, int length);

void resizeCharArray(char *arr, int length);

#endif
