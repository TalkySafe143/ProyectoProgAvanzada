#include "report.h"

using namespace std;

void getReport(char IdExam[4]){

    int numReports = 0;
    infoReport *reports = new infoReport[numReports];

    char filename[150];
    strcpy(filename, "lib\\files\\ExamenesPresentados.dat");

    infoReport report;
    ifstream examPresent("lib\\files\\ExamenesPresentados.dat", ios::binary);

    if(!examPresent)
    {
        cout << "No se pudo abrir el archivo \n";
    }
    else{
        while(!examPresent.eof())
        {
            if(examPresent.read((char *)&report, sizeof(report))){
                if(strcmp(IdExam, report.idExam) == 0)
                {
                    numReports = resizeReportArray(reports, numReports);
                    *(reports + (numReports - 1)) = report;
                }
            }
        }
        examPresent.close();
    }

    for (int i = 0; i < numReports; i++) {
        for (int j = i + 1; j < numReports; j++) {
            if ((reports + i)->grade < (reports + j)->grade) {
                infoReport temp = *(reports + i);
                *(reports + i) = *(reports + j);
                *(reports + j) = temp;
            }
        }
    }

    for (int i = 0; i < numReports; i++) {
        cout << (reports + i)->studentName << " - " << (reports + i)->grade << "%" << endl;
    }

    system("pause");

    delete [] reports;
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