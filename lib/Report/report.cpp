#include "report.h"
#include <fstream>
#include <string.h>

using namespace std;

void getReport(char IdExam[3]){
    
    infoReport report;
    ifstream examPresent("lib\\files\\ExamenesPresentados.dat", ios::binary);
     //Funcion para mostrar todos los examenes
    if(!examPresent)
    {
        cout << "No se pudo abrir el archivo \n";
    }
    else{
        while(!examPresent.eof())
        {
            if(examPresent.read((char *)&report, sizeof(report)))
            {
                if(strcmp(IdExam, report.idExam) == 0)
                {
                    cout << report.studentName << " - " << report.grade << endl;
                }
            }
        }
        examPresent.close();
    }
}

void createReport(infoReport report){

    ofstream examPresent("lib\\files\\ExamenesPresentados.dat", ios::binary|ios::app);

    if(!examPresent)
    {
        cout << "No se pudo abrir el archivo! \n";
    }
    else{
        examPresent.write((char *)&report, sizeof(report));
        examPresent.close();
    }
}