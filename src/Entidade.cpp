#include "Entidade.h"
#include "Dominios.h"
using namespace std;

void Atividade::SetCodigo(const Codigo& codigo)
{
    this->codigo = codigo;
}

Codigo Atividade::GetCodigo() const
{
    return codigo;
}

void Atividade::SetNome(const Nome& nome)
{
    this->nome = nome;
}

Nome Atividade::GetNome() const
{
    return nome;
}

void Atividade::SetData(const Data& data)
{
    this->data = data;
}

Data Atividade::GetData() const
{
    return data;
}

void Atividade::SetHorario(const Horario& horario)
{
    this->horario = horario;
}

Horario Atividade::GetHorario() const
{
    return horario;
}

void Atividade::SetDuracao(const Duracao& duracao)
{
    this->duracao = duracao;
}

Duracao Atividade::GetDuracao() const
{
    return duracao;
}

void Atividade::SetPreco(const Dinheiro& preco)
{
    this->preco = preco;
}

Dinheiro Atividade::GetPreco() const
{
    return preco;
}

void Atividade::SetAvaliacao(const Avaliacao& avaliacao)
{
    this->avaliacao = avaliacao;
}

Avaliacao Atividade::GetAvaliacao() const
{
    return avaliacao;
}

void Destino::SetCodigo(const Codigo& codigo)
{
    this->codigo = codigo;
}

Codigo Destino::GetCodigo() const
{
    return codigo;
}


void Destino::SetNome(const Nome& nome)
{
    this->nome = nome;
}

Nome Destino::GetNome() const
{
    return nome;
}

void Destino::SetAvaliacao(const Avaliacao& avaliacao)
{
    this->avaliacao = avaliacao;
}

Avaliacao Destino::GetAvaliacao() const
{
    return avaliacao;
}

void Destino :: SetDataInicio(const Data& data_de_inicio)
{
    this ->data_de_inicio = data_de_inicio;
}

Data Destino::GetDataInicio() const
{
    return data_de_inicio;
}

void Destino :: SetDataTermino(const Data& data_de_termino)
{
    this ->data_de_termino = data_de_termino;
}

Data Destino::GetDataTermino() const
{
    return data_de_termino;
}

void Conta::SetCodigo(const Codigo& codigo)
{
    this -> codigo = codigo;
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

void Viagem::SetNome(const Nome& nome)
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




void Hospedagem::SetCodigo(const Codigo& codigo)
{
    this->codigo = codigo;
}

Codigo Hospedagem::GetCodigo() const
{
    return codigo;
}


void Hospedagem::SetNome(const Nome& nome_hospedagem)
{
    this->nome_hospedagem = nome_hospedagem;
}

Nome Hospedagem::GetNome() const
{
    return nome_hospedagem;
}

void Hospedagem::SetDiaria(const Dinheiro& diaria_hospedagem)
{
    this->diaria_hospedagem = diaria_hospedagem;
}

Dinheiro Hospedagem::GetDiaria() const
{
    return diaria_hospedagem;
}

void Hospedagem::SetAvaliacao(const Avaliacao& avaliacao_hospedagem)
{
    this->avaliacao_hospedagem = avaliacao_hospedagem;
}

Avaliacao Hospedagem::GetAvaliacao() const
{
    return avaliacao_hospedagem;
}

void Hospedagem::SetCodigo(const Codigo& codigo)
{
    this->codigo = codigo;
}

Codigo Hospedagem::GetCodigo() const
{
    return codigo;
}