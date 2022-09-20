#include "utils.h"

using namespace std;

void checkIfFileExists(char *name) {
    ifstream alreadyCreated(name, ios::binary);

    if (!alreadyCreated) {
        ofstream createFile(name, ios::binary);
        createFile.close();
    }

    alreadyCreated.close();
}

int resizeQuestionArray(Question *&arr, int length){
    Question *temp = new Question[length + 1];

    for (int i = 0; i < length; i++) {
        *(temp + i) = *(arr + i);
    }

    delete [] arr;

    arr = temp;

    return length + 1;

}

int resizeExamArray(Exam *&arr, int length){
    Exam *temp = new Exam[length + 1];

    for (int i = 0; i < length; i++) {
        *(temp + i) = *(arr + i);
    }

    delete [] arr;

    arr = temp;

    return length + 1;

}

void prepareAdminFileName(PublicUser admin, char* fileName) {
    strcpy(fileName, "lib\\files\\");
    strcat(fileName, admin.username);
    strcat(fileName, "Bench.dat");
}

int resizeIdArray(char *&Id, int lenght)
{
    char *temp = new char[lenght + 4];

    for (int i = 0; i < lenght; i++){
        *(temp + i) = *(Id + i);
    }

    delete [] Id;

    Id = temp;

    return lenght + 4;
}