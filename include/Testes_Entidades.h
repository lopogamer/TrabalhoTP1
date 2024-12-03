#ifndef TESTES_ENTIDADES_H_INCLUDED
#define TESTES_ENTIDADES_H_INCLUDED
#include "Testes_Dominios.h"
#include "Dominios.h"


class TUViagem{
    private:
        const string VALOR_VALIDO_CODIGO = "aBcCz6";
        const string VALOR_VALIDO_NOME = "Nome";
        static const int VALOR_VALIDO3 = 4;
        Viagem* viagem;
        int estado;
        void setUp();
        void tearDown();
        void testarCenario();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = = -1;
        int run();
};

class TUConta{
    private:
        const string VALOR_VALIDO1 = "aBcCz6";
        const string VALOR_VALIDO2 = "16274";
        Viagem* viagem;
        int estado;
        void setUp();
        void tearDown();
        void testarCenario();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = = -1;
        int run();
};




#endif //TESTES_ENTIDADES_H_INCLUDED
