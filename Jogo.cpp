/*#include "Jogo.hpp"

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

}*/
#include "Jogo.hpp"
#include "Chao.hpp"
#include "Fase.hpp"
#include "FaseFloresta.hpp"
#include "menu.hpp"

namespace forestry {

Jogo::Jogo() :
    GG(),
    pMenu(nullptr),
    pChao(nullptr),
    pFase(nullptr),
    pJog1(nullptr),
    pJog2(nullptr),
    jogando(false)
{
    Ente::setGG(&GG);
    pMenu = new Menu(this);
}

Jogo::Jogo(bool doisJogadores) :
    Jogo()
{
    iniciarPartida(doisJogadores);
}

Jogo::~Jogo()
{
    delete pFase;
    delete pJog1;
    delete pJog2;
    delete pChao;
    delete pMenu;
    pJog1 = nullptr;
    pJog2 = nullptr;
    pChao = nullptr;
    pFase = nullptr;
    pMenu = nullptr;
    Ente::setGG(nullptr);
}

void Jogo::iniciarPartida(bool doisJogadores)
{
    delete pFase;
    delete pJog1;
    delete pJog2;
    delete pChao;
    pJog1 = nullptr;
    pJog2 = nullptr;
    pChao = nullptr;
    pFase = nullptr;

    const sf::Vector2u tamanhoJanela = GG.getTamanhoJanela();
    pChao = new Chao(0.f, 0.f,
                     static_cast<float>(tamanhoJanela.x),
                     static_cast<float>(tamanhoJanela.y));
    pJog1 = new Jogador(sf::Vector2f(100.f, 100.f), false);
    pChao->adicionarEntidade(pJog1);
    if (doisJogadores) {
        pJog2 = new Jogador(sf::Vector2f(200.f, 100.f), true);
        pChao->adicionarEntidade(pJog2);
    }
    pFase = new FaseFloresta(pJog1, pJog2);
    jogando = true;
}

void Jogo::sair()
{
    GG.fechar();
}

void Jogo::executar()
{
    while (GG.janelaAberta()) {
        GG.processarEventos();
        GG.limpar();

        if (!jogando) {
            pMenu->executar();
        } else {
            pJog1->executar();
            if (pJog2) {
                pJog2->executar();
            }

            pFase->executar();

            const sf::Vector2u tamanhoJanela = GG.getTamanhoJanela();
            pChao->definirLimites(
                0.f,
                0.f,
                static_cast<float>(tamanhoJanela.x),
                static_cast<float>(tamanhoJanela.y));
            pChao->executar();

            pJog1->desenhar();
            if (pJog2) {
                pJog2->desenhar();
            }
        }

        GG.mostrar();
    }
}

}

