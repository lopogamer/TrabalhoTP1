#ifndef ENTIDADE_H_INCLUDED
#define ENTIDADE_H_INCLUDED
#include "Dominios.h"
#include <string>
using namespace std;

class Atividade
{
private:
    Codigo codigo;
    Nome nome;
    Data data;
    Horario horario;
    Duracao duracao;
    Dinheiro preco;
    Avaliacao avaliacao;
public:
    void SetCodigo(const Codigo& codigo);
    Codigo GetCodigo() const;
    void SetNome(const Nome& nome);
    Nome GetNome() const;
    void SetData(const Data& data);
    Data GetData() const;
    void SetHorario(const Horario& horario);
    Horario GetHorario() const;
    void SetDuracao(const Duracao& duracao);
    Duracao GetDuracao() const;
    void SetPreco(const Dinheiro& preco);
    Dinheiro GetPreco() const;
    void SetAvaliacao(const Avaliacao& avaliacao);
    Avaliacao GetAvaliacao() const;
};

class Destino
{
private:
    Codigo codigo;
    Nome nome;
    Avaliacao avaliacao;
    Data data_de_inicio;
    Data data_de_termino;
public:
    void SetCodigo(const Codigo& codigo);
    Codigo GetCodigo() const;
    void SetNome(const Nome& nome);
    Nome GetNome() const;
    void SetAvaliacao(const Avaliacao& avaliacao);
    Avaliacao GetAvaliacao() const;
    void SetData_Inicio(const Data& data_de_inicio);
    Data GetData_Inicio() const;
    void SetData_Termino(const Data& data_de_termino);
    Data GetData_Termino() const;
};

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
    Nome GetNome() const;
    void SetAvaliacao(const Avaliacao& avaliacao);
    Avaliacao GetAvaliacao() const;
};

class Hospedagem
{
private:
    Nome nome_hospedagem;
    Dinheiro diaria_hospedagem;
    Avaliacao avaliacao_hospedagem;
public:
    void SetNome(const Nome&);
    Nome GetNome() const;
    void SetDiaria(const Dinheiro&);
    Dinheiro GetDiaria() const;
    void SetAvaliacao(const Avaliacao&);
    Avaliacao GetAvaliacao() const;
};

#endif // ENTIDADE_H_INCLUDED
