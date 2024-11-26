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
        estado = FALHA;
    }
}
void TUDinheiro::TestarCasoInvalido()
{
    try{
        dinheiro->SetDinheiro(VALOR_INVALIDO);
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

int TUDuracao::run(){
    setUp();
    TestarCasoValido();
    TestarCasoInvalido();
    tearDown();
    return estado;
}
void TUDuracao::setUp()
{
    duracao = new Duracao();
    estado = SUCESSO;
}

void TUDuracao::tearDown()
{
    delete duracao;
}

void TUDuracao::TestarCasoValido()
{
    try{
        duracao->SetValor(VALOR_VALIDO);
        if(duracao->GetValor()!= VALOR_VALIDO)
        {
            estado = FALHA;
        }
    }
    catch(invalid_argument  &e)
    {
        estado = FALHA;
    }
}
void TUDuracao::TestarCasoInvalido()
{
    try{
        duracao->SetValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument  &e)
    {
        if(duracao->GetValor() == VALOR_INVALIDO)
        {
            estado = FALHA;
        }
    }
}