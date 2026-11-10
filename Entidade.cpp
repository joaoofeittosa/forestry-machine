#include "ruinas/Entidade.h"


namespace ruinas {


Entidade::Entidade(sf::Vector2f posicao) :
    Ente(),
    x(posicao.x),
    y(posicao.y)
{
}


Entidade::~Entidade()
{
    if (buffer.is_open()) {
        buffer.close();
    }
}


void Entidade::salvarDataBuffer()
{
    if (buffer.is_open()) {
        buffer << x << " " << y << std::endl;
    }
}


}

