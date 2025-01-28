#include "Containers.h"
using namespace std;
#include <iostream>

DatabaseManager* DatabaseManager::instance = nullptr;

void DatabaseManager::execSQL(const std::string& sql) {
    char* errMsg = nullptr;
    int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK) {
        std::string error = "Erro SQL: " + std::string(errMsg);
        sqlite3_free(errMsg);
        throw std::runtime_error(error);
    }
}

