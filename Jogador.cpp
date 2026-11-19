#include "Jogo.hpp"
#include "Ente.hpp"
#include <algorithm>


namespace forestry {

const float Jogador::VELOCIDADE = 250.f;

Jogador::Jogador(sf::Vector2f posicao) :
    Personagem(posicao, 1),
    pontos(0)
{
    pFig = new sf::RectangleShape(sf::Vector2f(40.f, 40.f));
    pFig->setFillColor(sf::Color::Green);
    pFig->setPosition(getPosicao());
}

Jogador::~Jogador()
{
    delete pFig;
    pFig = nullptr;
}

void Jogador::executar()
{
    mover();
}

void Jogador::mover()
{
    sf::Vector2f direcao(0.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) direcao.x -= 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) direcao.x += 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) direcao.y -= 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) direcao.y += 1.f;

    sf::Vector2f novaPosicao =
        getPosicao() + direcao * VELOCIDADE * pGG->getDeltaTime();
    const sf::Vector2u tamanhoJanela = pGG->getTamanhoJanela();
    const sf::FloatRect limitesFigura = pFig->getLocalBounds();

    novaPosicao.x = std::clamp(
        novaPosicao.x,
        0.f,
        std::max(0.f, static_cast<float>(tamanhoJanela.x) - limitesFigura.size.x));
    novaPosicao.y = std::clamp(
        novaPosicao.y,
        0.f,
        std::max(0.f, static_cast<float>(tamanhoJanela.y) - limitesFigura.size.y));

    setPosicao(novaPosicao);
    pFig->setPosition(getPosicao());
}

void Jogador::salvar()
{
}

}

