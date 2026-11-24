#include "Jogador.hpp"
#include "Gerenciador_grafico.hpp"

namespace forestry {

const float Jogador::VELOCIDADE = 300.f;

Jogador::Jogador(sf::Vector2f posicao, bool segundo) :
    Personagem(posicao, 3),
    pontos(0),
    segundo(segundo)
{
    sf::RectangleShape* pRet = new sf::RectangleShape(sf::Vector2f(40.f, 40.f));
    pRet->setFillColor(segundo ? sf::Color::Blue : sf::Color::Green);
    pRet->setPosition(sf::Vector2f(x, y));
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

void Jogador::mover()
{
    float dt = pGG ? pGG->getDeltaTime() : 0.f;

    sf::Keyboard::Key esq   = segundo ? sf::Keyboard::Key::A     : sf::Keyboard::Key::Left;
    sf::Keyboard::Key dir   = segundo ? sf::Keyboard::Key::D     : sf::Keyboard::Key::Right;
    sf::Keyboard::Key cima  = segundo ? sf::Keyboard::Key::W     : sf::Keyboard::Key::Up;
    sf::Keyboard::Key baixo = segundo ? sf::Keyboard::Key::S     : sf::Keyboard::Key::Down;

    velocidade = sf::Vector2f(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(esq))   { velocidade.x -= VELOCIDADE; }
    if (sf::Keyboard::isKeyPressed(dir))   { velocidade.x += VELOCIDADE; }
    if (sf::Keyboard::isKeyPressed(cima))  { velocidade.y -= VELOCIDADE; }
    if (sf::Keyboard::isKeyPressed(baixo)) { velocidade.y += VELOCIDADE; }

    x += velocidade.x * dt;
    y += velocidade.y * dt;

    pFig->setPosition(sf::Vector2f(x, y));
}

void Jogador::salvar()
{
    salvarDataBuffer();
    if (buffer.is_open()) {
        buffer << num_vidas << " " << pontos << std::endl;
    }
}

}

