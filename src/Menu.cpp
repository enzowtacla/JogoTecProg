
#include "../include/Menus/Menu.h"

using namespace Jogo;
using namespace Menus;


Menu::Menu() : Ente(IDs::ID::MenuPrincipal), botoesMenu(), criarFase(false), numFase(0), numJogadores(0)
{
    largura = pGG->getTamJanela().x;
    altura = pGG->getTamJanela().y;
    fonte = pGG->getGrafico()->carregarFonte("Fonte/menu.ttf");

    std::vector<std::string> botoes = {
        "Fase 1", "Fase 2", "1 jogador", "2 jogadores", "Ranking", "Sair"};

    for (int i = 0; i < botoes.size(); i++)
    {
        sf::Text text;
        text.setFont(fonte);
        text.setString(botoes[i]);
        text.setFillColor(i == 0 ? sf::Color::Red : sf::Color::White);
        text.setPosition(sf::Vector2f(largura / 2 - text.getGlobalBounds().width / 2, altura / (botoes.size() + 1) * (i + 1)));
        botoesMenu.push_back(text);
    }

    posSelecionada = 0;
}

Menu::~Menu()
{
}

void Menu::desenhar()
{
    for (const auto &botao : botoesMenu)
    {
        pGG->desenhaElemento(botao);
    }
}
void Menu::moveCima()
{
    // std::cout << "Moveu para cima" << std::endl;
    if (posSelecionada - 1 >= 0)
    {
        botoesMenu[posSelecionada].setFillColor(sf::Color::White);
        posSelecionada--;
        botoesMenu[posSelecionada].setFillColor(sf::Color::Red);
    }
}

void Menu::moveBaixo()
{
    // std::cout << "Moveu para baixo" << std::endl;
    if (posSelecionada + 1 < botoesMenu.size())
    {
        botoesMenu[posSelecionada].setFillColor(sf::Color::White);
        posSelecionada++;
        botoesMenu[posSelecionada].setFillColor(sf::Color::Red);
    }
}

int Menu::getPosSelecionada()
{
    return posSelecionada;
}

void Menu::setPos(int pos)
{
    posSelecionada = pos;
}

void Menu::selecionado(int pos)
{
    switch(pos)
    {
        case(0):
        {
            criarFase = true;
            numFase = 1;
            pGG->limpaJanela();
        }break;

        case(1):
        {
            criarFase = true;
            numFase = 2;
            pGG->limpaJanela();
        }break;

        case(2):
        {
            numJogadores = 1;
        }break;

        case(3):
        {
            numJogadores = 2;
        }break;

        case(4):
        {

        }break;

        case(5):
        {
            pGG->fecharJanela();
        }break;
    }

}

const bool Menu::getCriarFase() const
{
    return criarFase;
}

const int Menu::getNumFase() const
{
    return numFase;
}
