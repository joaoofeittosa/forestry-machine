#ifndef GERENCIADOR_GRAFICO_HPP
#define GERENCIADOR_GRAFICO_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <string>


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
                         const std::string& titulo = "Forestry-Machine");
    ~Gerenciador_Grafico();


    void desenharEnte(Ente* pE);


    float getDeltaTime() const;
    sf::Vector2u getTamanhoJanela() const;
    void limpar();
    void mostrar();
    void processarEventos();
    bool janelaAberta() const;
    void fechar();
    
};


}

#endif
