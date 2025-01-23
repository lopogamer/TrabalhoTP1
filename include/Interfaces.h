#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED
#include "Dominios.h"
#include "Entidade.h"
#include <stdexcept>

using namespace std;

// CAMADA DE APRESENTAÇÃO
class IContaApresentacao;
class IAutenticacaoApresentacao;
class IViagemApresetacao;
class IContaServico;
class IAutenticacaoServico;
class IViagemServico;



class IContaApresentacao{
public:
    virtual void criarConta() = 0;
    virtual void executar(Codigo*) = 0;
    virtual void setCntrServicoConta(IContaServico*) = 0;
    virtual ~IContaApresentacao(){};
};


class IAutenticacaoApresentacao{
public:
    virtual bool autenticar(Codigo*) = 0;
    virtual void setCntrServicoAutenticacao(IAutenticacaoServico*) = 0;
    virtual ~IAutenticacaoApresentacao(){};
};

class IViagemApresetacao{
public:
    virtual void executar(const Codigo) = 0;
    virtual void setCntrServicoViagem(IViagemServico*) = 0;
    virtual ~IViagemApresetacao(){};
};



// CAMADA DE SERVIÇO

class IContaServico{
public:
    virtual bool criarConta(const Conta) = 0;
    virtual bool excluirConta(const Codigo) = 0;
    virtual bool lerConta(Conta*) = 0;
    virtual bool atualizarConta(const Conta) = 0;

    virtual ~IContaServico(){};

};

class IAutenticacaoServico{
public:
    virtual bool autenticarConta(const Conta) = 0;
    virtual ~IAutenticacaoServico(){};

};

class IViagemServico{
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

    virtual ~IViagemServico(){};
};

#endif //INTERFACES_H_INCLUDED