#ifndef GERENCIADOR_COLISOES_HPP
#define GERENCIADOR_COLISOES_HPP

#include <list>
#include <set>
#include <vector>

namespace forestry {

class Entidade;
class Inimigo;
class Jogador;
class Obstaculo;
class Projetil;

class GerenciadorColisoes {
private:
    std::vector<Inimigo*> LIs;
    std::list<Obstaculo*> LOs;
    std::set<Projetil*> LPs;
    Jogador* pJog1;
    Jogador* pJog2;

    bool verificarColisao(const Entidade* pe1, const Entidade* pe2) const;
    void tratarColisoesJogsObstacs();
    void tratarColisoesJogsInims();
    void tratarColisoesJogsProjeteis();
    void tratarColisoesProjeteisObstacs();

public:
    GerenciadorColisoes();
    ~GerenciadorColisoes();

    void setJogador1(Jogador* pJ1);
    void setJogador2(Jogador* pJ2);
    void incluirInimigo(Inimigo* pI);
    void incluirObstaculo(Obstaculo* pO);
    void incluirProjetil(Projetil* pP);
    void removerInimigo(Inimigo* pI);
    void removerObstaculo(Obstaculo* pO);
    void removerProjetil(Projetil* pP);
    void limpar();
    void executar();
};

}

#endif
