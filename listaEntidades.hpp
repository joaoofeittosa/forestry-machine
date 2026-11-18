#pragma once
#include "Lista.h"
#include "Entidade.h"

class ListaEntidades {
private:
    Lista<Entidades::Entidade> LEs;

public:
    ListaEntidades();
    ~ListaEntidades();

    void incluir(Entidades::Entidade* pE);
    void remover(Entidades::Entidade* pE);
    void percorrer();
    void desenharTudo();
    void limpar();
    Elemento<Entidades::Entidade>* getPrimeiro() const;
};