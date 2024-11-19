#include "Dominios.h"
#include "Entidade.h"
#include <iostream>
#include <locale>
using namespace std;

int main()
{
    Dinheiro dinheiro;
    cout << dinheiro.GetDinheiro() << endl;
    setlocale(LC_ALL, "portuguese");
    return 0;
}
