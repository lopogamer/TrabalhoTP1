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

#endif // TESTES_H_INCLUDED
