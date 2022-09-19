#include <iostream>
#include "auth\\auth.h"
#include "admin\\admin.h"
#include "admin\\questions\\bench.h"

using namespace std;

/*
 * Nombre: showQuestionsMenu
 * Objetivo: Mostrar el menu de preguntas
 * Entradas: El usuario que esta realizando la accion
 * Salidas: Ninguna
 * */
void showQuestionsMenu(PublicUser actualUser);

int main() {

    setlocale(LC_ALL, ""); // Poner las comas y acentos

    int option;

    PublicUser actualUser;

	bool isLogged = false;

    while (option != 3) {
        system("cls");
        cout << "================ Bienvenido al sistema de presentaci�n de ex�menes ================\n\n";
        cout << "1. Para entrar con tu usuario!\n";
        cout << "2. Crear un nuevo usuario!\n";
        cout << "3. Salir del sistema\n\n";
        cout << "Seleccione una opci�n: ";
        cin >> option;

        if (option < 1 || option > 3) {
            cout << "Por favor, ingrese una opci�n valida\n";
            continue;
        }

        switch (option) {
            case 1:
                actualUser = loginUser();
                if (actualUser.username[0] == '\0') {
                    continue;
                }
                isLogged = true;
                break;
            case 2:
                int userCreated = createUser();
                if (userCreated == 1) { //El usuario ya existe
                    continue;
                }
                break;
        }
        
        if (option == 3)
        	return 0;
        
        if (isLogged) {
            if (actualUser.isAdmin) {

                int optionMenu;

                do {
                    system("cls");
                    cout << "==================== Hola de nuevo, " << actualUser.username << " (Administrador) ====================\n";

                    cout << "�Bienvenido administrador!\n";

                    cout << "1. Crear examen.\n";
                    cout << "2. Eliminar examen.\n";
                    cout << "3. Editar examen.\n";
                    cout << "4. Modificar banco de preguntas.\n\n";
                    cout << "5. Salir.\n\n";
                    cout << "Seleccione una opci�n: ";
                    cin >> optionMenu;

                    if (optionMenu > 5 || optionMenu < 1) {
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
                            break;
                        case 2:
                            break;
                        case 3:
                            break;
                        case 4: 
                            showQuestionsMenu(actualUser);
                            break;
                    }

                    /*
                     * Para las opciones 1, 2 y 3, se debe editar admin\admin.cpp/.h
                     * Para la opcion 4, se debe editar admin\questions\bench.cpp/.h
                     * */

                } while (optionMenu != 5);

            } else {

                int optionMenu;

                do {

                    cout << "==================== Hola de nuevo, " << actualUser.username << " (Estudiante) ====================\n";

                    cout<<"\nBienvenido estudiante \n "<<endl;

                    cout<<"1. Presentar examen"<<endl;
                    cout<<"2. Ver resultados del examen"<<endl;
                    cout<<"3. Revisar ex�menes presentados"<<endl;
                    cout<<"4. Salir\n"<<endl;
                    cout<<"Seleccione una opci�n: ";

                    cin>> optionMenu;

                    if (optionMenu > 4 || optionMenu < 1) {
                        cout << "Ingrese una opci�n valida.\n";
                        system("pause");
                        system("cls");
                        continue;
                    }

                    if (optionMenu == 4) {
                        isLogged = false;
                    }

                    /*
                     * TODO: Implementar el folder de student/
                     * */

                } while(optionMenu!=4);
            }
        }
    }

    return 0;
}

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

/*
Malparido adrian
Pongale la documentacion a esa cagada
*/

/*
Sapo
*/