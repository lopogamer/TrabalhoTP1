#include "Controladoras.h"
#include "Containers.h"
#include "sqlite3.h"
#include "Dominios.h"
#include "Entidade.h"
using namespace std;

void CntrControleAcesso::iniciarControle() 
{
}

bool CntrIAS::autenticarConta(const Conta conta) {
    sqlite3* db = DatabaseManager::getInstance().getConnection(); // Conexão com o banco de dados.
    sqlite3_stmt* stmt = nullptr; // Declaração de uma instrução SQL.
    bool autenticado = false; // Flag de autenticação.
    const string sql = "SELECT 1 FROM Conta WHERE codigo = ? AND senha = ?;"; // Consulta SQL.
    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr); // Prepara a consulta.
    if (rc != SQLITE_OK) { // Verifica se houve erro.
        cerr << "Erro ao preparar SQL: " << sqlite3_errmsg(db) << endl;
        return false;
    }
    string codigo = conta.GetCodigo().GetCodigo(); // Obtém o código da conta.
    string senha = conta.GetSenha().GetSenha(); // Obtém a senha da conta.
    sqlite3_bind_text(
        stmt,  // Declaração de instrução. usar stmt para referenciar.
        1,    // Número do parâmetro. 1 para o primeiro parâmetro. const string sql = "SELECT 1 FROM Conta WHERE codigo = **?** AND senha = ?;"
        codigo.c_str(),  // Valor do parâmetro. Código da conta.
        codigo.size(),  // Tamanho do valor do parâmetro. -1 para calcular automaticamente.
        SQLITE_TRANSIENT // Tipo do valor do parâmetro. SQLITE_TRANSIENT para copiar o valor. 
        );

    sqlite3_bind_text(stmt, 2, senha.c_str(), senha.size(), SQLITE_TRANSIENT);


    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {  // Verifica se a consulta retornou alguma linha. Se sim, a conta foi autenticada.
        autenticado = true;
    } else if (rc != SQLITE_DONE) { // Verifica se apenas a consulta terminou. Se não, houve erro. 
                                    //Se retonar SQLITE_DONE, significa que a consulta não retornou nenhuma linha.**
        cerr << "Erro ao executar consulta: " << sqlite3_errmsg(db) << endl;
    }
    sqlite3_finalize(stmt); // Finaliza a instrução.
    return autenticado;
}

bool CntrIAA::autenticar(Codigo *codigo) {
    Senha senha;
    string entrada;
    while (true) {
        cout << endl << "----Autenticação do Usuário----" << endl;
        try {
            cout << "Digite o código da conta: ";
            cin >> entrada;
            codigo->SetCodigo(entrada);

            cout << "Digite a senha: ";
            cin >> entrada;
            senha.SetSenha(entrada);
            break;
        } catch (const std::exception& e) {
            cerr << "Erro: " << e.what() << '\n';
        }
    }
    Conta conta;
    conta.SetCodigo(*codigo);
    conta.SetSenha(senha);
    return cntrServicoAutenticacao->autenticarConta(conta);
}
void CntrICA::criarConta() // J
{

}
void CntrICA::executar(Codigo codigo) // L
{
}
void CntrIVA::executar(Codigo codigo) // A
{
}
bool CntrICS::criarConta(const Conta conta) //J
{
}
bool CntrICS::excluirConta(const Codigo codigo) // L
{
}
bool CntrICS::lerConta(Conta* conta)//A
{
}
bool CntrICS::atualizarConta(const Conta conta) // J
{
}
bool CntrIVS::criarViagem(const Viagem) // L
{
}
bool CntrIVS::excluirViagem(const Codigo) // A
{
}
bool CntrIVS::lerViagem(Viagem*) // J
{
}
bool CntrIVS::atualizarViagem(const Viagem) // L
{
}
bool CntrIVS::criarHospedagem(const Hospedagem) // A
{
}
bool CntrIVS::excluirHospedagem(const Codigo) // J
{
}
bool CntrIVS::lerHospedagem(Hospedagem*) // L
{
}
bool CntrIVS::atualizarHospedagem(const Hospedagem) // L
{
}
bool CntrIVS::criarDestino(const Destino) // A
{
}
bool CntrIVS::excluirDestino(const Codigo) // J
{
}
bool CntrIVS::lerDestino(Destino*) // L
{
}
bool CntrIVS::atualizarDestino(const Destino) // A
{
}
bool CntrIVS::criarAtividade(const Atividade) // J
{
}
bool CntrIVS::excluirAtividade(const Codigo) // L
{
}
bool CntrIVS::lerAtividade(Atividade*) // A
{
}
bool CntrIVS::atualizarAtividade(const Atividade) // J
{
}
