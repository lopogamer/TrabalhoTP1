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
        case TUDinheiro::SUCESSO: cout << "Teste de dinheiro bem sucedido" << endl;
            break;
        case TUDinheiro::FALHA: cout << "Teste de dinheiro falhou" << endl;
            break;
    }
    setlocale(LC_ALL, "portuguese");
    return 0;
}
