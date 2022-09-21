#include "present.h"
#include <fstream>

using namespace std;

void presentExam(PublicUser actualUser){

    char ID[3];
    Question *p;

    cout << ">>>>>>>>>>>>>>>>>>>> PRESENTACION DE EXAMENES <<<<<<<<<<<<<<<<< \n \n";
    
    listExam(actualUser);

    cout << "Digite el ID del examen que va a presentar: "; cin >> ID;

    p = searchExam(ID); //El apuntador queda en la primera pregunta del examen seleccionado


};