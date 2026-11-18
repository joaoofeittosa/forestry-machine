#pragma once
<<<<<<< Updated upstream
#include "Gerenciador_Grafico.hpp"
#include "Jogador.h"
=======
#include "Gerenciador_grafico.hpp"
#include "Jogador.hpp"
>>>>>>> Stashed changes


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

