#ifndef EXAM_H
#define EXAM_H

/*
 * Galindo
 * */

#include <iostream>
#include <chrono>
#include <ctime>
#include "..\\Question\\question.h"

struct listStudent {
    char userName[40];
    float grade;
};

struct Exam {
    char ID[3];
    char name[20];
    time_t date; // https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
    Question *questions; //  Convertirlo en dinamico [3] min
    listStudent Student;
    char owner[40]; // admin username
};

void createExam(Exam newExam);

void updateExam(char* id);

void deleteExam(char* id);

#endif //EXAM_H
