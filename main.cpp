#include <iostream>
#include "auth/auth.h"

using namespace std;

int main() {

    int option;

    while (option != 3) {
        cout << "1 para login y 2 para crear 3 para salir\n";
        cin >> option;

        if (option < 1 || option > 3) {
            cout << "Porfavor, ingrese una opcion valida\n";
            continue;
        }

        int userCreated;

        switch (option) {
            case 1:
                userCreated = loginUser();
                if (userCreated == 1) {
                    cout << "Alguna de tu informacion es incorrecta\n";
                    continue;
                }
                break;
            case 2:
                userCreated = createUser();
                if (userCreated == 1) {
                    cout << "Algo salio mal creando el usuario\n";
                    continue;
                }
                break;
        }

    }

    return 0;
}
