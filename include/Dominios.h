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

///@class Avaliacao
///@author João Gabriel - 232003607
///@brief Classe que representa uma avaliação.
///
/// A Avaliação é válida se atender aos seguintes critérios:
///
/// - Ser um inteiro no intervalo de 0 a 5.
/// - Não pode ser um valor negativo.

class Avaliacao
{
private:
    int valor; // Atributo que representa a avaliação.
    void Validar(int); // Método que valida a avaliação.
public:

    ///@brief Método que atribui um valor à avaliação.
    /// Este método atribui um valor à avaliação,
    /// desde que este valor esteja no intervalo de 0 a 5.
    /// Ele chama o método Validar para verificar se o valor é válido.
    /// Se o valor for inválido, uma exceção do tipo "invalid_argument" é lançada.
    /// @param valor Valor a ser atribuído à avaliação.
    /// @throws invalid_argument Se o valor não atender aos critérios estabelecidos.

    void SetAvaliacao(int); // Método para atribuir um valor à avaliação.

    ///@brief Método para obter o valor da avaliação.
    /// Este método retorna o valor armazenado.
    /// @return valor da avaliação.

    int GetAvaliacao() const; // Método para obter o valor da avaliação.
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
    void SetDuracao(int);
    int GetDuracao() const;
};

class Codigo
{
private:
    string codigo;
    void Validar(string&);
public:
    void SetCodigo(string);
    string GetCodigo() const;
};


/// @class Data
/// @author João Gabriel - 232003607
/// @brief Classe que representa uma data.
///
/// A Data é válida se atender aos seguintes critérios:
///
/// - Ser uma string no formato DD-MM-AA.
/// - O dia deve estar no intervalo de 1 a 31.
/// - O mês deve estar no intervalo de 1 a 12.
/// - O ano deve estar no intervalo de 00 a 99.
/// - Se o ano for bissexto, o mês de fevereiro deve ter no máximo 29 dias.

class Data
{
private:
    string data; // Atributo que representa a data.
    void Validar(const string& data) const; // Método que valida a data.
    bool bissexto(int ano) const // Método que verifica se um ano é bissexto.
    {
        return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
    }
public:
    /// @brief Método para atribuir uma data.
    /// Este método atribui uma data, desde que ela atenda aos critérios estabelecidos.
    /// Ele chama o método Validar para verificar se a data é válida.
    /// Se a data for inválida, uma exceção do tipo "invalid_argument" é lançada.
    /// @param data Data a ser atribuída.
    /// @throws invalid_argument Se a data não atender aos critérios estabelecidos.

    void SetData(const string& data); // Método para atribuir uma data.

    /// @brief Método para obter a data.
    /// Este método retorna a data armazenada.
    /// @return data em formato de string.

    string GetData() const; // Método para obter a data.
};

#endif // DOMINIOS_H_INCLUDED
