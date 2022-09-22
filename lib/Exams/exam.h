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


struct Exam {
    char ID[4];
    char name[50];
    time_t date; // https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
    struct Question *questions; //  Convertirlo en dinamico [3] min
    char owner[40]; // admin username
    int numberQuestions;
};

struct RegExam {
    char ID[4];
    char name[50];
    time_t date;
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

//Question *searchExamById(char ID[3], int &numberQuestions, char *owner, char *examName);

RegExam getRegExam(char* id);

void getQuestionsIDsFromExam(int* IDs, char* ExamId);

#endif //EXAM_H
