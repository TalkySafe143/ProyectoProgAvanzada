#ifndef BENCHLIB_H
#define BENCHLIB_H

/*
 * Andres
 * */

#include "..\\Question\\question.h"
#include "..\\..\\auth\\auth.cpp"

// Question getQuestion(int ID);
// Agregar una pregunta al banco de preguntas que esta en el archivo <admin>Bench.dat
void writeBenchQuestion(Question newQuestion, PublicUser admin);

// Actualizar una pregunta del banco de preguntas que esta en el archivo <admin>Bench.dat
void updateBenchQuestion(Question update, PublicUser admin);

// Eliminar una pregunta al banco de preguntas que esta en el archivo <admin>Bench.dat
void deleteBenchQuestion(Question deleted, PublicUser admin);

#endif //BENCHLIB_H
