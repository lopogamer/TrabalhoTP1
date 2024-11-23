#include "Dominios.h"
#include "Entidade.h"
#include <iostream>
#include <locale>
#include <stdexcept>
using namespace std;

int main()
{
    int val = 1;
    int in = 5;

    Avaliacao valor;
    Avaliacao valor2;

    valor.SetAvaliacao(in);
    cout << valor.GetAvaliacao() << endl;


    setlocale(LC_ALL, "portuguese");

    return 0;
}
