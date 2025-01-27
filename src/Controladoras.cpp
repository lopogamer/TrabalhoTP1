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
    int opcao;
        while (true) {
            try {
                cout << "--------------------------------" << endl;
                cout << "----Interface de Conta----" << endl;
                cout << "1 - Criar Conta" << endl;
                cout << "2 - Excluir Conta" << endl;
                cout << "3 - Ler Conta" << endl;
                cout << "4 - Atualizar Conta" << endl;

                cout << "--------------------------------" << endl;
                cout << "5 - Sair para a tela incial" << endl;

                cout << "Digite a opção desejada: "
                cin >> opcao;

                Conta NovaConta;
                Codigo CodigoConta;
                Conta conta;

                switch (opcao) {
                    case 1: {
                        if (setCntrServicoConta->criarConta(NovaConta))
                            cout <<"Conta criada com sucesso!!!" << endl;
                        break;
                    }    
                    case 2: {
                        if(setCntrServicoConta->excluirConta(CodigoConta))
                            cout <<"Conta criada com sucesso!!!" << endl;
                        break;
                    }
                    case 3: {
                        if(setCntrServicoConta->lerConta(&conta))
                            cout <<"Conta lida com sucesso!!!" << endl;
                        break;
                    }
                    case 4: {
                        if(setCntrServicoConta->atualizarConta(conta))
                            cout <<"Conta atualizada com sucesso!!!" << endl;
                        break;
                    }
                    case 5: {
                        cout << "Saindo da interface de conta..." << endl;
                        return;
                    }

                    default: {
                        cout << "Opção inválida. Tente novamente." <<endl;
                        break;
                    }    
                       
                }          
                    
                
            }catch (invalid_argument &exp) {
            cerr << "Erro: " << exp.what() << endl;
            }
        }
}
void CntrIVA::executar(Codigo codigo) // A
{

}
bool CntrICS::criarConta(const Conta conta) //J
{
}
bool CntrICS::excluirConta(const Codigo codigo) // L
{
    try{
        if(containerConta.remove(codigo)){
            return true;
        }
        else{
            return false;
        }
    }
    catch(invalid_argument &exp){
        cerr << "Erro ao excluir conta: " << exp.what() << endl;
        return false;
    }
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
