#ifndef QUESTION_H
#define QUESTION_H

#include <iostream>

struct Option {
    char letter;
    char sentence[50];
};

struct Question {
    int ID;
    char statement[500];
    Option options[4]; // Convertirlo en dinamico
    Option correctOption;
};

Question getQuestion(int id);

void createQuestion(Question newQuestion);

void updateQuestion(int id);

void deleteQuestion(int id);

#endif
