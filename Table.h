#ifndef TABLE_H
#define TABLE_H

#include <string>
#include <vector>

using namespace std;

void createTable(const string& dbName, const string& tableName, const vector<string>& schema);
void listTables(const string& dbName);

#endif
