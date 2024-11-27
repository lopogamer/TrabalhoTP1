#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED

#include <string>
#include <iostream>
#include "Dominios.h"
using namespace std;

class TUNome {
private:
	const string NOME_VALIDO = "Nome";
    	const string NOME_INVALIDO = "";
    	Nome* nome;
    	int estado;
    	void setUp();
    	void tearDown();
    	void TestarCasoValido();
    	void TestarCasoInvalido();
public:
    	const static int SUCESSO = 0;
    	const static int FALHA = -1;
    	int run();
};

class TUData {
private:
	const string DATA_VALIDA = "29-02-20";
	const string DATA_INVALIDA = "00-00-00";
	Data* data;
	int estado;
	void setUp();
	void tearDown();
	void TestarCasoValido();
	void TestarCasoInvalido();
public:
	const static int SUCESSO = 0;
	const static int FALHA = -1;
	int run();
};


class TUAvaliacao {
private:
	static const int AVALIACAO_VALIDA = 4;
	static const int AVALIACAO_INVALIDA = 7;
	Avaliacao* avaliacao;
	int estado;
	void setUp();
	void tearDown();
	void TestarCasoValido();
	void TestarCasoInvalido();
public:
	const static int SUCESSO = 0;
	const static int FALHA = -1;
	int run();
};



#endif // TESTES_H_INCLUDED
