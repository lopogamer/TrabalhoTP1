#include "Dominios.h"
using namespace std;

//-----------------------------------------------------------------------------
//Implementação de métodos da classe Senha

void Senha::Validar(string senha)
{
    if (senha.size() != 5)
        throw invalid_argument("Valor invalido");
    vector<bool> Duplicado(10, false);
    for (int i = 0; i < 5; i++) {
        if (senha[i] < '0' || senha[i] > '9')
            throw invalid_argument("Valor invalido");
        if (Duplicado[senha[i] - '0'])
            throw invalid_argument("Valor invalido");
        Duplicado[senha[i] - '0'] = true;
    }
    bool crescente = true, decrescente = true;
    for (int i = 0; i < 4; i++) {
        if (senha[i] + 1 != senha[i + 1])
            crescente = false;
        if (senha[i] - 1 != senha[i + 1])
            decrescente = false;

    }
    if(crescente || decrescente)
        throw invalid_argument("Valor invalido");
}

void Senha::SetSenha(string senha)
{
    Validar(senha);
    this->senha = senha;

}

string Senha::GetSenha() const
{
    return senha;
}

void Horario::Validar(string hora)
{
    if (hora.size() != 5 || hora[2] != ':')
        throw invalid_argument("Valor invalido");
    string Horas = hora.substr(0, 2);
    string Minutos = hora.substr(3, 2);
    int horasInt = stoi(Horas);
    int minutosInt = stoi(Minutos);
    if (!((horasInt >= 0 && horasInt <= 23) && (minutosInt >= 0 && minutosInt <= 59)))
        throw invalid_argument("Valor invalido");
}

void Horario::SetHora(string hora)
{
    Validar(hora);
    this->hora = hora;

}

string Horario::GetHora() const
{
    return hora;
}

void Dinheiro::Validar(const string& quantidade)
{
    regex padrao(
        R"(^(([1-9]\d{0,2}(\.\d{3})*|[0-9]\d{0,4}|200\.000),00|[0-9]\d{0,4},\d{2}|[1-9]\d{0,2}(\.\d{3})*,\d{2}|0,\d{2})$)");
    if (!regex_match(quantidade, padrao))
        throw invalid_argument("Valor Invalido");
    string valorsemponto = quantidade;
    valorsemponto.erase(remove(valorsemponto.begin(), valorsemponto.end(), '.'), valorsemponto.end());
    string parte_int = valorsemponto.substr(0, valorsemponto.find(','));
    string parte_dec = valorsemponto.substr(valorsemponto.find(',') + 1);
    long valorcomparacao = stol(parte_int) * 100 + stol(parte_dec);
    if (valorcomparacao > 20000000)
        throw invalid_argument("Valor Invalido");

}

void Dinheiro::SetDinheiro(string quantidade)
{
    Validar(quantidade);
    this->quantidade = quantidade;
}

string Dinheiro::GetDinheiro() const
{
    return quantidade;
}

void Avaliacao::Validar(int valor)
{
    if (valor < 0 || valor > 5)
        throw invalid_argument("Valor invalido");
}

void Avaliacao::SetValor(int valor)
{
    Validar(valor);
    this -> valor = valor;
}

int Avaliacao::GetValor() const
{
    return valor;
}

void Nome::Validar(string nome)
{
    if(nome.length() > 30 || nome.empty())
        throw invalid_argument("Valor invalido");
}


void Nome::SetNome(string nome)
{
    Validar(nome);
    this -> nome = nome;
}


string Nome::GetNome() const
{
    return nome;
}

void Duracao::Validar(int valor)
{
    if(valor < 0 || valor > 360)
        throw invalid_argument("Valor de duracao invalido");
}

void Duracao::SetValor(int valor)
{
    Validar(valor);
    this->valor = valor;
}

int Duracao::GetValor() const
{
    return valor;
}

void Codigo::Validar(string& codigo)
{
    regex pattern("^[A-Za-z0-9]{6}$");
    if (!regex_match(codigo, pattern))
        throw invalid_argument("Argumento inválido.");
}

void Codigo::SetCodigo(string codigo)
{
    Validar(codigo);
    this->codigo = codigo;
}

string Codigo::GetCodigo() const
{
    return codigo;
}

void Data::SetData(const string& data)
{
    Validar(data);
    this -> data = data;
}


void Data::Validar(const string& data) const
{
    if (data.length() != 8 || data[2] != '-' || data[5] != '-')
        throw invalid_argument("Valor invalido");

    int dia = std::stoi(data.substr(0, 2));
    int mes = std::stoi(data.substr(3, 2));
    int ano = std::stoi(data.substr(6, 2));

    if (mes < 1 || mes > 12 || dia < 1 || dia > 31 || ano < 0 || ano > 99)
        throw invalid_argument("Valor invalido");

    int diasPorMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };


    if (mes == 2 && bissexto(ano + 2000))   // Considera ano 2000+ para simplificação
        diasPorMes[1] = 29;

    if (mes == 2 && dia == 29 && !bissexto(ano + 2000))
        throw invalid_argument("Valor invalido");

    if (dia > diasPorMes[mes - 1])
        throw invalid_argument("Valor invalido");
}



string Data::GetData() const
{
    return data;
}
