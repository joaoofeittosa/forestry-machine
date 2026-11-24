#ifndef JOGO_HPP
#define JOGO_HPP

#include "Gerenciador_grafico.hpp"
#include "chao.hpp"
#include "Jogador.hpp"


namespace forestry {


class Jogo {
private:
    Gerenciador_Grafico GG;
    Chao* pChao;
    Jogador* pJog1;
    Jogador* pJog2;
    bool doisJogadores;


public:
    explicit Jogo(bool doisJogadores = true);
    ~Jogo();


    void executar();
};


}

#endif
