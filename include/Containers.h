#ifndef CONTAINERS_H
#define CONTAINERS_H
#include <sqlite3.h>
#include <stdexcept>
#include <string>
#include "Entidade.h"
#include "Dominios.h"
#include "SessionManager.h"
using namespace std;
class DatabaseManager {
private:
    static DatabaseManager* instance;
    sqlite3* db{};

    DatabaseManager() {
        if (int rc = sqlite3_open("database.db", &db); rc != SQLITE_OK) {
            throw runtime_error("Falha ao conectar ao banco: " + string(sqlite3_errmsg(db)));
        }
        const string sqlScript = R"(
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
                codigo TEXT PRIMARY KEY,
                nome TEXT NOT NULL,
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
    void execSQL(const string& sql);
    sqlite3* getConnection() { return db; }
    static void verifyEntityOwnership(const string& tableHierarchy, const string& whereColumn, const string& entityCode);
};

class ContainerViagem{
    public:
    bool createViagem(const Viagem);
    bool deleteViagem(const Codigo);
    bool readViagem(Viagem*);
    bool updateViagem(const Viagem);
};

class ContainerConta{
    public:
    bool createConta(const Conta);
    bool deleteConta(const Codigo);
    bool readConta(Conta*);
    bool updateConta(const Conta);
};

class ContainerDestino{
    public:
    bool createDestino(const Destino, Codigo);
    bool deleteDestino(const Codigo);
    bool readDestino(Destino*);
    bool updateDestino(const Destino);
};

class ContainerAtividade{
    public:
    bool createAtividade(const Atividade, Codigo);
    bool deleteAtividade(const Codigo);
    bool readAtividade(Atividade*);
    bool updateAtividade(const Atividade);
};

class ContainerHospedagem{
    public:
    bool createHospedagem(const Hospedagem, Codigo);
    bool deleteHospedagem(const Codigo);
    bool readHospedagem(Hospedagem*);
    bool updateHospedagem(const Hospedagem);
};

#endif // CONTAINERS_H