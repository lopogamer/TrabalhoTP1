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
