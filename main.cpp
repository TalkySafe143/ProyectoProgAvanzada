#include <iostream>
#include "auth\\auth.h"

using namespace std;

int main() {

    setlocale(LC_ALL, "");

    int option;

    PublicUser actualUser;
    
	bool isLogged = false;

    while (option != 3) {
        system("cls");
        cout << "================ Bienvenido al sistema de presentación de exámenes ================\n\n";
        cout << "1. Para entrar con tu usuario!\n";
        cout << "2. Crear un nuevo usuario!\n";
        cout << "3. Salir del sistema\n\n";
        cout << "Seleccione una opción: ";
        cin >> option;

        if (option < 1 || option > 3) {
            cout << "Por favor, ingrese una opción valida\n";
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

                    cout << "¡Bienvenido administrador!\n";

                    cout << "1. Crear examen.\n";
                    cout << "2. Eliminar examen.\n";
                    cout << "3. Editar examen.\n";
                    cout << "4. Modificar banco de preguntas.\n\n";
                    cout << "5. Salir.\n\n";
                    cout << "Seleccione una opción: ";
                    cin >> optionMenu;

                    if (optionMenu > 5 || optionMenu < 1) {
                        cout << "Ingrese una opción valida.\n";
                        system("pause");
                        system("cls");
                        continue;
                    }

                    if (optionMenu == 4) {
                        delete [] actualUser.username;
                        isLogged = false;
                    }

                } while (optionMenu != 4);

            } else {

                int optionMenu;

                do {

                    cout << "==================== Hola de nuevo, " << actualUser.username << " (Estudiante) ====================\n";

                    cout<<"\nBienvenido estudiante \n "<<endl;

                    cout<<"1. Presentar examen"<<endl;
                    cout<<"2. Ver resultados del examen"<<endl;
                    cout<<"3. Revisar exámenes presentados"<<endl;
                    cout<<"4. Salir\n"<<endl;
                    cout<<"Seleccione una opción: ";

                    cin>> optionMenu;

                    if (optionMenu > 4 || optionMenu < 1) {
                        cout << "Ingrese una opción valida.\n";
                        system("pause");
                        system("cls");
                        continue;
                    }

                    if (optionMenu == 4) {
                        delete [] actualUser.username;
                        isLogged = false;
                    }

                } while(optionMenu!=4);
            }
        }
    }

    return 0;
}
