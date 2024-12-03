#include "Testes_Entidades.h"
using namespace std;

void TUViagem::setUp(){
    viagem = new Viagem();
    estado = SUCESSO;
}

void TUViagem::tearDown(){
    delete viagem;
}

void TUViagem::testarCenarioSucesso(){
    Codigo codigo;
    codigo.SetCodigo(CODIGO_VALIDO);
    viagem->SetCodigo(codigo);
    if(viagem->GetCodigo().GetCodigo() != CODIGO_VALIDO)
        estado = FALHA;

    Nome nome;
    nome.SetNome(NOME_VALIDO);
    viagem->SetNome(nome);
    if(viagem->GetNome().GetNome() != NOME_VALIDO)
        estado = FALHA;

    Avaliacao avaliacao;
    avaliacao.SetAvaliacao(AVALIACAO_VALIDO);
    viagem->SetAvaliacao(avaliacao);
    if(viagem->GetAvaliacao().GetAvaliacao() != AVALIACAO_VALIDO)
        estado = FALHA;


}

int TUViagem::run(){
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}

void TUConta::setUp(){
    conta = new Conta();
    estado = SUCESSO;
}

void TUConta::tearDown(){
    delete conta;
}

void TUConta::testarCenarioSucesso(){
    Codigo codigo;
    codigo.SetCodigo(CODIGO_VALIDO);
    conta->SetCodigo(codigo);
    if(conta->GetCodigo().GetCodigo() != CODIGO_VALIDO)
        estado = FALHA;

    Senha senha;
    senha.SetSenha(SENHA_VALIDO);
    conta->SetSenha(senha);
    if(conta->GetSenha().GetSenha() != SENHA_VALIDO)
        estado = FALHA;
}

int TUConta::run(){
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}






