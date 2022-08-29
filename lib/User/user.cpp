#include "user.h"

using namespace std;

int registerUser(User user) {

    char *fileName = new char[20];

    strcpy(fileName, ".\\lib\\files\\users.txt");

    resizeCharArray(fileName);

    checkIfFileExists(fileName);

    fstream userFile(fileName, ios::in | ios::out | ios::app);

    if (!userFile)
        return 2;

    bool exist = false;

    char *read = new char[70]; // 30 for username, 30 for password and 1 for isAdmin

    while (!userFile.eof() && !exist) {

        userFile.getline(read, sizeof(read));

        User readingUser;

        readingUser.username = new char[30];
        readingUser.password = new char[30];

        getUserMembers(read, readingUser);

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

    userFile << user.username << ";" << user.password << ";" << user.isAdmin << "\n";

    userFile.close();

    delete [] fileName;

    return 0;
}

int checkUser(User user) {

    char *fileName = new char[20];

    strcpy(fileName, ".\\lib\\files\\users.txt");

    resizeCharArray(fileName);

    checkIfFileExists(fileName);

    User readUser;

    readUser.username = new char[30];
    readUser.password = new char[30];

    ifstream userFile(fileName);

    if (!userFile)
        return 2;

    char *read = new char[63];

    while (!userFile.eof()) {

        userFile.getline(read, sizeof(read));

        getUserMembers(read, readUser);

        cout << readUser.username << " Es el usuario del archivo" << endl;
        cout << user.username << " Es el usuario del usuario" << endl;

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

    actualUser.username = new char[30];
    actualUser.password = new char[30];

    if (!file) {
        cout << "Ocurrio un error con el archivo\n";
        return actualUser;
    }

    char *read = new char[63];

    while (!file.eof()) {

        file.getline(read, sizeof(read));

        getUserMembers(read, actualUser);
    }

    delete [] read;

    file.close();

    return actualUser;
}
