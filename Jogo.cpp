#pragma once
#include "ruinas/Gerenciador_Grafico.h"
#include "ruinas/Jogador.h"


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

