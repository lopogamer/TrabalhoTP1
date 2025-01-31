#include "Containers.h"
using namespace std;
#include <iostream>

DatabaseManager* DatabaseManager::instance = nullptr;

void DatabaseManager::verifyEntityOwnership(const string& tableHierarchy, const string& whereColumn, const string& entityCode) {
    sqlite3* db = getInstance().getConnection();
    sqlite3_stmt* stmt;
    string sql = 
        "SELECT conta_codigo FROM " + tableHierarchy + 
        " WHERE " + whereColumn + " = ?;";
    
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        throw runtime_error("Erro ao verificar entidade: " + string(sqlite3_errmsg(db)));
    }
    
    sqlite3_bind_text(stmt, 1, entityCode.c_str(), -1, SQLITE_STATIC);
    
    int rc = sqlite3_step(stmt);
    if (rc != SQLITE_ROW) {
        sqlite3_finalize(stmt);
        throw runtime_error("Entidade não encontrada.");
    }
    
    string contaCodigo(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
    sqlite3_finalize(stmt);
    
    Codigo contaLogada = SessionManager::getInstance()->getCodigo();
    if (contaCodigo != contaLogada.GetCodigo()) {
        throw runtime_error("Ação não permitida: entidade não pertence à conta logada.");
    }
}

void DatabaseManager::execSQL(const string& sql) {
    char* errMsg = nullptr;
    int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK) {
        string error = "Erro SQL: " + string(errMsg);
        sqlite3_free(errMsg);
        throw runtime_error(error);
    }
}

bool ContainerConta::createConta(Conta conta) {
    sqlite3* db = DatabaseManager::getInstance().getConnection();
    sqlite3_stmt* stmt = nullptr;

    string sql = "INSERT INTO Conta (codigo, senha) VALUES (?, ?);";
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        string error = sqlite3_errmsg(db);
        sqlite3_finalize(stmt);
        throw runtime_error("Falha ao preparar o statement: " + error);
    }

    string codigo = conta.GetCodigo().GetCodigo();
    string senha = conta.GetSenha().GetSenha();
    sqlite3_bind_text(stmt, 1, codigo.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, senha.c_str(), -1, SQLITE_STATIC);

    int rc = sqlite3_step(stmt);
    if (rc == SQLITE_CONSTRAINT) {
        sqlite3_finalize(stmt);
        throw runtime_error("Código já existente.");
    } else if (rc != SQLITE_DONE) {
        string error = sqlite3_errmsg(db);
        sqlite3_finalize(stmt);
        throw runtime_error("Falha ao executar o statement: " + error);
    }

    sqlite3_finalize(stmt);
    return true;
}

bool ContainerConta::updateConta(Conta conta) {
    sqlite3* db = DatabaseManager::getInstance().getConnection();
    sqlite3_stmt* stmt = nullptr;

    string sql = "UPDATE Conta SET senha = ? WHERE codigo = ?;";
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        string error = sqlite3_errmsg(db);
        sqlite3_finalize(stmt);
        throw runtime_error("Falha ao preparar o statement: " + error);
    }

    sqlite3_bind_text(stmt, 1, conta.GetSenha().GetSenha().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, conta.GetCodigo().GetCodigo().c_str(), -1, SQLITE_STATIC);

    int rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        string error = sqlite3_errmsg(db);
        sqlite3_finalize(stmt);
        throw runtime_error("Falha ao executar o statement: " + error);
    }

    int rowsAffected = sqlite3_changes(db);
    if (rowsAffected == 0) {
        sqlite3_finalize(stmt);
        throw runtime_error("Conta não encontrada.");
    }

    sqlite3_finalize(stmt);
    return true;
}

bool ContainerConta::deleteConta(Codigo codigo) {
    sqlite3 *db = DatabaseManager::getInstance().getConnection();
    sqlite3_stmt *stmt;

    string check = "SELECT COUNT(*) FROM Viagem WHERE conta_codigo = ?;";
    if (sqlite3_prepare_v2(db, check.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        throw runtime_error("Falha ao preparar a consulta: " + string(sqlite3_errmsg(db)));
    }
    sqlite3_bind_text(stmt, 1, codigo.GetCodigo().c_str(), -1, SQLITE_STATIC);
    
    int rc = sqlite3_step(stmt);
    if (rc != SQLITE_ROW) {
        sqlite3_finalize(stmt);
        throw runtime_error("Falha ao executar a consulta: " + string(sqlite3_errmsg(db)));
    }

    int count = sqlite3_column_int(stmt, 0);
    sqlite3_finalize(stmt);  

    if (count > 0) {
        throw runtime_error("A conta tem viagens associadas e não pode ser deletada.");
    }

    string sql = "DELETE FROM Conta WHERE codigo = ?;";
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        throw runtime_error("Falha ao preparar o delete: " + string(sqlite3_errmsg(db)));
    }
    
    sqlite3_bind_text(stmt, 1, codigo.GetCodigo().c_str(), -1, SQLITE_STATIC);
    rc = sqlite3_step(stmt);
    
    if (rc != SQLITE_DONE) {
        sqlite3_finalize(stmt);
        throw runtime_error("Falha ao executar o delete: " + string(sqlite3_errmsg(db)));
    }

    sqlite3_finalize(stmt);
    return true;
}

bool ContainerConta::readConta(Conta *conta){
    sqlite3 *db = DatabaseManager::getInstance().getConnection();
    sqlite3_stmt *stmt;

    string sql = "SELECT * FROM Conta WHERE codigo = ?;";
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        throw runtime_error("Falha ao preparar o statement: " + string(sqlite3_errmsg(db)));
    }
    sqlite3_bind_text(stmt, 1, conta->GetCodigo().GetCodigo().c_str(), -1, SQLITE_STATIC);
    int rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        string codigo = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
        string senha = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        Codigo cod;
        cod.SetCodigo(codigo);
        Senha sen;
        sen.SetSenha(senha);
        conta->SetCodigo(cod);
        conta->SetSenha(sen);
        sqlite3_finalize(stmt);
        return true;
    }
    sqlite3_finalize(stmt);
    return false;
}

bool ContainerViagem::createViagem(Viagem viagem) {
    sqlite3* db = DatabaseManager::getInstance().getConnection();
    sqlite3_stmt* stmt = nullptr;
    Codigo conta_codig = SessionManager::getInstance()->getCodigo();
    string sql = "INSERT INTO Viagem (codigo, nome, avaliacao, conta_codigo) VALUES (?, ?, ?, ?);";
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        string error = sqlite3_errmsg(db);
        sqlite3_finalize(stmt);
        throw runtime_error("Falha ao preparar o statement: " + error);
    }
    string Viagem_Codigo = viagem.GetCodigo().GetCodigo();
    string Viagem_Nome = viagem.GetNome().GetNome();
    int Viagem_Avaliacao = viagem.GetAvaliacao().GetAvaliacao();
    string Conta_Codigo = conta_codig.GetCodigo();

    sqlite3_bind_text(stmt, 1, Viagem_Codigo.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, Viagem_Nome.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 3, Viagem_Avaliacao);
    sqlite3_bind_text(stmt, 4, Conta_Codigo.c_str(), -1, SQLITE_STATIC);
    int rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        string error = sqlite3_errmsg(db);
        sqlite3_finalize(stmt);
        throw runtime_error("Falha ao executar o statement: " + error);
    }

    sqlite3_finalize(stmt);
    return true;
}

bool ContainerViagem::updateViagem(const Viagem viagem) {
    DatabaseManager::verifyEntityOwnership(
        "Viagem", 
        "codigo", 
        viagem.GetCodigo().GetCodigo()
    );

    sqlite3* db = DatabaseManager::getInstance().getConnection();
    sqlite3_stmt* stmt;
    string sql = "UPDATE Viagem SET nome = ?, avaliacao = ? WHERE codigo = ?;";
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        throw runtime_error("Falha ao preparar o statement: " + string(sqlite3_errmsg(db)));
    }
    sqlite3_bind_text(stmt, 1, viagem.GetNome().GetNome().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, viagem.GetAvaliacao().GetAvaliacao());
    sqlite3_bind_text(stmt, 3, viagem.GetCodigo().GetCodigo().c_str(), -1, SQLITE_STATIC);
    int rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        throw runtime_error("Falha ao executar o statement: " + string(sqlite3_errmsg(db)));
    }
    sqlite3_finalize(stmt);
    return true;
}

bool ContainerViagem::readViagem(Viagem* viagem) {
    DatabaseManager::verifyEntityOwnership(
        "Viagem", 
        "codigo", 
        viagem->GetCodigo().GetCodigo()
    );
    sqlite3* db = DatabaseManager::getInstance().getConnection();
    sqlite3_stmt* stmt;
    Codigo contaLogada = SessionManager::getInstance()->getCodigo();
    string checkSql = "SELECT conta_codigo FROM Viagem WHERE codigo = ?;";
    sqlite3_stmt* checkStmt;
    
    if (sqlite3_prepare_v2(db, checkSql.c_str(), -1, &checkStmt, nullptr) != SQLITE_OK) {
        throw runtime_error("Falha ao verificar viagem: " + string(sqlite3_errmsg(db)));
    }
    sqlite3_bind_text(checkStmt, 1, viagem->GetCodigo().GetCodigo().c_str(), -1, SQLITE_STATIC);
    
    if (sqlite3_step(checkStmt) != SQLITE_ROW) {
        sqlite3_finalize(checkStmt);
        throw runtime_error("Viagem não encontrada.");
    }
    
    string contaCodigo(reinterpret_cast<const char*>(sqlite3_column_text(checkStmt, 0)));
    sqlite3_finalize(checkStmt);

    if (contaCodigo != contaLogada.GetCodigo()) {
        throw runtime_error("Viagem não pertence à conta logada.");
    }

    string sql = "SELECT * FROM Viagem WHERE codigo = ?;";
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        throw runtime_error("Falha ao preparar o statement: " + string(sqlite3_errmsg(db)));
    }
    sqlite3_bind_text(stmt, 1, viagem->GetCodigo().GetCodigo().c_str(), -1, SQLITE_STATIC);
    int rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        string codigo = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
        string nome = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        int avaliacao = sqlite3_column_int(stmt, 2);
        string conta_codigo = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
        Codigo cod;
        cod.SetCodigo(codigo);
        Nome nom;
        nom.SetNome(nome);
        Avaliacao ava;
        ava.SetAvaliacao(avaliacao);
        Codigo conta_cod;
        conta_cod.SetCodigo(conta_codigo);
        viagem->SetCodigo(cod);
        viagem->SetNome(nom);
        viagem->SetAvaliacao(ava);
        sqlite3_finalize(stmt);
        return true;
    }
}

bool ContainerViagem::deleteViagem(Codigo codigo) {
    DatabaseManager::verifyEntityOwnership(
        "Viagem", 
        "codigo", 
        codigo.GetCodigo()
    );
    sqlite3* db = DatabaseManager::getInstance().getConnection();
    sqlite3_stmt* stmt;
    Codigo contaLogada = SessionManager::getInstance()->getCodigo();
    string check = "SELECT COUNT(*) FROM Destino WHERE viagem_codigo = ?;";
    if (sqlite3_prepare_v2(db, check.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        throw runtime_error("Falha ao preparar a consulta: " + string(sqlite3_errmsg(db)));
    }
    sqlite3_bind_text(stmt, 1, codigo.GetCodigo().c_str(), -1, SQLITE_STATIC);
    
    int rc = sqlite3_step(stmt);
    if (rc != SQLITE_ROW) {
        sqlite3_finalize(stmt);
        throw runtime_error("Falha ao executar a consulta: " + string(sqlite3_errmsg(db)));
    }
    int count = sqlite3_column_int(stmt, 0);
    sqlite3_finalize(stmt);

    if (count > 0) {
        throw runtime_error("A viagem tem destinos associados e não pode ser deletada.");
    }

    string sql = "DELETE FROM Viagem WHERE codigo = ?;";
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        throw runtime_error("Falha ao preparar o delete: " + string(sqlite3_errmsg(db)));
    }

    sqlite3_bind_text(stmt, 1, codigo.GetCodigo().c_str(), -1, SQLITE_STATIC);
    rc = sqlite3_step(stmt);

    if (rc != SQLITE_DONE) {
        sqlite3_finalize(stmt);
        throw runtime_error("Falha ao executar o delete: " + string(sqlite3_errmsg(db)));
    }
    return true;
}

bool ContainerDestino::createDestino(Destino destino, Codigo viagem_codigo) {
    DatabaseManager::verifyEntityOwnership(
        "Viagem", 
        "codigo", 
        viagem_codigo.GetCodigo()
    );
    sqlite3* db = DatabaseManager::getInstance().getConnection();
    sqlite3_stmt* stmt;

    Codigo contaLogada = SessionManager::getInstance()->getCodigo();
    sqlite3_stmt* checkStmt;
    string checkSql = "SELECT conta_codigo FROM Viagem WHERE codigo = ?;";
    
    if (sqlite3_prepare_v2(db, checkSql.c_str(), -1, &checkStmt, nullptr) != SQLITE_OK) {
        throw runtime_error("Falha ao verificar viagem: " + string(sqlite3_errmsg(db)));
    }
    sqlite3_bind_text(checkStmt, 1, viagem_codigo.GetCodigo().c_str(), -1, SQLITE_STATIC);
    
    if (sqlite3_step(checkStmt) != SQLITE_ROW) {
        sqlite3_finalize(checkStmt);
        throw runtime_error("Viagem não encontrada.");
    }
    
    string contaCodigoViagem(reinterpret_cast<const char*>(sqlite3_column_text(checkStmt, 0)));
    sqlite3_finalize(checkStmt);

    if (contaCodigoViagem != contaLogada.GetCodigo()) {
        throw runtime_error("Viagem não pertence à conta logada.");
    }

    string sql = "INSERT INTO Destino (codigo, nome, data_inicio, data_termino, avaliacao, viagem_codigo) VALUES (?, ?, ?, ?, ?, ?);";
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        throw runtime_error("Falha ao preparar o statement (Destino): " + string(sqlite3_errmsg(db)));
    }

    sqlite3_bind_text(stmt, 1, destino.GetCodigo().GetCodigo().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, destino.GetNome().GetNome().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, destino.GetDataInicio().GetData().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, destino.GetDataTermino().GetData().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 5, destino.GetAvaliacao().GetAvaliacao());
    sqlite3_bind_text(stmt, 6, viagem_codigo.GetCodigo().c_str(), -1, SQLITE_STATIC);

    int rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        sqlite3_finalize(stmt);
        throw runtime_error("Erro ao inserir Destino: " + string(sqlite3_errmsg(db)));
    }

    sqlite3_finalize(stmt);
    return true;
}

bool ContainerDestino::readDestino(Destino* destino) {
    DatabaseManager::verifyEntityOwnership(
        "Destino D JOIN Viagem V ON D.viagem_codigo = V.codigo",
        "D.codigo", 
        destino->GetCodigo().GetCodigo()
    );

    sqlite3* db = DatabaseManager::getInstance().getConnection();
    sqlite3_stmt* stmt;

    string sql = "SELECT * FROM Destino WHERE codigo = ?;";
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        throw runtime_error("Falha ao preparar a consulta (Destino): " + string(sqlite3_errmsg(db)));
    }

    sqlite3_bind_text(stmt, 1, destino->GetCodigo().GetCodigo().c_str(), -1, SQLITE_STATIC);
    int rc = sqlite3_step(stmt);

    if (rc == SQLITE_ROW) {
        Nome nome;
        nome.SetNome(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        destino->SetNome(nome);
        Data dataInicio;
        dataInicio.SetData(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
        destino->SetDataInicio(dataInicio);
        Data dataTermino;
        dataTermino.SetData(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
        destino->SetDataTermino(dataTermino);
        Avaliacao avaliacao;
        avaliacao.SetAvaliacao(sqlite3_column_int(stmt, 4));
        destino->SetAvaliacao(avaliacao);
        sqlite3_finalize(stmt);
        return true;
    }

    sqlite3_finalize(stmt);
    return false;
}

bool ContainerDestino::deleteDestino(Codigo codigo) {
    DatabaseManager::verifyEntityOwnership(
        "Destino D JOIN Viagem V ON D.viagem_codigo = V.codigo",
        "D.codigo", 
        codigo.GetCodigo()
    );
    sqlite3* db = DatabaseManager::getInstance().getConnection();
    sqlite3_stmt* stmt;
    
    string checkAtividades = "SELECT COUNT(*) FROM Atividade WHERE destino_codigo = ?;";
    if (sqlite3_prepare_v2(db, checkAtividades.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        throw runtime_error("Falha ao verificar atividades: " + string(sqlite3_errmsg(db)));
    }
    sqlite3_bind_text(stmt, 1, codigo.GetCodigo().c_str(), -1, SQLITE_STATIC);
    if (sqlite3_step(stmt) != SQLITE_ROW) {
        sqlite3_finalize(stmt);
        throw runtime_error("Erro na consulta de atividades");
    }
    int countAtividades = sqlite3_column_int(stmt, 0);
    sqlite3_finalize(stmt);

    string checkHospedagens = "SELECT COUNT(*) FROM Hospedagem WHERE destino_codigo = ?;";
    if (sqlite3_prepare_v2(db, checkHospedagens.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        throw runtime_error("Falha ao verificar hospedagens: " + string(sqlite3_errmsg(db)));
    }
    sqlite3_bind_text(stmt, 1, codigo.GetCodigo().c_str(), -1, SQLITE_STATIC);
    if (sqlite3_step(stmt) != SQLITE_ROW) {
        sqlite3_finalize(stmt);
        throw runtime_error("Erro na consulta de hospedagens");
    }
    int countHospedagens = sqlite3_column_int(stmt, 0);
    sqlite3_finalize(stmt);

    if (countAtividades > 0 || countHospedagens > 0) {
        throw runtime_error("Destino possui atividades ou hospedagens associadas");
    }

    // Excluir destino
    string sql = "DELETE FROM Destino WHERE codigo = ?;";
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        throw runtime_error("Falha ao preparar exclusão (Destino): " + string(sqlite3_errmsg(db)));
    }
    sqlite3_bind_text(stmt, 1, codigo.GetCodigo().c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        sqlite3_finalize(stmt);
        throw runtime_error("Erro ao excluir Destino: " + string(sqlite3_errmsg(db)));
    }

    sqlite3_finalize(stmt);
    return true;
}

bool ContainerDestino::updateDestino(const Destino destino) {
    DatabaseManager::verifyEntityOwnership(
        "Destino D JOIN Viagem V ON D.viagem_codigo = V.codigo",
        "D.codigo", 
        destino.GetCodigo().GetCodigo()
    );
    sqlite3* db = DatabaseManager::getInstance().getConnection();
    sqlite3_stmt* stmt;

    string sql = "UPDATE Destino SET nome = ?, data_inicio = ?, data_termino = ?, avaliacao = ? WHERE codigo = ?;";
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        throw runtime_error("Falha ao preparar atualização (Destino): " + string(sqlite3_errmsg(db)));
    }

    sqlite3_bind_text(stmt, 1, destino.GetNome().GetNome().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, destino.GetDataInicio().GetData().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, destino.GetDataTermino().GetData().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 4, destino.GetAvaliacao().GetAvaliacao());
    sqlite3_bind_text(stmt, 5, destino.GetCodigo().GetCodigo().c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        sqlite3_finalize(stmt);
        throw runtime_error("Erro ao atualizar Destino: " + string(sqlite3_errmsg(db)));
    }

    sqlite3_finalize(stmt);
    return true;
}

bool ContainerAtividade::createAtividade(Atividade atividade, Codigo destino_codigo) {
    DatabaseManager::verifyEntityOwnership(
        "Destino D JOIN Viagem V ON D.viagem_codigo = V.codigo",
        "D.codigo", 
        destino_codigo.GetCodigo()
    );
    sqlite3* db = DatabaseManager::getInstance().getConnection();
    sqlite3_stmt* stmt;
    string sql = "INSERT INTO Atividade (codigo, nome, data, horario, duracao, preco, avaliacao, destino_codigo) VALUES (?, ?, ?, ?, ?, ?, ?, ?);";
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        throw runtime_error("Falha ao preparar o statement (Atividade): " + string(sqlite3_errmsg(db)));
    }

    sqlite3_bind_text(stmt, 1, atividade.GetCodigo().GetCodigo().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, atividade.GetNome().GetNome().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, atividade.GetData().GetData().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, atividade.GetHorario().GetHora().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 5, atividade.GetDuracao().GetDuracao());
    sqlite3_bind_text(stmt, 6, atividade.GetPreco().GetDinheiro().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 7, atividade.GetAvaliacao().GetAvaliacao());
    sqlite3_bind_text(stmt, 8, destino_codigo.GetCodigo().c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        sqlite3_finalize(stmt);
        throw runtime_error("Erro ao inserir Atividade: " + string(sqlite3_errmsg(db)));
    }

    sqlite3_finalize(stmt);
    return true;
}

bool ContainerAtividade::readAtividade(Atividade* atividade) {
    DatabaseManager::verifyEntityOwnership(
        "Atividade A JOIN Destino D ON A.destino_codigo = D.codigo JOIN Viagem V ON D.viagem_codigo = V.codigo",
        "A.codigo", 
        atividade->GetCodigo().GetCodigo()
    );

    sqlite3* db = DatabaseManager::getInstance().getConnection();
    sqlite3_stmt* stmt;

    string sql = "SELECT * FROM Atividade WHERE codigo = ?;";
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        throw runtime_error("Falha ao preparar consulta (Atividade): " + string(sqlite3_errmsg(db)));
    }

    sqlite3_bind_text(stmt, 1, atividade->GetCodigo().GetCodigo().c_str(), -1, SQLITE_STATIC);
    int rc = sqlite3_step(stmt);

    if (rc == SQLITE_ROW) {
        Nome nome;
        nome.SetNome(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        atividade->SetNome(nome);
        Data data;
        data.SetData(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
        atividade->SetData(data);
        Horario horario;
        horario.SetHora(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
        atividade->SetHorario(horario);
        Duracao duracao;
        duracao.SetDuracao(sqlite3_column_int(stmt, 4));
        atividade->SetDuracao(duracao);
        Dinheiro preco;
        preco.SetDinheiro(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)));
        atividade->SetPreco(preco);
        Avaliacao avaliacao;
        avaliacao.SetAvaliacao(sqlite3_column_int(stmt, 6));
        atividade->SetAvaliacao(avaliacao);
        sqlite3_finalize(stmt);
        return true;
    }

    sqlite3_finalize(stmt);
    return false;
}

bool ContainerAtividade::deleteAtividade(Codigo codigo) {
    DatabaseManager::verifyEntityOwnership(
        "Atividade A JOIN Destino D ON A.destino_codigo = D.codigo JOIN Viagem V ON D.viagem_codigo = V.codigo",
        "A.codigo", 
        codigo.GetCodigo()
    );
    sqlite3* db = DatabaseManager::getInstance().getConnection();
    sqlite3_stmt* stmt;

    string sql = "DELETE FROM Atividade WHERE codigo = ?;";
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        throw runtime_error("Falha ao preparar exclusão (Atividade): " + string(sqlite3_errmsg(db)));
    }

    sqlite3_bind_text(stmt, 1, codigo.GetCodigo().c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        sqlite3_finalize(stmt);
        throw runtime_error("Erro ao excluir Atividade: " + string(sqlite3_errmsg(db)));
    }

    sqlite3_finalize(stmt);
    return true;
}

bool ContainerAtividade::updateAtividade(const Atividade atividade) {
    DatabaseManager::verifyEntityOwnership(
        "Atividade A JOIN Destino D ON A.destino_codigo = D.codigo JOIN Viagem V ON D.viagem_codigo = V.codigo",
        "A.codigo", 
        atividade.GetCodigo().GetCodigo()
    );
    sqlite3* db = DatabaseManager::getInstance().getConnection();
    sqlite3_stmt* stmt;

    string sql = "UPDATE Atividade SET nome = ?, data = ?, horario = ?, duracao = ?, preco = ?, avaliacao = ? WHERE codigo = ?;";
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        throw runtime_error("Falha ao preparar atualização (Atividade): " + string(sqlite3_errmsg(db)));
    }

    sqlite3_bind_text(stmt, 1, atividade.GetNome().GetNome().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, atividade.GetData().GetData().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, atividade.GetHorario().GetHora().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 4, atividade.GetDuracao().GetDuracao());
    sqlite3_bind_text(stmt, 5, atividade.GetPreco().GetDinheiro().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 6, atividade.GetAvaliacao().GetAvaliacao());
    sqlite3_bind_text(stmt, 7, atividade.GetCodigo().GetCodigo().c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        sqlite3_finalize(stmt);
        throw runtime_error("Erro ao atualizar Atividade: " + string(sqlite3_errmsg(db)));
    }

    sqlite3_finalize(stmt);
    return true;
}

bool ContainerHospedagem::createHospedagem(Hospedagem hospedagem, Codigo destino_codigo) {
    DatabaseManager::verifyEntityOwnership(
        "Destino D JOIN Viagem V ON D.viagem_codigo = V.codigo",
        "D.codigo", 
        destino_codigo.GetCodigo()
    );

    sqlite3* db = DatabaseManager::getInstance().getConnection();
    sqlite3_stmt* stmt;

    string sql = 
        "INSERT INTO Hospedagem (codigo, nome, diaria, avaliacao, destino_codigo) "
        "VALUES (?, ?, ?, ?, ?);";

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        throw runtime_error("Falha ao preparar inserção (Hospedagem): " + string(sqlite3_errmsg(db)));
    }

    sqlite3_bind_text(stmt, 1, hospedagem.GetCodigo().GetCodigo().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, hospedagem.GetNome().GetNome().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, hospedagem.GetDiaria().GetDinheiro().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 4, hospedagem.GetAvaliacao().GetAvaliacao());
    sqlite3_bind_text(stmt, 5, destino_codigo.GetCodigo().c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        sqlite3_finalize(stmt);
        throw runtime_error("Erro ao inserir Hospedagem: " + string(sqlite3_errmsg(db)));
    }

    sqlite3_finalize(stmt);
    return true;
}

bool ContainerHospedagem::readHospedagem(Hospedagem* hospedagem) {
    DatabaseManager::verifyEntityOwnership(
        "Hospedagem H JOIN Destino D ON H.destino_codigo = D.codigo JOIN Viagem V ON D.viagem_codigo = V.codigo",
        "H.codigo", 
        hospedagem->GetCodigo().GetCodigo()
    );

    sqlite3* db = DatabaseManager::getInstance().getConnection();
    sqlite3_stmt* stmt;

    string sql = "SELECT nome, diaria, avaliacao FROM Hospedagem WHERE codigo = ?;";
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        throw runtime_error("Falha ao preparar consulta (Hospedagem): " + string(sqlite3_errmsg(db)));
    }

    sqlite3_bind_text(stmt, 1, hospedagem->GetCodigo().GetCodigo().c_str(), -1, SQLITE_STATIC);
    int rc = sqlite3_step(stmt);

    if (rc == SQLITE_ROW) {
        Nome nome;
        nome.SetNome(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
        hospedagem->SetNome(nome);

        Dinheiro diaria;
        diaria.SetDinheiro(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        hospedagem->SetDiaria(diaria);

        Avaliacao avaliacao;
        avaliacao.SetAvaliacao(sqlite3_column_int(stmt, 2));
        hospedagem->SetAvaliacao(avaliacao);

        sqlite3_finalize(stmt);
        return true;
    }

    sqlite3_finalize(stmt);
    return false;
}

bool ContainerHospedagem::deleteHospedagem(Codigo codigo) {
    DatabaseManager::verifyEntityOwnership(
        "Hospedagem H JOIN Destino D ON H.destino_codigo = D.codigo JOIN Viagem V ON D.viagem_codigo = V.codigo",
        "H.codigo", 
        codigo.GetCodigo()
    );

    sqlite3* db = DatabaseManager::getInstance().getConnection();
    sqlite3_stmt* stmt;

    string sql = "DELETE FROM Hospedagem WHERE codigo = ?;";
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        throw runtime_error("Falha ao preparar exclusão (Hospedagem): " + string(sqlite3_errmsg(db)));
    }

    sqlite3_bind_text(stmt, 1, codigo.GetCodigo().c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        sqlite3_finalize(stmt);
        throw runtime_error("Erro ao excluir Hospedagem: " + string(sqlite3_errmsg(db)));
    }

    sqlite3_finalize(stmt);
    return true;
}

bool ContainerHospedagem::updateHospedagem(const Hospedagem hospedagem) {
    DatabaseManager::verifyEntityOwnership(
        "Hospedagem H JOIN Destino D ON H.destino_codigo = D.codigo JOIN Viagem V ON D.viagem_codigo = V.codigo",
        "H.codigo", 
        hospedagem.GetCodigo().GetCodigo()
    );

    sqlite3* db = DatabaseManager::getInstance().getConnection();
    sqlite3_stmt* stmt;

    string sql = 
        "UPDATE Hospedagem SET nome = ?, diaria = ?, avaliacao = ? "
        "WHERE codigo = ?;";

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        throw runtime_error("Falha ao preparar atualização (Hospedagem): " + string(sqlite3_errmsg(db)));
    }

    sqlite3_bind_text(stmt, 1, hospedagem.GetNome().GetNome().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, hospedagem.GetDiaria().GetDinheiro().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 3, hospedagem.GetAvaliacao().GetAvaliacao());
    sqlite3_bind_text(stmt, 4, hospedagem.GetCodigo().GetCodigo().c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        sqlite3_finalize(stmt);
        throw runtime_error("Erro ao atualizar Hospedagem: " + string(sqlite3_errmsg(db)));
    }

    sqlite3_finalize(stmt);
    return true;
}