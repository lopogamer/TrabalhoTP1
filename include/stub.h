#ifndef STUB_H
#define STUB_H

#include "Interfaces.h"
#include "Dominios.h"
#include "Entidade.h"
#include <iostream>
#include <string>
using namespace std;

class StubIAS : public IAS {
private:
    const string TRIGGER_FALHA = "123456";
public:
    bool autenticarConta(Conta) override;
};

#endif // STUB_H
