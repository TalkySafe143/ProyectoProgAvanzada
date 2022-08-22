#include <iostream>
#include "auth\\auth.h"

using namespace std;

int main() {

    int option;

    PublicUser actualUser;
    
	bool isLogged = false;

    while (option != 3) {
        cout << "1 para login y 2 para crear 3 para salir\n";
        cin >> option;

        if (option < 1 || option > 3) {
            cout << "Porfavor, ingrese una opcion valida\n";
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
        
        if (isLogged)
        	break;

    }


    if(actualUser.isAdmin) {

        int optionMenu;

        do {
            cout << "==================== Hola de nuevo, " << actualUser.username << " (Administrador) ====================\n";

            cout << "¡Bienvenido administrador!\n";

            cout << "1. Crear examen.\n";
            cout << "2. Eliminar examen.\n";
            cout << "3. Editar examen.\n";
            cout << "4. Salir.\n\n";
            cout << "Seleccione una opcion: ";
            cin >> optionMenu;

            if (optionMenu > 4 || optionMenu < 1) {
                cout << "Ingrese una opcion valida.\n";
                system("pause");
                system("cls");
                continue;
            }

        } while (optionMenu != 4);

    } else {

        int optionMenu;

        do {

            cout << "==================== Hola de nuevo, " << actualUser.username << " (Estudiante) ====================\n";

            cout<<"\nBienvenido estudiante \n "<<endl;

            cout<<"1. Presentar examen"<<endl;
            cout<<"2. Ver resultados del examen"<<endl;
            cout<<"3. Revisar examenes presentados"<<endl;
            cout<<"4. Salir"<<endl;
            cout<<"Seleccione una opcion: ";

            cin>> optionMenu;

            if (optionMenu > 4 || optionMenu < 1) {
                cout << "Ingrese una opcion valida.\n";
                system("pause");
                system("cls");
                continue;
            }

            /*switch (optionMenu){
              case 1: PresentarExamen();
                      break;
              case 2: VerResultado();
                      break;
              case 3: RevisarExamen();
                      break;
            }*/
        } while(optionMenu!=4);
    }

    /*
     * Hacer el sistema de Logout
     * Arreglar la interfaz de login
     * */

    return 0;
}
