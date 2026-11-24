
#include "Fase.hpp"

#include <filesystem>
#include <fstream>
#include <iostream>

namespace forestry {

Fase::Fase(const std::string& nome)
    : Ente(),
      listaEntidades(),
      nomeFase(nome),
     /* gerenciadorColisoes()*/
{

}

Fase::~Fase() {

   /* gerenciadorColisoes.limpar();*/
    listaEntidades.limpar();
}

void Fase::executar() {
 
    Elemento<Entidade>* pEl = listaEntidades.getPrimeiro();
    while (pEl) {
        Elemento<Entidade>* pProx = pEl->getProximo();
        Entidade* pE = pEl->getInfo();
        if (pE) {
            pE->executar();
        }
        pEl = pProx;
    }

   /* gerenciadorColisoes.executar();*/
    listaEntidades.desenharTudo();
}

void Fase::salvar() {
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
            pE->salvar(saida);  
}
        }
        pEl = pEl->getProximo();
    }

    saida << "\n  ]\n}\n";
}

void Fase::incluirEntidade(Entidade* pE) {
    if (!pE) return;
    listaEntidades.incluir(pE);
    /* gerenciadorColisoes.incluirEntidade(pE); */
}

void Fase::removerEntidade(Entidade* pE) {
    if (!pE) return;
    /* gerenciadorColisoes.removerEntidade(pE); */
    listaEntidades.remover(pE);
}

} 



