#include "Lista.hpp"
#include "Entidade.hpp"
#ifndef LISTA_ENTIDADES_HPP
#define LISTA_ENTIDADES_HPP

class ListaEntidades {
private:
    Lista<forestry::Entidade> LEs;

public:
    ListaEntidades();
    ~ListaEntidades();

    void incluir(forestry::Entidade* pE);
    void remover(forestry::Entidade* pE);
    void percorrer();
    void desenharTudo();
    void limpar();
    Elemento<forestry::Entidade>* getPrimeiro() const;
};

#endif