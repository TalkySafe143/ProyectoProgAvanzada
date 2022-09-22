#ifndef BENCH_H
#define BENCH_H

#include "..\\..\\lib\\Question\\question.h"
#include "..\\..\\auth\\auth.h"
#include "..\\..\\utils.h"



/*
 * Nombre: showQuestionsMenu
 * Objetivo: Mostrar el menu de preguntas
 * Entradas: El usuario que esta realizando la accion
 * Salidas: Ninguna
 * */
void showQuestionsMenu(PublicUser actualUser);

/*
 * Nombre: getBenchQuestion
 * Objetivo: Mostrar una sola pregunta de la banca de preguntas (Llamando a question.h)
 * Entradas: El administrador que esta realizando la accion
 * Salidas: Ninguna
 * */
void getBenchQuestion(PublicUser admin);

/*
 * Nombre: createBenchQuestion
 * Objetivo: Pedir los datos de la pregunta y crearla (Llamando a question.h)
 * Entradas: El administrador que esta realizando la accion
 * Salidas: Ninguna
 * */
void createBenchQuestion(PublicUser admin);

/*
 * Nombre: updateBenchQuestion
 * Objetivo: Pedir los datos de la pregunta y actualizarla (Llamando a question.h)
 * Entradas: El administrador que esta realizando la accion
 * Salidas: Ninguna
 * */
void updateBenchQuestion(PublicUser admin);

/*
 * Nombre: deleteBenchQuestion
 * Objetivo: Pedir el ID de la pregunta y eliminarla (Llamando a question.h)
 * Entradas: El administrador que esta realizando la accion
 * Salidas: Ninguna
 * */
void deleteBenchQuestion(PublicUser admin);

/*
 * Nombre: showBenchQuestions
 * Objetivo: Mostrar todas las preguntas del banco de preguntas
 * Entradas: El administrador que esta realizando la accion
 * Salidas: Ninguna
 * */
void showBenchQuestions(PublicUser admin);

#endif
