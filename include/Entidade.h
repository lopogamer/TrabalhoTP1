#ifndef ENTIDADE_H_INCLUDED
#define ENTIDADE_H_INCLUDED

#include "Dominios.h"
using namespace std;



class Conta
{
private:
    Codigo codigo;
    Senha senha;

public:
    void SetCodigo(const Codigo& codigo);
    Codigo GetCodigo() const;

    void SetSenha(const Senha& senha);
    Senha GetSenha() const;
};



class Viagem
{
private:
    Codigo codigo;
    Nome nome;
    Avaliacao avaliacao;

public:
    void SetCodigo(const Codigo& codigo);
    Codigo GetCodigo() const;
    void SetNome(const Nome& nome);
    Senha GetNome() const;
    void SetAvaliacao(const Avaliacao& avaliacao);
    Avaliacao GetAvaliacao() const;

};




#endif // ENTIDADE_H_INCLUDED
