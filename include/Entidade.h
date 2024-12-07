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
    void SetDataInicio(const Data& data_de_inicio);
    Data GetDataInicio() const;
    void SetDataTermino(const Data& data_de_termino);
    Data GetDataTermino() const;
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


/// @author João Gabriel - 232003607
/// @brief Classe que representa uma viagem.
/// @class Viagem
/// Esta classe representa uma viagem, que é composta pelos Domínios Codigo, Nome e Avaliacao.
class Viagem
{
private:
    Codigo codigo;
    Nome nome;
    Avaliacao avaliacao;
public:

    /// @brief Método que atribui o código da viagem, passando um objeto do tipo Codigo como parâmetro.
    /// @param codigo Objeto do tipo Codigo que será atribuído ao código da viagem.
    void SetCodigo(const Codigo& codigo);

    /// @brief Método que retorna o código da viagem.
    /// @return Codigo da viagem.
    Codigo GetCodigo() const;

    /// @brief Método que atribui o nome da viagem, passando um objeto do tipo Nome como parâmetro.
    /// @param nome Objeto do tipo Nome que será atribuído ao nome da viagem.
    void SetNome(const Nome& nome);

    /// @brief Método que retorna o nome da viagem.
    /// @return Nome da viagem.
    Nome GetNome() const;

    /// @brief Método que atribui a avaliação da viagem, passando um objeto do tipo Avaliacao como parâmetro.
    /// @param avaliacao Objeto do tipo Avaliacao que será atribuído à avaliação da viagem.
    void SetAvaliacao(const Avaliacao& avaliacao);

    /// @brief Método que retorna a avaliação da viagem.
    /// @return Avaliacao da viagem.
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
