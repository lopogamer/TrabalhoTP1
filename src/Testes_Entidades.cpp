#include "Testes_Entidades.h"
#include "Dominios.h"

void TUAtividade::setUp()
{
    atividade = new Atividade();
    estado = SUCESSO;
}

void TUAtividade::tearDown()
{
    delete atividade;
}
void TUAtividade::testarCenario(){
    Codigo codigo;
    codigo.SetCodigo(VALOR_VALIDO_CODIGO);
    atividade->SetCodigo(codigo);
    if(atividade->GetCodigo().GetCodigo() != VALOR_VALIDO_CODIGO){estado = FALHA;}
    Nome nome;
    nome.SetNome(VALOR_VALIDO_NOME);
    atividade->SetNome(nome);
    if(atividade->GetNome().GetNome()!= VALOR_VALIDO_NOME){estado = FALHA;}
    Data data;
    data.SetData(VALOR_VALIDO_DATA);
    atividade->SetData(data);
    if(atividade->GetData().GetData()!= VALOR_VALIDO_DATA){estado = FALHA;}
    Horario horario;
    horario.SetHora(VALOR_VALIDO_HORARIO);
    atividade->SetHorario(horario);
    if(atividade->GetHorario().GetHora()!= VALOR_VALIDO_HORARIO){estado = FALHA;}
    Duracao duracao;
    duracao.SetValor(VALOR_VALIDO_DURACAO);
    atividade->SetDuracao(duracao);
    if(atividade->GetDuracao().GetValor()!= VALOR_VALIDO_DURACAO){estado = FALHA;}
    Dinheiro preco;
    preco.SetDinheiro(VALOR_VALIDO_PRECO);
    atividade->SetPreco(preco);
    if(atividade->GetPreco().GetDinheiro()!= VALOR_VALIDO_PRECO){estado = FALHA;}
    Avaliacao avaliacao;
    avaliacao.SetValor(VALOR_VALIDO_AVALIACAO);
    atividade->SetAvaliacao(avaliacao);
    if(atividade->GetAvaliacao().GetValor()!= VALOR_VALIDO_AVALIACAO){estado = FALHA;}
}
int TUAtividade::run()
{
    setUp();
    testarCenario();
    tearDown();
    return estado;
}void TUDestino :: setUp(){
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
    destino->SetData_Termino(data_termino);
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