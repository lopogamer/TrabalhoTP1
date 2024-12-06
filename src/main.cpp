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
    cout << endl;
    cout << "TESTE DE ENTIDADES" << endl;
    TUHospedagem testeHospedagem;
    switch(testeHospedagem.run()){
        case TUHospedagem::SUCESSO: cout << "HOSPEDAGEM - SUCESSO" << endl;
            break;
        case TUHospedagem::FALHA : cout << "HOSPEDAGEM - FALHA" << endl;
            break;
    }
    return 0;    

}
