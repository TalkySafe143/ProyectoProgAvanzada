#include "exam.h"

int createExam(Exam newExam){
    ifstream file("..\\files\\exams.dat", ios::binary);

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

    ofstream examFile("..\\files\\exams.dat", ios::binary | ios::app);

    if (!examFile)
        return 1;

    RegExam writeExam;

    strcpy(writeExam.ID, newExam.ID);
    strcpy(writeExam.name, newExam.name);
    writeExam.date = newExam.date;
    strcpy(writeExam.owner, newExam.owner);
    writeExam.numberQuestions = newExam.numberQuestions;
    RegExam.Student = newExam.Student;

    examFile.write((char*)&writeExam, sizeof(writeExam));

    for (int i = 0; i < newExam.numberQuestions; i++) {
        examFile.write((char*)(newExam.questions + i), sizeof(*(newExam.questions + i)));
    }

    examFile.close();

    return 0;
}

int updateExam(char* id, Exam updateExam){
    fstream file("..\\files\\exams.dat", ios::binary | ios::in | ios::out);

    if (!file)
        return 1;

    bool found = false;

    while (!file.eof() && !found) {
        RegExam readExam;
        if (file.read((char*)&readExam, sizeof(readExam))) {
            if (strcmp(readExam.ID, id) == 0) {
                found = true;
                file.seekg((int) (-1) * sizeof(readExam), ios::cur);
                RegExam writeExam;

                strcpy(writeExam.ID, updateExam.ID);
                strcpy(writeExam.name, updateExam.name);
                writeExam.date = updateExam.date;
                strcpy(writeExam.owner, updateExam.owner);
                writeExam.numberQuestions = updateExam.numberQuestions;
                RegExam.Student = updateExam.Student;

                file.write((char *) &writeExam, sizeof(writeExam));

                for (int i = 0; i < readExam.numberQuestions; i++) {
                    file.write((char *) (updateExam.questions + i), sizeof(*(updateExam.questions + i)));
                }

            } else {
                for (int i = 0; i < readExam.numberQuestions; i++) {
                    Question readQuestion;
                    file.read((char*)&readQuestion, sizeof(readQuestion));
                }
            }
        }
    }

    if (!found)
        return 2;

    file.close();

    return 0;
}

int deleteExam(char* id){
    ifstream readFile("..\\files\\exams.dat", ios::binary);
    ofstream writeFile("..\\files\\temp.dat", ios::binary);

    if(!readFile || !writeFile)
        return 1;

    bool found = false;

    while (!readFile.eof()) {
        RegExam readExam;
        if (readFile.read((char*)&readExam, sizeof(readExam))) {
            if (strcmp(readExam.ID, id) == 0) {
                found = true;
                for (int i = 0; i < readExam.numberQuestions; i++) {
                    Question readQuestion;
                    readFile.read((char*)&readQuestion, sizeof(readQuestion));
                }
            } else {
                writeFile.write((char*)&readExam, sizeof(readExam));
                for (int i = 0; i < readExam.numberQuestions; i++) {
                    Question readQuestion;
                    readFile.read((char*)&readQuestion, sizeof(readQuestion));
                    writeFile.write((char*)&readQuestion, sizeof(readQuestion));
                }
            }
        }
    }

    readFile.close();
    writeFile.close();

    remove("..\\files\\exams.dat");
    rename("..\\files\\temp.dat", "..\\files\\exams.dat");

    if (!found) {
        return 2;
    } else {
        return 0;
    }
}