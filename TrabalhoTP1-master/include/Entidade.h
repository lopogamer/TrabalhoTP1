#ifndef ENTIDADE_H_INCLUDED
#define ENTIDADE_H_INCLUDED

#include "Dominios.h"
using namespace std;


class Atividade{
private:
    Codigo


};



class Conta
{
private:
    Codigo codigo_;
    Senha senha_;

public:
    void SetCodigo(const Codigo&);
    Codigo GetCodigo() const;
    void SetSenha(const Senha&);
    Senha GetSenha() const;
};





class Viagem
{
private:
    Codigo codigo_;
    Nome nome_;
    Avaliacao avaliacao_;

public:
    void SetCodigo(const Codigo&);
    Codigo GetCodigo() const;
    void SetNome(const Senha&);
    Senha GetNome() const;
    void SetAvaliacao(const Avaliacao&);
    Avaliacao GetAvaliacao() const;

};













#endif // ENTIDADE_H_INCLUDED
