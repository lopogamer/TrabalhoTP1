#include "Testes.h"
using namespace std;
#include <iostream>

void TUDinheiro::setUp()
{
    dinheiro = new Dinheiro();
    estado = SUCESSO;
}

void TUDinheiro::tearDown()
{
    delete dinheiro;
}

void TUDinheiro::TestarCasoValido()
{
    try{
        dinheiro->SetDinheiro(VALOR_VALIDO);
        if(dinheiro->GetDinheiro() != VALOR_VALIDO)
        {
            estado = FALHA;
        }
    }
    catch(invalid_argument  &e)
    {
        cout << "falhou no valor valido" << endl;
        estado = FALHA;
    }
}
void TUDinheiro::TestarCasoInvalido()
{
    try{
        dinheiro->SetDinheiro(VALOR_INVALIDO);
        cout << dinheiro->GetDinheiro() << endl;
        estado = FALHA;
    }
    catch(invalid_argument  &e)
    {
        if(dinheiro->GetDinheiro() == VALOR_INVALIDO)
        {
            estado = FALHA;
        }
    }
}

int TUDinheiro::run()
{
    setUp();
    TestarCasoValido();
    TestarCasoInvalido();
    tearDown();
    return estado;
}