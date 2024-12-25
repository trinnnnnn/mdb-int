#include <iostream>
#include <vector>
#include <string>
#include "Database.h"
#include "Table.h"
#include "TableOps.h"

using namespace std;

int main() {

    cout << "Creating database 'myDatabase'..." << endl;
    createDatabase("myDatabase");

    cout << "\nListing all databases:" << endl;
    listDatabases();

    cout << "\nCreating table 'users' in database 'myDatabase'..." << endl;
    vector<string> schema = {"id INT", "name TEXT", "age INT"};
    createTable("myDatabase", "users", schema);

    cout << "\nListing all tables in database 'myDatabase':" << endl;
    listTables("myDatabase");

    cout << "\nInserting rows into table 'users'..." << endl;
    vector<string> row1 = {"1", "Alice", "23"};
    vector<string> row2 = {"2", "Bob", "30"};
    vector<string> row3 = {"3", "Charlie", "27"};
    insertIntoTable("myDatabase", "users", row1);
    insertIntoTable("myDatabase", "users", row2);
    insertIntoTable("myDatabase", "users", row3);

    cout << "\nViewing table 'users' in CSV mode:" << endl;
    viewTableCSV("myDatabase", "users");

    return 0;
}
