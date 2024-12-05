#ifndef TESTES_ENTIDADES_H_INCLUDED
#define TESTES_ENTIDADES_H_INCLUDED
#include "Entidade.h"
#include "Dominios.h"
#include <string>
using namespace std;
class TUAtividade
{
    private:
        const string VALOR_VALIDO_CODIGO = "aZ42tK";
        const string VALOR_VALIDO_NOME = "Nome";
        const string VALOR_VALIDO_DATA = "29-02-20";
        const string VALOR_VALIDO_HORARIO = "23:34";
        const int VALOR_VALIDO_DURACAO = 21;
        const string VALOR_VALIDO_PRECO = "100,00";
        const int VALOR_VALIDO_AVALIACAO = 5;
        Atividade *atividade;
        int estado;
        void setUp();
        void tearDown();
        void testarCenario();
    public:
        static const int SUCESSO = 0;
        static const int FALHA = -1;
        int run();
};

#endif //TESTES_ENTIDADES_H_INCLUDED
