#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

///@class Avaliacao
///@author João Gabriel - 232003607
///@brief Classe que representa uma avaliação.
///
/// A Avaliação é **válida** se atender aos seguintes critérios:
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
    /// Este método atribui um valor ao objeto,
    /// desde que este valor esteja no intervalo de 0 a 5.
    /// Ele chama o método "Validar" para verificar se o valor é válido.
    /// Se o valor for inválido, uma exceção do tipo "invalid_argument" é lançada.
    /// @param inteiro que será atribuído.
    /// @throws invalid_argument Se o valor não atender aos critérios estabelecidos.

    void SetAvaliacao(int); // Método para atribuir um valor à avaliação.

    ///@brief Método para obter o valor da avaliação.
    /// Este método retorna o valor armazenado no objeto.
    /// @return inteiro O valor armazenado.

    int GetAvaliacao() const; // Método para obter o valor da avaliação.
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
/// @author Luan - 232036958
/// @brief Classe que representa uma data.
///
/// A Data é **válida** se atender aos seguintes critérios:
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
    /// Este método atribui uma data para o objeto, desde que ela atenda aos critérios estabelecidos.
    /// Ele chama o método "Validar" para verificar se a data é válida.
    /// Se a data for inválida, uma exceção do tipo "invalid_argument" é lançada.
    /// @param string que será atribuída.
    /// @throws invalid_argument Se a data não atender aos critérios estabelecidos.

    void SetData(const string& data); // Método para atribuir uma data.

    /// @brief Método para obter a data.
    /// Este método retorna a data armazenada no objeto.
    /// @return string A data armazenada.

    string GetData() const; // Método para obter a data.
};

/// @class Dinheiro
/// @author Alan - 232007830
/// @brief Classe para representar dinheiro.
///
/// O Dinheiro é **válido** se atender as seguintes regras:
///
/// - O valor informado tem que ser entre 0,00 a 200.000,00
/// - Use vírgulas como separadores decimais e pontos para milhares.
class Dinheiro
{
private:
    string quantidade; // Atributo que representa a quantia de dinheiro.
    void Validar(const string&); // Método para validar dinheiro.
public:
    /// @brief Método para atribuir o dinheiro.
    /// Este método tem o objetivo de atribuir o valor fornecido ao objeto. Antes disso,
    /// ele chama o método "Validar" para garantir que o quantia atenda os devidos requisitos de formatação.
    /// Em caso de quantia inválido, o método "Validar" lançará uma excessão do tipo "invalid_argument"
    /// @param string valor a ser setado
    /// @throws invalid_argument se o valor não atender as regras de formatação.


    void SetDinheiro(string);

    /// @brief Método para obter o dinheiro.
    /// Este método retorna o dinheiro armazenado no objeto.
    /// @return string dinheiro armazenada no objeto.

    string GetDinheiro() const; //Método para obter o Dinheiro.
};

/// @class Duração
/// @author Alan - 232007830
/// @brief Classe para representar a duração.
///
/// A Duração é **válida** se atender a seguinte regra:
/// - A duração informada ser um número inteiro de 0 a 360.
///
class Duracao
{
private:
    int valor; // Atributo que representa a duração.
    void Validar(int); // Método para validar a duração
public:

    /// @brief Método para atribuir a duração.
    /// Este método seta o valor da duração fornecida ao objeto. Entretanto, antes disso,
    /// é feito a chamada do método "Validar" para verificar se a duração informada possui os requisitos.
    /// Em caso de duração inválida, o método "Validar" jogará uma excessão do tipo "invalid_argument"
    /// @param string duração a ser atribuída
    /// @throws invalid_argument se a duração não atender os requisitos de formato.

    void SetDuracao(int); 

    /// @brief Método para obter a duração.
    /// Este método retorna a duração armazenada no objeto.
    /// @return inteiro "duração" armazenado no objeto.

    int GetDuracao() const; //Método para obter a duração.
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


class Nome
{
private:
    string nome;
    void Validar(string nome);
public:
    void SetNome(string nome);
    string GetNome() const;
};

class Senha
{
private:
    string senha;
    void Validar(string);
public:
    void SetSenha(string);
    string GetSenha() const;
};

#endif // DOMINIOS_H_INCLUDED

