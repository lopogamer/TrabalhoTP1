#ifndef CONTAINERS_H
#define CONTAINERS_H
#include <sqlite3.h>
#include <stdexcept>
#include <string>
class DatabaseManager {
private:
    static DatabaseManager* instance;
    sqlite3* db;                      

    DatabaseManager() {
        int rc = sqlite3_open("database.db", &db);
        if (rc != SQLITE_OK) {
            throw std::runtime_error("Falha ao conectar ao banco: " + std::string(sqlite3_errmsg(db)));
        }
        const std::string sqlScript = R"(
            PRAGMA foreign_keys = ON;

            CREATE TABLE IF NOT EXISTS Conta (
                codigo TEXT PRIMARY KEY,
                senha TEXT NOT NULL
            );

            CREATE TABLE IF NOT EXISTS Viagem (
                codigo TEXT PRIMARY KEY,
                nome TEXT NOT NULL,
                avaliacao INTEGER,
                conta_codigo TEXT,
                FOREIGN KEY (conta_codigo) REFERENCES Conta(codigo)
            );

            CREATE TABLE IF NOT EXISTS Destino (
                codigo TEXT PRIMARY KEY,
                nome TEXT NOT NULL,
                data_inicio TEXT,
                data_termino TEXT,
                avaliacao INTEGER,
                viagem_codigo TEXT,
                FOREIGN KEY (viagem_codigo) REFERENCES Viagem(codigo)
            );

            CREATE TABLE IF NOT EXISTS Atividade (
                codigo TEXT PRIMARY KEY,
                nome TEXT NOT NULL,
                data TEXT,
                horario TEXT,
                duracao INTEGER,
                preco TEXT,
                avaliacao INTEGER,
                destino_codigo TEXT,
                FOREIGN KEY (destino_codigo) REFERENCES Destino(codigo)
            );
            CREATE TABLE IF NOT EXISTS Hospedagem (
                nome TEXT PRIMARY KEY,
                diaria TEXT,
                avaliacao INTEGER,
                destino_codigo TEXT,
                FOREIGN KEY (destino_codigo) REFERENCES Destino(codigo)
            );
        )";
        execSQL(sqlScript);
    }


public:
    ~DatabaseManager() {
        if (db) {
            sqlite3_close(db);
        }
    }

    static DatabaseManager& getInstance() {
        static DatabaseManager instance;
        return instance;
    }

    DatabaseManager(const DatabaseManager&) = delete;
    DatabaseManager& operator=(const DatabaseManager&) = delete;
    void execSQL(const std::string& sql);
    sqlite3* getConnection() { return db; }
};
#endif // CONTAINERS_H