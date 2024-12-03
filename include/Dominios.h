#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

class Senha
{
private:
    string senha;
    void Validar(string);
public:
    void SetSenha(string);
    string GetSenha() const;
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

class Codigo/**/
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
