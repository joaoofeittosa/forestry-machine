#include "Entidade.hpp"


namespace forestry {


Entidade::Entidade(sf::Vector2f posicao) :
    Ente(),
    x(posicao.x),
    y(posicao.y)
{
}


Entidade::~Entidade() = default;


void Entidade::salvarDataBuffer()
{
    if (buffer.is_open()) {
        buffer << x << " " << y << std::endl;
    }
}


}

