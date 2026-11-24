#include "Mineiro.hpp"
#include "Jogador.hpp"
#include "Gerenciador_grafico.hpp"
#include <cmath>

namespace forestry {

Mineiro::Mineiro(sf::Vector2f pos)
    : Inimigo(pos, 2),
      forcaInvestida(192.f),
      quadroAtual(0),
      tempoAnimacao(0.f)
{
    num_vidas = 4;
    getCorpo().setSize(sf::Vector2f(164.f, 164.f));
    getCorpo().setPosition(pos);

    if (textura.loadFromFile("Assets/Minerador.png")) {
        textura.setSmooth(false);
        getCorpo().setTexture(&textura);
        getCorpo().setTextureRect(
            sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(32, 32)));
    } else {
        getCorpo().setFillColor(sf::Color(120, 120, 140));
    }
}

Mineiro::~Mineiro()
{
}

void Mineiro::danificar(Jogador* pJ)
{
    (void)pJ;
}

void Mineiro::mover()
{
    Jogador* alvo = getJogadorMaisProximo();
    if (!alvo) {
        velocidade.x = 0.f;
        return;
    }

    sf::RectangleShape& corpo = getCorpo();
    float dx = alvo->getPosicao().x - corpo.getPosition().x;
    if (std::abs(dx) > 5.f) {
        velocidade.x = (dx > 0.f) ? forcaInvestida : -forcaInvestida;
    } else {
        velocidade.x = 0.f;
    }

    const float dt = pGG ? pGG->getDeltaTime() : 0.f;
    moverHorizontal(velocidade.x * dt);
}

void Mineiro::executar()
{
    mover();

    if (std::abs(velocidade.x) > 0.f) {
        tempoAnimacao += pGG ? pGG->getDeltaTime() : 0.f;
        if (tempoAnimacao >= 0.12f) {
            tempoAnimacao -= 0.12f;
            quadroAtual = (quadroAtual + 1) % 8;
        }
    } else {
        quadroAtual = 0;
        tempoAnimacao = 0.f;
    }

    getCorpo().setTextureRect(
        sf::IntRect(sf::Vector2i(quadroAtual * 32, 0), sf::Vector2i(32, 32)));
}

void Mineiro::salvar()
{
    Inimigo::salvar();
}

}