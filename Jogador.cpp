#include "Jogador.hpp"
#include "Gerenciador_grafico.hpp"
#include <algorithm>

namespace forestry {

const float Jogador::VELOCIDADE = 300.f;
const float Jogador::GRAVIDADE = 1200.f;
const float Jogador::IMPULSO_PULO = 680.f;
const float Jogador::VELOCIDADE_MAX_QUEDA = 900.f;

Jogador::Jogador(sf::Vector2f posicao, bool segundo) :
    Personagem(posicao, 3),
    pontos(0),
    segundo(segundo),
    noChao(false),
    cimaPressionada(false),
    yAnterior(posicao.y),
    figuraVisual(sf::Vector2f(65.f, 106.f))
{
    sf::RectangleShape* pRet = new sf::RectangleShape(sf::Vector2f(40.f, 40.f));
    if (textura.loadFromFile(segundo
            ? "Assets/Personagem_2.png"
            : "Assets/Personagem_1.png")) {
        textura.setSmooth(false);
        figuraVisual.setTexture(&textura);
        figuraVisual.setTextureRect(
            sf::IntRect(sf::Vector2i(18, 17), sf::Vector2i(12, 26)));
    } else {
        figuraVisual.setFillColor(
            segundo ? sf::Color::Blue : sf::Color::Green);
    }
    pRet->setPosition(sf::Vector2f(x, y));
    figuraVisual.setPosition(sf::Vector2f(x, y));
    pFig = pRet;
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

void Jogador::desenhar()
{
    if (pGG && pFig) {
        figuraVisual.setPosition(
            pFig->getPosition() + sf::Vector2f(-12.5f, -66.f));
        pGG->desenharObjeto(figuraVisual);
    }
}

void Jogador::mover()
{
    const float dt = std::min(pGG ? pGG->getDeltaTime() : 0.f, 0.05f);
    yAnterior = y;

    sf::Keyboard::Key esq   = segundo ? sf::Keyboard::Key::A     : sf::Keyboard::Key::Left;
    sf::Keyboard::Key dir   = segundo ? sf::Keyboard::Key::D     : sf::Keyboard::Key::Right;
    sf::Keyboard::Key cima  = segundo ? sf::Keyboard::Key::W     : sf::Keyboard::Key::Up;
    sf::Keyboard::Key baixo = segundo ? sf::Keyboard::Key::S     : sf::Keyboard::Key::Down;

    const bool teclaPulo = sf::Keyboard::isKeyPressed(cima);
    if (teclaPulo && !cimaPressionada && noChao) {
        velocidade.y = -IMPULSO_PULO;
    }
    cimaPressionada = teclaPulo;
    noChao = false;

    velocidade.x = 0.f;
    if (sf::Keyboard::isKeyPressed(esq)) {
        velocidade.x -= VELOCIDADE;
    }
    if (sf::Keyboard::isKeyPressed(dir)) {
        velocidade.x += VELOCIDADE;
    }

    velocidade.y += GRAVIDADE * dt;
    if (sf::Keyboard::isKeyPressed(baixo) && velocidade.y > 0.f) {
        velocidade.y += GRAVIDADE * dt;
    }
    velocidade.y = std::min(velocidade.y, VELOCIDADE_MAX_QUEDA);

    x += velocidade.x * dt;
    y += velocidade.y * dt;

    pFig->setPosition(sf::Vector2f(x, y));
}

void Jogador::setNoChao(bool valor)
{
    noChao = valor;
    if (valor && velocidade.y > 0.f) {
        velocidade.y = 0.f;
    }
}

float Jogador::getYAnterior() const
{
    return yAnterior;
}

void Jogador::salvar()
{
    salvarDataBuffer();
    if (buffer.is_open()) {
        buffer << num_vidas << " " << pontos << std::endl;
    }
}

}

