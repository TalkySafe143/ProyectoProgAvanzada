#include "present.h"
#include <fstream>

using namespace std;

void presentExam(PublicUser actualUser){

    char ID[4];
    bool examExist = false;
    char owner[50];
    char examName[50];
    infoReport report;

    do{
        system ("cls");
        cout << ">>>>>>>>>>>>>>>>>>>> PRESENTACION DE EXAMENES <<<<<<<<<<<<<<<<< \n \n";
    
        listExam(actualUser); //Mostrar examenes que aun no ha presentado

        cout << "\nDigite el ID del examen que va a presentar: ";

        cin >> ID;

        RegExam exam = getRegExam(ID);

        strcpy(examName, exam.name);
        strcpy(owner, exam.owner);

        if(strcmp(exam.name, "\0")!= 0)
        {
            examExist = true;
        }
        else{
            cout << "No se encontro el examen \n \n";
            system("pause");
        }

        if(examExist)
        {
            Question questions[exam.numberQuestions];

            int questionsIDs[exam.numberQuestions];

            getQuestionsIDsFromExam(questionsIDs, ID);

            PublicUser examAdmin;

            strcpy(examAdmin.username, exam.owner);
            examAdmin.isAdmin = true;

            for (int i = 0; i < exam.numberQuestions; i++)
                *(questions + i) = getQuestion(examAdmin, *(questionsIDs + i));


            char answers[exam.numberQuestions]; //Para guardar respuestas de todo el examen
            int correctAnswers = 0;
            float grade;

            system("cls");

            for(int i= 0; i < exam.numberQuestions; i++)
            {
                cout << "\n\nID de la pregunta: " << (questions + i)->ID << endl;
                cout << (questions + i)->statement << endl;
                cout << "A. " << (questions + i)->OptionA <<endl;
                cout << "B. " << (questions + i)->OptionB <<endl;
                cout << "C. " << (questions + i)->OptionC <<endl;
                cout << "D. " << (questions + i)->OptionD <<endl;
                
                cout << "Digite su respuesta: "; cin >> *(answers+i);

                cout << "----------------------------------------\n";

                if(*(answers+i) == (questions + i)->correctOption)
                {
                    correctAnswers++;
                }
            }

            cout << "Acabaste el examen!! Para ver la revision del examen presiona cualquier tecla \n";
            system("pause");
            system("cls"); 

            grade = ((float)correctAnswers/(float)exam.numberQuestions)*100;

            cout << "===================== REVISION EXAMEN ===================== \n \n";
            
            cout << "Su calificacion: " << grade << "% \n";
            for(int i= 0; i < exam.numberQuestions; i++)
            {
                cout << "ID de la pregunta: " << (questions + i)->ID << endl;
                cout << (questions + i)->statement << endl;
                cout << "A. " << (questions + i)->OptionA <<endl;
                cout << "B. " << (questions + i)->OptionB <<endl;
                cout << "C. " << (questions + i)->OptionC <<endl;
                cout << "D. " << (questions + i)->OptionD <<endl;

                cout << "La respuesta correcta era: " << (questions + i)->correctOption <<endl;
                cout << "Su respuesta fue: " << *(answers+i) <<endl;
                cout << "------------------------------------------------\n";
            }
            system("pause");
            system("cls");
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