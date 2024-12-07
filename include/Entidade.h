#ifndef ENTIDADE_H_INCLUDED
#define ENTIDADE_H_INCLUDED
#include "Dominios.h"
#include <string>
using namespace std;

/// @author João Gabriel - 232003607
/// @brief Classe que representa uma atividade.
/// @class Atividade
/// Esta classe representa uma atividade, que é composta pelos Domínios Codigo, Nome, Data, Horario, Duracao, Dinheiro e Avaliacao.
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

    /// @brief Método que atribui o código da atividade, passando um objeto do tipo Codigo como parâmetro.
    /// @param codigo objeto do tipo Codigo que será atribuído ao código da viagem.
    void SetCodigo(const Codigo& codigo);

    /// @brief Método que retorna o código da viagem.
    /// @return Objeto do tipo Codigo.
    Codigo GetCodigo() const;

    /// @brief Método que atribui o nome da atividade, passando um objeto do tipo Nome como parâmetro.
    /// @param nome objeto do tipo Nome que será atribuído ao nome da atividade.
    void SetNome(const Nome& nome);

    /// @brief Método que retorna o nome da atividade.
    /// @return Objeto do tipo Nome.
    Nome GetNome() const;

    /// @brief Método que atribui a data da atividade, passando um objeto do tipo Data como parâmetro.
    /// @param data objeto do tipo Data que será atribuído à data da atividade.
    void SetData(const Data& data);

    /// @brief Método que retorna a data da atividade.
    /// @return Objeto do tipo Data.
    Data GetData() const;

    /// @brief Método que atribui o horário da atividade, passando um objeto do tipo Horario como parâmetro.
    /// @param horario objeto do tipo Horario que será atribuído ao horário da atividade.
    void SetHorario(const Horario& horario);

    /// @brief Método que retorna o horário da atividade.
    /// @return Objeto do tipo Horario.
    Horario GetHorario() const;

    /// @brief Método que atribui a duração da atividade, passando um objeto do tipo Duracao como parâmetro.
    /// @param duracao objeto do tipo Duracao que será atribuído à duração da atividade.
    void SetDuracao(const Duracao& duracao);

    /// @brief Método que retorna a duração da atividade.
    /// @return Objeto do tipo Duracao.
    Duracao GetDuracao() const;

    /// @brief Método que atribui o preço da atividade, passando um objeto do tipo Dinheiro como parâmetro.
    /// @param preco objeto do tipo Dinheiro que será atribuído ao preço da atividade.
    void SetPreco(const Dinheiro& preco);

    /// @brief Método que retorna o preço da atividade.
    /// @return Objeto do tipo Dinheiro.
    Dinheiro GetPreco() const;

    /// @brief Método que atribui a avaliação da atividade, passando um objeto do tipo Avaliacao como parâmetro.
    /// @param avaliacao objeto do tipo Avaliacao que será atribuído à avaliação da atividade.
    void SetAvaliacao(const Avaliacao& avaliacao);

    /// @brief Método que retorna a avaliação da atividade.
    /// @return Objeto do tipo Avaliacao.
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

/// @author Luan - 232036958
/// @class Hospedagem
/// @brief Classe que representa uma hospedagem.
/// Esta classe representa uma hospedagem, que é composta pelos Domínios Nome, Dinheiro e Avaliacao.

class Hospedagem
{
private:
    Nome nome_hospedagem;
    Dinheiro diaria_hospedagem;
    Avaliacao avaliacao_hospedagem;
public:
    /// @brief Método que atribui o nome da hospedagem, passando um objeto do tipo Nome ja validado como parâmetro.
    /// @param Nome objeto do tipo Nome que será atribuído ao nome da hospedagem.
    void SetNome(const Nome&);
    
    /// @brief Método que retorna o nome da hospedagem.
    /// @return Objeto do tipo Nome.
    Nome GetNome() const;

    /// @brief Método que atribui a diária da hospedagem, passando um objeto do tipo Dinheiro ja validado como parâmetro.
    /// @param Dinheiro objeto do tipo Dinheiro que será atribuído à diária da hospedagem.
    void SetDiaria(const Dinheiro&);

    /// @brief Método que retorna a diária da hospedagem.
    /// @return Objeto do tipo Dinheiro.
    Dinheiro GetDiaria() const;

    /// @brief Método que atribui a avaliação da hospedagem, passando um objeto do tipo Avaliacao ja validado como parâmetro.
    /// @param Avaliacao objeto do tipo Avaliacao que será atribuí
    void SetAvaliacao(const Avaliacao&);

    /// @brief Método que retorna a avaliação da hospedagem.
    /// @return Objeto do tipo Avaliacao.
    Avaliacao GetAvaliacao() const;
};

#endif // ENTIDADE_H_INCLUDED
