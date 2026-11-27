#include "Fase.hpp"

#include "Inimigo.hpp"
#include "Obstaculo.hpp"
#include "Projetil.hpp"

#include <filesystem>
#include <fstream>
#include <iostream>

namespace forestry {

Fase::Fase(const std::string& nome)
    : Ente(),
      listaEntidades(),
      nomeFase(nome)
{
}

Fase::~Fase()
{
    listaEntidades.limpar();
}

void Fase::executar()
{
    Elemento<Entidade>* pEl = listaEntidades.getPrimeiro();
    while (pEl) {
        Elemento<Entidade>* pProx = pEl->getProx();
        Entidade* pE = pEl->getInfo();
        if (pE) {
            pE->executar();
        }
        pEl = pProx;
    }

    gerenciadorColisoes.executar();
    listaEntidades.desenharTudo();
}

void Fase::salvar()
{
    std::error_code ec;
    std::filesystem::create_directories("jogo.salvo", ec);

    const std::string percurso = "jogo.salvo/" + nomeFase + ".json";
    std::ofstream saida(percurso);
    if (!saida.is_open()) {
        std::cerr << "[Fase] Falha ao abrir " << percurso << " para escrita.\n";
        return;
    }

    saida << "{\n";
    saida << "  \"fase\": \"" << nomeFase << "\",\n";
    saida << "  \"entidades\": [\n";

    bool primeiro = true;
    Elemento<Entidade>* pEl = listaEntidades.getPrimeiro();
    while (pEl) {
        Entidade* pE = pEl->getInfo();
        if (pE) {
            if (!primeiro) saida << ",\n";
            primeiro = false;
            pE->salvar();
        }
        pEl = pEl->getProx();
    }

    saida << "\n  ]\n}\n";
}

void Fase::incluirEntidade(Entidade* pE)
{
    if (!pE) return;
    listaEntidades.incluir(pE);

    if (Inimigo* pInimigo = dynamic_cast<Inimigo*>(pE)) {
        gerenciadorColisoes.incluirInimigo(pInimigo);
    }
    if (Obstaculo* pObstaculo = dynamic_cast<Obstaculo*>(pE)) {
        gerenciadorColisoes.incluirObstaculo(pObstaculo);
    }
    if (Projetil* pProjetil = dynamic_cast<Projetil*>(pE)) {
        gerenciadorColisoes.incluirProjetil(pProjetil);
    }
}

void Fase::removerEntidade(Entidade* pE)
{
    if (!pE) return;

    if (Inimigo* pInimigo = dynamic_cast<Inimigo*>(pE)) {
        gerenciadorColisoes.removerInimigo(pInimigo);
    }
    if (Obstaculo* pObstaculo = dynamic_cast<Obstaculo*>(pE)) {
        gerenciadorColisoes.removerObstaculo(pObstaculo);
    }
    if (Projetil* pProjetil = dynamic_cast<Projetil*>(pE)) {
        gerenciadorColisoes.removerProjetil(pProjetil);
    }

    listaEntidades.remover(pE);
}

}
