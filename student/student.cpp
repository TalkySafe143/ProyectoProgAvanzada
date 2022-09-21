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
       // presentExam();
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
    int lenght = 4;
    char *IDs = new char [lenght];
    char *p;
    bool Encontro;
    

    ifstream exams("\\lib\\files\\exams.dat", ios::binary);
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
                    strcat(IDs, regPresent.idExam);
                    strcat(IDs, "-");
                    lenght = resizeIdArray(IDs, lenght);
                    // IDs = 123-4g5-32d-3e4-345
                } 
            }
        }
        presents.close();
    }

    if(!exams)
    {
        cout << "No se pudo abrir el archivo \n";
    }
    else{
        while(!exams.eof())
        {
            if(exams.read((char *)&regExam, sizeof(regExam)))
            {
                Encontro = false;
                p = strtok(IDs, "-");
                while(p != NULL)
                {
                    if(strcmp(regExam.ID, p)== 0)
                    {
                        Encontro = true;
                    }
                    p = strtok(NULL, "-");
                }
                if(!Encontro)
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
