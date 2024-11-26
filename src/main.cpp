#include <iostream>
#include <locale>
#include "Testes.h"
using namespace std;

int main()
{
    TUHorario testeHorario;
    switch (testeHorario.run()){
        case TUHorario::SUCESSO: cout << "HORARIO - SUCESSO" << endl;
            break;
        case TUHorario::FALHA: cout << "HORARIO - FALHA" << endl;
            break;
    }

    TUSenha testeSenha;
    switch (testeSenha.run()){
        case TUSenha::SUCESSO: cout << "SENHA - SUCESSO" << endl;
            break;
        case TUSenha::FALHA: cout << "SENHA - FALHA" << endl;
            break;
    }
    setlocale(LC_ALL, "portuguese");
    return 0;
}
