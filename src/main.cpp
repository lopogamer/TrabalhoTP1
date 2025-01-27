#include <stdexcept>
#include "Containers.h"
#include "Controladoras.h"
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
    

    try{
        DatabaseManager& dbManager = DatabaseManager::getInstance();
        CntrControleAcesso cntrControleAcesso;
        cntrControleAcesso.iniciarControle();
    }catch(invalid_argument &e){
        cout <<  " Erro Fatal " << e.what() << endl;
    }
}   

