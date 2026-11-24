#ifndef CHAO_HPP
#define CHAO_HPP

#include "Entidade.hpp"

namespace forestry
{
    class Chao : public Entidade {
    private:
        float largura;
        float altura;

    public:
        Chao(float x, float y, float largura, float altura);
        virtual ~Chao();

        virtual void executar();
        virtual void salvar();
    };
}
#endif