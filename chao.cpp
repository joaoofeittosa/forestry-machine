#include "chao.hpp"
#include <algorithm>

namespace forestry
{
    Chao::Chao(float x, float y, float largura, float altura)
    : Entidade(sf::Vector2f(x, y)),
      largura(largura),
      altura(altura) {
    }

    Chao::~Chao() {
    }

    void Chao::adicionarEntidade(Entidade* entidade) {
        if (entidade) {
            entidades.push_back(entidade);
        }
    }

    void Chao::definirLimites(float novoX, float novoY,
                              float novaLargura, float novaAltura) {
        setPosicao(sf::Vector2f(novoX, novoY));
        largura = novaLargura;
        altura = novaAltura;
    }

    void Chao::executar() {
        for (Entidade* entidade : entidades) {
            if (!entidade || !entidade->getFigura()) {
                continue;
            }

            const sf::Vector2f tamanhoFigura =
                entidade->getFigura()->getLocalBounds().size;
            sf::Vector2f posicao = entidade->getPosicao();

            const float maxX = std::max(x, x + largura - tamanhoFigura.x);
            const float maxY = std::max(y, y + altura - tamanhoFigura.y);
            posicao.x = std::clamp(posicao.x, x, maxX);
            posicao.y = std::clamp(posicao.y, y, maxY);

            entidade->setPosicao(posicao);
            entidade->getFigura()->setPosition(posicao);
        }
    }

    void Chao::salvar() {
        salvarDataBuffer();
        buffer << " CHAO";
    }
}