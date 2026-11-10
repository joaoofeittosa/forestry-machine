#pragma once
#include "ruinas/Ente.h"
#include <fstream>


namespace ruinas {


class Entidade : public Ente {
protected:
    float x;
    float y;
    std::ofstream buffer;


public:
    explicit Entidade(sf::Vector2f posicao = sf::Vector2f(0.f, 0.f));
    virtual ~Entidade();


    void salvarDataBuffer();


    virtual void executar() = 0;
    virtual void salvar() = 0;


    sf::Vector2f getPosicao() const {
        return sf::Vector2f(x, y);
    }
    void setPosicao(sf::Vector2f p) { x = p.x; y = p.y; }
};


}

