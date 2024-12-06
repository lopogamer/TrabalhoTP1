#include "Testes_Dominios.h"
#include "Testes_Entidades.h"
#include <iostream>
#include <locale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "portuguese");
    cout << "TESTE DE DOMINIOS" << endl;
    TUavaliacao teste;
    switch(teste.run()){
        case TUavaliacao::SUCESSO: cout << "AVALIACAO - SUCESSO" << endl;
            break;
        case TUavaliacao::FALHA:   cout << "AVALIACAO - FALHA" << endl;
            break;
    }
    TUcodigo teste2;
    switch(teste2.run()){
        case TUcodigo::SUCESSO: cout << "CODIGO - SUCESSO " << endl;
            break;
        case TUcodigo::FALHA:   cout << " CODIGO - FALHA" << endl;
            break;
    }
    TUData teste_data;
    switch (teste_data.run()){
        case TUData::SUCESSO: cout << "DATA - SUCESSO" << endl;
            break;
        case TUData::FALHA: cout << "DATA - FALHA" << endl;
            break;
    }
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


    TUNome testeNome;
    switch (testeNome.run()){
        case TUNome::SUCESSO: cout << "NOME - SUCESSO" << endl;
            break;
        case TUNome::FALHA: cout << "NOME - FALHA" << endl;
            break;
    }
    TUSenha testeSenha;
    switch (testeSenha.run()){
        case TUSenha::SUCESSO: cout << "SENHA - SUCESSO" << endl;
            break;
        case TUSenha::FALHA: cout << "SENHA - FALHA" << endl;
            break;
    }
    
    TUDestino testeDestino;
    switch (testeDestino.run()){
        case TUDestino::SUCESSO: cout << "DESTINO - SUCESSO" << endl;
            break;
        case TUDestino::FALHA: cout << "DESTINO - FALHA" <<endl;
            break;    
    }

    cout << endl;
    cout << "TESTE DE ENTIDADES" << endl;
    TUAtividade testeAtividade;
    switch (testeAtividade.run()){
        case TUAtividade::SUCESSO: cout << "ATIVIDADE - SUCESSO" << endl;
            break;
        case TUAtividade::FALHA: cout << "ATIVIDADE - FALHA" << endl;
            break;
    }
    return 0;    
}
