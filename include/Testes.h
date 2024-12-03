#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED
#include "Dominios.h"
#include <string>
using namespace std;

class TUSenha{
    private: 
        const string VALOR_VALIDO = "01542";
        const string VALOR_INVALIDO = "12345";
        Senha *senha;
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

class TUHorario{
    private: 
        const string VALOR_VALIDO = "23:43";
        const string VALOR_INVALIDO = "69:69";
        Horario *horario;
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