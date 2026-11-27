#include "Obstaculo.hpp"

namespace forestry {

Obstaculo::Obstaculo(sf::Vector2f posicao, bool causaDano)
    : Entidade(posicao),
      dano(causaDano)
{
}

Obstaculo::~Obstaculo() = default;

bool Obstaculo::getDano() const
{
    return dano;
}

}