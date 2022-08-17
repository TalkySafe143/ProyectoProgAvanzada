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
    
    char adminIndicator[3];

    if (actualUser.isAdmin) {
        strcpy(adminIndicator, "YES");
    } else {
        strcpy(adminIndicator, "NO");
    }

    cout << "==================== Hola de nuevo, " << actualUser.username << " ====================\t\t\tAdmin: " << adminIndicator << endl;
    
    /*
	
		Andres -> Hacer la interfaz para las opciones si es admin o no
		Puede ver si es administrador con actualUser.isAdmin
	
	*/

    return 0;
}
