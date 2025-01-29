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

void CntrIVA::menuViagem()
{
    int opcao;
    string valor;
    int valorInt;
        while (true) {
            cout << endl << "--------------------------------" << endl;
            cout << "----Menu Viagem----" << endl;
            cout << "1 - Criar Viagem" << endl;
            cout << "2 - Excluir Viagem" << endl;
            cout << "3 - Ler Viagem" << endl;
            cout << "4 - Atualizar Viagem" << endl;
            cout << "5 - Sair para o menu principal" << endl;
            cout << "Digite a opção desejada: ";
            cin >> opcao;
            switch (opcao){
                case 1:
                    menuCriarViagem();
                case 2:
                    menuExcluirViagem();
                case 3:
                    menuLerViagem();
                case 4:
                    menuAtualizarViagem();
                case 5:
                    return;
            } 
        }
}

void CntrIVA::menuCriarViagem(){ //A

}

void CntrIVA::menuExcluirViagem(){ //A

}

void CntrIVA::menuLerViagem(){ //A

}

void CntrIVA::menuAtualizarViagem(){ //A

}


void CntrIVA::menuHospedagem() //J
{
    int opcao;
    string valor;
    int valorInt;
        while (true) {
            cout << endl << "--------------------------------" << endl;
            cout << "----Menu Hospedagem----" << endl;
            cout << "1 - Criar Hospedagem" << endl;
            cout << "2 - Excluir Hospedagem" << endl;
            cout << "3 - Ler Hospedagem" << endl;
            cout << "4 - Atualizar Hospedagem" << endl;
            cout << "5 - Sair para o menu princpal" << endl;
            cout << "Digite a opção desejada: ";
            cin >> opcao;
            switch (opcao){
                case 1:
                    menuCriarHospedagem();
                case 2:
                    menuExcluirHospedagem();
                case 3:
                    menuLerHospedagem();
                case 4:
                    menuAtualizarHospedagem();
                case 5:
                    return;
            } 
        }
}

void CntrIVA::menuCriarHospedagem(){
    string entrada;
    int valor;
    Hospedagem novaHospedagem;

    while (true) {
        try {
            cout << "Digite o código da nova hospedagem: ";
            cin >> entrada;
            Codigo codigo;
            codigo.SetCodigo(entrada); 
            novaHospedagem.SetCodigo(codigo);

            cout << "Digite o nome da nova hospedagem: ";
            cin >> entrada;
            Nome nome;
            nome.SetNome(entrada); 
            novaHospedagem.SetNome(nome);

            cout << "Digite a diária da nova hospedagem: ";
            cin >> entrada;
            Dinheiro diaria;
            diaria.SetDinheiro(entrada); 
            novaHospedagem.SetDiaria(diaria);

            cout << "Digite a avaliação da nova hospedagem: ";
            cin >> valor;
            Avaliacao avaliacao;
            avaliacao.SetAvaliacao(valor);
            novaHospedagem.SetAvaliacao(avaliacao);


            if (cntrServicoViagem->criarHospedagem(novaHospedagem)) {
                cout << "Hospedagem criada com sucesso!" << endl;
                break;
            } else {
                cout << "Falha ao criar hospedagem. Código já existente. Tente novamente." << endl;
            }
        } catch (const invalid_argument &e) {
            cout << "Erro ao criar hospedagem: " << e.what() << endl;
        } catch (const exception &e) {
            cout << "Erro inesperado: " << e.what() << endl;
        }
    }

}

void CntrIVA::menuExcluirHospedagem(){
    string entrada;
    Codigo codigo;

    while (true) {
        try {
            cout << "Digite o código da hospedagem: ";
            cin >> entrada;
            codigo.SetCodigo(entrada);

            if (cntrServicoViagem->excluirHospedagem(codigo)) {
                cout << "Hospedagem excluída com sucesso!" << endl;
                break;
            } else {
                cout << "Falha ao excluir hospedagem. Código não encontrado. Tente novamente." << endl;
            }
        } catch (const invalid_argument &e) {
            cout << "Erro ao excluir hospedagem: " << e.what() << endl;
        } catch (const exception &e) {
            cout << "Erro inesperado: " << e.what() << endl;
        }
    }

}

void CntrIVA::menuLerHospedagem(){
    string entrada;
    Codigo codigo;
    Hospedagem hospedagem;

    while (true) {
        try {
            cout << "Digite o código da hospedagem: ";
            cin >> entrada;
            codigo.SetCodigo(entrada); 
            hospedagem.SetCodigo(codigo);

            if (cntrServicoViagem->lerHospedagem(&hospedagem)) {
                cout << "Hospedagem encontrada: " << endl;
                cout << "Código: " << hospedagem.GetCodigo().GetCodigo() << endl;
                cout << "Nome: " << hospedagem.GetNome().GetNome() << endl;
                cout << "Diária: " << hospedagem.GetDiaria().GetDinheiro() << endl;
                cout << "Avaliação: " << hospedagem.GetAvaliacao().GetAvaliacao() << endl;
                break; 
            } else {
                cout << "Falha ao ler hospedagem. Código não encontrado. Tente novamente." << endl;
            }
        } catch (const invalid_argument &e) {
            cout << "Erro ao ler hospedagem: " << e.what() << endl;
        } catch (const exception &e) {
            cout << "Erro inesperado: " << e.what() << endl;
        }
    }
    
}


void CntrIVA::menuAtualizarHospedagem(){
    string entrada;
    int valor;
    Hospedagem hospedagem;

    while (true) {
        try {
            cout << "Digite o novo código da hospedagem: ";
            cin >> entrada;
            Codigo codigo;
            codigo.SetCodigo(entrada); 
            hospedagem.SetCodigo(codigo);

            cout << "Digite o novo nome da hospedagem: ";
            cin >> entrada;
            Nome nome;
            nome.SetNome(entrada); 
            hospedagem.SetNome(nome);

            cout << "Digite a nova diária da hospedagem: ";
            cin >> entrada;
            Dinheiro diaria;
            diaria.SetDinheiro(entrada); 
            hospedagem.SetDiaria(diaria);

            cout << "Digite a nova avaliação da hospedagem: ";
            cin >> valor;
            Avaliacao avaliacao;
            avaliacao.SetAvaliacao(valor);
            hospedagem.SetAvaliacao(avaliacao);

            if (cntrServicoViagem->atualizarHospedagem(hospedagem)) {
                cout << "Hospedagem atualizada com sucesso!" << endl;
                break;
            } else {
                cout << "Falha ao atualizar hospedagem. Código não encontrado. Tente novamente." << endl;
            }
        } catch (const invalid_argument &e) {
            cout << "Erro ao atualizar hospedagem: " << e.what() << endl;
        } catch (const exception &e) {
            cout << "Erro inesperado: " << e.what() << endl;
        }
    }

}

//MENU DESTINO
void CntrIVA::menuDestino() //A
{
    int opcao;
    string valor;
    int valorInt;
        while (true) {
            cout << endl << "--------------------------------" << endl;
            cout << "----Menu Destino----" << endl;
            cout << "1 - Criar Destino" << endl;
            cout << "2 - Excluir Destino" << endl;
            cout << "3 - Ler Destino" << endl;
            cout << "4 - Atualizar Destino" << endl;
            cout << "5 - Sair para o menu principal" << endl;
            cout << "Digite a opção desejada: ";
            cin >> opcao;
            switch (opcao){
                case 1:
                    menuCriarDestino();
                case 2:
                    menuExcluirDestino();
                case 3:
                    menuLerDestino();
                case 4:
                    menuAtualizarDestino();
                case 5:
                    return;
            } 
        }
}

void CntrIVA::menuCriarDestino(){ //A

}

void CntrIVA::menuExcluirDestino(){ //A

}

void CntrIVA::menuLerDestino(){ //A

}

void CntrIVA::menuAtualizarDestino(){ //A

}


//MENU ATIVIDADE
void CntrIVA::menuAtividade() //L
{
    int opcao;
    string valor;
    int valorInt;
        while (true) {
            cout << endl << "--------------------------------" << endl;
            cout << "----Menu Atividade----" << endl;
            cout << "1 - Criar Atividade" << endl;
            cout << "2 - Excluir Atividade" << endl;
            cout << "3 - Ler Atividade" << endl;
            cout << "4 - Atualizar Atividade" << endl;
            cout << "5 - Sair para o menu principal" << endl;
            cout << "Digite a opção desejada: ";
            cin >> opcao;
            switch (opcao){
                case 1:
                    menuCriarAtividade();
                case 2:
                    menuExcluirAtividade();
                case 3:
                    menuLerAtividade();
                case 4:
                    menuAtualizarAtividade();
                case 5:
                    return;
            } 
        }
}

void CntrIVA::menuCriarAtividade(){ //L

}

void CntrIVA::menuExcluirAtividade(){ //L

}

void CntrIVA::menuLerAtividade(){ //L

}

void CntrIVA::menuAtualizarAtividade(){ //L

}

bool CntrICS::criarConta(const Conta conta)
{
    ContainerConta containerConta;
    bool resultado = containerConta.createConta(conta);
    return resultado;
}

bool CntrICS::excluirConta(const Codigo codigo)
{
    ContainerConta containerConta;
    bool resultado = containerConta.deleteConta(codigo);
    return resultado;
}

bool CntrICS::lerConta(Conta* conta)
{
    ContainerConta containerConta;
    bool resultado = containerConta.readConta(conta);
    return resultado;
}

bool CntrICS::atualizarConta(const Conta conta)
{
    ContainerConta containerConta;
    bool resultado = containerConta.updateConta(conta);
    return resultado;
}
bool CntrIVS::criarViagem(const Viagem viagem)
{
    ContainerViagem containerviagem;
    bool resultado = containerviagem.createViagem(viagem);
    return resultado;
}

bool CntrIVS::excluirViagem(Codigo codigo)
{
    ContainerViagem containerviagem;
    bool resultado = containerviagem.deleteViagem(codigo);
    return resultado;
}

bool CntrIVS::lerViagem(Viagem* viagem)
{
    ContainerViagem containerviagem;
    bool resultado = containerviagem.readViagem(viagem);
    return resultado;
}

bool CntrIVS::atualizarViagem( Viagem viagem)
{
    ContainerViagem containerviagem;
    bool resultado = containerviagem.updateViagem(viagem);
    return resultado;
}

bool CntrIVS::criarHospedagem( Hospedagem hospedagem)
{
    ContainerHospedagem containerHospedagem;
    bool resultado = containerHospedagem.createHospedagem(hospedagem);
    return resultado;
}

bool CntrIVS::excluirHospedagem( Codigo codigo)
{
    ContainerHospedagem containerHospedagem;
    bool resultado = containerHospedagem.deleteHospedagem(codigo);
    return resultado;
}

bool CntrIVS::lerHospedagem(Hospedagem* hospedagem)
{
    ContainerHospedagem containerHospedagem;
    bool resultado = containerHospedagem.readHospedagem(hospedagem);
    return resultado;
}

bool CntrIVS::atualizarHospedagem( Hospedagem hospedagem)
{
    ContainerHospedagem containerHospedagem;
    bool resultado = containerHospedagem.updateHospedagem(hospedagem);
    return resultado;
}

bool CntrIVS::criarDestino( Destino destino)
{
    ContainerDestino containerDestino;
    bool resultado = containerDestino.createDestino(destino);
    return resultado;
}

bool CntrIVS::excluirDestino(Codigo codigo)
{
    ContainerDestino containerDestino;
    bool resultado = containerDestino.deleteDestino(codigo);
    return resultado;
}
bool CntrIVS::lerDestino(Destino* destino)
{
    ContainerDestino containerDestino;
    bool resultado = containerDestino.readDestino(destino);
    return resultado;
}

bool CntrIVS::atualizarDestino(Destino destino)
{
    ContainerDestino containerDestino;
    bool resultado = containerDestino.updateDestino(destino);
    return resultado;
}

bool CntrIVS::criarAtividade(Atividade atividade)
{
    ContainerAtividade containerAtividade;
    bool resultado = containerAtividade.createAtividade(atividade);
    return resultado;

}

bool CntrIVS::excluirAtividade(Codigo codigo)
{
    ContainerAtividade containerAtividade;
    bool resultado = containerAtividade.deleteAtividade(codigo);
    return resultado;
}

bool CntrIVS::lerAtividade(Atividade* atividade)
{
    ContainerAtividade containerAtividade;
    bool resultado = containerAtividade.readAtividade(atividade);
    return resultado;

}

bool CntrIVS::atualizarAtividade(Atividade atividade)
{
    ContainerAtividade containerAtividade;
    bool resultado = containerAtividade.updateAtividade(atividade);
    return resultado;

}
