#ifndef EXAM_H
#define EXAM_H

#include <iostream>
#include <chrono>
#include <ctime>
#include "..\\Question\\question.h"

struct Exam {
    char ID[3];
    char name[20];
    time_t date; // https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
    Question questions[3];
};
#endif //EXAM_H
