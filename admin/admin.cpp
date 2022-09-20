#include "admin.h"

using namespace std;

void showExams(PublicUser actualUser){
    ifstream file("\\lib\\files\\exams.dat", ios::binary);

    if (!file) {
        cout << "Existe un error en los archivos\n";
    } else {
        while (!file.eof()) {
            RegExam readExam;
            Question readQuestion;
            if (file.read((char*)&readExam, sizeof(readExam))) {
                if (strcmp(readExam.owner, actualUser.username) == 0) {
                    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<< " << readExam.name << " >>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
                    cout << "ID: " << readExam.ID << endl;
                    cout << "Fecha de creacion del examen: " << ctime(&readExam.date) << endl;
                    cout << "Preguntas: <<<<<<<<<<<<<<<<<" << endl;
                    for (int i = 0; i < readExam.numberQuestions; i++) {
                        file.read((char*)&readQuestion, sizeof(readQuestion));
                        cout << readQuestion.statement << endl;
                        cout << "A. " << readQuestion.OptionA << endl;
                        cout << "B. " << readQuestion.OptionB << endl;
                        cout << "C. " << readQuestion.OptionC << endl;
                        cout << "D. " << readQuestion.OptionD << endl;
                        cout << "ID de la pregunta: " << readQuestion.ID << endl;
                        cout << "Respuesta correcta: " << readQuestion.correctOption << endl;
                        cout << "------------------------------------------------------------\n";
                    }

                    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<< Fin del examen >>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
                } else {
                    for (int i = 0; i < readExam.numberQuestions; i++) {
                        file.read((char*)&readQuestion, sizeof(readQuestion));
                    }
                }
            }
        }
    }

    file.close();
};

void createExam(PublicUser actualUser) {
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<< CREAR EXAMEN >>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n";

    Exam newExam;

    generateUniqueID(newExam.ID);

    cout << "Ingrese el nombre del examen: ";
    cin.ignore();
    cin.getline(newExam.name, sizeof(newExam.name));

    auto now = chrono::system_clock::now();

    newExam.date = chrono::system_clock::to_time_t(now);

    strcpy(newExam.owner, actualUser.username);

    int limit;

    cout << "¿Cuantas preguntas desea generar?: ";

    cin >> limit;

    newExam.numberQuestions = 0;

    newExam.questions = new Question[numberQuestions];

    char filename[150];

    prepareAdminFileName(actualUser, filename);

    ifstream file(filename, ios::binary);

    int totalQuestions = 0;

    int alreadyAdded[limit] = {};

    Question readQuestion;

    if (!file) {
        cout << "Existio un problema con los archivos, se creo el examen sin preguntas.\n";
    } else {
        while (!file.eof()) {
            if (file.read((char*)&readQuestion, sizeof(readQuestion))) {
                totalQuestions++;
            }
        }
        file.close();

        for (int i = 0; i < limit; i++) {

            int random = rand() % totalQuestions;

            ifstream file(filename, ios::binary);

            if (!file) {
                cout << "Ups, algo paso con los archivos de bench\n";
            } else {
                int whileCount = 0;
                bool exist;
                while (!file.eof()) {
                    if(file.read((char*)&readQuestion, sizeof(readQuestion))) {
                        if (whileCount == random) {
                            do {
                                exist = false;
                                for (int j = 0; j < limit; j++) {
                                    if (alreadyAdded[j] == random) {
                                        exist = true;
                                        break;
                                    }
                                }

                                if (!exist) {
                                    newExam.numberQuestions = resizeQuestionArray(newExam.questions, newExam.numberQuestions);
                                    *(newExam.questions + (newExam.numberQuestions - 1)) = readQuestion;
                                    alreadyAdded[i] = random;
                                }
                            } while (exist);
                            break;
                        }
                        whileCount++;
                    }
                }
            }

            file.close();
        }   
    }

    int confirm = createExam(newExam);

    switch (confirm) {
        case 1:
            cout << "Algo sucedio en los archivos al momento de crear!\n";
            system("pause");
            system("cls");
            break;
        case 2:
            cout << "Algo sucedio en la logica, revisa bien!\n";
            system("pause");
            system("cls");
            break;
        case 0:
            cout << "Examen creado correctamente\n";
            system("pause");
            system("cls");
            break;
    }

    delete [] newExam.questions;

};

void updateExam(PublicUser actualUser){};

void deleteExam(PublicUser actualUser){};