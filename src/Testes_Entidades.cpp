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
    duracao.SetDuracao(VALOR_VALIDO_DURACAO);
    atividade->SetDuracao(duracao);
    if(atividade->GetDuracao().GetDuracao()!= VALOR_VALIDO_DURACAO){estado = FALHA;}
    Dinheiro preco;
    preco.SetDinheiro(VALOR_VALIDO_PRECO);
    atividade->SetPreco(preco);
    if(atividade->GetPreco().GetDinheiro()!= VALOR_VALIDO_PRECO){estado = FALHA;}
    Avaliacao avaliacao;
    avaliacao.SetAvaliacao(VALOR_VALIDO_AVALIACAO);
    atividade->SetAvaliacao(avaliacao);
    if(atividade->GetAvaliacao().GetAvaliacao()!= VALOR_VALIDO_AVALIACAO){estado = FALHA;}
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
    
}void TUHospedagem::setUp()
{
    hospedagem = new Hospedagem();
    estado = SUCESSO;
}

void TUHospedagem::tearDown()
{
    delete hospedagem;
}

void TUHospedagem::testarCenario()
{
    Nome nome;
    nome.SetNome(VALOR_VALIDO_NOME);
    hospedagem->SetNome(nome);
    if(hospedagem->GetNome().GetNome()!= VALOR_VALIDO_NOME)
    estado = FALHA;

    Dinheiro dinheiro;
    dinheiro.SetDinheiro(VALOR_VALIDO_DIARIA);
    hospedagem->SetDiaria(dinheiro);
    if(hospedagem->GetDiaria().GetDinheiro()!= VALOR_VALIDO_DIARIA)
    estado = FALHA;

    Avaliacao avaliacao;
    avaliacao.SetAvaliacao(VALOR_VALIDO_AVALIACAO);
    hospedagem->SetAvaliacao(avaliacao);
    if(hospedagem->GetAvaliacao().GetAvaliacao() != VALOR_VALIDO_AVALIACAO)
    estado = FALHA;

}

int TUHospedagem::run()
{
    setUp();
    testarCenario();
    tearDown();
    return estado;
}using namespace std;

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






