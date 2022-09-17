#ifndef QUESTION_H
#define QUESTION_H

#include <iostream>

/*
 * Adrian
 * */

struct Question {
    int ID;
    char statement[500];
    char OptionA[50];
    char OptionB[50];
    char OptionC[50];
    char OptionD[50];
    char correctOption[50];
};

/*
   Nombre: getQuestion
   Objetivo: Consultar preguntas al archivo ........
   Entradas: Ninguna
   Salidas: Ninguna
*/   
void getQuestion();

/*
   Nombre: createQuestion
   Objetivo: Insertar preguntas al archivo ........
   Entradas: Ninguna
   Salidas: Ninguna
*/   
void createQuestion();

/*
   Nombre: updateQuestion
   Objetivo: Editar preguntas del archivo ........
   Entradas: Ninguna
   Salidas: Ninguna
*/ 
void updateQuestion();

/*
   Nombre: deleteQuestion
   Objetivo: Eliminar preguntas del archivo ........
   Entradas: Ninguna
   Salidas: Ninguna
*/ 
void deleteQuestion();

#endif
