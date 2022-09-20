#ifndef REPORT_H
#define REPORT_H

#include <iostream>

struct infoReport {
    char Admin[50];
    char Exam[50];
    char idExam[3];
    char studentName[50];
    float grade;
};

void getReport(char IdExam[3]);

void createReport(infoReport report);

#endif