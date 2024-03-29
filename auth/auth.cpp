#include "auth.h"

using namespace std;

int createUser() {
    User userToCreate;

    system("cls");

    cout << "====================================== CREAR USUARIO ======================================\n";

    cout << "\nPor favor, ingrese un nombre de usuario (40 caracteres): ";
    cin.ignore();
    cin.getline(userToCreate.username, sizeof(userToCreate.username));
    cout << "\nPor favor, ingrese una contrase�a: ";
    cin.getline(userToCreate.password, sizeof(userToCreate.password));

    int admin = 3;
    while (admin != 1 && admin != 0) {
        cout << "�Eres administrador? [YES -> 1 | NO -> 0]: ";
        cin >> admin;
    }

    if (admin == 0) {
        userToCreate.isAdmin = false;
    } else {
        userToCreate.isAdmin = true;
    }

    int confirm = registerUser(userToCreate);

    switch (confirm) {
        case 0:
            cout << "Usuario creado correctamente!\n";
            system("pause");
            system("cls");
            return 0;
            break;
        case 1:
            cout << "El usuario ya existe\n";
            system("pause");
            system("cls");
            return 1;
            break;
        case 2:
            cout << "Posiblemente exista un fallo en los archivos\n";
            system("pause");
            system("cls");
            return 1;
            break;
    }
}

PublicUser loginUser() {
    User userToQuery;

    system("cls");

    cout << "====================================== INGRESAR  ======================================\n";

    cout << "\nPor favor, ingrese su nombre de usuario: ";
    cin.ignore();
    cin.getline(userToQuery.username, sizeof(userToQuery.username));
    cout << "\nPor favor, ingrese su contraseña: ";
    cin.getline(userToQuery.password, sizeof(userToQuery.password));

    int confirm = checkUser(userToQuery);

    User actualUser;
    PublicUser result;

    switch (confirm) {
        case 0:
            cout << "Usuario loggeado correctamente!\n";
            system("pause");
            system("cls");

            actualUser = getActualUser();

            strcpy(result.username, actualUser.username);
            result.isAdmin = actualUser.isAdmin;

            return result;
            break;
        case 1:
            cout << "Alguna de su informacion es incorrecta\n";
            system("pause");
            system("cls");

            result.username[0] = '\0';

            return result;
            break;
        case 2:
            cout << "Posiblemente exista un fallo en los archivos\n";
            system("pause");
            system("cls");

            result.username[0] = '\0';

            return result;
            break;
    }
}
