#include "Jogo.hpp"

namespace forestry {

Jogo::Jogo(bool doisJogadores) :
    GG(),
    pChao(nullptr),
    pJog1(nullptr),
    pJog2(nullptr),
    doisJogadores(doisJogadores)
{
    Ente::setGG(&GG);
    const sf::Vector2u tamanhoJanela = GG.getTamanhoJanela();
    pChao = new Chao(
        0.f,
        0.f,
        static_cast<float>(tamanhoJanela.x),
        static_cast<float>(tamanhoJanela.y));

    pJog1 = new Jogador(sf::Vector2f(100.f, 100.f), false);
    pChao->adicionarEntidade(pJog1);
    if (doisJogadores) {
        pJog2 = new Jogador(sf::Vector2f(200.f, 100.f), true);
        pChao->adicionarEntidade(pJog2);
    }
}

Jogo::~Jogo()
{
    delete pJog1;
    pJog1 = nullptr;
    if (doisJogadores) {
        delete pJog2;
        pJog2 = nullptr;
    }
    delete pChao;
    pChao = nullptr;
    Ente::setGG(nullptr);
}

void Jogo::executar()
{
    while (GG.janelaAberta()) {
        GG.processarEventos();
        GG.limpar();
        pJog1->executar();
        if (doisJogadores) {
            pJog2->executar();
        }

        const sf::Vector2u tamanhoJanela = GG.getTamanhoJanela();
        pChao->definirLimites(
            0.f,
            0.f,
            static_cast<float>(tamanhoJanela.x),
            static_cast<float>(tamanhoJanela.y));
        pChao->executar();

        pJog1->desenhar();
        if (doisJogadores) {
            pJog2->desenhar();
        }
        GG.mostrar();
    }
}

}

