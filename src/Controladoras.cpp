#include "Controladoras.h"
#include "Dominios.h"
#include "Entidade.h"
#include "Containers.h"
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
    string entrada;
    Conta novaConta;

    while (true) {
        try {
            cout << "Digite o código da nova conta: ";
            cin >> entrada;
            Codigo codigo;
            codigo.SetCodigo(entrada); 
            novaConta.SetCodigo(codigo);

            cout << "Digite a senha da nova conta: ";
            cin >> entrada;
            Senha senha;
            senha.SetSenha(entrada); 
            novaConta.SetSenha(senha);

            if (cntrServicoConta->criarConta(novaConta)) {
                cout << "Conta criada com sucesso!" << endl;
                break;
            } else {
                cout << "Falha ao criar conta. Código já existente. Tente novamente." << endl;
            }
        } catch (const invalid_argument &e) {
            cout << "Erro ao criar conta: " << e.what() << endl;
        } catch (const exception &e) {
            cout << "Erro inesperado: " << e.what() << endl;
        }
    }
    
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
    if(containerConta.create(conta)){
        return true;
    }
    else{
        return false;
    }
 
}
bool CntrICS::excluirConta(const Codigo codigo) // L
{
}
bool CntrICS::lerConta(Conta* conta)//A
{
}
bool CntrICS::atualizarConta(const Conta conta) // J
{
    if(containerConta.update(conta)){
        return true;
    }
    else{
        return false;
    } 
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
bool CntrIVS::excluirHospedagem(const Codigo codigo) // J
{
    if(containerHospedagem.remove(codigo)){
        return true;
    }
    else{
        return false;
    }
}
bool CntrIVS::lerHospedagem(Hospedagem*) // L
{
}
bool CntrIVS::atualizarHospedagem(const Hospedagem hospedagem) // L
{
    if(containerHospedagem.update(hospedagem)){
        return true;
    }
    else{
        return false;
    }
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
bool CntrIVS::criarAtividade(const Atividade atividade) // J
{
    if(containerAtividade.create(atividade)){
        return true;
    }
    else{
        return false;
    }
}
bool CntrIVS::excluirAtividade(const Codigo) // L
{
}
bool CntrIVS::lerAtividade(Atividade*) // A
{
}
bool CntrIVS::atualizarAtividade(const Atividade atividade) // J
{
    if(containerAtividade.update(atividade)){
        return true;
    }
    else{
        return false;
    }
}
