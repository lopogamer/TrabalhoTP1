#include "Testes_Dominios.h"
#include "Testes_Entidades.h"
#include <iostream>
#include <locale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "portuguese");

    TUViagem teste;

    switch(teste.run()){
        case TUViagem::SUCESSO: cout << "SUCESSO - VIAGEM" << endl;
                                break;
        case TUViagem::FALHA  : cout << "FALHA   - VIAGEM" << endl;
                                break;
    }

    TUConta teste2;

    switch(teste2.run()){
        case TUConta::SUCESSO: cout << "SUCESSO - CONTA" << endl;
                                break;
        case TUConta::FALHA  : cout << "FALHA   - CONTA" << endl;
                                break;
    }

    return 0;


}
