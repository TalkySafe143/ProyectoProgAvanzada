#include "student.h"
#include <fstream>
#include <iostream>

using namespace std;

void showStudentMenu(PublicUser actualUser, bool &isLogged){
    int option;

    do{
    system("cls");
    cout << "==================== Hola de nuevo, " << actualUser.username << " (Estudiante) ====================\n";

    cout << "�Bienvenido estudiante!\n";

    cout << "1. Presentar Examen \n";
    cout << "2. Salir \n\n";
    cout << "Seleccione una opci�n: "; cin >> option;

    
    if (option < 1 || option > 2) {
        cout << "Por favor, ingrese una opci�n valida\n";
        system("pause");
        system("cls");
        continue;
    }

    if(option == 1)
    {
       presentExam(actualUser);
    }

    if(option == 2)
    {
        isLogged = false;
    }

    }while(option != 2);
}

void listExam(PublicUser actualUser){
    
    RegExam regExam;
    Question regQuestion;
    infoReport regPresent;
    int lenght = 0;
    char *p;
    bool found;

    char filename[150];
    strcpy(filename, "lib\\files\\exams.dat");

    char filename2[150];
    strcpy(filename2, "lib\\files\\ExamenesPresentados.dat");

    checkIfFileExists(filename);
    checkIfFileExists(filename2);

    char userFilename[150];

    strcpy(userFilename, "lib\\files\\");
    strcat(userFilename, actualUser.username);
    strcat(userFilename, "examsIDs.txt");

    ofstream IdReg(userFilename);
    ifstream exams("lib\\files\\exams.dat", ios::binary);
    ifstream presents("lib\\files\\ExamenesPresentados.dat", ios::binary);
    
    if(!presents)
    {
        cout << "No se pudo abrir el archivo \n";
    }
    else{
        while(!presents.eof())
        {
            if(presents.read((char *)&regPresent, sizeof(regPresent)))
            {
                if(strcmp(regPresent.studentName, actualUser.username)== 0)
                {
                    IdReg << regPresent.idExam << "-";
                    lenght += 4;
                } 
            }
        }
        presents.close();
        IdReg.close();
    }

    if(!exams)
    {
        cout << "No se pudo abrir el archivo \n";
    }
    else{

        ifstream readText(userFilename);

        char IDs[lenght+1];

        readText.getline(IDs, sizeof(IDs) + 1);

        readText.close();

        while(!exams.eof())
        {
            if(exams.read((char *)&regExam, sizeof(regExam)))
            {
                found = false;

                char IdsCopy[lenght];

                strcpy(IdsCopy, IDs);

                p = strtok(IdsCopy, "-");
                while(p != NULL)
                {
                    if(strcmp(regExam.ID, p)== 0)
                    {
                        found = true;
                        break;
                    }
                    p = strtok(NULL, "-");
                }
                if(!found)
                {
                    cout << regExam.ID << " - " << regExam.name << " - " << regExam.owner << endl;
                }                      
            }
                
            for(int i=0; i < regExam.numberQuestions; i++)
            {
                    exams.read((char *)&regQuestion, sizeof(regQuestion));
            }
        }
        exams.close();
    }
}
