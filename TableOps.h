#ifndef TABLE_OPS_H
#define TABLE_OPS_H

#include <string>
#include <vector>

using namespace std;

void insertIntoTable(const string& dbName, const string& tableName, const vector<string>& values);
void viewTableCSV(const string& dbName, const string& tableName);

#endif
