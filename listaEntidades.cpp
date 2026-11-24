#include "ListaEntidades.hpp"

ListaEntidades::ListaEntidades() {}

ListaEntidades::~ListaEntidades() {
    limpar();
}

void ListaEntidades::incluir(forestry::Entidade* pE) {
    LEs.incluir(pE);
}

void ListaEntidades::remover(forestry::Entidade* pE) {
    LEs.remover(pE);
}

void ListaEntidades::percorrer() {
    Elemento<forestry::Entidade>* aux = LEs.getPrimeiro();
    while (aux != nullptr) {
        forestry::Entidade* ent = aux->getInfo();
        if (ent) {
            ent->executar();
        }
        aux = aux->getProx();
    }
}

void ListaEntidades::desenharTudo() {
    Elemento<forestry::Entidade>* aux = LEs.getPrimeiro();
    while (aux != nullptr) {
        forestry::Entidade* ent = aux->getInfo();
        if (ent) {
            ent->desenhar();
        }
        aux = aux->getProx();
    }
}

void ListaEntidades::limpar() {
    Elemento<forestry::Entidade>* aux = LEs.getPrimeiro();
    while (aux != nullptr) {
        delete aux->getInfo();
        aux = aux->getProx();
    }
    LEs.limpar();
}

Elemento<forestry::Entidade>* ListaEntidades::getPrimeiro() const {
    return LEs.getPrimeiro();
}