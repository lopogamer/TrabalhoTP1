#include "Dominios.h"
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <regex>
using namespace std;

bool Senha::Validar(string senha)
{
    if (senha.size() != 5)
        return false;
    vector<bool> Duplicado(10, false);
    for (int i = 0; i < 5; i++) {
        if (senha[i] < '0' || senha[i] > '9')
            return false;
        if (Duplicado[senha[i] - '0'])
            return false;
        Duplicado[senha[i] - '0'] = true;
    }
    bool crescente = true, decrescente = true;
    for (int i = 0; i < 4; i++) {
        if (senha[i] + 1 != senha[i + 1])
            crescente = false;
        if (senha[i] - 1 != senha[i + 1])
            decrescente = false;
    }
    return !(crescente || decrescente);
}

bool Senha::SetSenha(string senha)
{
    if (Validar(senha)) {
        this->senha = senha;
        cout << "Senha Definida Com Sucesso" << endl;
        return true;
    } else {
        cout << "Erro ao definir a senha: Senha inv�lida" << endl;
        return false;
    }
}

string Senha::GetSenha() const
{
    return senha;
}

bool Horario::Validar(string hora)
{
    if (hora.size() != 5 || hora[2] != ':')
        return false;
    string Horas = hora.substr(0, 2);
    string Minutos = hora.substr(3, 2);
    int horasInt = stoi(Horas);
    int minutosInt = stoi(Minutos);
    return (horasInt >= 0 && horasInt <= 23) && (minutosInt >= 0 && minutosInt <= 59);
}

bool Horario::SetHora(string hora)
{
    if (Validar(hora)) {
        this->hora = hora;
        cout << "Hora Definida Com Sucesso" << endl;
        return true;
    } else {
        cout << "Erro ao definir Horario." << endl;
        return false;
    }
}

string Horario::GetHora() const
{
    return hora;
}

bool Dinheiro::Validar(const string& quantidade)
{
    regex pattern(R"(^(200000(\.00?)?|[0-1]?\d{1,5}(\.\d{1,2})?)$)");
    return regex_match(quantidade, pattern);
}

bool Dinheiro::SetDinheiro(string quantidade)
{
    if (Validar(quantidade)) {
        this->quantidade = quantidade;
        cout << "Dinheiro Setado com sucesso" << endl;
        return true;
    } else {
        cout << "Dinheiro N�o Setado" << endl;
        return false;
    }
}

string Dinheiro::GetDinheiro() const
{
    return quantidade;
}

bool Avaliacao::Validar(int valor) const
{
    return valor >= 0 && valor <= 5;
}

bool Avaliacao::SetValor(int valor)
{
    if (Validar(valor)) {
        return true;
        this->digito = digito;
    }
    return false;
}

int Avaliacao::GetValor() const
{
    return digito;
}

bool Nome::Validar(string nome)
{
    return nome.length() <= 30 && !nome.empty();
}

bool Nome::SetNome(string nome)
{
    if (Validar(nome)) {
        nome = nome;
        return true;
    }
    return false;
}

string Nome::GetNome() const
{
    return nome;
}

bool Duracao::Validar(int valor)
{
    return valor >= 0 && valor <= 360;
}

bool Duracao::SetValor(int valor)
{
    if (Validar(valor)) {
        this->valor = valor;
        return true;
    }
    return false;
}

int Duracao::GetValor() const
{
    return valor;
}

bool Codigo::Validar(string& codigo)
{
    regex pattern("^[A-Za-z0-9]{6}$");
    return regex_match(codigo, pattern);
}

bool Codigo::SetCodigo(string codigo)
{
    if (Validar(codigo)) {
        this->codigo = codigo;
        return true;
    }
    return false;
}

string Codigo::GetCodigo() const
{
    return codigo;
}

bool Data::SetData(const string& data)
{
    if (Validar(data)) {
        this->data = data;
        return true;
    } else
        return false;
}

bool Data::Validar(const string& data) const
{
    if (data.length() != 8 || data[2] != '-' || data[5] != '-')
        return false;
    int dia = stoi(data.substr(0, 2));
    int mes = stoi(data.substr(3, 2));
    int ano = stoi(data.substr(6, 2));
    if (mes < 1 || mes > 12 || dia < 1 || dia > 31 || ano < 0 || ano > 99)
        return false;
    int diasPorMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (mes == 2) {
        if (bissexto(ano + 2000))
            diasPorMes[1] = 29;
    }
    return dia <= diasPorMes[mes - 1];
}


string Data::GetData() const
{
    return data;
}
