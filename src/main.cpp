#include "Dominios.h"
#include "Entidade.h"
#include "Testes.h"
#include <iostream>
#include <locale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "portuguese");
    TUavaliacao teste;
    switch(teste.run()){
        case TUavaliacao::SUCESSO: cout << "SUCESSO  - DOMINIO AVALICAO" << endl;
            break;
        case TUavaliacao::FALHA:   cout << "FALHA   - DOMINIO  AVALIACAO" << endl;
            break;
    }

    TUcodigo teste2;
    switch(teste2.run()){
        case TUcodigo::SUCESSO: cout << "SUCESSO  - DOMINIO CODIGO" << endl;
            break;
        case TUcodigo::FALHA:   cout << "FALHA   - DOMINIO CODIGO" << endl;
            break;
    }
    return 0;
}
