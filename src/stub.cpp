#include "stub.h"
#include "Entidade.h"

using namespace std;

bool StubIAS::autenticarConta(Conta conta){
    cout << "StubIAS::autenticar" << endl;
    cout << "Codigo: " << conta.GetCodigo().GetCodigo() << endl;
    cout << "Senha: " << conta.GetSenha().GetSenha() << endl;

    if (conta.GetCodigo().GetCodigo() == TRIGGER_FALHA)
    {
        return false;
    }
    return true;

}
