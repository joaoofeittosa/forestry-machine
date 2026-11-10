/*#pragma once
#include "Types.h"
#include <SFML/Graphics.hpp>
#include <string>


namespace ruinas {
class Entity {
public:
    explicit Entity(sf::Vector2f position); virtual ~Entity()=default;
    virtual void update(float dt)=0;
    virtual void draw(sf::RenderWindow& window) const=0;
    virtual sf::FloatRect bounds() const=0;
    virtual bool isAlive() const
    {
        return alive_;
    }
    virtual void damage(int amount);
    sf::Vector2f position() const
    {
        return position_;
    }
    void setPosition(sf::Vector2f p)
    {
        position_=p;
    }
    int health() const
    {
        return health_;
    }
protected:
    sf::Vector2f position_, velocity_{0.f,0.f}; int health_=1; bool alive_=true;
    float gravity_=1100.f;
};


}*/


#pragma once
#include <SFML/Graphics.hpp>


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

