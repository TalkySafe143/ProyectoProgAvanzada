#include "utils.h"

using namespace std;

void checkIfFileExists(char *name) {
    ifstream alreadyCreated(name, ios::binary);

    if (!alreadyCreated) {
        ofstream createFile(name, ios::binary);
        createFile.close();
    }

    alreadyCreated.close();
}
