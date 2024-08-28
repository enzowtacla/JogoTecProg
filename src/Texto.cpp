#include "Texto.h"

using namespace Jogo;
using namespace Menus;
using namespace Botoes;

Texto::Texto(const Font fonte, const std::string info, const unsigned int tamFonte) : fonte(fonte), texto(), info(info), corTexto(Color::White), corBorda(Color::Black), tamFonte(tamFonte)
{
    inicializa();
}

Texto::~Texto()
{
}

void Texto::inicializa()
{
    texto.setString(info);
    texto.setCharacterSize(tamFonte);
    texto.setFont(fonte);
    texto.setOutlineThickness(5.f);
    texto.setOutlineColor(corBorda);
    texto.setFillColor(corTexto);
    tam = Vector2f(texto.getGlobalBounds().width, texto.getGlobalBounds().height);
}

void Texto::setCorTexto(const Color corTexto)
{
    this->corTexto = corTexto;
    texto.setFillColor(corTexto);
}

const Text Texto::getTexto() const
{
    return texto;
}

void Texto::setPos(const Vector2f pos)
{
    this->pos = pos;
    texto.setPosition(pos);
}

const Vector2f Texto::getPos() const
{
    return pos;
}

const Vector2f Texto::getTam() const
{
    return tam;
}

void Texto::setTamanhoBorda(const float tamBorda)
{
    texto.setOutlineThickness(tamBorda);
    tam = Vector2f(texto.getGlobalBounds().width, texto.getGlobalBounds().height);
}

void Texto::setEspacamento(const float tamEspaco)
{
    texto.setLetterSpacing(tamEspaco);
    tam = Vector2f(texto.getGlobalBounds().width, texto.getGlobalBounds().height);
}

void Texto::setString(std::string nome)
{
    texto.setString(nome);
    tam = Vector2f(texto.getGlobalBounds().width, texto.getGlobalBounds().height);
}

const std::string Texto::getString() const
{
    return texto.getString();
}

void Texto::setTamFonte(const unsigned int tamFonte)
{
    texto.setCharacterSize(tamFonte);
    tam = sf::Vector2f(texto.getGlobalBounds().width, texto.getGlobalBounds().height);
}