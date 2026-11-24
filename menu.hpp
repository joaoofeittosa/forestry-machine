#ifndef MENU_HPP
#define MENU_HPP
#include "Ente.hpp"
#include <optional>

namespace forestry {

class Jogo;

class Menu : public Ente {
private:
    Jogo* pJogo;

    sf::Font fonte;
    bool temFonte;

    sf::Texture texFundo;
    bool temFundo;
    sf::Texture texPlaca;
    sf::Texture texPlay;
    sf::Texture texX;
    bool texturasOk;

    sf::RectangleShape fundo;
    std::optional<sf::Sprite> placa;
    std::optional<sf::Sprite> botoes[3];
    std::optional<sf::Text> titulo;
    std::optional<sf::Text> rotulos[3];

    int selecionada;
    bool antEsq, antDir, antEnter, antClique;
    sf::Vector2i antMouse;

    void posicionar(float largura, float altura);
    void ajustarTexto(sf::Text& t, float larguraMax);
    void centralizarTexto(sf::Text& t, float cx, float cy);
    void confirmar();

public:
    explicit Menu(Jogo* pJ = nullptr);
    ~Menu();

    void executar();
};

}

/*#include "Ente.hpp"
#include <vector>
#include <string>

class Jogo;

class Menu : public Ente {
private:
    Jogo* pJogo;
    sf::Font fonte;
    std::vector<sf::Text> opcoes;
    int selecionado;
    bool emRanking;
    std::vector<std::string> linhasRanking;

    void carregarRanking();

public:
    Menu(Jogo* pJ);
    ~Menu();

    void executar() override;
    void desenhar() override;
    void moverCima();
    void moverBaixo();
    void selecionarOpcao();
};*/
#endif