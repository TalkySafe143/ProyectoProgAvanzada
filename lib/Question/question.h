#ifndef QUESTION_H
#define QUESTION_H

#include <iostream>

/*
 * Adrian
 * */


struct Option {
    char letter;
    char sentence[50];
};

struct Question {
    int ID;
    char statement[500];
    Option options[4];
    Option correctOption;
};

Question getQuestion(int id);

void createQuestion(Question newQuestion, PublicUser admin);

void updateQuestion(int id, Question questionToUpdate);

void deleteQuestion(int id);

#endif
