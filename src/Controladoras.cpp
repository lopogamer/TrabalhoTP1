#include "Controladoras.h"
#include "Dominios.h"
#include "Entidade.h"
using namespace std;

void CntrControleAcesso::iniciarControle()
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
void CntrICA::criarConta()
{
}

void CntrICA::executar(Codigo)
{
}

void CntrIVA::executar(Codigo)
{
}

bool CntrICS::criarConta(const Conta)
{
}

bool CntrICS::excluirConta(const Codigo)
{
}

bool CntrICS::lerConta(Conta*)
{
}

bool CntrICS::atualizarConta(const Conta)
{
}

bool CntrIVS::criarViagem(const Viagem)
{
}

bool CntrIVS::excluirViagem(const Codigo)
{
}

bool CntrIVS::lerViagem(Viagem*)
{
}

bool CntrIVS::atualizarViagem(const Viagem)
{
}

bool CntrIVS::criarHospedagem(const Hospedagem)
{
}

bool CntrIVS::excluirHospedagem(const Codigo)
{
}

bool CntrIVS::lerHospedagem(Hospedagem*)
{
}

bool CntrIVS::atualizarHospedagem(const Hospedagem)
{
}

bool CntrIVS::criarDestino(const Destino)
{
}

bool CntrIVS::excluirDestino(const Codigo)
{
}

bool CntrIVS::lerDestino(Destino*)
{
}

bool CntrIVS::atualizarDestino(const Destino)
{
}

bool CntrIVS::criarAtividade(const Atividade)
{
}

bool CntrIVS::excluirAtividade(const Codigo)
{
}

bool CntrIVS::lerAtividade(Atividade*)
{
}

bool CntrIVS::atualizarAtividade(const Atividade)
{
}

bool CntrIAS::autenticarConta(const Conta)
{
}


