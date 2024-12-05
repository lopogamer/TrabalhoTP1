#include "Testes_Entidades.h"

void TUDestino :: setUp(){
    destino = new Destino();
    estado = SUCESSO;
}

void TUDestino :: tearDown(){
    delete destino;
}

void TUDestino :: testarCenario(){
    Nome nome;
    nome.SetNome(NOME_VALIDO);
    destino->SetNome(nome);
    if(destino->GetNome().GetNome() != NOME_VALIDO)
    estado = FALHA;
    Data data_inicio;
    data_inicio.SetData(DATA_INICIO_VALIDO);
    destino->SetData_Inicio(data_inicio);
    if(destino->GetData_Inicio().GetData() != DATA_INICIO_VALIDO)
    estado = FALHA;
    Data data_termino;
    data_termino.SetData(DATA_TERMINO_VALIDO);
    destino->SetData_Inicio(data_termino);
    if(destino->GetData_Termino().GetData() != DATA_TERMINO_VALIDO)
    estado = FALHA;
    Avaliacao avaliacao;
    avaliacao.SetAvaliacao(AVALIACAO_VALIDO);
    destino->SetAvaliacao(avaliacao);
    if(destino->GetAvaliacao().GetAvaliacao() != AVALIACAO_VALIDO)
    estado = FALHA;
    Codigo codigo;
    codigo.SetCodigo(CODIGO_VALIDO);
    destino->SetCodigo(codigo);
    if(destino->GetCodigo().GetCodigo() != CODIGO_VALIDO)
    estado = FALHA;

}

int TUDestino :: run(){

    setUp();
    testarCenario();
    tearDown();
    return estado;
    
}