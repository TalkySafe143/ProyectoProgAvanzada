#ifndef AUTH_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define AUTH_H

#include <iostream>
#include <string.h>
#include "..\\lib\\User\\user.h"

struct PublicUser {
    char username[40];
    bool isAdmin;
};

/*
 * Nombre: createUser
 * Objetivo: Mostrar la interfaz para crear un usuario
 * Entradas: Ninguna
 * Salidas: Retorna 0 -> si el usuario se creo correctamente, 1 -> Algun tipo de fallo
*/
int createUser();

/*
 * Nombre: loginUser
 * Objetivo: Mostrar la interfaz del proceso de Login de un usuario
 * Entradas: Ninguna
 * Salidas: La estructura PublicUser con el usuario recuperado
*/
PublicUser loginUser();

#endif
