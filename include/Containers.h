#ifndef CONTAINERS_H
#define CONTAINERS_H
#include <vector>
#include "Entidade.h"
using namespace std;

class ContainerConta{
    private:
    map<Codigo, Conta> contas;
    public:
    bool create(Conta);
    bool remove(Codigo);
    bool read(Conta*);
    bool update(Conta);
};

class ContainerViagem{
    private:
    map<Codigo, Viagem> viagens;
    public:
    bool create(Viagem);
    bool remove(Codigo);
    bool read(Viagem*);
    bool update(Viagem);
};

class ContainerDestino{
    private:
    map<Codigo, Destino> destinos;
    public:
    bool create(Destino);
    bool remove(Codigo);
    bool read(Destino*);
    bool update(Destino);
};

class ContainerHospedagem{
    private:
    map<Codigo, Hospedagem> hospedagens;
    public:
    bool create(Hospedagem);
    bool remove(Codigo);
    bool read(Hospedagem*);
    bool update(Hospedagem);
};

class ContainerAtividade{
    private:
    map<Codigo, Atividade> atividades;
    public:
    bool create(Atividade);
    bool remove(Codigo);
    bool read(Atividade*);
    bool update(Atividade);
};

#endif //CONTAINERS_H
