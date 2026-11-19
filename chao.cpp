#include "Chao.hpp"

namespace forestry
{
    Chao::Chao(float x, float y, float largura, float altura)
    : Entidade(sf::Vector2f(x, y)),
      largura(largura),
      altura(altura) {
    }

    Chao::~Chao() {
    }

    void Chao::executar() {
        // O chao e fixo: nao precisa atualizar sua posicao.
    }

    void Chao::salvar() {
        salvarDataBuffer();
        buffer << " CHAO";
    }
}