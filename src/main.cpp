#include "Testes_Dominios.h"
#include "Testes_Entidades.h"
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

    cout << "TESTE DE DOMINIOS" << endl;
    TUAvaliacao testeAvaliacao;
    switch(testeAvaliacao.run())
    {
    case TUAvaliacao::SUCESSO:
        cout << "AVALIACAO - SUCESSO" << endl;
        break;
    case TUAvaliacao::FALHA:
        cout << "AVALIACAO - FALHA" << endl;
        break;
    }
    TUCodigo testeCodigo;
    switch(testeCodigo.run())
    {
    case TUCodigo::SUCESSO:
        cout << "CODIGO - SUCESSO " << endl;
        break;
    case TUCodigo::FALHA:
        cout << " CODIGO - FALHA" << endl;
        break;
    }
    TUData testeData;
    switch (testeData.run())
    {
    case TUData::SUCESSO:
        cout << "DATA - SUCESSO" << endl;
        break;
    case TUData::FALHA:
        cout << "DATA - FALHA" << endl;
        break;
    }
    TUDinheiro testeDinheiro;
    switch (testeDinheiro.run())
    {
    case TUDinheiro::SUCESSO:
        cout << "DINHEIRO - SUCESSO" << endl;
        break;
    case TUDinheiro::FALHA:
        cout << "DINHEIRO - FALHA" << endl;
        break;
    }
    TUDuracao testeDuracao;
    switch (testeDuracao.run())
    {
    case TUDuracao::SUCESSO:
        cout << "DURACAO - SUCESSO" << endl;
        break;
    case TUDuracao::FALHA:
        cout << "DURACAO - FALHA" << endl;
        break;
    }
    TUHorario testeHorario;
    switch (testeHorario.run())
    {
    case TUHorario::SUCESSO:
        cout << "HORARIO - SUCESSO" << endl;
        break;
    case TUHorario::FALHA:
        cout << "HORARIO - FALHA" << endl;
        break;
    }


    TUNome testeNome;
    switch (testeNome.run())
    {
    case TUNome::SUCESSO:
        cout << "NOME - SUCESSO" << endl;
        break;
    case TUNome::FALHA:
        cout << "NOME - FALHA" << endl;
        break;
    }
    TUSenha testeSenha;
    switch (testeSenha.run())
    {
    case TUSenha::SUCESSO:
        cout << "SENHA - SUCESSO" << endl;
        break;
    case TUSenha::FALHA:
        cout << "SENHA - FALHA" << endl;
        break;
    }

    cout << endl;
    cout << "TESTE DE ENTIDADES" << endl;

    TUViagem testeViagem;

    switch(testeViagem.run())
    {
    case TUViagem::SUCESSO:
        cout << "VIAGEM - SUCESSO" << endl;
        break;
    case TUViagem::FALHA  :
        cout << "VIAGEM  - FALHA" << endl;
        break;
    }

    TUConta testeConta;

    switch(testeConta.run())
    {
    case TUConta::SUCESSO:
        cout << "CONTA - SUCESSO" << endl;
        break;
    case TUConta::FALHA  :
        cout << "CONTA - FALHA" << endl;
        break;
    }


    TUDestino testeDestino;
    switch (testeDestino.run())
    {
    case TUDestino::SUCESSO:
        cout << "DESTINO - SUCESSO" << endl;
        break;
    case TUDestino::FALHA:
        cout << "DESTINO - FALHA" << endl;
        break;
    }


    TUAtividade testeAtividade;
    switch (testeAtividade.run())
    {
    case TUAtividade::SUCESSO:
        cout << "ATIVIDADE - SUCESSO" << endl;
        break;
    case TUAtividade::FALHA:
        cout << "ATIVIDADE - FALHA" << endl;
        break;
    }

    TUHospedagem testeHospedagem;
    switch(testeHospedagem.run())
    {
    case TUHospedagem::SUCESSO:
        cout << "HOSPEDAGEM - SUCESSO" << endl;
        break;
    case TUHospedagem::FALHA :
        cout << "HOSPEDAGEM - FALHA" << endl;
        break;
    }
    return 0;

}
