#include "FaseFloresta.hpp"

#include "Gnomo.hpp"
#include "Mineiro.hpp"
// #include "Rocha.hpp"
// #include "Espinho.hpp"
#include <algorithm>
#include <iostream>

namespace forestry {

FaseFloresta::FaseFloresta(Jogador* jogador1, Jogador* jogador2)
    : Fase("Floresta"),
      pJogador1(jogador1),
      pJogador2(jogador2)
{
    criarCenario();
    criarObstaculo();
    criarInimigos();
}

FaseFloresta::~FaseFloresta() {
    delete pFig;
    pFig = nullptr;
}

void FaseFloresta::executar() {
    desenhar();
    Fase::executar();
}

void FaseFloresta::criarCenario() {
    const sf::Vector2u janela = pGG->getTamanhoJanela();
    sf::RectangleShape* fundo = new sf::RectangleShape(
        sf::Vector2f(static_cast<float>(janela.x), static_cast<float>(janela.y)));

    if (texturaFundo.loadFromFile("Assets/Background_Floresta.png")) {
        fundo->setTexture(&texturaFundo, true);
        fundo->setFillColor(sf::Color::White);
    } else {
        std::cerr << "FaseFloresta: nao foi possivel carregar o fundo." << std::endl;
        fundo->setFillColor(sf::Color(25, 35, 25));
    }

    pFig = fundo;   
}

void FaseFloresta::criarObstaculo() {
    // incluirEntidade(new Rocha(sf::Vector2f(450.f, 600.f)));
    // incluirEntidade(new Espinho(sf::Vector2f(850.f, 620.f)));
}

void FaseFloresta::criarInimigos() {
    const float linhaDoChao =
        static_cast<float>(pGG->getTamanhoJanela().y) - 60.f;

    Gnomo* gnomo = new Gnomo(sf::Vector2f(
        600.f, std::max(0.f, linhaDoChao - 128.f)));
    gnomo->setJogadores(pJogador1, pJogador2);
    incluirEntidade(gnomo);

    Mineiro* mineiro = new Mineiro(sf::Vector2f(
        1000.f, std::max(0.f, linhaDoChao - 192.f)));
    mineiro->setJogadores(pJogador1, pJogador2);
    incluirEntidade(mineiro);
}

}
