#include "Testes_Dominios.h"
#include "Testes_Entidades.h"
#include <iostream>
#include <locale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "portuguese");

    cout << endl;
    cout << "TESTE DE ENTIDADES" << endl;

    TUViagem testeViagem;

    switch(testeViagem.run()){
        case TUViagem::SUCESSO: cout << "VIAGEM - SUCESSO" << endl;
                                break;
        case TUViagem::FALHA  : cout << "VIAGEM  - FALHA" << endl;
                                break;
    }

    TUConta testeConta;

    switch(testeConta.run()){
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

    
    TUAtividade testeAtividade;
    switch (testeAtividade.run()){
        case TUAtividade::SUCESSO: cout << "ATIVIDADE - SUCESSO" << endl;
            break;
        case TUAtividade::FALHA: cout << "ATIVIDADE - FALHA" << endl;
            break;
    }

    TUHospedagem testeHospedagem;
    switch(testeHospedagem.run()){
        case TUHospedagem::SUCESSO: cout << "HOSPEDAGEM - SUCESSO" << endl;
            break;
        case TUHospedagem::FALHA : cout << "HOSPEDAGEM - FALHA" << endl;
            break;
    }
    return 0;    

}
