#include "Entidade.h"
#include "Dominios.h"
#include "Testes.h"
#include <iostream>
#include <locale>
using namespace std;

int main()
{

	TUAvaliacao teste3;
	switch (teste3.run()) {
		case TUAvaliacao::SUCESSO:cout << "SUCESSO - DOMINIO AVALIACAO" << endl;
			break;
		case TUAvaliacao::FALHA:cout << "FALHA - DOMINIO AVALIACAO" << endl;
			break;
	}


    setlocale(LC_ALL, "portuguese");
    return 0;

}
