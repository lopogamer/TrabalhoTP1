#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED
#include "Dominios.h"

class TUavaliacao{
    private:
        const static int VALOR_VALIDO = 5;
        const static int VALOR_INVALIDO = 6;
        Avaliacao *avaliacao;
        int estado;
        void setUp();
        void tearDown();
        void TestarCasoValido();
        void TestarCasoInvalido();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = 1;
        int run();
};

class TUcodigo{
    private:
        const string VALOR_VALIDO = "aZ42tK";
        const string VALOR_INVALIDO = "0";
        Codigo *codigo;
        int estado;
        void setUp();
        void tearDown();
        void TestarCasoValido();
        void TestarCasoInvalido();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = 1;
        int run();
};

#endif // TESTES_H_INCLUDED
