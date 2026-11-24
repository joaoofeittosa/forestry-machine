#include "Gnomo.hpp"
#include "Jogador.hpp"
#include "Gerenciador_grafico.hpp"
#include <algorithm>
#include <cmath>

namespace forestry {

Gnomo::Gnomo(sf::Vector2f pos)
    : Inimigo(pos, 1),
      alcancePerseguicao(300.f),
      velocidadePatrulha(108.f),
      direcao(1)
{
    num_vidas = 2;
    getCorpo().setSize(sf::Vector2f(164.f, 128.f));
    getCorpo().setPosition(pos);

    if (textura.loadFromFile("Assets/Gnomo.png")) {
        textura.setSmooth(false);
        getCorpo().setTexture(&textura, true);
    } else {
        getCorpo().setFillColor(sf::Color(200, 60, 60));
    }
}

Gnomo::~Gnomo()
{
}

void Gnomo::danificar(Jogador* pJ)
{
    (void)pJ;
}

void Gnomo::mover()
{
    sf::RectangleShape& corpo = getCorpo();
    Jogador* alvo = getJogadorMaisProximo();
    if (alvo) {
        sf::Vector2f posicaoAlvo = alvo->getPosicao();
        float dx = posicaoAlvo.x - corpo.getPosition().x;
        if (std::abs(dx) < alcancePerseguicao) {
            direcao = (dx > 0.f) ? 1 : -1;
        }
    }

    if (pGG) {
        const float maxX = std::max(
            0.f,
            static_cast<float>(pGG->getTamanhoJanela().x) - corpo.getSize().x);
        if (corpo.getPosition().x <= 0.f) {
            direcao = 1;
        } else if (corpo.getPosition().x >= maxX) {
            direcao = -1;
        }
    }

    velocidade.x = direcao * velocidadePatrulha;
    const float dt = pGG ? pGG->getDeltaTime() : 0.f;
    moverHorizontal(velocidade.x * dt);
}

void Gnomo::executar()
{
    mover();
}

void Gnomo::salvar()
{
    Inimigo::salvar();
}

}