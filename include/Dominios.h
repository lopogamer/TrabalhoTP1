//-----------------------------------------------------
//Diretivas de compilação para evitar múltiplas inclusões

#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED
//-----------------------------------------------------
//Inclusão de bibliotecas necessárias
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <regex>
using namespace std;

/// @file Dominios.h
/// @brief Declaraçoes das classes-Dominio
/// Este arquivo contem as declaraçoes das classes Dominios com a declaraçao dos metodos Validar,
/// Set, Get

/// @class Senha
/// @author Luan - 232036958
/// @brief Classe para representar a senha de um usuário.
///
/// A Senha é **valida** se atender as seguintes regras:
///
/// - Tem exatamente 5 dígitos numéricos (0-9).
/// - Não possui dígitos repetidos.
/// - Não é uma sequência crescente ou decrescente.
class Senha
{
private:
    string senha; // Atributo que representa a senha.
    void Validar(string); // Método para validar a senha.
public:

    /// @brief Método para atribuir a senha.
    /// Este método tenta atribuir a senha fornecida ao objeto. Antes de definir a senha,
    /// ele chama o método `Validar` para garantir que a senha atende às regras de formato.
    /// Se a senha for inválida, o método `Validar` lançará uma exceção do tipo `invalid_argument`
    /// @param string senha a ser setada
    /// @throws invalid_argument se a senha não atender as regras de formato.

    void SetSenha(string); 

    /// @brief Método para obter a senha.
    /// Este método retorna a senha armazenada no objeto.
    /// @return string senha armazenada no objeto.

    string GetSenha() const; // Método para obter a senha.
};

class Horario
{
private:
    string hora;
    void Validar(string);
public:
    void SetHora(string);
    string GetHora() const;
};

class Dinheiro
{
private:
    string quantidade;
    void Validar(const string&);
public:
    void SetDinheiro(string);
    string GetDinheiro() const;
};

class Avaliacao
{
private:
    int valor;
    void Validar(int);
public:
    void SetValor(int);
    int GetValor() const;
};

class Nome
{
private:
    string nome;
    void Validar(string nome);
public:
    void SetNome(string nome);
    string GetNome() const;
};

class Duracao
{
private:
    int valor;
    void Validar(int);
public:
    void SetValor(int);
    int GetValor() const;
};

class Codigo
{
private:
    string codigo;
    void Validar(string&);
public:
    void SetCodigo(string);
    string GetCodigo() const;
};

class Data
{
private:
    string data;
    void Validar(const string& data) const;
    bool bissexto(int ano) const
    {
        return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
    }
public:
    void SetData(const string& data);
    string GetData() const;
};

#endif // DOMINIOS_H_INCLUDED
