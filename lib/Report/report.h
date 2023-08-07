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

/*
 * Nombre: getReport
 * Objetivo: Obtener los reportes de un examen
 * Entradas: El ID del examen a obtener los reportes
 * Salidas: Ninguna
*/
void getReport(char IdExam[4]);

/*
 * Nombre: createReport
 * Objetivo: Escribir el reporte entrante a ExamenesPresentados.dat
 * Entradas: El reporte que se va a escribir
 * Salidas: Ninguna
*/
void createReport(infoReport report);

#endif