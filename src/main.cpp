#include "Controladoras.h"
#include <iostream>
#include <locale>
#include "sqlite/sqlite3.h"
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

    sqlite3 *db;
    int rc;

    rc = sqlite3_open("TrabalhoTP1.db", &db);

    if (rc)
    {
        cerr << "Erro ao abrir o banco de dados: " << endl;
        return 0;
    }
    else
    {
        cout << "Banco de dados aberto com sucesso!" << endl;
    }
}

