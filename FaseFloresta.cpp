#include "FaseFloresta.hpp"

#include "AnaoDeJardim.hpp"        
#include "Mineiro.hpp"      
#include "Rocha.hpp"     
#include "Espinho.hpp"  

namespace forestry {

FaseFloresta::FaseFloresta()
    : Fase("Floresta")
{
    criarCenario();
    criarObstaculo();
    criarInimigos();
}

FaseFloresta::~FaseFloresta() {
    
}

void FaseFloresta::criarCenario() {
    const sf::Vector2u janela = pGG->getTamanhoJanela();
    sf::RectangleShape* fundo = new sf::RectangleShape(
        sf::Vector2f(static_cast<float>(janela.x), static_cast<float>(janela.y)));

    texturaFundo.loadFromFile("assets/floresta.png");
    fundo->setTexture(&texturaFundo);

    pFig = fundo;   
}

void FaseFloresta::criarObstaculo() {
    incluirEntidade(new Rocha(sf::Vector2f(450.f, 600.f)));
    incluirEntidade(new Espinho(sf::Vector2f(850.f, 620.f)));
}

void FaseFloresta::criarInimigos() {
    incluirEntidade(new AnapoDeJardim(sf::Vector2f(600.f, 590.f)));
    incluirEntidade(new Mineiro(sf::Vector2f(1000.f, 600.f)));
}

}
