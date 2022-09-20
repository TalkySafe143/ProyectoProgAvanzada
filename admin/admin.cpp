#include "admin.h"

using namespace std;

void showAdminMenu(PublicUser actualUser, bool &isLogged)
{
    int optionMenu;

     do {
            system("cls");
            cout << "==================== Hola de nuevo, " << actualUser.username << " (Administrador) ====================\n";

            cout << "�Bienvenido administrador!\n";

            cout << "1. Crear examen.\n";
            cout << "2. Eliminar examen.\n";
            cout << "3. Editar examen.\n";
            cout << "4. Modificar banco de preguntas.\n\n";
            cout << "5. Salir.\n\n";
            cout << "Seleccione una opci�n: ";
            cin >> optionMenu;

            if (optionMenu > 5 || optionMenu < 1) {
              cout << "Ingrese una opci�n valida.\n";
              system("pause");
              system("cls");
              continue;
            }

            if (optionMenu == 5) {
               isLogged = false;
            }

            switch (optionMenu)
            {
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4: 
                    showQuestionsMenu(actualUser);
                    break;
            }

                    /*
                     * Para las opciones 1, 2 y 3, se debe editar admin\admin.cpp/.h
                     * Para la opcion 4, se debe editar admin\questions\bench.cpp/.h
                     * */

        } while (optionMenu != 5);
}


void createExam(User actualUser) {};

void updateExam(User actualUser){};

void deleteExam(User actualUser){};