#ifndef BENCH_H
#define BENCH_H

#include "..\\..\\lib\\Question\\question.h"
#include "..\\..\\auth\\auth.h"

void createBenchQuestion(PublicUser admin); // admin.username << Bench.dat

void updateBenchQuestion(PublicUser admin);

void deleteBenchQuestion(PublicUser admin);

#endif
