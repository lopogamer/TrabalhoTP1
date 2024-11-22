#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED
#include "Dominios.h"
#include <string>
using namespace std;
class TUDinheiro{
    private:
        inline const static string VALOR_VALIDO = "193.231,21";
        inline const static string VALOR_INVALIDO = "200.000,01";
        Dinheiro *dinheiro;
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