#ifndef CONTROLADORAS_H_INCLUDED
#define CONTROLADORAS_H_INCLUDED
#include "Interfaces.h"


class CntrControleAcesso
{
    public:
    void iniciarControle();
};

class CntrIAS:public IAutenticacaoServico{
    public:
    bool autenticarConta(const Conta);
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


class CntrICA : public IContaApresentacao{
private:
    IContaServico *cntrServicoConta;
    bool criarConta();
public:
    void executar(Codigo*);
    void setCntrServicoConta(IContaServico*);
};
inline void CntrICA::setCntrServicoConta(IContaServico *cntrServicoConta){
    this->cntrServicoConta = cntrServicoConta;
};

class CntrIVA:public IViagemApresetacao{
private:
    IViagemServico *cntrServicoViagem;
    void executar(Codigo);
    
    //Menus
    void menuViagem();
    void menuHospedagem();
    void menuDestino();
    void menuAtividade();

    //Menus de viagem
    void menuCriarViagem();
    void menuExcluirViagem();
    void menuLerViagem();
    void menuAtualizarViagem();

    //Menus de hospedagem
    void menuCriarHospedagem();
    void menuExcluirHospedagem();
    void menuLerHospedagem();
    void menuAtualizarHospedagem();

    //Menus de destino
    void menuCriarDestino();
    void menuExcluirDestino();
    void menuLerDestino();
    void menuAtualizarDestino();

    //Menus de atividade
    void menuCriarAtividade();
    void menuExcluirAtividade();
    void menuLerAtividade();
    void menuAtualizarAtividade();

public:
    void setCntrServicoViagem(IViagemServico*);
};

inline void CntrIVA::setCntrServicoViagem(IViagemServico *cntrServicoViagem){
    this->cntrServicoViagem = cntrServicoViagem;
};

//Controladoras De Serviço
class CntrICS : public IContaServico
{
public:
    bool criarConta(const Conta);
    bool excluirConta(const Codigo);
    bool lerConta(Conta*);
    bool atualizarConta(const Conta);
};

class CntrIVS : public IViagemServico

{
    public:
    bool criarViagem(const Viagem);
    bool excluirViagem(const Codigo);
    bool lerViagem(Viagem*);
    bool atualizarViagem(const Viagem);

    bool criarHospedagem(const Hospedagem, const Codigo);
    bool excluirHospedagem(const Codigo);
    bool lerHospedagem(Hospedagem*);
    bool atualizarHospedagem(const Hospedagem);

    bool criarDestino(const Destino, const Codigo);
    bool excluirDestino(const Codigo);
    bool lerDestino(Destino*);
    bool atualizarDestino(const Destino);

    bool criarAtividade(const Atividade, const Codigo);
    bool excluirAtividade(const Codigo);
    bool lerAtividade(Atividade*);
    bool atualizarAtividade(const Atividade);
    
};

#endif //CONTROLADORAS_H_INCLUDED