#include "Dominios.h"
#include "Entidade.h"
#include "Testes.h"
#include <iostream>
#include <locale>
using namespace std;

int main()
{
    TUDinheiro testeDinheiro;
    switch (testeDinheiro.run()){
        case TUDinheiro::SUCESSO: cout << "DINHEIRO - SUCESSO" << endl;
            break;
        case TUDinheiro::FALHA: cout << "DINHEIRO - FALHA" << endl;
            break;
    }
    TUDuracao testeDuracao;
    switch (testeDuracao.run()){
        case TUDuracao::SUCESSO: cout << "DURACAO - SUCESSO" << endl;
            break;
        case TUDuracao::FALHA: cout << "DURACAO - FALHA" << endl;
            break;
    }
    setlocale(LC_ALL, "portuguese");
    return 0;
}
