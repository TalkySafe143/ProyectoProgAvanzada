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

int resizeOptionArray(Option *arr, int length){
    Option *temp = new Option[length + 1];

    for (int i = 0; i < length; i++) {
        *(temp + i) = *(arr + i);
    }

    delete [] arr;

    arr = temp;

    return length + 1;
}

int resizeQuestionArray(Question *arr, int length){
    Question *temp = new Question[length + 1];

    for (int i = 0; i < length; i++) {
        *(temp + i) = *(arr + i);
    }

    delete [] arr;

    arr = temp;

    return length + 1;

}

int resizeExamArray(Exam *arr, int length){
    Exam *temp = new Exam[length + 1];

    for (int i = 0; i < length; i++) {
        *(temp + i) = *(arr + i);
    }

    delete [] arr;

    arr = temp;

    return length + 1;

}

void resizeCharArray(char *arr){

    int length = strlen(arr) + 1;

    char *temp = new char[length];

    for (int i = 0; i < length; i++) {
        *(temp + i) = *(arr + i);
    }

    delete [] arr;

    arr = temp;
}

User getUserMembers(char *line, User read) {

    char *p = strtok(line, ";");

    for (int i = 1; i <= 3; i++) {
        switch (i) {
            case 1:
                strcpy(read.username, p);
                break;
            case 2:
                strcpy(read.password, p);
                break;
            case 3:
                if (*(p + 0) == '0') {
                    read.isAdmin = false;
                } else {
                    read.isAdmin = true;
                }
                break;
        }
    }
}
