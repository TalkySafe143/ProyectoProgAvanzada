#ifndef QUESTION_H
#define QUESTION_H

#include <iostream>
#include "..\\..\\auth\\auth.h"
#include "..\\..\\utils.h"
#include <string.h>
#include <fstream>

struct Question {
    int ID;
    char statement[500];
    char OptionA[50];
    char OptionB[50];
    char OptionC[50];
    char OptionD[50];
    char correctOption;
};

/*
   Nombre: getQuestion
   Objetivo: Consultar preguntas al archivo ........
   Entradas: El administrador que esta realizando la accion
   Salidas: La pregunta encontrada con el ID, si no se encuentra, en el "statement" va a ser '\0', si es 'fileError'
   significa que hay un error en los archivos
*/   
Question getQuestion(struct PublicUser admin, int ID);


/*
   Nombre: createQuestion
   Objetivo: Insertar preguntas al archivo ........
   Entradas: El administrador que esta realizando la accion
 * Salidas: Un entero que representa el codigo de la transaccion
 *          1 -> Fallo en los archivos, 2 -> Fallo en el proceso (Logica) y 0 -> Transaccion exitosa
*/   
int createQuestion(struct PublicUser admin, Question newQuestion);

/*
   Nombre: updateQuestion
   Objetivo: Editar preguntas del archivo ........
   Entradas: El administrador que esta realizando la accion
 * Salidas: Un entero que representa el codigo de la transaccion
 *          1 -> Fallo en los archivos, 2 -> Fallo en el proceso (Logica) y 0 -> Transaccion exitosa
*/ 
int updateQuestion(struct PublicUser admin, Question updatedQuestion);

/*
   Nombre: deleteQuestion
   Objetivo: Eliminar preguntas del archivo ........
   Entradas: El administrador que esta realizando la accion
 * Salidas: Un entero que representa el codigo de la transaccion
 *          1 -> Fallo en los archivos, 2 -> Fallo en el proceso (Logica) y 0 -> Transaccion exitosa
*/ 
int deleteQuestion(struct PublicUser admin, int ID);

#endif
