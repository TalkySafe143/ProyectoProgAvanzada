#include "present.h"
#include <fstream>

using namespace std;

void presentExam(PublicUser actualUser){

    char ID[3];
    Question *p;
    bool examExist = false;
    int numberQuestions = 0;
    char owner[50];
    char examName[20];
    infoReport report;

    do{
        system ("cls");
        cout << ">>>>>>>>>>>>>>>>>>>> PRESENTACION DE EXAMENES <<<<<<<<<<<<<<<<< \n \n";
    
        listExam(actualUser); //Mostrar examenes que aun no ha presentado

        cout << endl;
        cout << "Digite el ID del examen que va a presentar: "; cin >> ID;

        p = searchExamById(ID, numberQuestions, owner, examName);  //El apuntador queda en la primera pregunta del examen seleccionado

        if(strcmp(p->statement, "\0")!= 0)
        {
            examExist = true;
        }
        else{
            cout << "No se encontro el examen \n \n";
            system("pause");
        }

        if(examExist)
        {
            char answers[numberQuestions]; //Para guardar respuestas de todo el examen
            int correctAnswers = 0;
            float grade;

            for(int i= 0; i < numberQuestions; i++)
            {
                cout << (p+i)->ID << endl;
                cout << (p+i)->statement << endl;
                cout << (p+i)->OptionA <<endl;
                cout << (p+i)->OptionB <<endl;
                cout << (p+i)->OptionC <<endl;
                cout << (p+i)->OptionD <<endl;
                
                cout << "Digite su respuesta: "; cin >> (answers+i);

                if(*(answers+i) == (p+i)->correctOption)
                {
                    correctAnswers++;
                }
            }

            cout << "Acabaste el examen!! Para ver la revision del examen presiona cualquier tecla \n";
            system("pause");
            system("cls"); 

            grade = (correctAnswers/numberQuestions)*100;
            p = searchExamById(ID, numberQuestions, owner, examName); 

            cout << "===================== REVISION EXAMEN ===================== \n \n";
            
            cout << "Su calificacion: " << grade << "% \n";
            for(int i= 0; i < numberQuestions; i++)
            {
                cout << (p+i)->ID << endl;
                cout << (p+i)->statement << endl;
                cout << (p+i)->OptionA <<endl;
                cout << (p+i)->OptionB <<endl;
                cout << (p+i)->OptionC <<endl;
                cout << (p+i)->OptionD <<endl;

                cout << "La respuesta correcta era: " << (p+i)->correctOption <<endl; 
                cout << "Su respuesta fue: " << (answers+i) <<endl;
            }
            
            //CREAR INFORME
            strcpy(report.Admin, owner);
            strcpy(report.Exam, examName);
            strcpy(report.idExam, ID);
            report.grade = grade;
            strcpy(report.studentName, actualUser.username);
            createReport(report);
        }
    }while(!examExist);
    
};