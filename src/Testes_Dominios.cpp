#include "Testes_Dominios.h"
#include <iostream>
using namespace std;

void TUNome::setUp()
{
    nome = new Nome();
    estado = SUCESSO;
}

void TUNome::tearDown()
{
    delete nome;
}

void TUNome::TestarCasoValido()
{
    try {
        nome->SetNome(VALOR_VALIDO);
        if (nome->GetNome() != VALOR_VALIDO)
            estado = FALHA;
    } catch (invalid_argument& e) {
        estado = FALHA;
    }
}

void TUNome::TestarCasoInvalido()
{
    try {
        nome->SetNome(VALOR_INVALIDO);
        cout << nome->GetNome() << endl;
        estado = FALHA;
    } catch (invalid_argument& e) {
        if (nome->GetNome() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUNome::run()
{
    setUp();
    TestarCasoValido();
    TestarCasoInvalido();
    tearDown();
    return estado;
}

void TUData::setUp()
{
    data = new Data();
    estado = SUCESSO;
}

void TUData::tearDown()
{
    delete data;
}

void TUData::TestarCasoValido()
{
    try {
        data->SetData(VALOR_VALIDO);
        if (data->GetData() != VALOR_VALIDO)
            estado = FALHA;
    } catch (invalid_argument& e) {
        estado = FALHA;
    }
}

void TUData::TestarCasoInvalido()
{
    try {
        data->SetData(VALOR_INVALIDO);
        cout << data->GetData() << endl;
        estado = FALHA;
    } catch (invalid_argument& e) {
        if (data->GetData() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUData::run()
{
    setUp();
    TestarCasoValido();
    TestarCasoInvalido();
    tearDown();
    return estado;
}


void TUavaliacao::setUp()
{
    avaliacao = new Avaliacao();
    estado = SUCESSO;
}

void TUavaliacao::tearDown()
{
    delete avaliacao;
}

void TUavaliacao::TestarCasoValido()
{
    try {
        avaliacao->SetAvaliacao(VALOR_VALIDO);
        if (avaliacao->GetAvaliacao() != VALOR_VALIDO)
            estado = FALHA;
    } catch (invalid_argument& e) {
        estado = FALHA;
    }
}

void TUavaliacao::TestarCasoInvalido()
{
    try {
        avaliacao->SetAvaliacao(VALOR_INVALIDO);
        cout << avaliacao->GetAvaliacao() << endl;
        estado = FALHA;
    } catch (invalid_argument& e) {
        if (avaliacao->GetAvaliacao() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUavaliacao::run()
{
    setUp();
    TestarCasoValido();
    TestarCasoInvalido();
    tearDown();
    return estado;
}


//Codigo
void TUcodigo::setUp()
{
    codigo = new Codigo();
    estado = SUCESSO;
}
void TUcodigo::tearDown()
{
    delete codigo;
}
void TUcodigo::TestarCasoValido()
{
    try {
        codigo->SetCodigo(VALOR_VALIDO);
        if(codigo->GetCodigo() != VALOR_VALIDO)
            estado = FALHA;
    } catch(invalid_argument& e) {
        estado = FALHA;
    }
}
void TUcodigo::TestarCasoInvalido()
{
    try {
        codigo->SetCodigo(VALOR_INVALIDO);
        estado = FALHA;
    } catch(invalid_argument& e) {
        if(codigo->GetCodigo() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUcodigo::run()
{
    setUp();
    TestarCasoValido();
    TestarCasoInvalido();
    tearDown();
    return estado;
}
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
    try {
        dinheiro->SetDinheiro(VALOR_VALIDO);
        if(dinheiro->GetDinheiro() != VALOR_VALIDO)
            estado = FALHA;
    } catch(invalid_argument&  e) {
        estado = FALHA;
    }
}
void TUDinheiro::TestarCasoInvalido()
{
    try {
        dinheiro->SetDinheiro(VALOR_INVALIDO);
        estado = FALHA;
    } catch(invalid_argument&  e) {
        if(dinheiro->GetDinheiro() == VALOR_INVALIDO)
            estado = FALHA;
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

int TUDuracao::run()
{
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
    try {
        duracao->SetDuracao(VALOR_VALIDO);
        if(duracao->GetDuracao() != VALOR_VALIDO)
            estado = FALHA;
    } catch(invalid_argument&  e) {
        estado = FALHA;
    }
}
void TUDuracao::TestarCasoInvalido()
{
    try {
        duracao->SetDuracao(VALOR_INVALIDO);
        estado = FALHA;
    } catch(invalid_argument&  e) {
        if(duracao->GetDuracao() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

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
    try {
        senha->SetSenha(VALOR_VALIDO);
        if(senha->GetSenha() != VALOR_VALIDO)
            estado = FALHA;
    } catch(invalid_argument&  e) {
        estado = FALHA;
    }
}
void TUSenha::TestarCasoInvalido()
{
    try {
        senha->SetSenha(VALOR_INVALIDO);
        cout << senha->GetSenha() << endl;
        estado = FALHA;
    } catch(invalid_argument&  e) {
        if(senha->GetSenha() == VALOR_INVALIDO)
            estado = FALHA;
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
    try {
        horario->SetHora(VALOR_VALIDO);
        if(horario->GetHora() != VALOR_VALIDO)
            estado = FALHA;
    } catch(invalid_argument&  e) {

        estado = FALHA;
    }
}
void TUHorario::TestarCasoInvalido()
{
    try {
        horario->SetHora(VALOR_INVALIDO);
        cout << horario->GetHora() << endl;
        estado = FALHA;
    } catch(invalid_argument&  e) {
        if(horario->GetHora() == VALOR_INVALIDO)
            estado = FALHA;
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