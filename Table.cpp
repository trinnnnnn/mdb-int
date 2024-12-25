#include "Table.h"
#include <iostream>
#include <fstream>
#include <direct.h>
#include <io.h>

using namespace std;

void createTable(const string& dbName, const string& tableName, const vector<string>& schema) {
    string dbPath = "database/" + dbName;
    string tablePath = dbPath + "/" + tableName + ".csv";

    if (_access(dbPath.c_str(), 0) != 0) {
        cout << "Database '" << dbName << "' does not exist." << endl;
        return;
    }

    if (_access(tablePath.c_str(), 0) == 0) {
        cout << "Table '" << tableName << "' already exists." << endl;
        return;
    }

    ofstream tableFile(tablePath);
    if (tableFile.is_open()) {
        for (size_t i = 0; i < schema.size(); ++i) {
            tableFile << schema[i];
            if (i < schema.size() - 1) {
                tableFile << ",";
            }
        }
        tableFile << endl;
        tableFile.close();
        cout << "Table '" << tableName << "' created successfully in database '" << dbName << "'." << endl;
    } else {
        cout << "Failed to create table '" << tableName << "'." << endl;
    }
}

void listTables(const string& dbName) {
    string dbPath = "database/" + dbName;

    if (_access(dbPath.c_str(), 0) != 0) {
        cout << "Database '" << dbName << "' does not exist." << endl;
        return;
    }

    cout << "Tables in database '" << dbName << "':" << endl;

    struct _finddata_t fileEntry;
    intptr_t handle = _findfirst((dbPath + "/*.csv").c_str(), &fileEntry);

    if (handle == -1) {
        cout << "No tables found." << endl;
        return;
    }

    do {
        string tableName = fileEntry.name;
        tableName = tableName.substr(0, tableName.find(".csv"));
        cout << " - " << tableName << endl;
    } while (_findnext(handle, &fileEntry) == 0);

    _findclose(handle);
}
