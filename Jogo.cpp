#pragma once
#include "Gerenciador_Grafico.h"
#include "Jogador.h"


namespace ruinas {


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

