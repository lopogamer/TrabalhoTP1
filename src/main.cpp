#include "Controladoras.h"
#include "Interfaces.h"
#include "stub.h"
#include "Entidade.h"
#include "Dominios.h"
#include <iostream>
#include <locale>
using namespace std;

int main()
{
    /// @mainpage Documentação do TrabalhoTP1
    ///
    /// Bem-vindo à documentação do TrabalhoTP1!
    /// 
    /// Este projeto contém as seguintes funcionalidades:
    /// 
    /// - Implementação de classes de domínio.
    /// - Implementação de classes de entidades que utilizam as classes de domínio como atributos.
    /// - Implementação de testes de unidade para as classes de domínio utilizando a biblioteca stdexcept para testar as exceções.
    /// - Implementação de testes de unidade para as classes de entidades para testar os métodos de atribuição e obtenção de valores.
    setlocale(LC_ALL, "portuguese");


    IAA *cntrIAA = new CntrIAA;
    IAS *stubIAS = new StubIAS;
    Codigo codigo;

    cntrIAA->setCntrServicoAutenticacao(stubIAS);

    if(cntrIAA->autenticar(&codigo)){
        cout << endl << "Autenticado com sucesso" << endl;
    }else{
        cout << endl << "Falha na autenticação" << endl;
    }
    delete stubIAS;
    delete cntrIAA;
}
