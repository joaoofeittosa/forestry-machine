#include <SFML/Graphics.hpp>
#ifndef ENTE_HPP
#define ENTE_HPP


namespace forestry {


class Gerenciador_Grafico;


class Ente {
protected:
    int id;
    static Gerenciador_Grafico* pGG;
    sf::Shape* pFig;


public:
    Ente();
    virtual ~Ente();


    virtual void executar() = 0;
    void desenhar();


    sf::Shape* getFigura() const {
        return pFig;
    }
    static void setGG(Gerenciador_Grafico* pG);
};


}

#endif

