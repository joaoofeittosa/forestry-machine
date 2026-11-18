#include "Chao.hpp"
#include <iostream>

namespace forestry {

Chao::Chao(const std::string& caminho, float larguraJanela, float alturaJanela)
{
    if (!textura.loadFromFile(caminho)) {
        std::cout << "Nao achei " << caminho << "\n";
    }
    textura.setRepeated(true);
    sprite.setTexture(textura);

    int alturaImagem = textura.getSize().y;

    // repete a imagem até cobrir a largura da janela
    sprite.setTextureRect(sf::IntRect(0, 0, (int)larguraJanela, alturaImagem));

    // cola o chão na parte de baixo da janela
    sprite.setPosition(0.f, alturaJanela - alturaImagem);
}

void Chao::desenhar(sf::RenderWindow& janela)
{
    janela.draw(sprite);
}

sf::FloatRect Chao::getLimites() const
{
    return sprite.getGlobalBounds();
}

}