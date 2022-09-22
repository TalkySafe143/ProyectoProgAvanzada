#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <fstream>
#include ".\\lib\\User\\user.h"
#include ".\\lib\\Exams\\exam.h"
#include ".\\auth\\auth.h"
#include "lib\\Report\\report.h"

/*
 * Nombre: checkIfFileExists
 * Objetivo: Revisar si el archivo ya fue creado previamente, de lo contrario crearlo
 * Entradas: Recibe el nombre del archivo
 * Salidas: Ninguna
*/
void checkIfFileExists(char *name);

/*
 * Nombre: resizeQuestionArray
 * Objetivo: Redimensionar el tamaño del array de questions
 * Entradas: EL array de Questions y su tamaño correspondiente
 * Salidas: El nuevo tamaño del arreglo
*/
int resizeQuestionArray(struct Question *&arr, int length);

/*
 * Nombre: resizeReportArray
 * Objetivo: Redimensionar el tamaño del array de infoReport
 * Entradas: EL array de reportes y su tamaño correspondiente
 * Salidas: El nuevo tamaño del arreglo
*/
int resizeReportArray(struct infoReport *&arr, int length);

/*
 * Nombre: resizeExamArray
 * Objetivo: Redimensionar el tamaño del array de los examenes
 * Entradas: El array de los examenes y el tamaño correspondiente
 * Salidas: El nuevo tamaño del arreglo
*/
int resizeExamArray(struct Exam *&arr, int length);

/*
 * Nombre: prepareAdminFileName
 * Objetivo: Agrega el nombre del administrador al nombre del archivo del banco de preguntas correspondiente
 * Entradas: El administrador y el nombre del archivo
 * Salidas: Ninguna
*/
void prepareAdminFileName(struct PublicUser admin, char* fileName);

/*
 * Nombre: generateUniqueID
 * Objetivo: generar un ID con el abecedario y numeros del 1/9
 * Entradas: recibe ID el cual se va a llenar
 * Salidas: Ninguna
*/
void generateUniqueID(char* ID);

/*
 * Nombre: Mayuscula
 * Objetivo: Convertir la letra de las respuestas en mayuscula si no lo esta.
 * Entradas: La letra a convertir
 * Salidas: Ninguna
*/
void Mayuscula(char &letra);

#endif
