#ifndef STUDENT_H
#define STUDENT_H

#include "..\\lib\\Exams\\exam.h"
#include "..\\lib\\Question\\question.h"
#include "..\\lib\\Report\\report.h"
#include "..\\utils.h"

void showStudentMenu(PublicUser actualUser, bool &isLogged);

void listExam(PublicUser actualUser);

#endif