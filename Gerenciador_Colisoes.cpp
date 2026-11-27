#include "Gerenciador_Colisoes.hpp"

#include "Entidade.hpp"
#include "Inimigo.hpp"
#include "Jogador.hpp"
#include "Obstaculo.hpp"
#include "Projetil.hpp"

#include <algorithm>

namespace forestry {

GerenciadorColisoes::GerenciadorColisoes()
    : pJog1(nullptr),
      pJog2(nullptr)
{
}

GerenciadorColisoes::~GerenciadorColisoes()
{
    limpar();
}

void GerenciadorColisoes::setJogador1(Jogador* pJ1)
{
    pJog1 = pJ1;
}

void GerenciadorColisoes::setJogador2(Jogador* pJ2)
{
    pJog2 = pJ2;
}

void GerenciadorColisoes::incluirInimigo(Inimigo* pI)
{
    if (pI && std::find(LIs.begin(), LIs.end(), pI) == LIs.end()) {
        LIs.push_back(pI);
    }
}

void GerenciadorColisoes::incluirObstaculo(Obstaculo* pO)
{
    if (pO && std::find(LOs.begin(), LOs.end(), pO) == LOs.end()) {
        LOs.push_back(pO);
    }
}

void GerenciadorColisoes::incluirProjetil(Projetil* pP)
{
    if (pP) {
        LPs.insert(pP);
    }
}

void GerenciadorColisoes::removerInimigo(Inimigo* pI)
{
    LIs.erase(std::remove(LIs.begin(), LIs.end(), pI), LIs.end());
}

void GerenciadorColisoes::removerObstaculo(Obstaculo* pO)
{
    LOs.remove(pO);
}

void GerenciadorColisoes::removerProjetil(Projetil* pP)
{
    LPs.erase(pP);
}

void GerenciadorColisoes::limpar()
{
    LIs.clear();
    LOs.clear();
    LPs.clear();
    pJog1 = nullptr;
    pJog2 = nullptr;
}

bool GerenciadorColisoes::verificarColisao(
    const Entidade* pe1,
    const Entidade* pe2) const
{
    if (!pe1 || !pe2 || !pe1->getFigura() || !pe2->getFigura()) {
        return false;
    }

    const sf::FloatRect limites1 = pe1->getFigura()->getGlobalBounds();
    const sf::FloatRect limites2 = pe2->getFigura()->getGlobalBounds();
    if (limites1.findIntersection(limites2).has_value()) {
        return true;
    }

    const Jogador* jogador = dynamic_cast<const Jogador*>(pe1);
    const Obstaculo* obstaculo = dynamic_cast<const Obstaculo*>(pe2);
    if (!jogador || !obstaculo || jogador->getVelocidade().y <= 0.f) {
        return false;
    }

    const float topoObstaculo = limites2.position.y;
    const float peAnterior = jogador->getYAnterior() + limites1.size.y;
    const float peAtual = limites1.position.y + limites1.size.y;
    const bool cruzouTopo =
        peAnterior <= topoObstaculo && peAtual >= topoObstaculo;
    const bool sobrepoeHorizontalmente =
        limites1.position.x < limites2.position.x + limites2.size.x
        && limites1.position.x + limites1.size.x > limites2.position.x;

    return cruzouTopo && sobrepoeHorizontalmente;
}

void GerenciadorColisoes::tratarColisoesJogsObstacs()
{
    Jogador* jogadores[] = { pJog1, pJog2 };

    for (Jogador* pJ : jogadores) {
        if (!pJ) {
            continue;
        }

        for (Obstaculo* pO : LOs) {
            if (pO && verificarColisao(pJ, pO)) {
                pO->obstaculizar(pJ);
            }
        }
    }
}

void GerenciadorColisoes::tratarColisoesJogsInims()
{
    Jogador* jogadores[] = { pJog1, pJog2 };

    for (Jogador* pJ : jogadores) {
        if (!pJ) {
            continue;
        }

        for (Inimigo* pI : LIs) {
            if (pI && verificarColisao(pJ, pI)) {
                pI->danificar(pJ);
            }
        }
    }
}

void GerenciadorColisoes::tratarColisoesJogsProjeteis()
{
    Jogador* jogadores[] = { pJog1, pJog2 };

    for (Jogador* pJ : jogadores) {
        if (!pJ) {
            continue;
        }

        for (Projetil* pP : LPs) {
            if (pP && verificarColisao(pJ, pP)) {
                pP->danificar(pJ);
            }
        }
    }
}

void GerenciadorColisoes::tratarColisoesProjeteisObstacs()
{
    for (Projetil* pP : LPs) {
        if (!pP) {
            continue;
        }

        for (Obstaculo* pO : LOs) {
            if (pO && verificarColisao(pP, pO)) {
                pP->colidirObstaculo();
            }
        }
    }
}

void GerenciadorColisoes::executar()
{
    tratarColisoesJogsObstacs();
    tratarColisoesJogsInims();
    tratarColisoesJogsProjeteis();
    tratarColisoesProjeteisObstacs();
}

}
