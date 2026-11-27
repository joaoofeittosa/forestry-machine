#include "Plataforma.hpp"

#include "Jogador.hpp"

#include <iostream>

namespace forestry {

namespace {
const float LARGURA_PLATAFORMA = 130.f;
}

Plataforma::Plataforma(sf::Vector2f posicao, int altura)
    : Obstaculo(posicao, false),
      altura(std::max(1, altura))
{
    sf::RectangleShape* retangulo = new sf::RectangleShape(
        sf::Vector2f(LARGURA_PLATAFORMA, static_cast<float>(this->altura)));
    retangulo->setPosition(posicao);
    if (textura.loadFromFile("Assets/Plataforma_Floresta.PNG")) {
        retangulo->setTexture(&textura, true);
        retangulo->setFillColor(sf::Color::White);
    } else {
        std::cerr << "Plataforma: nao foi possivel carregar a textura da floresta."
                  << std::endl;
        retangulo->setFillColor(sf::Color::Green);
    }
    pFig = retangulo;
}

Plataforma::~Plataforma()
{
    delete pFig;
    pFig = nullptr;
}

void Plataforma::executar()
{
}

void Plataforma::obstaculizar(Jogador* p)
{
    if (!p || !p->getFigura()) {
        return;
    }

    const sf::FloatRect jogador = p->getFigura()->getGlobalBounds();
    const sf::FloatRect plataforma = pFig->getGlobalBounds();
    const sf::Vector2f velocidade = p->getVelocidade();
    const float topo = plataforma.position.y;
    const float base = topo + plataforma.size.y;
    const bool sobrepoeVerticalmente =
        jogador.position.y < base
        && jogador.position.y + jogador.size.y > topo;
    const bool sobrepoeHorizontalmente =
        jogador.position.x < plataforma.position.x + plataforma.size.x
        && jogador.position.x + jogador.size.x > plataforma.position.x;

    if (velocidade.y <= 0.f
        || !sobrepoeVerticalmente
        || !sobrepoeHorizontalmente) {
        return;
    }

    sf::Vector2f posicao = p->getPosicao();
    posicao.y = topo - jogador.size.y;
    p->setPosicao(posicao);
    p->getFigura()->setPosition(posicao);

    sf::Vector2f novaVelocidade = velocidade;
    novaVelocidade.y = 0.f;
    p->setNoChao(true);
    p->setVelocidade(novaVelocidade);
}

void Plataforma::salvar()
{
    salvarDataBuffer();
    if (buffer.is_open()) {
        buffer << " PLATAFORMA " << altura << std::endl;
    }
}

}