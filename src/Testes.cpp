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
using namespace std;
#include <iostream>

void TUSenha::setUp()
{
    senha = new Senha();
    estado = SUCESSO;
}

void TUSenha::tearDown()
{
    delete senha;
}

void TUSenha::TestarCasoValido()
{
    try{
        senha->SetSenha(VALOR_VALIDO);
        if(senha->GetSenha() != VALOR_VALIDO)
        {
            estado = FALHA;
        }
    }
    catch(invalid_argument  &e)
    {
        estado = FALHA;
    }
}
void TUSenha::TestarCasoInvalido()
{
    try{
        senha->SetSenha(VALOR_INVALIDO);
        cout << senha->GetSenha() << endl;
        estado = FALHA;
    }
    catch(invalid_argument  &e)
    {
        if(senha->GetSenha() == VALOR_INVALIDO)
        {
            estado = FALHA;
        }
    }
}

int TUSenha::run()
{
    setUp();
    TestarCasoValido();
    TestarCasoInvalido();
    tearDown();
    return estado;
}

void TUHorario::setUp()
{
    horario = new Horario();
    estado = SUCESSO;
}

void TUHorario::tearDown()
{
    delete horario;
}

void TUHorario::TestarCasoValido()
{
    try{
        horario->SetHora(VALOR_VALIDO);
        if(horario->GetHora() != VALOR_VALIDO)
        {
            estado = FALHA;
        }
    }
    catch(invalid_argument  &e)
    {
        
        estado = FALHA;
    }
}
void TUHorario::TestarCasoInvalido()
{
    try{
        horario->SetHora(VALOR_INVALIDO);
        cout << horario->GetHora() << endl;
        estado = FALHA;
    }
    catch(invalid_argument  &e)
    {
        if(horario->GetHora() == VALOR_INVALIDO)
        {
            estado = FALHA;
        }
    }
}

int TUHorario::run()
{
    setUp();
    TestarCasoValido();
    TestarCasoInvalido();
    tearDown();
    return estado;
}