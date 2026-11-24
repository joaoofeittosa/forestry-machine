#ifndef GNOMO_HPP
#define GNOMO_HPP

#include "Inimigo.hpp"

namespace forestry {

    class Gnomo : public Inimigo {
    private:
        float alcancePerseguicao;
        float velocidadePatrulha;
        int direcao;

    public:
        Gnomo(sf::Vector2f pos = sf::Vector2f(0.f, 0.f));
        virtual ~Gnomo();

        void danificar(Jogador* pJ) override;
        void mover() override;
        void executar() override;
        void salvar() override;
    };

}

#endif