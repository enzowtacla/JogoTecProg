#include "TextoAnimado.h"

using namespace Jogo;
using namespace Menus;
using namespace Botoes;

TextoAnimado::TextoAnimado(const sf::Font fonte, const std::string info) : Texto(fonte, info), clareando(true), transparente(255)
{
}

TextoAnimado::~TextoAnimado()
{
}

void TextoAnimado::mudarClareando()
{
    clareando = !clareando;
}

const bool TextoAnimado::getClareando() const
{
    return clareando;
}

const int TextoAnimado::getTransparente() const
{
    return transparente;
}

void TextoAnimado::setTransparente(const int transparente)
{
    this->transparente = transparente;
    atualizar();
}

void TextoAnimado::resetar()
{
    transparente = 255;
    atualizar();
}

void TextoAnimado::atualizar()
{
    corBorda = sf::Color{0, 0, 0, (sf::Uint8)this->transparente};
    corTexto = sf::Color{corTexto.r, corTexto.g, corTexto.b, (sf::Uint8)this->transparente};
    texto.setOutlineColor(corBorda);
    texto.setFillColor(corTexto);
}