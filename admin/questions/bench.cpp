#include "bench.h"

using namespace std;

void showQuestionsMenu(PublicUser actualUser) {
    int optionBanc;
    do {
        system("cls");
        cout << "Modificar Banco de preguntas\n";

        cout << "1. Crear pregunta.\n";
        cout << "2. Modificar pregunta.\n";
        cout << "3. Consultar pregunta.\n";
        cout << "4. Borrar pregunta.\n";
        cout << "5. Mostrar todas las preguntas.\n\n";
        cout << "6. Salir.\n\n";
        cout << "Seleccione una opci�n: ";
        cin >> optionBanc;

        if (optionBanc > 6 || optionBanc < 1) { //Validaciones
            cout << "Ingrese una opci�n valida.\n";
            system("pause");
            system("cls");
            continue;
        }

        switch(optionBanc)
        {
            case 1:
                createBenchQuestion(actualUser);
                break;
            case 2:
                updateBenchQuestion(actualUser);
                break;
            case 3:
                getBenchQuestion(actualUser);
                break;
            case 4:
                deleteBenchQuestion(actualUser);
                break;
            case 5:
                showBenchQuestions(actualUser);
                break;
        }
    } while(optionBanc !=6);
}

void createBenchQuestion(PublicUser admin){
    Question create;

    system("cls");

    cout << "*************** CREAR PREGUNTA ***************" << endl;
    cout << "Ingrese el ID de la pregunta: ";
    cin >> create.ID;
    cout << "Ingrese el enunciado de la pregunta: ";
    cin.ignore();
    cin.getline(create.statement, sizeof(create.statement));
    cout << "Ingrese la opcion A: ";
    cin.getline(create.OptionA, sizeof(create.OptionA));
    cout << "Ingrese la opcion B: ";
    cin.getline(create.OptionB, sizeof(create.OptionB));
    cout << "Ingrese la opcion C: ";
    cin.getline(create.OptionC, sizeof(create.OptionC));
    cout << "Ingrese la opcion D: ";
    cin.getline(create.OptionD, sizeof(create.OptionD));
    cout << "Ingrese la respuesta correcta: ";
    cin >> create.correctOption;

    int result = createQuestion(admin, create);

    if (result == 0) {
        cout << "Pregunta creada exitosamente" << endl;
    } else if (result == 1) {
        cout << "Error al crear la pregunta (Archivos)" << endl;
    } else if (result == 2) {
        cout << "Ya existe una pregunta con ese ID" << endl;
    }

    system("pause");
    system("cls");
};

void updateBenchQuestion(PublicUser admin){ 

    int idSearch = -2, opcion = -2;

    while (idSearch != -1) {
        system("cls");
        cout << "*************** EDITAR PREGUNTA *************** \n \n";

        cout << "Digite el ID de la pregunta que desea editar: ";

        cin >> idSearch;

        Question question = getQuestion(admin, idSearch);

        while (strcmp(question.statement, "\0") == 0 || strcmp(question.statement, "fileError") == 0) {
            if (idSearch == -1) {
                break;
            }
            if (strcmp(question.statement, "\0") == 0) {
                cout << "La pregunta que quiere modificar no existe!\nPor favor, ingrese un ID valido [-1 para salir]: ";
                cin >> idSearch;
                question = getQuestion(admin, idSearch);
            } else {
                cout << "Existe un error en los archivos\n";
                system("pause");
                idSearch = -1;
            }
        }

        if (idSearch == -1) {
            continue;
        }

        cout << "Esta es la pregunta que se va a modificar \n\n";
        cout << "1. (ID)" << question.ID << endl;
        cout << "2. (Enunciado)" << question.statement << endl;
        cout << "3. (Opcion A)" << question.OptionA << endl;
        cout << "4. (Opcion B)" << question.OptionB << endl;
        cout << "5. (Opcion C)" << question.OptionC << endl;
        cout << "6. (Opcion D)" << question.OptionD << endl;
        cout << "7. (Opcion correcta)" << question.correctOption << endl;

        while (opcion != -1) {
            cout << "Que deseea modificar? (Digite un numero) [-1 para salir]: ";
            cin >> opcion;

            switch(opcion) {
                case -1:
                    break;
                case 1:
                    cout << "Ingrese el nuevo ID: ";
                    cin >> question.ID;
                    break;
                case 2:
                    cout << "Ingrese el nuevo enunciado: ";
                    cin.ignore();
                    cin.getline(question.statement, sizeof(question.statement));
                    break;
                case 3:
                    cout << "Ingrese la nueva opcion A: ";
                    cin.ignore();
                    cin.getline(question.OptionA, sizeof(question.OptionA));
                    break;
                case 4:
                    cout << "Ingrese la nueva opcion B: ";
                    cin.ignore();
                    cin.getline(question.OptionB, sizeof(question.OptionB));
                    break;
                case 5:
                    cout << "Ingrese la nueva opcion C: ";
                    cin.ignore();
                    cin.getline(question.OptionC, sizeof(question.OptionC));
                    break;
                case 6:
                    cout << "Ingrese la nueva opcion D: ";
                    cin.ignore();
                    cin.getline(question.OptionD, sizeof(question.OptionD));
                    break;
                case 7:
                    cout << "Ingrese la nueva opcion correcta: ";
                    cin.ignore();
                    cin >> question.correctOption;
                    break;
                default:
                    cout << "Opcion invalida \n";
                    system("pause");
                    system("cls");
                    break;
            }
            if (opcion >= 1 && opcion <= 7) {
                opcion = -1;
            }
        }

        int confirm = updateQuestion(admin, question);

        if (confirm == 1) {
            cout << "Hay un problema con los archivos!\n";
            system("pause");
            system("cls");
        } else if (confirm == 2) {
            cout << "Ups, quiza hay algo que estas digitando mal o no se esta contemplando\n";
            system("pause");
            system("cls");
        } else {
            cout << "La pregunta se ha actualizado correctamente!\n";
            system("pause");
            system("cls");
        }
        idSearch = -1;
    }
};

void deleteBenchQuestion(PublicUser admin){
    int idSearch;

    system("cls");
    cout << "*************** ELIMINAR PREGUNTA *************** \n \n";

    cout << "Digite el ID de la pregunta que desea eliminar: ";
    cin >> idSearch;

    int result = deleteQuestion(admin, idSearch);

    if (result == 0) {
        cout << "Pregunta eliminada exitosamente" << endl;
        system("pause");
        system("cls");
    } else if (result == 1) {
        cout << "Error al eliminar la pregunta (Archivos)" << endl;
        system("pause");
        system("cls");
    } else if (result == 2) {
        cout << "No existe una pregunta con ese ID" << endl;
        system("pause");
        system("cls");
    }
};

void showBenchQuestions(PublicUser admin){

    char filename[150];

    prepareAdminFileName(admin, filename); 

    checkIfFileExists(filename); //Si no exite, la funcion lo crea

    ifstream file(filename, ios::binary);

    if (!file) {
        cout << "Error al abrir el archivo" << endl;
        system("pause");
        system("cls");
    } else {
        Question question;

        while (!file.eof()) {
            if (file.read((char*)&question, sizeof(question))) {
                cout << "ID: " << question.ID << endl;
                cout << "Pregunta: " << question.statement << endl;
                cout << "Opcion A: " << question.OptionA << endl;
                cout << "Opcion B: " << question.OptionB << endl;
                cout << "Opcion C: " << question.OptionC << endl;
                cout << "Opcion D: " << question.OptionD << endl;
                cout << "Opcion correcta: " << question.correctOption << endl;
                cout << "----------------------------------" << endl;
            }
        }
    }

    file.close();

    system("pause");
    system("cls");
};

void getBenchQuestion(PublicUser admin) {
    int idSearch;

    system("cls");
    cout << "*************** BUSCAR PREGUNTA *************** \n \n";

    cout << "Digite el ID de la pregunta que desea buscar: ";
    cin >> idSearch;

    Question question = getQuestion(admin, idSearch);

    if (strcmp(question.statement, "\0") == 0) {
        cout << "La pregunta que quiere buscar no existe!\n";
    } else if (strcmp(question.statement, "fileError") == 0) {
        cout << "Existe un error en los archivos\n";
    } else {
        cout << "ID: " << question.ID << endl;
        cout << "Pregunta: " << question.statement << endl;
        cout << "Opcion A: " << question.OptionA << endl;
        cout << "Opcion B: " << question.OptionB << endl;
        cout << "Opcion C: " << question.OptionC << endl;
        cout << "Opcion D: " << question.OptionD << endl;
        cout << "Opcion correcta: " << question.correctOption << endl;
    }

    system("pause");
    system("cls");
}