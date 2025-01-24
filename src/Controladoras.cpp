#include "Controladoras.h"
#include "Dominios.h"
#include "Entidade.h"
using namespace std;

void CntrControleAcesso::iniciarControle() // Alan
{
    return;
}

bool CntrIAS::autenticarConta(const Conta conta)
{
}

bool CntrIAA::autenticar(Codigo *codigo) {
    Senha senha;
    string entrada;
    while (true) {
        cout << endl << "----Autenticação do Usuário----" << endl;
        try {
            cout << "Digite o código da conta: ";
            cin >> entrada;
            codigo->SetCodigo(entrada); // Pode lançar exceção.

            cout << "Digite a senha: ";
            cin >> entrada;
            senha.SetSenha(entrada); // Pode lançar exceção.
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
    return;
}
void CntrICA::executar(Codigo codigo) // L
{
    return;
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
