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
void TUAtividade::testarCenario()
{
    Codigo codigo;
    codigo.SetCodigo(VALOR_VALIDO_CODIGO);
    atividade->SetCodigo(codigo);
    if(atividade->GetCodigo().GetCodigo() != VALOR_VALIDO_CODIGO)estado = FALHA;
    Nome nome;
    nome.SetNome(VALOR_VALIDO_NOME);
    atividade->SetNome(nome);
    if(atividade->GetNome().GetNome() != VALOR_VALIDO_NOME)estado = FALHA;
    Data data;
    data.SetData(VALOR_VALIDO_DATA);
    atividade->SetData(data);
    if(atividade->GetData().GetData() != VALOR_VALIDO_DATA)estado = FALHA;
    Horario horario;
    horario.SetHora(VALOR_VALIDO_HORARIO);
    atividade->SetHorario(horario);
    if(atividade->GetHorario().GetHora() != VALOR_VALIDO_HORARIO)estado = FALHA;
    Duracao duracao;
    duracao.SetValor(VALOR_VALIDO_DURACAO);
    atividade->SetDuracao(duracao);
    if(atividade->GetDuracao().GetValor() != VALOR_VALIDO_DURACAO)estado = FALHA;
    Dinheiro preco;
    preco.SetDinheiro(VALOR_VALIDO_PRECO);
    atividade->SetPreco(preco);
    if(atividade->GetPreco().GetDinheiro() != VALOR_VALIDO_PRECO)estado = FALHA;
    Avaliacao avaliacao;
    avaliacao.SetValor(VALOR_VALIDO_AVALIACAO);
    atividade->SetAvaliacao(avaliacao);
    if(atividade->GetAvaliacao().GetValor() != VALOR_VALIDO_AVALIACAO)estado = FALHA;
}
int TUAtividade::run()
{
    setUp();
    testarCenario();
    tearDown();
    return estado;
}