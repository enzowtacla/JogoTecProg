#include "../include/Entidades/Obstaculos/Slime.h" 
#include "../include/Entidades/Personagens/Jogadores/Jogador.h"

#include <iostream> 

using namespace Jogo;
using namespace Entidades;
using namespace Obstaculos;
using namespace sf;

Slime::Slime(const sf::Vector2f pos, const sf::Vector2f tam)
    : Obstaculo(pos, tam, IDs::ID::slime), pegajosidadePulo(-0.13f), pegajosidadeMovimento(0.5f), jogadorColidindo(false)
{
    corpo = sf::RectangleShape(tam);
    corpo.setPosition(pos);
    corpo.setFillColor(Color::Green);
}

Slime::~Slime()
{
}

void Slime::atualizar()
{
    // desnecessário por enquanto
}

void Slime::colisao(Entidade* outra, sf::Vector2f ds)
{
    if (outra->getId() == IDs::ID::jogador)
    {
        if (!jogadorColidindo)
        {
            atrapalhar(static_cast<Personagens::Jogadores::Jogador*>(outra));
            jogadorColidindo = true;
        }
    }
    else if (jogadorColidindo)
    {
        restaurarEfeito(static_cast<Personagens::Jogadores::Jogador*>(outra));
        jogadorColidindo = false;
    }
}

void Slime::atrapalhar(Personagens::Jogadores::Jogador* pJogador)
{
    if (pJogador)
    {
        pJogador->setVelocidadeMovimento(pJogador->getVelocidadeMovimento() * pegajosidadeMovimento);
        //pJogador->setVelocidadePulo(pJogador->getVelocidadePulo() * pegajosidadePulo);
    }
}

void Slime::restaurarEfeito(Personagens::Jogadores::Jogador* pJogador)
{
    if (pJogador)
    {
        pJogador->setVelocidadeMovimento(VELOCIDADE_JOGADOR_X);
       // pJogador->setVelocidadePulo(TAMANHO_PULO);
    }
}
