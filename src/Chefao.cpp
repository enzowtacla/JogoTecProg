#include "../include/Entidades/Personagens/Inimigos/Chefao.h"

using namespace Jogo;
using namespace Entidades;
using namespace Personagens;
using namespace Inimigos;

Entidades::Personagens::Jogadores::Jogador *Chefao::pJogador = nullptr;
Entidades::Personagens::Jogadores::Jogador *Chefao::pJogador2 = nullptr;

Chefao::Chefao (const Vector2f pos, const Vector2f tam) : Inimigo(pos, tam, IDs::ID::chefao), forcaAtaque(DANAR)
{
    corpo.setFillColor(Color::Yellow);
}

Chefao::~Chefao()
{

}

void Chefao::setJogador(Entidades::Personagens::Jogadores::Jogador *j)
{
	pJogador = j;
}

void Chefao::setJogador2(Entidades::Personagens::Jogadores::Jogador *j)
{
	pJogador2 = j;
}

void Chefao::persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo)
{
	if (posJogador.x - posInimigo.x > 0.f)
	{
		paraEsquerda = false;
		andar(paraEsquerda);
	}
	else
	{
		paraEsquerda = true;
		andar(paraEsquerda);
	}
}

void Chefao::moveInimigo()
{
	if (pJogador->getVivo() && pJogador2->getVivo())
    {
        sf::Vector2f posJogador1 = pJogador->getCorpo().getPosition();
        sf::Vector2f posJogador2 = pJogador2->getCorpo().getPosition();
        sf::Vector2f posInimigo = corpo.getPosition();
        float dist1 = fabs(posJogador1.x - posInimigo.x);
        float dist2 = fabs(posJogador2.x - posInimigo.x);

        if (dist1 <= ALCANCE_X && dist1 <= ALCANCE_Y &&
            (dist1 < dist2 || dist2 > ALCANCE_X || dist2 > ALCANCE_Y))
        {
            persegueJogador(posJogador1, posInimigo);
        }
        else if (dist2 <= ALCANCE_X && dist2 <= ALCANCE_Y)
        {
            persegueJogador(posJogador2, posInimigo);
        }
        else
        {
            atualizaMovimentoAleatorio();
        }
    }
    else if (pJogador->getVivo()) 
    {
        sf::Vector2f posJogador1 = pJogador->getCorpo().getPosition();
        sf::Vector2f posInimigo = corpo.getPosition();
        persegueJogador(posJogador1, posInimigo);
    }
    else if (pJogador2->getVivo()) 
    {
        sf::Vector2f posJogador2 = pJogador2->getCorpo().getPosition();
        sf::Vector2f posInimigo = corpo.getPosition();
        persegueJogador(posJogador2, posInimigo);
    }
    else
    {
        atualizaMovimentoAleatorio();
    }
}

void Chefao::colisao(Entidade *outra, sf::Vector2f ds)
{
	if (outra->getId() == IDs::ID::jogador)
	{
		//(static_cast<Personagens::Personagem *>(outra));
	}
}

/*
void Chefao:: (Personagem* pPersonagem)
{
	if(pPersonagem){
		Personagens::Jogadores::Jogador* pJogador = static_cast<Personagens::Jogadores::Jogador*>(pPersonagem);
		pJogador->tomarDano(forcaAtaque);
		pJogador->knockBack(EMPURRAO);
	}
}
*/