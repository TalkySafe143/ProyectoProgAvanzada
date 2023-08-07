#include "exam.h"

using namespace std;

int createExam(Exam newExam){

    char filename[150];

    strcpy(filename, "lib\\files\\exams.dat");

    checkIfFileExists(filename);

    ifstream file(filename, ios::binary);

    /*
     * exams.dat
     *
     * RegExam ----------------
     * Questions --------------
     *
     * RegExam ---------------
     * Questions -------------
     *
     * */

    if (!file)
        return 1;

    while (!file.eof()) {
        RegExam readExam;
        if (file.read((char*)&readExam, sizeof(readExam))) {
            if (strcmp(readExam.ID, newExam.ID) == 0) {
                file.close();
                return 2;
            }
            for (int i = 0; i < readExam.numberQuestions; i++) {
                Question readQuestion;
                file.read((char*)&readQuestion, sizeof(readQuestion));
            }
        }
    }

    file.close();

    ofstream examFile("lib\\files\\exams.dat", ios::binary | ios::app);

    if (!examFile)
        return 1;

    RegExam writeExam;

    strcpy(writeExam.ID, newExam.ID);
    strcpy(writeExam.name, newExam.name);
    writeExam.date = newExam.date;
    strcpy(writeExam.owner, newExam.owner);
    writeExam.numberQuestions = newExam.numberQuestions;

    examFile.write((char*)&writeExam, sizeof(writeExam));

    for (int i = 0; i < newExam.numberQuestions; i++) {
        examFile.write((char*)(newExam.questions + i), sizeof(*(newExam.questions + i)));
    }

    examFile.close();

    return 0;
};

RegExam getRegExam(char* id) {

    RegExam readExam;
    RegExam errorExam;

    char filename[150];

    strcpy(filename, "lib\\files\\exams.dat");

    checkIfFileExists(filename);

    ifstream file(filename, ios::binary);

    if (!file) {
        file.close();
        strcpy(errorExam.name, "errorFile");
        return errorExam;
    }

    while (!file.eof()) {
        if (file.read((char*)&readExam, sizeof(readExam))) {
            if (strcmp(readExam.ID, id) == 0) {
                file.close();
                return readExam;
            } else {
                Question readQuestion;
                for (int i = 0; i < readExam.numberQuestions; i++) {
                    file.read((char*)&readQuestion, sizeof(readQuestion));
                }
            }
        }
    }

    file.close();

    strcpy(errorExam.name, "\0");
    return errorExam;
};

void getQuestionsIDsFromExam(int* IDs, char* ExamId) {

    RegExam readExam;
    char filename[150];

    strcpy(filename, "lib\\files\\exams.dat");

    checkIfFileExists(filename);

    ifstream file(filename, ios::binary);

    bool found = false;

    if (!file) {
        *(IDs + 0) = -1;
    } else {
        Question readQuestion;
        while (!file.eof()) {
            if (file.read((char*)&readExam, sizeof(readExam))) {
                if (strcmp(readExam.ID, ExamId) == 0) {
                    for (int i = 0; i < readExam.numberQuestions; i++) {
                        file.read((char*)&readQuestion, sizeof(readQuestion));
                        *(IDs + i) = readQuestion.ID;
                    }
                    found = true;
                    break;
                } else {
                    for (int i = 0; i < readExam.numberQuestions; i++) {
                        file.read((char*)&readQuestion, sizeof(readQuestion));
                    }
                }
            }
        }
    }

    if (!found)
        *(IDs + 0) = -2;


    file.close();
}