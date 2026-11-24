#ifndef INIMIGO_HPP
#define INIMIGO_HPP

#include "Personagem.hpp"

namespace forestry {

    class Jogador;

    class Inimigo : public Personagem {
    protected:
        int nivelMaldade;
        Jogador* pJogador1;
        Jogador* pJogador2;
        sf::Texture textura;
        sf::RectangleShape corpo;

        Jogador* getJogadorMaisProximo() const;
        sf::RectangleShape& getCorpo() { return corpo; }
        void moverHorizontal(float deslocamento);

    public:
        Inimigo(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), int maldade = 1);
        virtual ~Inimigo();

        void setJogadores(Jogador* pJ1, Jogador* pJ2 = nullptr);
        int getNivelMaldade() const;

        virtual void danificar(Jogador* pJ) = 0;
        virtual void mover() = 0;
        virtual void executar() override;
        virtual void salvar() override;
    };

}

#endif