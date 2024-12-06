#ifndef TESTES_ENTIDADES_H_INCLUDED
#define TESTES_ENTIDADES_H_INCLUDED
#include "Testes_Dominios.h"
#include "Dominios.h"
#include "Entidade.h"
using namespace std;

class TUViagem{
    private:
        const string CODIGO_VALIDO = "aBcCz6";
        const string NOME_VALIDO = "Nome";
        static const int AVALIACAO_VALIDO = 4;
        Viagem *viagem;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};

class TUConta{
    private:
        const string CODIGO_VALIDO = "aBcCz6";
        const string SENHA_VALIDO = "64790";
        Conta *conta;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};


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
