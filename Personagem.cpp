#include "ruinas/Personagem.h"


namespace ruinas {


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

