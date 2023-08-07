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

/*
 * Nombre: showAdminMenu
 * Objetivo: Mostrar el menu de las acciones de administrador
 * Entradas: El usuario que esta realizando la accion, Verifica que este loggeado correctamente
 * Salidas: Ninguna
*/
void showAdminMenu(PublicUser actualUser, bool &isLogged);

/*
 * Nombre: createExam
 * Objetivo: Preparar el examen a crear
 * Entradas: El usuario que esta realizando la accion
 * Salidas: Ninguna
 * */
void createExam(PublicUser actualUser);

/*
 * Nombre: listExamAdmin
 * Objetivo: Muestra la lista de los examenes de un administrador
 * Entradas: El usuario que esta realizando la accion
 * Salidas: Ninguna
*/
void listExamAdmin(PublicUser actualUser);

/*
 * Nombre: getReports
 * Objetivo: Muestra la interfaz para verificar los reportes de un examen
 * Entradas: El usuario que esta realizando la accion
 * Salidas: Ninguna
*/
void getReports(PublicUser actualUser);


#endif
