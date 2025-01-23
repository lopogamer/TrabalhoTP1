#ifndef CONTROLADORAS_H_INCLUDED
#define CONTROLADORAS_H_INCLUDED
#include <iostream>
#include "Interfaces.h"
#include "Containers.h"


class CntrControleAcesso
{
    public:
        void iniciarControle();
};


class CntrICA:public IContaApresentacao{
private:
    IContaServico *cntrServicoConta;
public:
    void criarConta();
    void executar(Codigo);
    void setCntrServicoConta(IContaServico*);

};

inline void CntrICA::setCntrServicoConta(IContaServico *cntrServicoConta){
    this->cntrServicoConta = cntrServicoConta;
};

class CntrIAA:public IAutenticacaoApresentacao{
private:
    IAutenticacaoServico *cntrServicoAutenticacao;
public:
    bool autenticar(Codigo*);
    void setCntrServicoAutenticacao(IAutenticacaoServico*);
};

inline void CntrIAA::setCntrServicoAutenticacao(IAutenticacaoServico *cntrServicoAutenticacao){
    this->cntrServicoAutenticacao = cntrServicoAutenticacao;
};

class CntrIVA:public IViagemApresetacao{
private:
    IViagemServico *cntrServicoViagem;
public:
    void executar(Codigo);
    void setCntrServicoViagem(IViagemServico*);
};

inline void CntrIVA::setCntrServicoViagem(IViagemServico *cntrServicoViagem){
    this->cntrServicoViagem = cntrServicoViagem;
};

//Controladoras De Serviço
class CntrICS : public IContaServico
{
    ContainerConta containerConta;
public:
    bool criarConta(const Conta);
    bool excluirConta(const Codigo);
    bool lerConta(Conta*);
    bool atualizarConta(const Conta);
};

class CntrIVS : public IViagemServico
{
    ContainerViagem containerViagem;
    ContainerDestino containerDestino;
    ContainerAtividade containerAtividade;
    public:
    bool criarViagem(const Viagem);
    bool excluirViagem(const Codigo);
    bool lerViagem(Viagem*);
    bool atualizarViagem(const Viagem);

    bool criarHospedagem(const Hospedagem);
    bool excluirHospedagem(const Codigo);
    bool lerHospedagem(Hospedagem*);
    bool atualizarHospedagem(const Hospedagem);

    bool criarDestino(const Destino);
    bool excluirDestino(const Codigo);
    bool lerDestino(Destino*);
    bool atualizarDestino(const Destino);

    bool criarAtividade(const Atividade);
    bool excluirAtividade(const Codigo);
    bool lerAtividade(Atividade*);
    bool atualizarAtividade(const Atividade);
};

#endif //CONTROLADORAS_H_INCLUDED