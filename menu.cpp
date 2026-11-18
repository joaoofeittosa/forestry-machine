#include "Menu.h"
#include "Jogo.h"
#include <fstream>
#include <iostream>

Menu::Menu(Jogo* pJ) : Ente(200), pJogo(pJ), selecionado(0), emRanking(false) {
    // Carregue uma fonte .ttf válida no seu diretório (ex: arial.ttf)
    if (!fonte.loadFromFile("arial.ttf")) {
        std::cerr << "Aviso: fonte arial.ttf nao encontrada. Coloque um arquivo .ttf na pasta do executavel.\n";
    }

    std::vector<std::string> textos = {
        "1 - Jogar Fase 1 (1 Jogador)",
        "2 - Jogar Fase 1 (2 Jogadores)",
        "3 - Jogar Fase 2 (1 Jogador)",
        "4 - Carregar Jogo Salvo",
        "5 - Ranking",
        "6 - Sair"
    };

    for (size_t i = 0; i < textos.size(); i++) {
        sf::Text t;
        t.setFont(fonte);
        t.setString(textos[i]);
        t.setCharacterSize(30);
        t.setPosition(420.f, 200.f + i * 55.f);
        t.setFillColor(i == 0 ? sf::Color::Yellow : sf::Color::White);
        opcoes.push_back(t);
    }
}

Menu::~Menu() {}

void Menu::moverCima() {
    if (selecionado > 0) {
        opcoes[selecionado].setFillColor(sf::Color::White);
        selecionado--;
        opcoes[selecionado].setFillColor(sf::Color::Yellow);
    }
}

void Menu::moverBaixo() {
    if (selecionado < static_cast<int>(opcoes.size()) - 1) {
        opcoes[selecionado].setFillColor(sf::Color::White);
        selecionado++;
        opcoes[selecionado].setFillColor(sf::Color::Yellow);
    }
}

void Menu::carregarRanking() {
    linhasRanking.clear();
    std::ifstream arq("ranking.txt");
    std::string linha;
    while (std::getline(arq, linha)) {
        linhasRanking.push_back(linha);
    }
    arq.close();
}

void Menu::selecionarOpcao() {
    if (emRanking) {
        emRanking = false;
        return;
    }

    switch (selecionado) {
        case 0: pJogo->iniciarFase(1, false); break;
        case 1: pJogo->iniciarFase(1, true); break;
        case 2: pJogo->iniciarFase(2, false); break;
        case 3: pJogo->carregarJogo(); break;
        case 4:
            carregarRanking();
            emRanking = true;
            break;
        case 5: pGG->fecharJanela(); break;
    }
}

void Menu::executar() {
    // Controle via eventos no Jogo::executar()
}

void Menu::desenhar() {
    sf::RenderWindow* win = pGG->getWindow();
    if (!win) return;

    if (emRanking) {
        sf::Text titulo("RANKING (Pressione Enter para voltar)", fonte, 32);
        titulo.setPosition(350.f, 100.f);
        titulo.setFillColor(sf::Color::Cyan);
        win->draw(titulo);

        for (size_t i = 0; i < linhasRanking.size() && i < 10; i++) {
            sf::Text item(linhasRanking[i], fonte, 26);
            item.setPosition(420.f, 180.f + i * 40.f);
            win->draw(item);
        }
    } else {
        for (auto& op : opcoes) {
            win->draw(op);
        }
    }
}