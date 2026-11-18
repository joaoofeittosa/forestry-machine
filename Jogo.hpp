#pragma once
#include "Gerenciador_grafico.hpp"
#include "Jogador.hpp"


namespace forestry {


class Jogo {
private:
    Gerenciador_Grafico GG;
    Jogador* pJog1;


public:
    Jogo();
    ~Jogo();


    void executar();
};


}

