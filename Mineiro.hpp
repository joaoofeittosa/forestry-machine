#ifndef MINEIRO_HPP
#define MINEIRO_HPP

#include "Inimigo.hpp"

namespace forestry {

    class Mineiro : public Inimigo {
    private:
        float forcaInvestida;
        int quadroAtual;
        float tempoAnimacao;

    public:
        Mineiro(sf::Vector2f pos = sf::Vector2f(0.f, 0.f));
        virtual ~Mineiro();

        void danificar(Jogador* pJ) override;
        void mover() override;
        void executar() override;
        void salvar() override;
    };

}

#endif