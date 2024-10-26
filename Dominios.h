#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <string>
using namespace std;

class Senha {
private:
    string senha;
    bool validar(string);

public:
    bool SetSenha(string);
    string GetSenha() const;
};

inline string Senha::GetSenha() const {
    return senha;
}

class Horario {
private:
    string hora;
    bool Validar(string);

public:
    bool SetHora(string);
    string GetHora() const;
};

inline string Horario::GetHora() const {
    return hora;
}

class Dinheiro {
private:
    string quantidade;
    bool Validar(const string&);

public:
    bool SetDinheiro(string);
    string GetDinheiro() const;
};

inline string Dinheiro::GetDinheiro() const {
    return quantidade;
}

class Avaliacao {
private:
    int digito_;
    bool Validar(int valor) const;

public:
    bool setValor(int valor);
    int getValor() const;
};

inline int Avaliacao::getValor() const {
    return digito_;
}

class Nome {
private:
    string nome_;
    bool Validar(string nome);

public:
    bool setNome(string nome);
    string getNome() const;
};

inline string Nome::getNome() const {
    return nome_;
}

class Duracao {
private:
    int valor;
    bool validar(int);

public:
    bool SetValor(int);
    int GetValor() const;
};

inline int Duracao::GetValor() const {
    return valor;
}

class Codigo {
private:
    string codigo;
    bool validar(string&);

public:
    bool SetCodigo(string);
    string GetCodigo() const;
};

inline string Codigo::GetCodigo() const {
    return codigo;
}

#endif // DOMINIOS_H_INCLUDED
