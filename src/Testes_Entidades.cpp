#include "Testes_Entidades.h"

void TUHospedagem::setUp()
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
    avaliacao.SetValor(VALOR_VALIDO_AVALIACAO);
    hospedagem->SetAvaliacao(avaliacao);
    if(hospedagem->GetAvaliacao().GetValor() != VALOR_VALIDO_AVALIACAO)
    estado = FALHA;

}

int TUHospedagem::run()
{
    setUp();
    testarCenario();
    tearDown();
    return estado;
}
