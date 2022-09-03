#include <iostream>
#include "auth\\auth.h"

using namespace std;

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
                if (userCreated == 1) {
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
