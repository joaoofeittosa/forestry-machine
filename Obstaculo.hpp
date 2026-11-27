#ifndef OBSTACULO_HPP
#define OBSTACULO_HPP

#include "Entidade.hpp"

namespace forestry {

class Jogador;

class Obstaculo : public Entidade {
protected:
    bool dano;

public:
    explicit Obstaculo(
        sf::Vector2f posicao = sf::Vector2f(0.f, 0.f),
        bool causaDano = false);
    virtual ~Obstaculo();

    virtual void executar() override = 0;
    virtual void obstaculizar(Jogador* p) = 0;
    virtual void salvar() override = 0;

    bool getDano() const;
};

}

#endif
