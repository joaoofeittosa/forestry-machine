#ifndef PLATAFORMA_HPP
#define PLATAFORMA_HPP

#include "Obstaculo.hpp"

namespace forestry {

class Plataforma : public Obstaculo {
private:
    sf::Texture textura;
    int altura;

public:
    explicit Plataforma(
        sf::Vector2f posicao = sf::Vector2f(0.f, 0.f),
        int altura = 50);
    ~Plataforma() override;

    void executar() override;
    void obstaculizar(Jogador* p) override;
    void salvar() override;
};

}

#endif