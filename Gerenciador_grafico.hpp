#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#ifndef GERENCIADOR_GRAFICO_HPP
#define GERENCIADOR_GRAFICO_HPP

namespace forestry {


class Ente;


class Gerenciador_Grafico {
private:
    sf::RenderWindow obj;
    sf::Clock relogio;
    float dt;


public:
    Gerenciador_Grafico(unsigned int largura = 1280,
                        unsigned int altura = 720,
                        const std::string& titulo = "Ruinas");
    ~Gerenciador_Grafico();


    void desenharEnte(Ente* pE);


    float getDeltaTime() const;
    void limpar();
    void mostrar();
    void processarEventos();
    bool janelaAberta() const;
    void fechar();
    
};


}

#endif
