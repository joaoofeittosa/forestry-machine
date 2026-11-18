#include "Personagem.h"


namespace forestry {


Personagem::Personagem(sf::Vector2f posicao, int vidas) :
    Entidade(posicao),
    num_vidas(vidas),
    velocidade(0.f, 0.f)
{
}


Personagem::~Personagem()
{
}


}

