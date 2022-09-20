#ifndef ADMIN_H
#define ADMIN_H

#include "..\\lib\\User\\user.h"
#include "..\\auth\\auth.h"
#include "..\\lib\\Exams\\exam.h"
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
 * Nombre: createExam
 * Objetivo: Preparar el examen a crear
 * Entradas: El usuario que esta realizando la accion
 * Salidas: Ninguna
 * */
void createExam(PublicUser actualUser);

/*
 * Nombre: updateExam
 * Objetivo: Pedir los datos a actualizar del examen
 * Entradas: El usuario que esta realizando la accion
 * Salidas: Ninguna
 * */
void updateExam(PublicUser actualUser);

/*
 * Nombre: deleteExam
 * Objetivo: Pedir el ID para eliminar el examen
 * Entradas: El usuario que esta realizando la accion
 * Salidas: Ninguna
 * */
void deleteExam(PublicUser actualUser);

#endif
