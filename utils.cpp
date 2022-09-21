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

    // La direccion del archivo quedaria lib\\files\\<NombreUsuario>Bench.dat
}

void generateUniqueID(char* ID) {
    const int ch_MAX = 35;

    char keys[ch_MAX] = {'a', 'b', 'c', 'd', 'e', 'f', 'g',
                         'h', 'i', 'j', 'k', 'l', 'm', 'n',
                         'o', 'p', 'q', 'r', 's', 't', 'u',
                         'v', 'w', 'x', 'y', 'z', '1', '2',
                         '3', '4', '5', '6', '7', '8', '9'};

    for (int i = 0; i < 3; i++) {
        ID[i] = keys[rand() % ch_MAX];
    }
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