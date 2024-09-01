#include "../include/Entidades/Obstaculos/Slime.h" 
#include "../include/Entidades/Personagens/Jogadores/Jogador.h"

#include <iostream> 

using namespace Jogo;
using namespace Entidades;
using namespace Obstaculos;
using namespace sf;

Slime::Slime(const sf::Vector2f pos, const sf::Vector2f tam)
    : Obstaculo(pos, tam, VELOCIDADE_SLIME,IDs::ID::slime), pegajosidadeMovimento(0.4f)
{
    textura = pGG->carregarTextura("Assets/slime.png");
    //corpo = sf::RectangleShape(tam);
    //corpo.setPosition(pos);
    corpo.setTexture(&textura);
}

Slime::~Slime()
{
}

void Slime::atualizar()
{
    atualizarPosicao();
}

void Slime::colisao(Entidade* outra, sf::Vector2f ds)
{
    if (outra->getId() == IDs::ID::jogador)
    {
        atrapalhar(static_cast<Personagens::Jogadores::Jogador*>(outra));

    }
}

void Slime::atrapalhar(Personagens::Jogadores::Jogador* pJogador)
{
    if (pJogador)
    {
        pJogador->setVelocidadeMovimento(pJogador->getVelocidadeMovimento() * pegajosidadeMovimento);
    }
}
