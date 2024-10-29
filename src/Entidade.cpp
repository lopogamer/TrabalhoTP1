#include "Entidade.h"
using namespace std;

void Conta::SetCodigo(const Codigo& codigo)
{
    this->codigo = codigo;
}

Codigo Conta::GetCodigo() const
{
    return codigo;

}

void Conta::SetSenha(const Senha& senha)
{
    this->senha = senha;

}

Senha Conta::GetSenha() const
{
    return senha;
}




void Viagem::SetCodigo(const Codigo& codigo)
{
    this->codigo = codigo;
}

Codigo Viagem::GetCodigo() const
{
    return codigo;

}

void::SetNome(const Nome& nome)
{
    this->nome = nome;
}


Nome Viagem::GetNome() const
{
    return nome;

}



void Viagem::SetAvaliacao(const Avaliacao& avaliacao)
{
    this->avaliacao = avaliacao;

}

Avaliacao Viagem::GetAvaliacao() const
{
    return avaliacao;
}


