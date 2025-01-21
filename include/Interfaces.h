#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED
#include "Dominios.h"
#include "Entidade.h"
#include <stdexcept>

using namespace std;

// CAMADA DE APRESENTAÇÃO
class ICA;
class IAA;
class IVA;
class ICS;
class IAS;
class IVS;



class ICA{
public:
    virtual void criarConta() = 0;
    virtual void executar(Codigo*) = 0;
    virtual void setCntrServicoConta(ICS*) = 0;
    virtual ~ICA(){}; // Destrutor virtual
};


class IAA{
public:
    virtual bool autenticar(Codigo*) = 0;
    virtual void setCntrServicoAutenticacao(IAS*) = 0;
    virtual ~IAA(){}; 
};

class IVA{
public:
    virtual void executar(const Codigo) = 0;
    virtual void setCntrServicoViagem(IVS*) = 0;
    virtual ~IVA(){}; 
};



// CAMADA DE SERVIÇO

class ICS{
public:
    virtual bool criarConta(const Conta) = 0;
    virtual bool excluirConta(const Codigo) = 0;
    virtual bool lerConta(Conta*) = 0;
    virtual bool atualizarConta(const Conta) = 0;

    virtual ~ICS(){};

};

class IAS{
public:
    virtual bool autenticarConta(const Conta) = 0;
    virtual ~IAS(){};

};

class IVS{
public:
    virtual bool criarViagem(const Viagem) = 0;
    virtual bool excluirViagem(const Codigo) = 0;
    virtual bool lerViagem(Viagem*) = 0;
    virtual bool atualizarViagem(const Viagem) = 0;

    virtual bool criarHospedagem(const Hospedagem) = 0;
    virtual bool excluirHospedagem(const Codigo) = 0;
    virtual bool lerHospedagem(Hospedagem*) = 0;
    virtual bool atualizarHospedagem(const Hospedagem) = 0;

    virtual bool criarDestino(const Destino) = 0;
    virtual bool excluirDestino(const Codigo) = 0;
    virtual bool lerDestino(Destino*) = 0;
    virtual bool atualizarDestino(const Destino) = 0;

    virtual bool criarAtividade(const Atividade) = 0;
    virtual bool excluirAtividade(const Codigo) = 0;
    virtual bool lerAtividade(Atividade*) = 0;
    virtual bool atualizarAtividade(const Atividade) = 0;

    virtual ~IVS(){};
};

#endif //INTERFACES_H_INCLUDED