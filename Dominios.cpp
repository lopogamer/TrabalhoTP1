#include "Dominios.h"
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <regex>
using namespace std;

bool Senha::validar(string k) {

    if (k.size() != 5){

        return false;

    }

    vector<bool> Duplicado(10, false);

    for (int i = 0; i < 5; i++) {

        if (k[i] < '0' || k[i] > '9'){

            return false;

        }

        if (Duplicado[k[i] - '0']){

            return false;

        }

        Duplicado[k[i] - '0'] = true;
    }

    bool crescente = true, decrescente = true;

    for (int i = 0; i < 4; i++) {

        if (k[i] + 1 != k[i + 1]) crescente = false;

        if (k[i] - 1 != k[i + 1]) decrescente = false;

    }

    if(crescente or decrescente){

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
        cout << "Erro ao definir a senha: Senha inv�lida" << endl;
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


bool Horario::SetHora(string hora){
    if(Validar(hora)){
        this -> hora = hora;
        cout << "Hora Definida Com Succeso";
        return true;
    }else{
        cout << "Erro ao definir Horario: " << endl;
        return false;
    }
}


bool Dinheiro::Validar(const string& quantidade) {
        regex pattern(R"(^(200000(\.00?)?|[0-1]?\d{1,5}(\.\d{1,2})?)$)");
        return regex_match(quantidade, pattern);
}
bool Dinheiro::SetDinheiro(string quantidade){
    if(Validar(quantidade)){
        this -> quantidade = quantidade;
        cout << "Dinheiro Setado com sucesso" << endl;
        return true;
    }else{
        cout << "Dinheiro Nao Setado" << endl;
        return false;
    }
}