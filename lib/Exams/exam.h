#ifndef EXAM_H
#define EXAM_H

/*
 * Galindo
 * */

#include <iostream>
#include <chrono>
#include <ctime>
#include <fstream>
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
    int numberQuestions;
};

struct RegExam {
    char ID[3];
    char name[20];
    time_t date;
    listStudent Student;
    char owner[40];
    int numberQuestions;
};

/*
 * Nombre: createExam
 * Objetivo: Crear un examen
 * Entradas: El objeto del examen que se va a crear
 * Salidas: Un entero que representa el codigo de la transaccion
 *          1 -> Fallo en los archivos, 2 -> Fallo en el proceso (Logica) y 0 -> Transaccion exitosa
 * */
int createExam(Exam newExam);

/*
 * Nombre: updateExam
 * Objetivo: Actualizar un examen
 * Entradas: El ID del examen que se va a actualizar y el objeto del examen que se va a actualizar
 * Salidas: Un entero que representa el codigo de la transaccion
 *          1 -> Fallo en los archivos, 2 -> Fallo en el proceso (Logica) y 0 -> Transaccion exitosa
 * */
int updateExam(char* id, Exam updateExam);

/*
 * Nombre: deleteExam
 * Objetivo: Eliminar un examen
 * Entradas: El ID del examen que se va a eliminar
 * Salidas: Un entero que representa el codigo de la transaccion
 *          1 -> Fallo en los archivos, 2 -> Fallo en el proceso (Logica) y 0 -> Transaccion exitosa
 * */
int deleteExam(char* id);

#endif //EXAM_H
