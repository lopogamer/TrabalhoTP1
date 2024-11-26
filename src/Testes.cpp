#include "Testes.h"
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
		nome->SetNome(NOME_VALIDO);
		if (nome->GetNome() != NOME_VALIDO) {
			estado = FALHA;
		}
	}
	catch (invalid_argument& e) {
		cout << "Falhou no valor valido" << endl;
		estado = FALHA;
	}
}

void TUNome::TestarCasoInvalido()
{
    try {
        nome->SetNome(NOME_INVALIDO);
        cout << nome->GetNome() << endl;
        estado = FALHA;
	}
    catch (invalid_argument& e) {
        if (nome->GetNome() == NOME_INVALIDO) {
        estado = FALHA;
		}
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
		data->SetData(DATA_VALIDA);
		if (data->GetData() != DATA_VALIDA) {
			estado = FALHA;
		}
	}
	catch (invalid_argument& e) {
		cout << "Falhou no valor valido" << endl;
		estado = FALHA;
	}
}

void TUData::TestarCasoInvalido()
{
	try {
		data->SetData(DATA_INVALIDA);
		cout << data->GetData() << endl;
		estado = FALHA;
	}
	catch (invalid_argument& e) {
		if (data->GetData() == DATA_INVALIDA) {
			estado = FALHA;
		}
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


void TUAvaliacao::setUp()
{
	avaliacao = new Avaliacao();
	estado = SUCESSO;
}

void TUAvaliacao::tearDown()
{
	delete avaliacao;
}

void TUAvaliacao::TestarCasoValido()
{
	try {
		avaliacao->SetAvaliacao(AVALIACAO_VALIDA);
		if (avaliacao->GetAvaliacao() != AVALIACAO_VALIDA) {
			estado = FALHA;
		}
	}
	catch (invalid_argument& e) {
		cout << "Falhou no valor valido" << endl;
		estado = FALHA;
	}
}

void TUAvaliacao::TestarCasoInvalido()
{
	try {
		avaliacao->SetAvaliacao(AVALIACAO_INVALIDA);
		cout << avaliacao->GetAvaliacao() << endl;
		estado = FALHA;
	}
	catch (invalid_argument& e) {
		if (avaliacao->GetAvaliacao() == AVALIACAO_INVALIDA) {
			estado = FALHA;
		}
	}
}

int TUAvaliacao::run()
{
	setUp();
	TestarCasoValido();
	TestarCasoInvalido();
	tearDown();
	return estado;
}


