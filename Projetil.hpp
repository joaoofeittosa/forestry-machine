#ifndef PROJETIL_HPP
#define PROJETIL_HPP

#include "Entidade.hpp"

namespace forestry {

class Jogador;

class Projetil : public Entidade {
public:
    virtual ~Projetil() = default;

    virtual void danificar(Jogador* p) = 0;
    virtual void colidirObstaculo() = 0;
};

}

#endif