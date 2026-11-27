#ifndef FASE_HPP
#define FASE_HPP

#include "Ente.hpp"
#include "ListaEntidades.hpp"
#include "Gerenciador_grafico.hpp"
#include "Gerenciador_Colisoes.hpp"
#include "Entidade.hpp"

namespace forestry {

    class Fase : public Ente {
    protected:
        ListaEntidades listaEntidades;
        std::string nomeFase;
        GerenciadorColisoes gerenciadorColisoes;

    public:
        Fase(const std::string& nome);
        virtual ~Fase();

        virtual void executar() override;
        virtual void salvar();

        virtual void criarInimigos() = 0;
        virtual void criarObstaculo() = 0;
        virtual void criarCenario() = 0;

        void incluirEntidade(Entidade* pE);
        void removerEntidade(Entidade* pE);
    };
}

#endif
