#ifndef MENU_HPP
#define MENU_HPP
#include "Ente.hpp"
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
};
#endif