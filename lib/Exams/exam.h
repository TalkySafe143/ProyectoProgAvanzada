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
 * Nombre: getRegExam
 * Objetivo: Obtener el registro de un examen en especifico
 * Entradas: El ID del examen que se va a obtener
 * Salidas: La estructura del registro del examen, en RegExam.name se guardará:
 *          "errorFile" -> Fallo en los archivos, "\0" -> Fallo en el proceso (Logica) y si la transaccion es exitosa
 *          contiene la informacion del registro del examen
 * */
RegExam getRegExam(char* id);

/*
 * Nombre: getQuestionsIDsFromExam
 * Objetivo: Llenar el arreglo de enteros que representan los IDs de las preguntas de un examen
 * Entradas: Recibe el array de enteros donde se guardarán los IDs y el ID del examen a consultar sus preguntas
 * Salidas: Ninguna, sin embargo, en el arreglo de enteros que contiene los IDs puede estar en la primera posicion:
	-1 -> Hay un fallo en el archivo , -2 -> Fallo en el Proceso, si la transaccion salió exitosa va a contener los IDs
    De las preguntas del examen.
 *
*/
void getQuestionsIDsFromExam(int* IDs, char* ExamId);

#endif //EXAM_H
