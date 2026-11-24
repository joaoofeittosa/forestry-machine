#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include "Personagem.hpp"


namespace forestry {


class Jogador : public Personagem {
private:
    int pontos;
    static const float VELOCIDADE;


public:
    explicit Jogador(sf::Vector2f posicao = sf::Vector2f(0.f, 0.f));
    ~Jogador();


    void executar();
    void salvar();
    void mover();
};


}

#endif
