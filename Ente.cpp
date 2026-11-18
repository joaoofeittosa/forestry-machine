
#include "Gerenciador_grafico.hpp"
#include "Ente.hpp"


namespace forestry {


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



