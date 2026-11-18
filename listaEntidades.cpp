#include "ListaEntidades.hpp"

ListaEntidades::ListaEntidades() {}

ListaEntidades::~ListaEntidades() {
    limpar();
}

void ListaEntidades::incluir(Entidades::Entidade* pE) {
    LEs.incluir(pE);
}

void ListaEntidades::remover(Entidades::Entidade* pE) {
    LEs.remover(pE);
}

void ListaEntidades::percorrer() {
    Elemento<Entidades::Entidade>* aux = LEs.getPrimeiro();
    while (aux != nullptr) {
        Entidades::Entidade* ent = aux->getInfo();
        if (ent && ent->getAtivo()) {
            ent->executar();
        }
        aux = aux->getProx();
    }
}

void ListaEntidades::desenharTudo() {
    Elemento<Entidades::Entidade>* aux = LEs.getPrimeiro();
    while (aux != nullptr) {
        Entidades::Entidade* ent = aux->getInfo();
        if (ent && ent->getAtivo()) {
            ent->desenhar();
        }
        aux = aux->getProx();
    }
}

void ListaEntidades::limpar() {
    Elemento<Entidades::Entidade>* aux = LEs.getPrimeiro();
    while (aux != nullptr) {
        delete aux->getInfo();
        aux = aux->getProx();
    }
    LEs.limpar();
}

Elemento<Entidades::Entidade>* ListaEntidades::getPrimeiro() const {
    return LEs.getPrimeiro();
}