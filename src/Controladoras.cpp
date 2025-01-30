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


void CntrControleAcesso::iniciarControle()
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
                        SessionManager::getInstance()->setCodigo(codigoUsuario);
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
            }
            case 3: {
                cout << "Saindo do controle de acesso..." << endl;
                exit(0);
            }
        }
    }catch(exception &exp){
        cerr << "Erro: " << exp.what() << endl;
    }
    }
}

bool CntrIAS::autenticarConta(Conta conta) {
    ContainerConta containerConta;
    Conta contaUX;
    Codigo codigo;
    codigo.SetCodigo(conta.GetCodigo().GetCodigo());
    contaUX.SetCodigo(codigo);
    containerConta.readConta(&contaUX);
    if(conta.GetSenha().GetSenha() == contaUX.GetSenha().GetSenha()){
        return true;
    }else{
        return false;
    }
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
            Conta conta;
            conta.SetCodigo(*codigo);
            conta.SetSenha(senha);
            if (cntrServicoAutenticacao->autenticarConta(conta)) {
                cout << "Autenticação realizada com sucesso!" << endl;
                return true;
            } else {
                cout << "Falha na autenticação. Código ou senha inválidos. Tente novamente." << endl;
            }
            break;
        } catch (const std::exception& e) {
            cerr << "Erro: " << e.what() << '\n';
        }
    }
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
    string entrada;
    Viagem novaViagem;

    while(true){
        try{
            cout << endl << "Menu de criação de viagem" << endl;

            cout << "Digite o código da nova viagem: ";
            cin >> entrada;
            Codigo codigo;
            codigo.SetCodigo(entrada);
            novaViagem.SetCodigo(codigo);

            cout << "Digite o nome da nova viagem: ";
            cin >> entrada;
            Nome nome;
            nome.SetNome(entrada);
            novaViagem.SetNome(nome);

            cout << "Digite a avaliação da nova viagem: ";
            cin >> entrada;
            Avaliacao avaliacao;
            avaliacao.SetAvaliacao(stoi(entrada));
            novaViagem.SetAvaliacao(avaliacao);

            if(cntrServicoViagem->criarViagem(novaViagem)){
                cout << "Viagem criada com sucesso!" << endl;
                break;
            }else{
                cout << "Falha ao criar viagem. Tente novamente." << endl;
            }

        }catch(const invalid_argument &e){
            cout << "Erro ao criar viagem: " << e.what() << endl;
        }catch(const exception &e){
            cout << "Erro inesperado: " << e.what() << endl;
        }
    }

}

void CntrIVA::menuExcluirViagem(){ //A
    string entrada;
    Codigo codigo;
    while(true){
        try{
            cout << endl << "Menu de exclusão de viagem" << endl;

            cout << "Digite o código da viagem que deseja excluir: ";
            cin >> entrada;
            codigo.SetCodigo(entrada);

            if(cntrServicoViagem->excluirViagem(codigo)){
                cout << "Viagem excluída com sucesso!" << endl;
                break;
            }else{
                cout << "Falha ao excluir viagem. Tente novamente." << endl;
            }
        }catch(const invalid_argument &e){
            cout << "Erro ao excluir viagem: " << e.what() << endl;
        }catch(const exception &e){
            cout << "Erro inesperado: " << e.what() << endl;
        }
    }
}

void CntrIVA::menuLerViagem(){ //A
    string entrada;
    Codigo codigo;
    Viagem viagem;
    while(true){
        try{
            cout << endl << "Menu de leitura de viagem" << endl;

            cout << "Digite o código da viagem que deseja ler: ";
            cin >> entrada;
            codigo.SetCodigo(entrada);
            viagem.SetCodigo(codigo);

            if(cntrServicoViagem->lerViagem(&viagem)){
                cout << "Viagem lida com sucesso!" << endl;
                cout << "Código: " << viagem.GetCodigo().GetCodigo() << endl;
                cout << "Nome: " << viagem.GetNome().GetNome() << endl;
                cout << "Avaliação: " << viagem.GetAvaliacao().GetAvaliacao() << endl;
                break;
            }else{
                cout << "Falha ao ler viagem. Viagem já existente. Tente novamente." << endl;
            }
        }catch(const invalid_argument &e){
            cout << "Erro ao ler viagem: " << e.what() << endl;
        }catch(const exception &e){
            cout << "Erro inesperado: " << e.what() << endl;
        }
    }

}

void CntrIVA::menuAtualizarViagem(){ //A
    string entrada;
    Viagem viagem;
    while(true){
        try{
            cout << endl << "Menu de atualização de viagem" << endl;

            cout << "Digite o código da viagem que deseja atualizar: ";
            cin >> entrada;
            Codigo codigo;
            codigo.SetCodigo(entrada);
            viagem.SetCodigo(codigo);

            cout << "Digite o novo nome da viagem: ";
            cin >> entrada;
            Nome nome;
            nome.SetNome(entrada);
            viagem.SetNome(nome);

            cout << "Digite a nova avaliação da viagem: ";
            cin >> entrada;
            Avaliacao avaliacao;
            avaliacao.SetAvaliacao(stoi(entrada));
            viagem.SetAvaliacao(avaliacao);

            if(cntrServicoViagem->atualizarViagem(viagem)){
                cout << "Viagem atualizada com sucesso!" << endl;
                break;
            }else{
                cout << "Falha ao atualizar viagem. Tente novamente." << endl;
            }
        }catch(const invalid_argument &e){
            cout << "Erro ao atualizar viagem: " << e.what() << endl;
        }catch(const exception &e){
            cout << "Erro inesperado: " << e.what() << endl;
        }
    }

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
            cout << "Digite o codigo da Viagem ao qual a hospedagem pertence: ";
            cin >> entrada;
            Codigo codigoViagem;
            codigoViagem.SetCodigo(entrada);

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


            if (cntrServicoViagem->criarHospedagem(novaHospedagem, codigoViagem)) {
                cout << "Hospedagem criada com sucesso!" << endl;
                break;
            } else {
                cout << "Falha ao criar hospedagem." << endl;
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
    string entrada;
    Destino novoDestino;

    Codigo codigoViagem;
    Viagem viagem;

    while(true){
        try{
        cout << endl << "Menu de criação de destino" << endl;

        cout << "Dige o código da viagem: ";
        cin >> entrada;
        codigoViagem.SetCodigo(entrada);
        viagem.SetCodigo(codigoViagem);

        if (not(cntrServicoViagem->lerViagem(&viagem))){
            cout << "Viagem não encontrada. Tente novamente." << endl;
            continue;
        }else{
            cout << "Digite o código do destino: ";
            cin >> entrada;
            Codigo codigo;
            codigo.SetCodigo(entrada);
            novoDestino.SetCodigo(codigo);

            cout << "Digite o nome do destino: ";
            cin >> entrada;
            Nome nome;
            nome.SetNome(entrada);
            novoDestino.SetNome(nome);

            cout << "Digite a data de início do destino: ";
            cin >> entrada;
            Data dataInicio;
            dataInicio.SetData(entrada);

            cout << "Digite a data de término do destino: ";
            cin >> entrada;
            Data dataTermino;
            dataTermino.SetData(entrada);

            if(cntrServicoViagem->criarDestino(novoDestino, codigoViagem)){
                cout << "Destino criado com sucesso!" << endl;
                break;
            }else{
                cout << "Falha ao criar destino. Destino já existente. Tente novamente." << endl;
            }
        }
        }catch(const invalid_argument &e){
            cout << "Erro ao criar destino: " << e.what() << endl;
        }catch(const exception &e){
            cout << "Erro inesperado: " << e.what() << endl;
        }
    }
}

void CntrIVA::menuExcluirDestino(){ //A
    string entrada;
    Codigo codigo;
    while(true){
        try{
        cout << endl << "Menu de exclusão de destino" << endl;
        cout << "Digite o código do destino que deseja excluir: ";
        cin >> entrada;
        codigo.SetCodigo(entrada);
        if(cntrServicoViagem->excluirDestino(codigo)){
            cout << "Destino excluído com sucesso!" << endl;
            break;
        }else{
            cout << "Falha ao excluir destino. Destino não existente. Tente novamente." << endl;
        }
        }catch(const invalid_argument &e){
            cout << "Erro ao excluir destino: " << e.what() << endl;
        }catch(const exception &e){
            cout << "Erro inesperado: " << e.what() << endl;
        }
    }

}

void CntrIVA::menuLerDestino(){ //A
    string entrada;
    Codigo codigo;
    Destino destino;
    while(true){
        try{
        cout << endl << "Menu de leitura de destino" << endl;
        cout << "Digite o código do destino que deseja ler: ";
        cin >> entrada;
        codigo.SetCodigo(entrada);
        destino.SetCodigo(codigo);

        if(cntrServicoViagem->lerDestino(&destino)){
            cout << "Destino lido com sucesso!" << endl;
            cout << "Código: " << destino.GetCodigo().GetCodigo() << endl;
            cout << "Nome: " << destino.GetNome().GetNome() << endl;
            cout << "Data de início: " << destino.GetDataInicio().GetData() << endl;
            cout << "Data de término: " << destino.GetDataTermino().GetData() << endl;
            break;
        }else{
            cout << "Falha ao ler destino. Destino não existente. Tente novamente." << endl;
        }
        }catch(const invalid_argument &e){
            cout << "Erro ao ler destino: " << e.what() << endl;
        }catch(const exception &e){
            cout << "Erro inesperado: " << e.what() << endl;
    }
}

}

void CntrIVA::menuAtualizarDestino(){ //A
    string entrada;
    Destino destino;
    while(true){
        try{
        cout << endl << "Menu de atualização de destino" << endl;
        cout << "Digite o código do destino que deseja atualizar: ";
        cin >> entrada;
        Codigo codigo;
        codigo.SetCodigo(entrada);
        destino.SetCodigo(codigo);

        cout << "Digite o novo nome do destino: ";
        cin >> entrada;
        Nome nome;
        nome.SetNome(entrada);
        destino.SetNome(nome);

        cout << "Digite a nova data de início do destino: ";
        cin >> entrada;
        Data dataInicio;
        dataInicio.SetData(entrada);
        destino.SetDataInicio(dataInicio);

        cout << "Digite a nova data de término do destino: ";
        cin >> entrada;
        Data dataTermino;
        dataTermino.SetData(entrada);
        destino.SetDataTermino(dataTermino);

        if(cntrServicoViagem->atualizarDestino(destino)){
            cout << "Destino atualizado com sucesso!" << endl;
            break;
        }else{
            cout << "Falha ao atualizar destino. Tente novamente." << endl;
        }
        }catch(const invalid_argument &e){
            cout << "Erro ao atualizar destino: " << e.what() << endl;
        }catch(const exception &e){
            cout << "Erro inesperado: " << e.what() << endl;
        }
    }

}


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

bool CntrIVS::criarHospedagem(Hospedagem hospedagem, Codigo codigo)
{
    ContainerHospedagem containerHospedagem;
    bool resultado = containerHospedagem.createHospedagem(hospedagem, codigo);
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


bool CntrIVS::criarDestino(Destino destino, Codigo codigo)
{
    ContainerDestino containerDestino;
    bool resultado = containerDestino.createDestino(destino, codigo);
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

bool CntrIVS::criarAtividade(Atividade atividade, Codigo codigo)
{
    ContainerAtividade containerAtividade;
    bool resultado = containerAtividade.createAtividade(atividade, codigo);
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
