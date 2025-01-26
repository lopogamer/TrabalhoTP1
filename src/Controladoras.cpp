#include "Controladoras.h"
#include "Dominios.h"
#include "Entidade.h"
using namespace std;

void CntrControleAcesso::iniciarControle() // Alan
{
    int opcao;
    Codigo codigoUsuario;
    CntrIAA cntrIAA;
    CntrICA cntrICA;
    CntrIVA cntrIVA;

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
                if(cntrIAA.autenticar(&codigoUsuario))
                    cntrIVA.executar(codigoUsuario); //Indo para a interface de viagem
                break;
            }
            case 2: {
                if(cntrICA.criarConta())
                    cout << "Conta criada com sucesso!" << endl;
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
    int opcao;
        while (true) {
            try {
                cout << "--------------------------------" << endl;
                cout << "----Interface de Viagem----" << endl;
                cout << "Viagem:" << endl;
                cout << "1 - Criar Viagem" << endl;
                cout << "2 - Excluir Viagem" << endl;
                cout << "3 - Ler Viagem" << endl;
                cout << "4 - Atualizar Viagem" << endl;

                cout << "Hospedagem:" << endl;
                cout << "5 - Criar Hospedagem" << endl;
                cout << "6 - Excluir Hospedagem" << endl;
                cout << "7 - Ler Hospedagem" << endl;
                cout << "8 - Atualizar Hospedagem" << endl;

                cout << "Destino:" << endl;
                cout << "9 - Criar Destino" << endl;
                cout << "10 - Excluir Destino" << endl;
                cout << "11 - Ler Destino" << endl;
                cout << "12 - Atualizar Destino" << endl;

                cout << "Atividade:" << endl;
                cout << "13 - Criar Atividade" << endl;
                cout << "14 - Excluir Atividade" << endl;
                cout << "15 - Ler Atividade" << endl;
                cout << "16 - Atualizar Atividade" << endl;

                cout << "--------------------------------" << endl;
                cout << "17 - Sair para a tela inicial" << endl;

                cout << "Digite a opção desejada: ";
                cin >> opcao;

                Viagem NovaViagem;
                Codigo codigoViagem;
                Viagem viagem;
                Hospedagem hospedagem;
                Codigo codigoHospedagem;
                Destino destino;
                Codigo codigoDestino;
                Atividade atividade;
                Codigo codigoAtividade;

                switch (opcao) {
                    //Casos relacionados a viagem
                    case 1: {
                        if(cntrServicoViagem->criarViagem(NovaViagem))
                            cout << "Viagem criada com sucesso!" << endl;
                        break;
                    }
                    case 2: {
                        if (cntrServicoViagem->excluirViagem(codigoViagem))
                            cout << "Viagem excluída com sucesso!" << endl;
                        break;
                    }
                    case 3: {
                        if (cntrServicoViagem->lerViagem(&viagem))
                            cout << "Viagem lida com sucesso!" << endl;
                        break;
                    }
                    case 4: {
                        if (cntrServicoViagem->atualizarViagem(viagem))
                            cout << "Viagem atualizada com sucesso!" << endl;
                        break;
                    }

                    //Casos relacionados a hospedagem
                    case 5: {
                        if(cntrServicoViagem->criarHospedagem(hospedagem))
                            cout << "Hospedagem criada com sucesso!" << endl;
                        break;
                    }
                    case 6: {
                        if (cntrServicoViagem->excluirHospedagem(codigoHospedagem))
                            cout << "Hospedagem excluída com sucesso!" << endl;
                        break;
                    }
                    case 7: {
                        if (cntrServicoViagem->lerHospedagem(&hospedagem))
                            cout << "Hospedagem lida com sucesso!" << endl;
                        break;
                    }
                    case 8: {
                        if (cntrServicoViagem->atualizarHospedagem(hospedagem))
                            cout << "Hospedagem atualizada com sucesso!" << endl;
                        break;
                    }

                    //Casos relacionados a destino
                    case 9: {
                        if(cntrServicoViagem->criarDestino(destino));
                            cout << "Destino criado com sucesso!" << endl;
                        break;
                    }
                    case 10: {
                        if (cntrServicoViagem->excluirDestino(codigoDestino))
                            cout << "Destino excluído com sucesso!" << endl;
                        break;
                    }
                    case 11: {
                        if (cntrServicoViagem->lerDestino(&destino))
                            cout << "Destino lido com sucesso!" << endl;
                        break;
                    }
                    case 12: {
                        if (cntrServicoViagem->atualizarDestino(destino))
                            cout << "Destino atualizado com sucesso!" << endl;
                        break;
                    }

                    //Casos relacionados a atividade
                    case 13: {
                        if(cntrServicoViagem->criarAtividade(atividade))
                            cout << "Atividade criada com sucesso!" << endl;
                        break;
                    }
                    case 14: {
                        if (cntrServicoViagem->excluirAtividade(codigoAtividade))
                            cout << "Atividade excluída com sucesso!" << endl;
                        break;
                    }
                    case 15: {
                        if (cntrServicoViagem->lerAtividade(&atividade))
                            cout << "Atividade lida com sucesso!" << endl;
                        break;
                    }
                    case 16: {
                        if (cntrServicoViagem->atualizarAtividade(atividade))
                            cout << "Atividade atualizada com sucesso!" << endl;
                        break;
                    }

                    //Outros casos
                    case 17: {
                        cout << "Saindo da interface de viagem..." << endl;
                        return;
                    }
                    default: {
                        cout << "Opção inválida. Tente novamente." << endl;
                        break;
                    }
                }
            }catch (invalid_argument &exp) {
            cerr << "Erro: " << exp.what() << endl;
        } 
    }
}


bool CntrICS::criarConta(const Conta conta) //J
{
}
bool CntrICS::excluirConta(const Codigo codigo) // L
{
}

bool CntrICS::lerConta(Conta* conta)//A
{
    try{
        if(containerConta.read(conta)){
            return true;
        }
        else{
            return false;
        }
    }
    catch(invalid_argument &exp){
        cerr << "Erro ao ler conta: " << exp.what() << endl;
        return false;
    }
   
}


bool CntrICS::atualizarConta(const Conta conta) // J
{
}
bool CntrIVS::criarViagem(const Viagem) // L
{
}

bool CntrIVS::excluirViagem(const Codigo codigo) // A
{
    try{
        if(containerViagem.remove(codigo)){
            return true;
        }
        else{
            return false;
        }
    }
    catch(invalid_argument &exp){
        cerr << "Erro ao excluir viagem: " << exp.what() << endl;
        return false;
    }
}

bool CntrIVS::lerViagem(Viagem*) // J
{
}

bool CntrIVS::atualizarViagem(const Viagem viagem) // L
{

}

bool CntrIVS::criarHospedagem(const Hospedagem hospedagem) // A
{
    try{
        if(containerHospedagem.create(hospedagem)){
            return true;
        }
        else{
            return false;
        }
    }
    catch(invalid_argument &exp){
        cerr << "Erro ao criar hospedagem: " << exp.what() << endl;
        return false;
    }
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

bool CntrIVS::criarDestino(const Destino destino) // A
{
    try{
        if(containerDestino.create(destino)){
            return true;
        }
        else{
            return false;
        }
    }
    catch(invalid_argument &exp){
        cerr << "Erro ao criar destino: " << exp.what() << endl;
        return false;
    }
}

bool CntrIVS::excluirDestino(const Codigo) // J
{
}
bool CntrIVS::lerDestino(Destino*) // L
{
}

bool CntrIVS::atualizarDestino(const Destino destino) // A
{
    try{
        if(containerDestino.update(destino)){
            return true;
        }
        else{
            return false;
        }
    }
    catch(invalid_argument &exp){
        cerr << "Erro ao atualizar destino: " << exp.what() << endl;
        return false;
    }
}

bool CntrIVS::criarAtividade(const Atividade) // J
{
}
bool CntrIVS::excluirAtividade(const Codigo) // L
{
}

bool CntrIVS::lerAtividade(Atividade* atividade) // A
{
    try{
        if(containerAtividade.read(atividade)){
            return true;
        }
        else{
            return false;
        }
    }
    catch(invalid_argument &exp){
        cerr << "Erro ao ler atividade: " << exp.what() << endl;
        return false;
    }
}

bool CntrIVS::atualizarAtividade(const Atividade) // J
{

}
