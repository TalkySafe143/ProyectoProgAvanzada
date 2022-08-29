#include "auth.h"

using namespace std;

int createUser() {
    User userToCreate;

    userToCreate.username = new char[CHAR_ARRAY_LENGTH];
    userToCreate.password = new char[CHAR_ARRAY_LENGTH];

    system("cls");

    cout << "====================================== CREAR USUARIO ======================================\n";
    cout << "\nPor favor, ingrese un nombre de usuario (30 caracteres): ";
    cin.ignore();
    cin.getline(userToCreate.username, CHAR_ARRAY_LENGTH);
    cout << "\nPor favor, ingrese una contraseña: ";
    cin.getline(userToCreate.password, CHAR_ARRAY_LENGTH);

    int admin = 3;
    while (admin != 1 && admin != 0) {
        cout << "¿Eres administrador? [YES -> 1 | NO -> 0]: ";
        cin >> admin;
    }

    if (admin == 0) {
        userToCreate.isAdmin = false;
    } else {
        userToCreate.isAdmin = true;
    }

    int confirm = registerUser(userToCreate);

    delete [] userToCreate.username;
    delete [] userToCreate.password;

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

    userToQuery.username = new char[CHAR_ARRAY_LENGTH];
    userToQuery.password = new char[CHAR_ARRAY_LENGTH];

    system("cls");

    cout << "====================================== INGRESAR  ======================================\n";

    cout << "\nPor favor, ingrese su nombre de usuario: ";
    cin.ignore();
    cin.getline(userToQuery.username, CHAR_ARRAY_LENGTH);
    cout << "\nPor favor, ingrese su contraseÃ±a: ";
    cin.getline(userToQuery.password, CHAR_ARRAY_LENGTH);

    int confirm = checkUser(userToQuery);

    delete [] userToQuery.username;
    delete [] userToQuery.password;

    User actualUser;
    PublicUser result;

    result.username = new char[CHAR_ARRAY_LENGTH];

    switch (confirm) {
        case 0:
            cout << "Usuario loggeado correctamente!\n";
            system("pause");
            system("cls");

            actualUser = getActualUser();

            strcpy(result.username, actualUser.username);
            result.isAdmin = actualUser.isAdmin;

            delete [] actualUser.username;
            delete [] actualUser.password;

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
