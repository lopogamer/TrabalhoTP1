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
    bool Validar(const string&);
public:
    bool SetDinheiro(string);
    string GetDinheiro() const;
};

class Avaliacao
{
private:
    int digito;
    bool Validar(int digito) const;
public:
    bool SetValor(int valor);
    int GetValor() const;
};

class Nome
{
private:
    string nome;
    bool Validar(string nome);
public:
    bool SetNome(string nome);
    string GetNome() const;
};

class Duracao
{
private:
    int valor;
    bool Validar(int);
public:
    bool SetValor(int);
    int GetValor() const;
};

class Codigo
{
private:
    string codigo;
    bool Validar(string&);
public:
    bool SetCodigo(string);
    string GetCodigo() const;
};

class Data
{
private:
    string data;
    bool Validar(const string& data) const;
    bool bissexto(int ano) const
    {
        return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
    }
public:
    bool SetData(const string& data);
    string GetData() const;
};

#endif // DOMINIOS_H_INCLUDED
