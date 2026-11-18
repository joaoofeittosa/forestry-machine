#pragma once
#include "Gerenciador_Grafico.hpp"
#include "Jogador.h"


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

