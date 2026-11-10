#pragma once
#include "ruinas/Entidade.h"


namespace ruinas {


class Personagem : public Entidade {
protected:
    int num_vidas;
    sf::Vector2f velocidade;


public:
    explicit Personagem(sf::Vector2f posicao = sf::Vector2f(0.f, 0.f),
                        int vidas = 1);
    virtual ~Personagem();


    virtual void executar() = 0;
    virtual void salvar() = 0;
    virtual void mover() = 0;


    int geVidas() const {
        return num_vidas;
    }
    sf::Vector2f getVelocidade() const { return velocidade; }
    void setVelocidade(sf::Vector2f v) { velocidade = v; }
};


}

