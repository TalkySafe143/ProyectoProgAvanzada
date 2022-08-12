#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <fstream>
#include "./lib/user.h"
using namespace std;

void checkIfFileExists(char name[20]) {
    ifstream alreadyCreated(name, ios::binary);

    if (!alreadyCreated) {
        ofstream createFile(name, ios::binary);
        createFile.close();
    }

    alreadyCreated.close();
}

#endif