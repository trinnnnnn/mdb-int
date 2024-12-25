#ifndef TABLE_OPS_H
#define TABLE_OPS_H

#include <string>
#include <vector>

// Function declarations
void insertIntoTable(const std::string& dbName, const std::string& tableName, const std::vector<std::string>& values);
void viewTableCSV(const std::string& dbName, const std::string& tableName);

#endif
