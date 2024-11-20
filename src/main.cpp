#include "Dominios.h"
#include "Entidade.h"
#include <iostream>
#include <locale>
#include <stdexcept>
using namespace std;

int main()
{

    setlocale(LC_ALL, "portuguese");

    Data data1;
    Data data2;
    Data data3;

    string valida = "29-02-16";
    string invalida = "01-01-100";

    string invalida2 = "29-02-21";

    data1.SetData(valida);
    cout << data1.GetData() << endl;
    data2.SetData(invalida);
    cout << data2.GetData() << endl;
    data3.SetData(invalida2);
    cout << data3.GetData() << endl;


    return 0;
}
