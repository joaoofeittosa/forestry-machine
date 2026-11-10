#include "ruinas/Jogo.h"


namespace ruinas {


Jogo::Jogo() :
    GG(),
    pJog1(nullptr)
{
    Ente::setGG(&GG);
    pJog1 = new Jogador(sf::Vector2f(100.f, 100.f));
}


Jogo::~Jogo()
{
    delete pJog1;
    pJog1 = nullptr;
    Ente::setGG(nullptr);
}


void Jogo::executar()
{
    while (GG.janelaAberta()) {
        GG.processarEventos();
        GG.limpar();


        pJog1->executar();
        pJog1->desenhar();


        GG.mostrar();
    }
}


}

