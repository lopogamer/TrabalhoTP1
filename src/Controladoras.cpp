#include "Controladoras.h"
#include "Containers.h"
#include "sqlite3.h"
#include "Dominios.h"
#include "Entidade.h"
#include "Interfaces.h"
#include "Containers.h"
#include "sqlite3.h"
#include <string>
#include <iostream>
using namespace std;


void CntrControleAcesso::iniciarControle() // Alan
{
    int opcao;
    Codigo codigoUsuario;
    IAutenticacaoApresentacao *cntrIAA = new CntrIAA();
    IAutenticacaoServico *cntrIAS = new CntrIAS();
    cntrIAA->setCntrServicoAutenticacao(cntrIAS);
    IContaApresentacao *cntrICA = new CntrICA();
    IContaServico *cntrICS = new CntrICS();
    cntrICA->setCntrServicoConta(cntrICS);
    IViagemApresetacao *cntrIVA = new CntrIVA();
    IViagemServico *cntrIVS = new CntrIVS();
    cntrIVA->setCntrServicoViagem(cntrIVS);
    while (true) {
        try{
        cout << "----Controle de Acesso----" << endl;
        cout << "1 - Acessar Conta" << endl;
        cout << "2 - Criar Conta" << endl;
        cout << "3 - Sair" << endl;
        cout << "Digite a opção desejada: ";
        cin >> opcao;
        switch(opcao){
            case 1: {
                    if (cntrIAA->autenticar(&codigoUsuario))
                    {
                        cntrIVA->executar(codigoUsuario);
                    }else
                    {
                        cout << "Falha na Autenticaçao" << endl;
                    }
                break;
            }
            case 2: {
                if(cntrICA->criarConta())
                    cout << "Conta criada com sucesso!" << endl;
                    cntrICA->executar(&codigoUsuario);
                    break;
            }
            case 3: {
                cout << "Saindo do controle de acesso..." << endl;
                return;
            }
        }
    }catch(exception &exp){
        cerr << "Erro: " << exp.what() << endl;
    }
    }
}

bool CntrIAS::autenticarConta(Conta conta) {
    ContainerConta containerConta;
    bool autenticado = containerConta.readConta(&conta);    
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

bool CntrICA::criarConta()
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


void CntrICA::executar(Codigo *codigo) // L
{
    int opcao;
        while (true) {
            cout << "--------------------------------" << endl;
            cout << "----Interface de Conta----" << endl;
            cout << "1 - Criar Conta" << endl;
            cout << "2 - Excluir Conta" << endl;
            cout << "3 - Ler Conta" << endl;
            cout << "4 - Atualizar Conta" << endl;
            cout << "--------------------------------" << endl;
            cout << "5 - Sair para a tela incial" << endl;
            cout << "Digite a opção desejada: ";
            cin >> opcao;
            switch (opcao){
                case 1:
                    criarConta();
                    break;
                case 2:{
                    while(true){
                        try
                        {
                            
                        }
                        catch(const std::exception& e)
                        {
                            std::cerr << e.what() << '\n';
                        }
                        
                    }
                }
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    return;
            }
    }
}

void CntrIVA::executar(Codigo codigo) // A
{
    int opcao;
    string valor;
    int valorInt;
        while (true) {
            cout << endl << "--------------------------------" << endl;
            cout << "---- Escolha o Menu ----" << endl;
            cout << "1 - Viagem:" << endl;
            cout << "2-  Hospedagem:" << endl;
            cout << "3 - Destino:" << endl;
            cout << "4 - Atividade:" << endl;
            cout << "5 - Sair para a tela inicial" << endl;
            cout << "Digite a opção desejada: ";
            cin >> opcao;
            switch (opcao){
                case 1:
                    menuViagem();
                    break;
                case 2:
                    menuHospedagem();
                    break;
                case 3:
                    menuDestino();
                    break;
                case 4:
                    menuAtividade();
                    break;
                case 5:
                    return;
            } 
        }
}


bool CntrICS::criarConta(const Conta conta)
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
bool CntrIVS::criarViagem(const Viagem viagem) // L
{
    ContainerViagem containerviagem;

    bool resultado = containerviagem.createViagem(viagem);
    return resultado;
}

bool CntrIVS::excluirViagem(Codigo codigo) // A
{

}

bool CntrIVS::lerViagem(Viagem* viagem) // J
{

}

bool CntrIVS::atualizarViagem( Viagem viagem) // L
{

}

bool CntrIVS::criarHospedagem( Hospedagem hospedagem) // A
{

}
bool CntrIVS::excluirHospedagem( Codigo codigo) // J
{

}
bool CntrIVS::lerHospedagem(Hospedagem* hospedagem) // L
{

}
bool CntrIVS::atualizarHospedagem( Hospedagem hospedagem) // L
{

}

bool CntrIVS::criarDestino( Destino destino) // A
{

}

bool CntrIVS::excluirDestino(Codigo codigo) // J
{
}
bool CntrIVS::lerDestino(Destino* destino) // L
{

}

bool CntrIVS::atualizarDestino( Destino destino) // A
{

}

bool CntrIVS::criarAtividade( Atividade) // J
{

}
bool CntrIVS::excluirAtividade( Codigo codigo) // L
{

}

bool CntrIVS::lerAtividade(Atividade* atividade) // A
{

}

bool CntrIVS::atualizarAtividade(Atividade atividade) // J
{

}
