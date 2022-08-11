#ifndef AUTH_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define AUTH_H

#include <iostream>
#include "../lib/user.h"

using namespace std;

int createUser() {
    User userToCreate;
    cout << "====================================== CREAR USUARIO ======================================\n";

    cout << "Por favor, ingrese un nombre de usuario (40 caracteres): ";
    cin.ignore();
    cin.getline(userToCreate.username, sizeof(userToCreate.username));
    cout << "Por favor, ingrese una contraseña: ";
    cin.getline(userToCreate.password, sizeof(userToCreate.password));
    
    int admin = 3;
    while (admin != 1 && admin != 0) {
        cout << "¿Es administrador del sistema? [Ingrese 0 no es administrador, de lo contrario ingrese 1]: ";
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

int loginUser() {
    User userToQuery;

    cout << "====================================== INGRESAR  ======================================\n";

    cout << "Por favor, ingrese su nombre de usuario: ";
    cin.ignore();
    cin.getline(userToQuery.username, sizeof(userToQuery.username));
    cout << "Por favor, ingrese su contraseña: ";
    cin.getline(userToQuery.password, sizeof(userToQuery.password));

    int confirm = checkUser(userToQuery);

    switch (confirm) {
        case 0:
            cout << "Usuario loggeado correctamente!\n";
            system("pause");
            system("cls");
            return 0;
            break;
        case 1:
            cout << "Alguna de su informacion es incorrecta\n";
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

#endif