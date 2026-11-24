#ifndef FASE_FLORESTA_HPP
#define FASE_FLORESTA_HPP

#include "Fase.hpp"

namespace forestry {

    class FaseFloresta : public Fase {
    private:
       
        sf::Texture texturaFundo;

    public:
        FaseFloresta();
        virtual ~FaseFloresta();

        virtual void executar() override;
        virtual void criarInimigos() override;   
        virtual void criarObstaculo() override;  
        virtual void criarCenario() override;    
    };
}

#endif


