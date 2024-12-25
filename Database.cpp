#include "Database.h"
#include <iostream>
#include <vector>
#include <string>
#include <direct.h>
#include <io.h>

using namespace std;

void createDatabase(const string& dbName) {

    if (access(dbName.c_str(), 0) == 0) {
        cout << "Database '" << dbName << "' already exists." << endl;
    } else {

        if (mkdir(dbName.c_str()) == 0) {
            cout << "Database '" << dbName << "' created successfully." << endl;
        } else {
            cout << "Failed to create database '" << dbName << "'." << endl;
        }
    }
}

void listDatabases() {
    cout << "Available databases:" << endl;

    struct _finddata_t dirEntry;
    intptr_t handle = _findfirst("*", &dirEntry);

    if (handle == -1) {
        cout << "No directories found." << endl;
        return;
    }

    do {
        if (dirEntry.attrib & _A_SUBDIR && string(dirEntry.name) != "." && string(dirEntry.name) != "..") {
            cout << " - " << dirEntry.name << endl;
        }
    } while (_findnext(handle, &dirEntry) == 0);

    _findclose(handle);
}
