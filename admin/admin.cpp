#include "admin.h"

using namespace std;

void showAdminMenu(PublicUser actualUser, bool &isLogged)
{
    int optionMenu;

    do {
        system("cls");
        cout << "==================== Hola de nuevo, " << actualUser.username << " (Administrador) ====================\n";

        cout << "�Bienvenido administrador!\n";

        cout << "1. Crear examen.\n";
        cout << "2. Ver informes.\n";
        cout << "3. Mostrar examenes creados.\n";
        cout << "4. Entrar a banco de preguntas.\n\n";
        cout << "5. Salir.\n\n";
        cout << "Seleccione una opci�n: ";
        cin >> optionMenu;

        if (optionMenu > 5 || optionMenu < 1) { //Validacion
            cout << "Ingrese una opci�n valida.\n";
            system("pause");
            system("cls");
            continue;
        }

        if (optionMenu == 5) {
            isLogged = false;
        }

        switch (optionMenu)
        {
            case 1:
                createExam(actualUser);
                break;
            case 2:
                getReports(actualUser);
                break;
            case 3:
                showExams(actualUser);
                break;
            case 4:
                showQuestionsMenu(actualUser);
                break;
        }

    } while (optionMenu != 5);
}

void showExams(PublicUser actualUser){

    char filename[150];

    strcpy(filename, "lib\\files\\exams.dat");

    checkIfFileExists(filename);

    ifstream file(filename, ios::binary);

    if (!file) {
        cout << "Existe un error en los archivos\n";
    } else {
        while (!file.eof()) {
            RegExam readExam;
            Question readQuestion;
            if (file.read((char*)&readExam, sizeof(readExam))) {
                if (strcmp(readExam.owner, actualUser.username) == 0) {
                    system("cls");
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

                    system("pause");

                } else {
                    for (int i = 0; i < readExam.numberQuestions; i++) {
                        file.read((char*)&readQuestion, sizeof(readQuestion));
                    }
                }
            }
        }
    }

    file.close();
    system("pause");
};

void createExam(PublicUser actualUser) {

    system("cls");
    cout << "======================================== CREAR EXAMEN ========================================\n\n";

    Exam newExam;

    bool alreadyID;

    do {
        alreadyID = false;

        generateUniqueID(newExam.ID);

        ifstream readFile("lib\\files\\exams.dat", ios::binary);

        if (readFile) {
            RegExam checkID;
            Question checkQ;
            while (!readFile.eof()) {
                if (readFile.read((char*)&checkID, sizeof(checkID))) {
                    if (strcmp(newExam.ID, checkID.ID) == 0) {
                        alreadyID = true;
                        break;
                    }
                    for (int i = 0; i < checkID.numberQuestions; i++) {
                        readFile.read((char*)&checkQ, sizeof(checkQ));
                    }
                }
            }
        }

        readFile.close();
    } while (alreadyID);

    cout << "Ingrese el nombre del examen: ";
    cin.ignore();
    cin.getline(newExam.name, sizeof(newExam.name));

    auto now = chrono::system_clock::now(); // Obtiene la fecha y la informacion de ese instante

    newExam.date = chrono::system_clock::to_time_t(now); // Convierte esa fecha en time_t para poder guardarlo y mostrarlo

    strcpy(newExam.owner, actualUser.username);

    int limit;

    cout << "¿Cuantas preguntas desea generar?: ";

    cin >> limit;

    newExam.numberQuestions = 0;

    newExam.questions = new Question[newExam.numberQuestions];

    char filename[150];

    prepareAdminFileName(actualUser, filename);

    ifstream file(filename, ios::binary);

    int totalQuestions = 0;

    int alreadyAdded[limit] = {};

    Question readQuestion;

    if (!file) {
        cout << "Hay un problema con los archivos, se creo el examen sin preguntas.\n";
    } else {
        while (!file.eof()) {
            if (file.read((char*)&readQuestion, sizeof(readQuestion))) {
                totalQuestions++;
            }
        }
        file.close();

        if (limit > totalQuestions) {
            cout << "No existe ese numero de preguntas en el banco de preguntas\n";
            system("pause");
        } else {
            for (int i = 0; i < limit; i++) { // 3

                bool exist;
                int random;

                do {
                    exist = false;
                    random = 1 + (rand() % totalQuestions);

                    for (int j = 0; j < limit; j++) {
                        if (alreadyAdded[j] == random) {
                            exist = true;
                            break;
                        }
                    }
                } while (exist);


                ifstream file(filename, ios::binary);

                if (!file) {
                    cout << "Ups, algo paso con los archivos de bench\n";
                } else {
                    int whileCount = 1;
                    while (!file.eof()) {
                        if(file.read((char*)&readQuestion, sizeof(readQuestion))) {
                            if (whileCount == random) { // [1]
                                newExam.numberQuestions = resizeQuestionArray(newExam.questions, newExam.numberQuestions);
                                *(newExam.questions + (newExam.numberQuestions - 1)) = readQuestion;
                                alreadyAdded[i] = random;
                                break;
                            }
                            whileCount++;
                        }
                    }
                }

                file.close();
            }
        }
    }

    if (limit <= totalQuestions) {
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
    }
};

void listExamAdmin(PublicUser actualUser){
    
    RegExam regExam;
    Question regQuestion;
    
    ifstream exams("lib\\files\\exams.dat", ios::binary);
    
    if(!exams)
    {
        cout << "No se pudo abrir el archivo \n";
    }
    else{
        while(!exams.eof())
        {
            if(exams.read((char *)&regExam, sizeof(regExam)))
            {
                if(strcmp(regExam.owner, actualUser.username)== 0)
                {
                    cout << regExam.ID << " - " << regExam.name << " - " << regExam.owner << endl;
                }

                for(int i=0; i < regExam.numberQuestions; i++)
                {
                    exams.read((char *)&regQuestion, sizeof(regQuestion));
                }
            } else {

                for (int i = 0; i < regExam.numberQuestions; i++) {
                    exams.read((char *) &regQuestion, sizeof(regQuestion));
                }
            }
        }
    }

    exams.close();
};

void getReports(PublicUser actualUser)
{
    char ID[4];

    system("cls");
    cout << "======================================== INFORMES ======================================== \n \n";

    cout << "(ID examen - Nombre examen - Creador examen) \n \n";
    listExamAdmin(actualUser);

    cout << "\n \nDigite el ID del examen para ver su informe: ";
    cin >> ID;

    system("cls");

    cout << "\n(Nombre Estudiante - Nota)\n";
    getReport(ID);
};