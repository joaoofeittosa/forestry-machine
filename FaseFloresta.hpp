#ifndef FASE_FLORESTA_HPP
#define FASE_FLORESTA_HPP

#include "Fase.hpp"

namespace forestry {

    class Jogador;

    class FaseFloresta : public Fase {
    private:
        Jogador* pJogador1;
        Jogador* pJogador2;
        sf::Texture texturaFundo;

    public:
        FaseFloresta(Jogador* jogador1, Jogador* jogador2 = nullptr);
        virtual ~FaseFloresta();

        virtual void executar() override;
        virtual void criarInimigos() override;   
        virtual void criarObstaculo() override;  
        virtual void criarCenario() override;    
    };
}

#endif


