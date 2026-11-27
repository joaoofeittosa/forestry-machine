#include "FaseFloresta.hpp"

#include "Gnomo.hpp"
#include "Mineiro.hpp"
#include "Plataforma.hpp"
#include <algorithm>
#include <iostream>

namespace forestry {

FaseFloresta::FaseFloresta(Jogador* jogador1, Jogador* jogador2)
    : Fase("Floresta"),
      pJogador1(jogador1),
      pJogador2(jogador2)
{
    gerenciadorColisoes.setJogador1(pJogador1);
    gerenciadorColisoes.setJogador2(pJogador2);
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
    const sf::Vector2u tamanhoJanela = pGG->getTamanhoJanela();
    const float escalaX = static_cast<float>(tamanhoJanela.x) / 1254.f;
    const float escalaY = static_cast<float>(tamanhoJanela.y) / 690.f;
    const sf::Vector2f posicoesReferencia[] = {
        sf::Vector2f(151.f, 511.f),
        sf::Vector2f(322.f, 421.f),
        sf::Vector2f(487.f, 300.f),
        sf::Vector2f(690.f, 421.f),
        sf::Vector2f(849.f, 313.f),
        sf::Vector2f(968.f, 225.f),
        sf::Vector2f(1075.f, 400.f)
    };

    for (const sf::Vector2f& referencia : posicoesReferencia) {
        const sf::Vector2f posicao(
            referencia.x * escalaX,
            referencia.y * escalaY);
        incluirEntidade(new Plataforma(posicao, 50));
    }
}

void FaseFloresta::criarInimigos() {
    const float linhaDosPes =
        static_cast<float>(pGG->getTamanhoJanela().y) - 40.f;
    const float alturaVisivelGnomo = 120.f;
    const float alturaVisivelMineiro = 123.f;

    Gnomo* gnomo = new Gnomo(sf::Vector2f(
        600.f, std::max(0.f, linhaDosPes - alturaVisivelGnomo)));
    gnomo->setJogadores(pJogador1, pJogador2);
    incluirEntidade(gnomo);

    Mineiro* mineiro = new Mineiro(sf::Vector2f(
        1000.f, std::max(0.f, linhaDosPes - alturaVisivelMineiro)));
    mineiro->setJogadores(pJogador1, pJogador2);
    incluirEntidade(mineiro);
}

}
