#include "Dominios.h"
#include "Entidade.h"
#include "Testes.h"
#include <iostream>
#include <locale>
#include "Testes.h"
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
