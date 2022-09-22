#ifndef USER_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define USER_H

#include <iostream>
#include <fstream>
#include <string.h>
#include "..\\..\\utils.h"

struct User {
    char username[40];
    char password[40];
    bool isAdmin;
};

/*
 * Nombre: registerUser
 * Objetivo: Registrar a un usuario en el sistema y escribirlo en users.dat
 * Entradas: Recibe el usuario a registrar
 * Salidas: Un entero que representa el codigo de la transaccion
 *          1 -> Fallo en los archivos, 2 -> Fallo en el proceso (Logica) y 0 -> Transaccion exitosa
*/
int registerUser(User user);

/*
 * Nombre: checkUser
 * Objetivo: Loggear al usuario y escribirlo en actualUser.dat
 * Entradas: Recibe el usuario a verificar sus credenciales
 * Salidas: Un entero que representa el codigo de la transaccion
 *          1 -> Fallo en los archivos, 2 -> Fallo en el proceso (Logica) y 0 -> Transaccion exitosa
*/
int checkUser(User user);

/*
 * Nombre: getActualUser
 * Objetivo: Obtener el usuario que esta ejecutando el programa (Leyendo actualUser.dat)
 * Entradas: Ninguna
 * Salidas: El usuario actual
*/
User getActualUser();

#endif
