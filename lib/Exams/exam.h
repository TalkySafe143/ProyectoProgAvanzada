#ifndef EXAM_H
#define EXAM_H

#include <iostream>
#include <chrono>
#include <ctime>
#include "..\\Question\\question.h"

struct listStudents {
    char userName[40];
    float grade;
};

struct Exam {
    char ID[3];
    char name[20];
    time_t date; // https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
    Question questions[3]; //  Convertirlo en dinamico
    listStudents Student;
    char owner[40]; // admin username
};
#endif //EXAM_H
