#ifndef STUDENT_H
#define STUDENT_H

#include "..\\lib\\Exams\\exam.h"
#include "..\\lib\\Question\\question.h"
#include "..\\lib\\Report\\report.h"
#include "..\\utils.h"
#include "..\\student\\Present\\present.h"

/*
 * Nombre: showStudentMenu
 * Objetivo: Mostrar el menu al que tiene acceso el estudiante
 * Entradas: El usuario que esta realizando la accion y si esta loggeado correctamente
 * Salidas: Ninguna
*/
void showStudentMenu(PublicUser actualUser, bool &isLogged);

/*
 * Nombre: listExam
 * Objetivo: Muestra los examenes disponibles para presentar
 * Entradas: El usuario que esta realizando la accion
 * Salidas: Ninguna
*/
void listExam(PublicUser actualUser);

#endif