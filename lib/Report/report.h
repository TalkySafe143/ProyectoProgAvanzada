#ifndef REPORT_H
#define REPORT_H

#include <iostream>
#include "..\\..\\utils.h"
#include <fstream>
#include <string.h>
#include <algorithm>

struct infoReport {
    char Admin[50];
    char Exam[50];
    char idExam[4];
    char studentName[50];
    float grade;
};

void getReport(char IdExam[4]);

void createReport(infoReport report);

#endif