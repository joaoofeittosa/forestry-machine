#include "Inimigo.hpp"
#include "Jogador.hpp"
#include "Gerenciador_grafico.hpp"
#include <algorithm>
#include <cmath>

namespace forestry {

Inimigo::Inimigo(sf::Vector2f pos, int maldade)
    : Personagem(pos),
      nivelMaldade(maldade),
      pJogador1(nullptr),
      pJogador2(nullptr),
      textura(),
      corpo(sf::Vector2f(48.f, 64.f))
{
    corpo.setPosition(pos);
    pFig = &corpo;
}

Inimigo::~Inimigo()
{
    pJogador1 = nullptr;
    pJogador2 = nullptr;
}

void Inimigo::setJogadores(Jogador* pJ1, Jogador* pJ2)
{
    pJogador1 = pJ1;
    pJogador2 = pJ2;
}

int Inimigo::getNivelMaldade() const
{
    return nivelMaldade;
}

Jogador* Inimigo::getJogadorMaisProximo() const
{
    sf::Shape* figura1 = pJogador1 ? pJogador1->getFigura() : nullptr;
    sf::Shape* figura2 = pJogador2 ? pJogador2->getFigura() : nullptr;
    if (!figura1 && !figura2) return nullptr;
    if (figura1 && !figura2) return pJogador1;
    if (!figura1 && figura2) return pJogador2;

    sf::Vector2f posAtual = corpo.getPosition();
    sf::Vector2f d1 = figura1->getPosition() - posAtual;
    sf::Vector2f d2 = figura2->getPosition() - posAtual;

    float dist1 = std::hypot(d1.x, d1.y);
    float dist2 = std::hypot(d2.x, d2.y);

    return (dist1 <= dist2) ? pJogador1 : pJogador2;
}

void Inimigo::moverHorizontal(float deslocamento)
{
    sf::Vector2f posicao = getPosicao();
    posicao.x += deslocamento;
    if (pGG) {
        const sf::Vector2u tamanhoJanela = pGG->getTamanhoJanela();
        const float maxX = std::max(
            0.f, static_cast<float>(tamanhoJanela.x) - corpo.getSize().x);
        posicao.x = std::clamp(posicao.x, 0.f, maxX);
    }

    setPosicao(posicao);

    posicao.x = std::round(posicao.x);
    corpo.setPosition(posicao);
}

void Inimigo::executar()
{
    mover();
}

void Inimigo::salvar()
{
    // Serialização dos dados base do inimigo (posição, vida, nivelMaldade)
}

}