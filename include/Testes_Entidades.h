#ifndef TESTES_ENTIDADES_H_INCLUDED
#define TESTES_ENTIDADES_H_INCLUDED
#include "Testes_Dominios.h"
#include "Dominios.h"
using namespace std;

class TUViagem{
    private:
        const string CODIGO_VALIDO = "aBcCz6";
        const string NOME_VALIDO = "Nome";
        static const int AVALIACAO_VALIDO = 4;
        Viagem* viagem;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = = -1;
        int run();
};

class TUConta{
    private:
        const string CODIGO_VALIDO = "aBcCz6";
        const string SENHA_VALIDO = "16274";
        Conta* conta;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = = -1;
        int run();
};




#endif //TESTES_ENTIDADES_H_INCLUDED
