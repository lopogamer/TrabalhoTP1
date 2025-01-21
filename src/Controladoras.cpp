#include "Controladoras.h"
#include "Dominios.h"
#include "Entidade.h"
using namespace std;

bool CntrIAA::autenticar(Codigo *codigo) {
    if (codigo == nullptr) {
        throw std::invalid_argument("Ponteiro para Codigo é nulo.");
    }

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

    if (cntrServicoAutenticacao == nullptr) {
        throw std::runtime_error("Serviço de autenticação não inicializado.");
    }

    return cntrServicoAutenticacao->autenticarConta(conta);
}
