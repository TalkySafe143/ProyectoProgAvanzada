#include "question.h"
#include <string.h>
#include <fstream>

using namespace std;

void getQuestion(){
    Question question;
    ifstream arch("admin\questions\bench.cpp/.h", ios::binary);
    int idSearch; 
    bool Encontro = false;

    system("cls");
    cout << "*********CONSULTAR PREGUNTA********** \n";
    if(arch)
    {
        cout << "Digite el ID de la pregunta que desea consultar: ";cin >> idSearch;
        while(!arch.eof())
        {
            if(arch.read((char *)&question, sizeof(question)))
            {
                if(idSearch == question.ID)
                {
                    cout << question.ID << endl;
                    cout << question.statement << endl;
                    cout << question.OptionA << endl;
                    cout << question.OptionB << endl;
                    cout << question.OptionC << endl;
                    cout << question.OptionD << endl;
                    cout << question.correctOption << endl;
                    Encontro = true;
                    break;
                }
            }
        }
        if(!Encontro)
        {
            cout << "No existe ninguna pregunta con ese ID \n";
        }
        arch.close();
    }
    else{
        cout << "No se pudo abrir el archivo! \n";
    }
    system("pause");
}


void createQuestion(){
    Question question;
    ofstream arch("admin\questions\bench.cpp/.h", ios::binary|ios::app);

    system("cls");
    cout << "*********CREAR PREGUNTA********** \n";
    if(arch)
    {
        cout << "Digite el ID de la pregunta: ";cin >> question.ID;
        cin.ignore();
        cout << "Digite el enunciado: ";cin.getline(question.statement, sizeof(question.statement));
        cout << "Digite opcion A: ";cin.getline(question.OptionA, sizeof(question.OptionA));
        cout << "Digite opcion B: ";cin.getline(question.OptionB, sizeof(question.OptionB));
        cout << "Digite opcion C: ";cin.getline(question.OptionC, sizeof(question.OptionC));
        cout << "Digite opcion D: ";cin.getline(question.OptionD, sizeof(question.OptionD));
        cout << "Digite la opcion correcta";cin.getline(question.correctOption, sizeof(question.correctOption));
        arch.write((char *)&question, sizeof(question));
        arch.close();
    }
    else{
        cout << "No se pudo abrir el archivo \n"; 
    }
    system("pause");
}


void updateQuestion(){
    Question question;
    fstream arch("admin\questions\bench.cpp/.h", ios::binary|ios::in|ios::out);
    bool Encontro = false;
    int idSearch, opcion;

    system("cls");
    cout << "*********EDITAR PREGUNTA********** \n";
    if(arch)
    {
        cout << "Digite el ID de la pregunta que desea editar: ";cin >> idSearch;
        while(!arch.eof())
        {
            if(arch.read((char *)&question, sizeof(question)))
            {
                if(idSearch == question.ID)
                {
                    cout << "Esta es la pregunta que se va a modificar \n\n";
                    cout << "1. " << question.ID << endl;
                    cout << "2. " << question.statement << endl;
                    cout << "3. " << question.OptionA << endl;
                    cout << "4. " << question.OptionB << endl;
                    cout << "5. " << question.OptionC << endl;
                    cout << "6. " << question.OptionD << endl;                    
                    cout << "7. " << question.correctOption << endl;
                    Encontro = true;

                    cout << "Que deseea modificar? (Digite un numero): ";cin >> opcion;
                    cin.ignore();
                    switch(opcion)
                    {
                        case 1: 
                            cin >> question.ID;
                            break;
                        case 2:
                            cin.getline(question.statement, sizeof(question.statement));
                            break;
                        case 3: 
                            cin.getline(question.OptionA, sizeof(question.OptionA));
                            break;
                        case 4:
                            cin.getline(question.OptionB, sizeof(question.OptionB));
                            break;
                        case 5:
                            cin.getline(question.OptionC, sizeof(question.OptionC));
                            break;
                        case 6:
                            cin.getline(question.OptionD, sizeof(question.OptionD));
                            break;
                        case 7:
                            cin.getline(question.correctOption, sizeof(question.correctOption));
                            break;
                        default:
                            cout << "Opcion invalida \n";
                            break;
                    }

                    if(opcion > 0 && opcion < 8)
                    {
                        arch.seekg((int)((-1)*sizeof(question)), ios::cur);
                        arch.write((char *)&question, sizeof(question));
                        cout << "Pregunta modificada correctamente! \n";   
                    } 
                    break; 
                }
            }
        }
        if(!Encontro)
        {
            cout << "No existe ninguna pregunta con ese ID \n";
        }
        arch.close();
    }
    else{
        cout << "No se pudo abrir el archivo! \n";
    }
    system("pause");
}

void deleteQuestion(){};