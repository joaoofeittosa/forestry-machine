#ifndef CHAO_HPP
#define CHAO_HPP

#include "Entidade.hpp"
#include <vector>

namespace forestry
{
    class Chao : public Entidade {
    private:
        float largura;
        float altura;
        std::vector<Entidade*> entidades;

    public:
        Chao(float x, float y, float largura, float altura);
        virtual ~Chao();

        void adicionarEntidade(Entidade* entidade);
        void definirLimites(float x, float y, float largura, float altura);
        virtual void executar();
        virtual void salvar();
    };
}
#endif