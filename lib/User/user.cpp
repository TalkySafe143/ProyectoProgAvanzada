#include "user.h"

using namespace std;

int registerUser(User user) {

    char *fileName = new char[30];

    strcpy(fileName, ".\\lib\\files\\users.txt");

    checkIfFileExists(fileName);

    fstream userFile(fileName, ios::in | ios::out | ios::app);

    delete [] fileName;


    if (!userFile) {
        return 2;
    }

    bool exist = false;

    char *read = new char[70]; // 30 for username, 30 for password and 1 for isAdmin

    while (!userFile.eof() && !exist) {

        userFile.getline(read, 70);

        if (strcmp(read, "") == 0) {
            continue;
        }

        User readingUser;

        readingUser.username = new char[CHAR_ARRAY_LENGTH];
        readingUser.password = new char[CHAR_ARRAY_LENGTH];

        readingUser = getUserMembers(read, readingUser);

        if (strcmp(readingUser.username, user.username) == 0) {
            exist = true;
        }

        delete [] readingUser.username;
        delete [] readingUser.password;
    }

    delete [] read;

    if (exist)
        return 1;

    userFile.clear();

    userFile << user.username << ";" << user.password << ";" << user.isAdmin << endl;

    userFile.close();

    return 0;
}

int checkUser(User user) {

    char *fileName = new char[30];

    strcpy(fileName, ".\\lib\\files\\users.txt");

    checkIfFileExists(fileName);

    User readUser;

    readUser.username = new char[CHAR_ARRAY_LENGTH];
    readUser.password = new char[CHAR_ARRAY_LENGTH];

    ifstream userFile(fileName);

    if (!userFile)
        return 2;

    char *read = new char[70];

    while (!userFile.eof()) {

        userFile.getline(read, 70);

        if (strcmp(read, "") == 0) {
            continue;
        }

        readUser = getUserMembers(read, readUser);

        if (strcmp(readUser.username, user.username) == 0) {
            if (strcmp(readUser.password, user.password) == 0) {

                ofstream actualUser(".\\lib\\files\\actualUser.txt");

                if (!actualUser)
                    return 2;

                actualUser << readUser.username << ";" << readUser.password << ";" << readUser.isAdmin << "\n";

                actualUser.close();

                delete [] read;

                delete [] readUser.username;
                delete [] readUser.password;

                userFile.close();

                return 0;
            } else {

                delete [] read;

                delete [] readUser.username;
                delete [] readUser.password;

                userFile.close();

                return 1;
            }
        }
    }

    delete [] read;

    delete [] readUser.username;
    delete [] readUser.password;

    userFile.close();

    delete [] fileName;

    cout << "Hola main\n";

    return 1;
}

User getActualUser() {
    ifstream file(".\\lib\\files\\actualUser.txt");

    User actualUser;

    actualUser.username = new char[CHAR_ARRAY_LENGTH];
    actualUser.password = new char[CHAR_ARRAY_LENGTH];

    if (!file) {
        cout << "Ocurrio un error con el archivo\n";
        return actualUser;
    }

    char *read = new char[70];

    while (!file.eof()) {

        file.getline(read, 70);

        if (strcmp(read, "") == 0) {
            continue;
        }

        actualUser = getUserMembers(read, actualUser);
    }

    delete [] read;

    file.close();

    return actualUser;
}
