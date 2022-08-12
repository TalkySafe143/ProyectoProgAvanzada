#include <iostream>
#include "auth/auth.h"

using namespace std;

int main() {

    int option;

    PublicUser actualUser;

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
                break;
            case 2:
                int userCreated = createUser();
                if (userCreated == 1) {
                    continue;
                }
                break;
        }

        char adminIndicator[3];

        if (actualUser.isAdmin) {
            strcpy(adminIndicator, "YES");
        } else {
            strcpy(adminIndicator, "NO");
        }

        cout << "==================== Hola de nuevo, " << actualUser.username << " ====================\t\t\tAdmin: " << adminIndicator << endl;

    }

    return 0;
}
