#include "user.h"

using namespace std;

int registerUser(User user) {

    char fileName[20];

    strcpy(fileName, ".\\lib\\files\\users.dat");

    checkIfFileExists(fileName);

    User readUser;
    fstream userFile(fileName, ios::binary | ios::in | ios::out);

    if (!userFile)
        return 2;

    bool exist = false;

    while (!userFile.eof() && !exist) {
        if (userFile.read((char *)&readUser, sizeof(readUser))) {
            if (strcmp(readUser.username, user.username) == 0) {
                exist = true;
            }
        }
    }

    if (exist)
        return 1;

    userFile.clear(); // Cuando se lee con fstream para que ya pueda escribir otra vez

    userFile.write((char *)&user, sizeof(user));

    userFile.close();

    return 0;
}

int checkUser(User user) {

    char fileName[20];

    strcpy(fileName, ".\\lib\\files\\users.dat");

    checkIfFileExists(fileName);

    User readUser;

    ifstream userFile(fileName, ios::binary);

    if (!userFile)
        return 2;

    while (!userFile.eof()) {
        if (userFile.read((char *)&readUser, sizeof(readUser))) {
            if (strcmp(readUser.username, user.username) == 0) {
                if (strcmp(readUser.password, user.password) == 0) {

                    ofstream actualUser(".\\lib\\files\\actualUser.dat", ios::binary);

                    if (!actualUser)
                        return 2;

                    actualUser.write((char *)&readUser, sizeof(readUser));

                    actualUser.close();

                    return 0;
                } else {
                    return 1;
                }
            }
        }
    }

    userFile.close();

    return 1;
}

User getActualUser() {
    ifstream file(".\\lib\\files\\actualUser.dat", ios::binary);

    User actualUser;

    if (!file) {
        cout << "Ocurrio un error con el archivo\n";
        return actualUser;
    }

    file.read((char *)&actualUser, sizeof(actualUser));

    file.close();

    return actualUser;
}
