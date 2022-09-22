#include <iostream>
#include <ctime>
#include "auth\\auth.h"
#include "admin\\admin.h"
#include "admin\\questions\\bench.h"
#include "student\\student.h"

using namespace std;

int main() {

    system("color f");

    srand(time(NULL)); // Generar una semilla aleatoria para generateUniqueID() en utils.cpp

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

        if (option < 1 || option > 3) { //Validacion
            cout << "Por favor, ingrese una opci�n valida\n";
            system("pause");
            continue;
        }

        switch (option) {
            case 1:
                actualUser = loginUser(); 
                if (actualUser.username[0] == '\0') { //Informacion incorrecta o Error en el archivo
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

        if(option == 3)
        {
            return 0; //Cerrar programa
        }
        
        if (isLogged) {
            if (actualUser.isAdmin) {
                showAdminMenu(actualUser, isLogged);

            } else {
                showStudentMenu(actualUser, isLogged);
            }
        }
    }

    return 0;
}
