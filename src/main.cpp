#include "Dominios.h"
#include "Entidade.h"
#include <iostream>
#include <locale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "portuguese");
    TUavaliacao teste;
    switch(teste.run()){
        case TUavaliacao::SUCESSO: cout << "SUCESSO  - AVALICAO" << endl;
            break;
        case TUavaliacao::FALHA:   cout << "FALHA   -  AVALIACAO" << endl;
            break;
    }

    TUcodigo teste2;
    switch(teste2.run()){
        case TUcodigo::SUCESSO: cout << "SUCESSO  - CODIGO" << endl;
            break;
        case TUcodigo::FALHA:   cout << "FALHA   -  CODIGO" << endl;
            break;
    }
    return 0;
}
