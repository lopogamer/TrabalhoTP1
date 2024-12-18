#ifndef TESTES_DOMINIOS_H_INCLUDED
#define TESTES_DOMINIOS_H_INCLUDED

#include <string>
#include <iostream>
#include "Dominios.h"
using namespace std;

class TUNome
{
private:
    const string VALOR_VALIDO = "Nome";
    const string VALOR_INVALIDO = "";
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

class TUData
{
private:
    const string VALOR_VALIDO = "29-02-20";
    const string VALOR_INVALIDO = "00-00-00";
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

class TUAvaliacao
{
private:
    const static int VALOR_VALIDO = 5;
    const static int VALOR_INVALIDO = 6;
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

class TUCodigo
{
private:
    const string VALOR_VALIDO = "aZ42tK";
    const string VALOR_INVALIDO = "0";
    Codigo* codigo;
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

class TUDinheiro
{
private:
    const string VALOR_VALIDO = "193.231,21";
    const string VALOR_INVALIDO = "200.000,01";
    Dinheiro* dinheiro;
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

class TUDuracao
{
private:
    const int VALOR_VALIDO = 21;
    const int VALOR_INVALIDO = 765;
    Duracao* duracao;
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


class TUSenha
{
private:
    const string VALOR_VALIDO = "01542";
    const string VALOR_INVALIDO = "12345";
    Senha* senha;
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

class TUHorario
{
private:
    const string VALOR_VALIDO = "23:43";
    const string VALOR_INVALIDO = "69:69";
    Horario* horario;
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

#endif // TESTES_DOMINIOS_H_INCLUDED
