#ifndef CONTROLADORAS_H_INCLUDED
#define CONTROLADORAS_H_INCLUDED
#include <iostream>
#include "Interfaces.h"

class CntrICA:public ICA{
private:
    ICS *cntrServicoConta;
public:
    void criarConta();
    void executar(Codigo);
    void setCntrServicoConta(ICS*);

};

inline void CntrICA::setCntrServicoConta(ICS *cntrServicoConta){
    this->cntrServicoConta = cntrServicoConta;
};

class CntrIAA:public IAA{
private:
    IAS *cntrServicoAutenticacao;
public:
    bool autenticar(Codigo*);
    void setCntrServicoAutenticacao(IAS*);
};

inline void CntrIAA::setCntrServicoAutenticacao(IAS *cntrServicoAutenticacao){
    this->cntrServicoAutenticacao = cntrServicoAutenticacao;
};

class CntrIVA:public IVA{
private:
    IVS *cntrServicoViagem;
public:
    void executar(Codigo);
    void setCntrServicoViagem(IVS*);
};

inline void CntrIVA::setCntrServicoViagem(IVS *cntrServicoViagem){
    this->cntrServicoViagem = cntrServicoViagem;
};



#endif //CONTROLADORAS_H_INCLUDED