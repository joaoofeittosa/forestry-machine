#include "Elemento.hpp"
#ifndef LISTA_HPP
#define LISTA_HPP

template <class TL>
class Lista {
private:
    Elemento<TL>* pPrimeiro;
    Elemento<TL>* pUltimo;

public:
    Lista() : pPrimeiro(nullptr), pUltimo(nullptr) {}

    ~Lista() {
        limpar();
    }

    void incluir(TL* p) {
        if (!p) return;
        Elemento<TL>* novo = new Elemento<TL>();
        novo->setInfo(p);

        if (pPrimeiro == nullptr) {
            pPrimeiro = novo;
            pUltimo = novo;
        } else {
            pUltimo->setProx(novo);
            pUltimo = novo;
        }
    }

    void remover(TL* p) {
        Elemento<TL>* aux = pPrimeiro;
        Elemento<TL>* ant = nullptr;

        while (aux != nullptr && aux->getInfo() != p) {
            ant = aux;
            aux = aux->getProx();
        }

        if (aux != nullptr) {
            if (aux == pPrimeiro) {
                pPrimeiro = aux->getProx();
            } else {
                ant->setProx(aux->getProx());
            }
            if (aux == pUltimo) {
                pUltimo = ant;
            }
            delete aux;
        }
    }

    void limpar() {
        Elemento<TL>* aux = pPrimeiro;
        while (aux != nullptr) {
            pPrimeiro = aux->getProx();
            delete aux;
            aux = pPrimeiro;
        }
        pPrimeiro = nullptr;
        pUltimo = nullptr;
    }

    Elemento<TL>* getPrimeiro() const { return pPrimeiro; }
};

#endif