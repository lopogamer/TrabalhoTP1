#ifndef TESTES_ENTIDADES_H_INCLUDED
#define TESTES_ENTIDADES_H_INCLUDED
#include "Testes_Dominios.h"
#include "Dominios.h"
#include "Entidade.h"

class TUDestino {
    private:
        const string NOME_VALIDO = "Nome";
        const string DATA_INICIO_VALIDO = "28-02-20";
        const string DATA_TERMINO_VALIDO = "07-03-20";
        const static int AVALIACAO_VALIDO = 5;
        const string CODIGO_VALIDO = "aZ42tK";
        Destino *destino;
        int estado;
        void setUp();
        void tearDown();
        void testarCenario();
    public:
        const static int SUCESSO = 1;
        const static int FALHA = 0;
        int run();

};


#endif //TESTES_ENTIDADES_H_INCLUDED
