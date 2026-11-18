<<<<<<< Updated upstream
#include "Gerenciador_Grafico.hpp"
#include "Ente.hpp"
=======
#include "Gerenciador_grafico.hpp"
#include "Ente.hpp"
#include <optional>
>>>>>>> Stashed changes


namespace forestry {


Gerenciador_Grafico::Gerenciador_Grafico(unsigned int largura,
                                         unsigned int altura,
                                         const std::string& titulo) :
    obj(sf::VideoMode(sf::Vector2u(largura, altura)), titulo),
    dt(0.f)
{
    obj.setFramerateLimit(60);
}


Gerenciador_Grafico::~Gerenciador_Grafico()
{
    if (obj.isOpen()) {
        obj.close();
    }
}


void Gerenciador_Grafico::desenharEnte(Ente* pE)
{
    if (pE && pE->getFigura()) {
        obj.draw(*pE->getFigura());
    }
}


void Gerenciador_Grafico::limpar()
{
    dt = relogio.restart().asSeconds();
    if (dt > 0.05f) {
        dt = 0.05f;
    }
    obj.clear();
}


void Gerenciador_Grafico::mostrar()
{
    obj.display();
}


void Gerenciador_Grafico::processarEventos()
{
    while (const std::optional<sf::Event> evento = obj.pollEvent()) {
        if (evento->is<sf::Event::Closed>()) {
            obj.close();
        }
    }
}

float Gerenciador_Grafico::getDeltaTime() const
{
    return dt;
}


bool Gerenciador_Grafico::janelaAberta() const
{
    return obj.isOpen();
}


void Gerenciador_Grafico::fechar()
{
    obj.close();
}


}

