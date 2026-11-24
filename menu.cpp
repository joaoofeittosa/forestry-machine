/*#include "Menu.hpp"
#include "Jogo.hpp"
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
}*/
#include "menu.hpp"
#include "Jogo.hpp"
#include "Gerenciador_grafico.hpp"
#include <algorithm>
#include <iostream>

namespace forestry {

Menu::Menu(Jogo* pJ) :
    Ente(),
    pJogo(pJ),
    temFonte(false),
    temFundo(false),
    texturasOk(false),
    selecionada(0),
    antEsq(false),
    antDir(false),
    antEnter(true),
    antClique(true),
    antMouse(-1, -1)
{
    const char* fontes[] = {
        "Assets/fonte.ttf",
        "C:/Windows/Fonts/arial.ttf",
        "/System/Library/Fonts/Supplemental/Arial.ttf"
    };
    for (const char* caminho : fontes) {
        if (fonte.openFromFile(caminho)) {
            temFonte = true;
            break;
        }
    }
    if (!temFonte) {
        std::cerr << "Menu: nao foi possivel carregar uma fonte." << std::endl;
    }

    temFundo = texFundo.loadFromFile("Assets/Background_Menu.png");
    if (temFundo) {
        texFundo.setSmooth(false);
        fundo.setTexture(&texFundo, true);
        fundo.setFillColor(sf::Color::White);
    } else {
        std::cerr << "Menu: nao foi possivel carregar a imagem de fundo." << std::endl;
        fundo.setFillColor(sf::Color(25, 35, 25));
    }

    texturasOk = texPlaca.loadFromFile("Assets/placa_pendurada.png") &&
                 texPlay.loadFromFile("Assets/botao_laranja_play_normal.png") &&
                 texX.loadFromFile("Assets/botao_laranja_x_normal.png");
    if (!texturasOk) {
        std::cerr << "Menu: nao foi possivel carregar as imagens de Assets/." << std::endl;
    } else {
        placa.emplace(texPlaca);
        botoes[0].emplace(texPlay);
        botoes[1].emplace(texPlay);
        botoes[2].emplace(texX);
    }

    if (temFonte) {
        const sf::Color creme(255, 240, 200);
        const sf::Color contorno(60, 30, 10);

        titulo.emplace(fonte, "FORESTRY MACHINE", 40);
        titulo->setFillColor(creme);
        titulo->setOutlineColor(contorno);
        titulo->setOutlineThickness(3.f);

        const char* nomes[] = {"1 Jogador", "2 Jogadores", "Sair"};
        for (int i = 0; i < 3; i++) {
            rotulos[i].emplace(fonte, nomes[i], 24);
            rotulos[i]->setOutlineColor(contorno);
            rotulos[i]->setOutlineThickness(2.f);
        }
    }
}

Menu::~Menu()
{
    pJogo = nullptr;
}

void Menu::ajustarTexto(sf::Text& t, float larguraMax)
{
    t.setScale(sf::Vector2f(1.f, 1.f));
    float w = t.getLocalBounds().size.x;
    if (w > larguraMax && w > 0.f) {
        float s = larguraMax / w;
        t.setScale(sf::Vector2f(s, s));
    }
}

void Menu::centralizarTexto(sf::Text& t, float cx, float cy)
{
    sf::FloatRect b = t.getLocalBounds();
    t.setOrigin(sf::Vector2f(b.position.x + b.size.x / 2.f,
                             b.position.y + b.size.y / 2.f));
    t.setPosition(sf::Vector2f(cx, cy));
}

void Menu::posicionar(float largura, float altura)
{
    float cx = largura / 2.f;

    float pw = largura * 0.5f;
    float ph = altura * 0.92f;

    if (texturasOk) {
        sf::Vector2u tp = texPlaca.getSize();
        float esc = ph / static_cast<float>(tp.y);
        pw = tp.x * esc;
        placa->setScale(sf::Vector2f(esc, esc));
        placa->setOrigin(sf::Vector2f(tp.x / 2.f, tp.y / 2.f));
        placa->setPosition(sf::Vector2f(cx, altura / 2.f));
    }

    float topo = altura / 2.f - ph / 2.f;
    float tamBotao = std::min(pw * 0.22f, ph * 0.11f);
    float primeiroBotaoY = topo + ph * 0.48f;
    float espacamentoVertical = ph * 0.17f;

    if (temFonte) {
        ajustarTexto(*titulo, pw * 0.70f);
        centralizarTexto(*titulo, cx, topo + ph * 0.30f);
    }

    for (int i = 0; i < 3; i++) {
        float yBotao = primeiroBotaoY + i * espacamentoVertical;

        if (texturasOk) {
            sf::Vector2u ts = botoes[i]->getTexture().getSize();
            float esc = tamBotao / static_cast<float>(ts.x);
            if (i == selecionada) {
                esc *= 1.12f;
                botoes[i]->setColor(sf::Color::White);
            } else {
                botoes[i]->setColor(sf::Color(190, 190, 190));
            }
            botoes[i]->setScale(sf::Vector2f(esc, esc));
            botoes[i]->setOrigin(sf::Vector2f(ts.x / 2.f, ts.y / 2.f));
            botoes[i]->setPosition(sf::Vector2f(cx, yBotao));
        }

        if (temFonte) {
            rotulos[i]->setFillColor(i == selecionada ? sf::Color(255, 220, 60)
                                                      : sf::Color(255, 240, 200));
            ajustarTexto(*rotulos[i], pw * 0.28f);
            centralizarTexto(*rotulos[i], cx,
                             yBotao + tamBotao * 0.56f + ph * 0.02f);
        }
    }
}

void Menu::confirmar()
{
    if (!pJogo) {
        return;
    }
    switch (selecionada) {
        case 0: pJogo->iniciarPartida(false); break;
        case 1: pJogo->iniciarPartida(true);  break;
        case 2: pJogo->sair();                break;
    }
}

void Menu::executar()
{
    if (!pGG) {
        return;
    }

    sf::Vector2u tam = pGG->getTamanhoJanela();
    float largura = static_cast<float>(tam.x);
    float altura = static_cast<float>(tam.y);

    posicionar(largura, altura);

    bool esq = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) ||
               sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) ||
               sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A);
    bool dir = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) ||
               sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) ||
               sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D);
    bool enter = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) ||
                 sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);
    bool clique = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);

    if (esq && !antEsq) {
        selecionada = (selecionada + 2) % 3;
    }
    if (dir && !antDir) {
        selecionada = (selecionada + 1) % 3;
    }
    bool confirmou = enter && !antEnter;

    sf::Vector2i mp = pGG->getPosicaoMouse();
    float mx = static_cast<float>(mp.x);
    float my = static_cast<float>(mp.y);

    if (texturasOk) {
        if (mp != antMouse) {
            for (int i = 0; i < 3; i++) {
                if (botoes[i]->getGlobalBounds().contains(sf::Vector2f(mx, my))) {
                    selecionada = i;
                }
            }
        }
        if (clique && !antClique) {
            for (int i = 0; i < 3; i++) {
                if (botoes[i]->getGlobalBounds().contains(sf::Vector2f(mx, my))) {
                    selecionada = i;
                    confirmou = true;
                }
            }
        }
    }

    antEsq = esq;
    antDir = dir;
    antEnter = enter;
    antClique = clique;
    antMouse = mp;

    if (confirmou) {
        confirmar();
        return;
    }

    posicionar(largura, altura);

    fundo.setSize(sf::Vector2f(largura, altura));
    pGG->desenharObjeto(fundo);

    if (texturasOk) {
        pGG->desenharObjeto(*placa);
        for (int i = 0; i < 3; i++) {
            pGG->desenharObjeto(*botoes[i]);
        }
    }

    if (temFonte) {
        pGG->desenharObjeto(*titulo);
        for (int i = 0; i < 3; i++) {
            pGG->desenharObjeto(*rotulos[i]);
        }
    }
}

}