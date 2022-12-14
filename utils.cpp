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
        ID[i] = keys[rand() % ch_MAX]; // 0 - 34
    }

    ID[3] = '\0';
}

void Mayuscula(char &letra)
{
	char letraMin, letramayus;
	
	for(int j=0; j<26;j++)
	{
	    letraMin='a'+j;
	    letramayus='A'+j;
	    if(letra == letraMin)
	    {
	        letra = letramayus;
			break;	
		}
	}
}

int resizeReportArray(struct infoReport *&arr, int length) {
    infoReport *temp = new infoReport[length + 1];

    for (int i = 0; i < length; i++) {
        *(temp + i) = *(arr + i);
    }

    delete [] arr;

    arr = temp;

    return length + 1;
}