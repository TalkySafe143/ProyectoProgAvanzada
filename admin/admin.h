#ifndef ADMIN_H
#define ADMIN_H

#include "..\\lib\\User\\user.h"
#include "..\\auth\\auth.h"
#include "..\\lib\\Exams\\exam.h"
#include "..\\admin\\questions\\bench.h"
#include "..\\lib\\Report\\report.h"
#include <iostream>
#include <fstream>

/*
 * Nombre: showExams
 * Objetivo: Mostrar los examenes existentes del administrador (Llamando a exam.cpp)
 * Entradas: El usuario que esta realizando la accion
 * Salidas: Ninguna
 * */
void showExams(PublicUser actualUser);


void showAdminMenu(PublicUser actualUser, bool &isLogged);

/*
 * Nombre: createExam
 * Objetivo: Preparar el examen a crear
 * Entradas: El usuario que esta realizando la accion
 * Salidas: Ninguna
 * */
void createExam(PublicUser actualUser);

void listExamAdmin(PublicUser actualUser);

void getReports(PublicUser actualUser);


#endif
