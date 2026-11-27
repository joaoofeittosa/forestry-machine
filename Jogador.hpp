#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include "Personagem.hpp"

namespace forestry {

class Jogador : public Personagem {
private:
    int pontos;
    bool segundo;
    bool noChao;
    bool cimaPressionada;
    float yAnterior;
    sf::Texture textura;
    sf::RectangleShape figuraVisual;
    static const float VELOCIDADE;
    static const float GRAVIDADE;
    static const float IMPULSO_PULO;
    static const float VELOCIDADE_MAX_QUEDA;

public:
    explicit Jogador(sf::Vector2f posicao = sf::Vector2f(0.f, 0.f),
                     bool segundo = false);
    ~Jogador();

    void executar();
    void desenhar() override;
    void salvar();
    void mover() override;
    void setNoChao(bool valor);
    float getYAnterior() const;
};

}
#endif
