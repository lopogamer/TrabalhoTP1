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

bool CntrIAS::autenticarConta(const Conta conta) {
    sqlite3* db = DatabaseManager::getInstance().getConnection(); // Conexão com o banco de dados.
    sqlite3_stmt* stmt = nullptr; // Declaração de uma instrução SQL.
    bool autenticado = false; // ‘Flag’ de autenticação.
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
        codigo.size(),  // Tamanho do valor do parâmetro. — 1 para calcular automaticamente.
        SQLITE_TRANSIENT // Tipo do valor do parâmetro. SQLITE_TRANSIENT para copiar o valor. 
        );

    sqlite3_bind_text(stmt, 2, senha.c_str(), senha.size(), SQLITE_TRANSIENT);


    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {  // Verifica se a consulta retornou alguma linha. Se sim, a conta foi autenticada.
        autenticado = true;
    } else if (rc != SQLITE_DONE) { // Verifica se apenas a consulta terminou. Se não, houve erro. 
                                    //Se retornar SQLITE_DONE, significa que a consulta não retornou nenhuma linha.**
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

bool CntrICA::criarConta() // J
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
            try {
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

                Conta NovaConta;
                Codigo CodigoConta;
                Conta conta;

                switch (opcao) {
                    case 1: {
                        if (setCntrServicoConta->)
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

}


bool CntrICS::atualizarConta(const Conta conta) // J
{

}
bool CntrIVS::criarViagem(const Viagem viagem) // L
{
}

bool CntrIVS::excluirViagem(const Codigo codigo) // A
{

}

bool CntrIVS::lerViagem(Viagem*) // J
{

}

bool CntrIVS::atualizarViagem(const Viagem viagem) // L
{

}

bool CntrIVS::criarHospedagem(const Hospedagem hospedagem) // A
{

}
bool CntrIVS::excluirHospedagem(const Codigo codigo) // J
{

}
bool CntrIVS::lerHospedagem(Hospedagem* hospedagem) // L
{

}
bool CntrIVS::atualizarHospedagem(const Hospedagem hospedagem) // L
{

}

bool CntrIVS::criarDestino(const Destino destino) // A
{

}

bool CntrIVS::excluirDestino(const Codigo) // J
{
}
bool CntrIVS::lerDestino(Destino* destino) // L
{

}

bool CntrIVS::atualizarDestino(const Destino destino) // A
{

}

bool CntrIVS::criarAtividade(const Atividade) // J
{

}
bool CntrIVS::excluirAtividade(const Codigo codigo) // L
{

}

bool CntrIVS::lerAtividade(Atividade* atividade) // A
{

}

bool CntrIVS::atualizarAtividade(const Atividade) // J
{

}
