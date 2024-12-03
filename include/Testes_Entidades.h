#ifndef TESTES_ENTIDADES_H_INCLUDED
#define TESTES_ENTIDADES_H_INCLUDED
#include "Entidade.h"
class TUHospedagem{
    private:
        const string VALOR_VALIDO_NOME = "Nome";
        const string VALOR_VALIDO_DIARIA = "193.231,21";
        const static int VALOR_VALIDO_AVALIACAO = 5;
        Hospedagem *hospedagem;
        int estado;
        void setUp();
        void tearDown();
        void testarCenario();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};


#endif //TESTES_ENTIDADES_H_INCLUDED
