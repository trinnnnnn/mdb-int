#include "TableOps.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <io.h>

using namespace std;

void insertIntoTable(const string& dbName, const string& tableName, const vector<string>& values) {
    string tablePath = "database/" + dbName + "/" + tableName + ".csv";

    if (_access(tablePath.c_str(), 0) != 0) {
        cout << "Table '" << tableName << "' does not exist in database '" << dbName << "'." << endl;
        return;
    }

    // Open the table in append mode
    ofstream tableFile(tablePath, ios::app);
    if (tableFile.is_open()) {
        for (size_t i = 0; i < values.size(); ++i) {
            tableFile << values[i];
            if (i < values.size() - 1) {
                tableFile << ",";
            }
        }
        tableFile << endl;
        tableFile.close();
        cout << "Row inserted into table '" << tableName << "'." << endl;
    } else {
        cout << "Failed to insert row into table '" << tableName << "'." << endl;
    }
}

void viewTableCSV(const string& dbName, const string& tableName) {
    string tablePath = "database/" + dbName + "/" + tableName + ".csv";

    if (_access(tablePath.c_str(), 0) != 0) {
        cout << "Table '" << tableName << "' does not exist in database '" << dbName << "'." << endl;
        return;
    }

    ifstream tableFile(tablePath);
    string line;

    if (tableFile.is_open()) {
        cout << "Data in table '" << tableName << "' (CSV mode):" << endl;
        while (getline(tableFile, line)) {
            cout << line << endl;
        }
        tableFile.close();
    } else {
        cout << "Failed to read table '" << tableName << "'." << endl;
    }
}
