#pragma once
#include <SFML/Graphics.hpp>
#include <string>

namespace forestry {

class Chao {
private:
    sf::Texture textura;   // a "foto" (declare antes do sprite)
    sf::Sprite sprite;     // quem mostra a foto

public:
    Chao(const std::string& caminho, float larguraJanela, float alturaJanela);

    // evita cópias, pois o sprite aponta para a textura desta própria classe
    Chao(const Chao&) = delete;
    Chao& operator=(const Chao&) = delete;

    void desenhar(sf::RenderWindow& janela);
    sf::FloatRect getLimites() const;   // útil depois para colisão
};

}