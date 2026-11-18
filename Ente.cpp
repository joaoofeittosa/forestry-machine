/*#include "forestry/Entity.h"
namespace forestry {


Entity::Entity(sf::Vector2f p):position_(p)
{


}


void Entity::damage(int amount)
{
    health_-=amount; if(health_<=0) alive_=false;
}


}*/


#include "Ente.h"
#include "Gerenciador_Grafico.h"


namespace forestry{


Gerenciador_Grafico* Ente::pGG = nullptr;


Ente::Ente() : id(0), pFig(nullptr)
{
}


Ente::~Ente()
{
    pFig = nullptr;
}


void Ente::desenhar()
{
    if (pGG) {
        pGG->desenharEnte(this);
    }
}


void Ente::setGG(Gerenciador_Grafico* pG)
{
    pGG = pG;
}


}



