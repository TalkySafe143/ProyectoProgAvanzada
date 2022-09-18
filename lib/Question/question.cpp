#include "question.h"
#include <fstream>

using namespace std;

Question getQuestion(PublicUser admin, int ID){
    Question question;
    Question errorQuestion;

    char filename[150];

    prepareAdminFileName(admin, filename);

    checkIfFileExists(filename);

    ifstream arch(filename, ios::binary);

    if (!arch) {
        strcpy(errorQuestion.statement, "fileError");
        return errorQuestion;
    }

    while (!arch.eof()) {
        if(arch.read((char*)&question, sizeof(question))) {
            if (question.ID == ID) {
                arch.close();
                return question;
            }
        }
    }

    strcpy(errorQuestion.statement, "\0");

    arch.close();

    return errorQuestion;
}


int createQuestion(PublicUser admin, Question newQuestion){
    Question question = getQuestion(admin, newQuestion.ID);

    if (strcmp(question.statement, "\0") != 0) { // Ya existe
        return 2;
    }

    char filename[150];

    prepareAdminFileName(admin, filename);

    ofstream arch(filename, ios::binary|ios::app);

    if (!arch) {
        return 1;
    }

    arch.write((char*)&newQuestion, sizeof(newQuestion));

    arch.close();

    return 0;
}


int updateQuestion(PublicUser admin, Question updatedQuestion){

    char filename[150];

    prepareAdminFileName(admin, filename);

    checkIfFileExists(filename);

    fstream arch(filename, ios::binary|ios::in|ios::out);
    bool found = false;

    if (!arch)
        return 1;

    while (!arch.eof() && !found) {
        Question readQuestion;
        if (arch.read((char*)&readQuestion, sizeof(readQuestion))) {
            if (readQuestion.ID == updatedQuestion.ID) {
                found = true;
                arch.seekg((int)(-1)*(sizeof(readQuestion)), ios::cur);
                arch.write((char*)&updatedQuestion, sizeof(updatedQuestion));
            }
        }
    }

    arch.close();

    if (!found)
        return 2;

    return 0;
}

int deleteQuestion(PublicUser admin, int ID){

    Question question = getQuestion(admin, ID);

    if (strcmp(question.statement, "\0") == 0) { // No existe
        return 2;
    }

    char filename[150];
    char tempFilename[150];

    PublicUser temp;

    strcpy(temp.username, "temp");

    prepareAdminFileName(temp, tempFilename);
    prepareAdminFileName(admin, filename);

    checkIfFileExists(filename);

    ifstream arch(filename, ios::binary);
    ofstream archTemp(tempFilename, ios::binary);
    bool found = false;

    if(!arch || !archTemp)
        return 1;
    
    while(!arch.eof())
    {
        if(arch.read((char *)&question, sizeof(question)))
        {
            if(ID != question.ID)
            {
                archTemp.write((char *)&question, sizeof(question));
            }
            else
            {
                found = true;
            }
        }
    }
    arch.close();
    archTemp.close();
    remove(filename);
    rename(tempFilename, filename);
    if(!found)
        return 2;

    return 0;
}