#include "Dominios.h"
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <regex>
using namespace std;

bool Senha::validar(string k) {
    if (k.size() != 5) {
        return false;
    }

    vector<bool> Duplicado(10, false);
    for (int i = 0; i < 5; i++) {
        if (k[i] < '0' || k[i] > '9') {
            return false;
        }

        if (Duplicado[k[i] - '0']) {
            return false;
        }

        Duplicado[k[i] - '0'] = true;
    }

    bool crescente = true, decrescente = true;
    for (int i = 0; i < 4; i++) {
        if (k[i] + 1 != k[i + 1]) {
            crescente = false;
        }
        if (k[i] - 1 != k[i + 1]) {
            decrescente = false;
        }
    }

    if (crescente || decrescente) {
        return false;
    }
    return true;
}

bool Senha::SetSenha(string senha) {
    if (validar(senha)) {
        this->senha = senha;
        cout << "Senha Definida Com Sucesso" << endl;
        return true;
    } else {
        cout << "Erro ao definir a senha: Senha inválida" << endl;
        return false;
    }
}

bool Horario::Validar(string hora) {
    if (hora.size() != 5 || hora[2] != ':') {
        return false;
    }

    string Horas = hora.substr(0, 2);
    string Minutos = hora.substr(3, 2);
    int horasInt = stoi(Horas);
    int minutosInt = stoi(Minutos);

    if (horasInt < 0 || horasInt > 23) {
        return false;
    }
    if (minutosInt < 0 || minutosInt > 59) {
        return false;
    }
    return true;
}

bool Horario::SetHora(string hora) {
    if (Validar(hora)) {
        this->hora = hora;
        cout << "Hora Definida Com Sucesso" << endl;
        return true;
    } else {
        cout << "Erro ao definir Horario." << endl;
        return false;
    }
}

bool Dinheiro::Validar(const string& quantidade) {
    regex pattern(R"(^(200000(\.00?)?|[0-1]?\d{1,5}(\.\d{1,2})?)$)");
    return regex_match(quantidade, pattern);
}

bool Dinheiro::SetDinheiro(string quantidade) {
    if (Validar(quantidade)) {
        this->quantidade = quantidade;
        cout << "Dinheiro Setado com sucesso" << endl;
        return true;
    } else {
        cout << "Dinheiro Não Setado" << endl;
        return false;
    }
}

bool Avaliacao::Validar(int valor) const {
    return valor >= 0 && valor <= 5;
}

bool Avaliacao::setValor(int valor) {
    if (!Validar(valor)) {
        return false;
    }
    digito_ = valor;
    return true;
}

bool Nome::setNome(string nome) {
    if (Validar(nome)) {
        nome_ = nome;
        return true;
    }
    return false;
}

bool Nome::Validar(string nome) {
    return nome.length() <= 30 && !nome.empty();
}

bool Duracao::validar(int valor) {
    return valor >= 0 && valor <= 360;
}

bool Duracao::SetValor(int valor) {
    if (validar(valor)) {
        this->valor = valor;
        return true;
    } else {
        return false;
    }
}

bool Codigo::validar(string& codigo) {
    regex pattern("^[A-Za-z0-9]{6}$");
    return regex_match(codigo, pattern);
}

bool Codigo::SetCodigo(string codigo) {
    if (validar(codigo)) {
        this->codigo = codigo;
        return true;
    } else {
        return false;
    }
}

bool Data::validar(int d, int m, int a) const {
    if (m < 1 || m > 12) {
        return false;
    }

    if (d < 1 || d > 31) {
        return false;
    }

    if (a < 0 || a > 99) {
        return false;
    }

    int diasPorMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Ajusta para fevereiro em ano bissexto
    if (m == 2 && bissexto(a)) diasPorMes[1] = 29;

    return d >= 1 && d <= diasPorMes[m - 1];

}

bool Data::bissexto(int a) const {
    return (a % 4 == 0 && a % 100 != 0) || a % 400 == 0;
}

bool Data::SetData(int d, int m, int a) {
    if (validar(d, m, a)) {
        dia_ = d;
        mes_ = m;
        ano_ = a;
        return true;
    }
    return false;
}


