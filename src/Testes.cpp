#include "Testes.h"
//Avalicao
void TUavaliacao::setUp(){
    avaliacao = new Avaliacao();
    estado = SUCESSO;
}
void TUavaliacao::tearDown(){
    delete avaliacao;
}
void TUavaliacao::TestarCasoValido(){
    try{
        avaliacao->SetValor(VALOR_VALIDO);
        if(avaliacao->GetValor() != VALOR_VALIDO){
            estado = FALHA;
        }
    }catch(invalid_argument &e){
        estado = FALHA;
    }
}
void TUavaliacao::TestarCasoInvalido(){
    try{
        avaliacao->SetValor(VALOR_INVALIDO);
        estado = FALHA;
    }catch(invalid_argument &e){
        if(avaliacao->GetValor() == VALOR_INVALIDO){
            estado = FALHA;
        }
    }
}

int TUavaliacao::run(){
    setUp();
    TestarCasoValido();
    TestarCasoInvalido();
    tearDown();
    return estado;
}

//Codigo
void TUcodigo::setUp(){
    codigo = new Avaliacao();
    estado = SUCESSO;
}
void TUcodigo::tearDown(){
    delete codigo;
}
void TUcodigo::TestarCasoValido(){
    try{
        codigo->SetCodigo(VALOR_VALIDO);
        if(codigo->GetCodigo() != VALOR_VALIDO){
            estado = FALHA;
        }
    }catch(invalid_argument &e){
        estado = FALHA;
    }
}
void TUcodigo::TestarCasoInvalido(){
    try{
        codigo->SetCodigo(VALOR_INVALIDO);
        estado = FALHA;
    }catch(invalid_argument &e){
        if(codigo->GetCodigo() == VALOR_INVALIDO){
            estado = FALHA;
        }
    }
}

int TUcodigo::run(){
    setUp();
    TestarCasoValido();
    TestarCasoInvalido();
    tearDown();
    return estado;
}
