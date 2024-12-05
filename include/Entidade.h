
#ifndef ENTIDADE_H_INCLUDED
#define ENTIDADE_H_INCLUDED
#include "Dominios.h"
#include <string>
using namespace std;
/// @file Entidade.h
/// @brief Declaraçoes das classes-Entidade
/// Este arquivo contem as declaraçoes das classes Entidade com a declaraçao dos metodos Set, Get
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


/// @author Ribeiro, Luan - 232036958
/// @brief Classe para representar a conta de um usuário.
/// 
/// A conta e composta por um objeto do tipo Codigo e um objeto do tipo Senha.
class Conta
{
private:
    Codigo codigo;
    Senha senha;

public:
    /// @brief Seta um valor do objeto codigo da classe conta, passando um objeto do tipo Codigo validado.
    /// @param codigo Objeto do tipo Codigo para ser atribuido ao atributo codigo.
    void SetCodigo(const Codigo& codigo);

    /// @brief Retorna Objeto do tipo Codigo que contem o valor do atributo codigo.
    /// @return Objeto Codigo.
    Codigo GetCodigo() const;

    /// @brief Seta um valor do objeto senha da classe conta, passando um objeto do tipo Senha validado.
    /// @param senha Objeto do tipo Senha para ser atribuido ao atributo senha.
    void SetSenha(const Senha& senha);

    /// @brief Retorna Objeto do tipo Senha que contem o valor do atributo senha.
    /// @return Objeto Senha.
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
