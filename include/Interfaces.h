
#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "Dominios.h"
#include "Entidade.h"
#include <stdexcept>
using namespace std;



/// @file Interfaces.h
/// @brief Arquivo que contém as declarações de interfaces para as camadas de apresentação e serviço.


/// CAMADA DE APRESENTAÇÃO

/// @class IContaApresentacao
/// @brief Interface para a camada de apresentação relacionada à conta.
class IContaApresentacao {
public:
    /// @brief Cria uma nova conta.
    /// @return true se a conta foi criada com sucesso, false caso contrário.
    virtual bool criarConta() = 0;

    /// @brief Executa a interface de apresentação da conta.
    /// @param codigo Ponteiro para o código da conta.
    virtual void executar(Codigo*) = 0;

    /// @brief Define o serviço de conta associado.
    /// @param cntrServicoConta Ponteiro para o serviço de conta.
    virtual void setCntrServicoConta(IContaServico*) = 0;

    /// @brief Destrutor virtual.
    virtual ~IContaApresentacao(){};
};

/// @class IAutenticacaoApresentacao
/// @brief Interface para a camada de apresentação relacionada à autenticação.
class IAutenticacaoApresentacao {
public:
    /// @brief Autentica uma conta.
    /// @param codigo Ponteiro para o código da conta.
    /// @return true se a autenticação foi bem-sucedida, false caso contrário.
    virtual bool autenticar(Codigo*) = 0;

    /// @brief Define o serviço de autenticação associado.
    /// @param cntrServicoAutenticacao Ponteiro para o serviço de autenticação.
    virtual void setCntrServicoAutenticacao(IAutenticacaoServico*) = 0;

    /// @brief Destrutor virtual.
    virtual ~IAutenticacaoApresentacao(){};
};

/// @class IViagemApresetacao
/// @brief Interface para a camada de apresentação relacionada à viagem.
class IViagemApresetacao {
public:
    /// @brief Executa a interface de apresentação da viagem.
    /// @param codigo Código da viagem.
    virtual void executar(const Codigo) = 0;

    /// @brief Exibe o menu de viagem.
    virtual void menuViagem() = 0;

    /// @brief Exibe o menu de hospedagem.
    virtual void menuHospedagem() = 0;

    /// @brief Exibe o menu de destino.
    virtual void menuDestino() = 0;

    /// @brief Exibe o menu de atividade.
    virtual void menuAtividade() = 0;

    /// @brief Define o serviço de viagem associado.
    /// @param cntrServicoViagem Ponteiro para o serviço de viagem.
    virtual void setCntrServicoViagem(IViagemServico*) = 0;

    /// @brief Destrutor virtual.
    virtual ~IViagemApresetacao(){};
};

/// CAMADA DE SERVIÇO

/// @class IContaServico
/// @brief Interface para a camada de serviço relacionada à conta.
class IContaServico {
public:
    /// @brief Cria uma nova conta.
    /// @param conta Objeto do tipo Conta contendo os dados da conta.
    /// @return true se a conta foi criada com sucesso, false caso contrário.
    virtual bool criarConta(const Conta) = 0;

    /// @brief Exclui uma conta existente.
    /// @param codigo Código da conta a ser excluída.
    /// @return true se a conta foi excluída com sucesso, false caso contrário.
    virtual bool excluirConta(const Codigo) = 0;

    /// @brief Lê os dados de uma conta.
    /// @param conta Ponteiro para o objeto Conta onde os dados serão armazenados.
    /// @return true se a leitura foi bem-sucedida, false caso contrário.
    virtual bool lerConta(Conta*) = 0;

    /// @brief Atualiza os dados de uma conta.
    /// @param conta Objeto do tipo Conta contendo os novos dados da conta.
    /// @return true se a conta foi atualizada com sucesso, false caso contrário.
    virtual bool atualizarConta(const Conta) = 0;

    /// @brief Destrutor virtual.
    virtual ~IContaServico(){};
};

/// @class IAutenticacaoServico
/// @brief Interface para a camada de serviço relacionada à autenticação.
class IAutenticacaoServico {
public:
    /// @brief Autentica uma conta.
    /// @param conta Objeto do tipo Conta contendo os dados da conta.
    /// @return true se a autenticação foi bem-sucedida, false caso contrário.
    virtual bool autenticarConta(const Conta) = 0;
    /// @brief Destrutor virtual
    virtual ~IAutenticacaoServico(){};
};

/// @class IViagemServico
/// @brief Interface para a camada de serviço relacionada à viagem.
class IViagemServico {
public:
    /// @brief Cria uma nova viagem.
    /// @param viagem Objeto do tipo Viagem contendo os dados da viagem.
    /// @return true se a viagem foi criada com sucesso, false caso contrário.
    virtual bool criarViagem(const Viagem) = 0;

    /// @brief Exclui uma viagem existente.
    /// @param codigo Código da viagem a ser excluída.
    /// @return true se a viagem foi excluída com sucesso, false caso contrário.
    virtual bool excluirViagem(const Codigo) = 0;

    /// @brief Lê os dados de uma viagem.
    /// @param viagem Ponteiro para o objeto Viagem onde os dados serão armazenados.
    /// @return true se a leitura foi bem-sucedida, false caso contrário.
    virtual bool lerViagem(Viagem*) = 0;

    /// @brief Atualiza os dados de uma viagem.
    /// @param viagem Objeto do tipo Viagem contendo os novos dados da viagem.
    /// @return true se a viagem foi atualizada com sucesso, false caso contrário.
    virtual bool atualizarViagem(const Viagem) = 0;

    /// @brief Cria uma nova hospedagem.
    /// @param hospedagem Objeto do tipo Hospedagem contendo os dados da hospedagem.
    /// @return true se a hospedagem foi criada com sucesso, false caso contrário.
    virtual bool criarHospedagem(const Hospedagem) = 0;

    /// @brief Exclui uma hospedagem existente.
    /// @param codigo Código da hospedagem a ser excluída.
    /// @return true se a hospedagem foi excluída com sucesso, false caso contrário.
    virtual bool excluirHospedagem(const Codigo) = 0;

    /// @brief Lê os dados de uma hospedagem.
    /// @param hospedagem Ponteiro para o objeto Hospedagem onde os dados serão armazenados.
    /// @return true se a leitura foi bem-sucedida, false caso contrário.
    virtual bool lerHospedagem(Hospedagem*) = 0;

    /// @brief Atualiza os dados de uma hospedagem.
    /// @param hospedagem Objeto do tipo Hospedagem contendo os novos dados da hospedagem.
    /// @return true se a hospedagem foi atualizada com sucesso, false caso contrário.
    virtual bool atualizarHospedagem(const Hospedagem) = 0;
    /// @brief Cria um novo destino.
    /// @param destino Objeto do tipo Destino contendo os dados do destino.
    /// @return true se o destino foi criado com sucesso, false caso contrário.
    virtual bool criarDestino(const Destino) = 0;
    /// @brief Exclui um destino existente.
    /// @param codigo Código do destino a ser excluído.
    /// @return true se o destino foi excluído com sucesso, false caso contrário.
    virtual bool criarDestino(const Destino, const Codigo) = 0;
    /// @brief Lê os dados de um destino.
    /// @param destino Ponteiro para o objeto Destino onde os dados serão armazenados.
    /// @return true se a leitura foi bem-sucedida, false caso contrário.
    virtual bool lerDestino(Destino*) = 0;

    /// @brief Atualiza os dados de um destino.
    /// @param destino Objeto do tipo Destino contendo os novos dados do destino.
    /// @return true se o destino foi atualizado com sucesso, false caso contrário.
    virtual bool atualizarDestino(const Destino) = 0;

    /// @brief Cria uma nova atividade.
    /// @param atividade Objeto do tipo Atividade contendo os dados da atividade.
    /// @return true se a atividade foi criada com sucesso, false caso contrário.
    virtual bool criarAtividade(const Atividade) = 0;

    /// @brief Exclui uma atividade existente.
    /// @param codigo Código da atividade a ser excluída.
    /// @return true se a atividade foi excluída com sucesso, false caso contrário.
    virtual bool excluirAtividade(const Codigo) = 0;

    /// @brief Lê os dados de uma atividade.
    /// @param atividade Ponteiro para o objeto Atividade onde os dados serão armazenados.
    /// @return true se a leitura foi bem-sucedida, false caso contrário.
    virtual bool lerAtividade(Atividade*) = 0;

    /// @brief Atualiza os dados de uma atividade.
    /// @param atividade Objeto do tipo Atividade contendo os novos dados da atividade.
    /// @return true se a atividade foi atualizada com sucesso, false caso contrário.
    virtual bool atualizarAtividade(const Atividade) = 0;

    /// @brief Destrutor virtual.
    virtual ~IViagemServico(){};
};

#endif // INTERFACES_H_INCLUDED