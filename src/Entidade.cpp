#include "../include/Entidades/Entidade.h"

using namespace Jogo;
using namespace Entidades;

Entidade::Entidade(const Vector2f pos, const Vector2f tam, const float vel, const IDs::ID id) : Ente(id), corpo(sf::RectangleShape(tam)), pos(pos), tam(tam), poderemover(false), velFinal(vel, 0.0f), velMax(vel), dt(0)
{
	corpo.setPosition(pos);
}

Entidade::~Entidade()
{
}

void Entidade::atualizarPosicao()
{
	dt = pGG->getTempo();

	Vector2f ds(0.f, 0.f);

	if (andando)
	{
		ds.x = velFinal.x * dt;
		if (paraEsquerda)
		{
			ds.x *= -1;
		}
	}

	const float Vy = velFinal.y;
	velFinal.y = velFinal.y + GRAVIDADE * dt;
	ds.y = Vy * dt + (GRAVIDADE * dt * dt) / 2.0f;

	setPos(Vector2f(pos.x + ds.x, pos.y + ds.y));

	velFinal.x = velMax;
}
const sf::RectangleShape Entidade::getCorpo() const
{
	return corpo;
}

void Entidade::setPos(const sf::Vector2f pos)
{
	corpo.setPosition(pos);
	this->pos = pos;
}

void Entidade::setTam(const sf::Vector2f tam)
{
	corpo.setSize(tam);
	this->tam = tam;
}

sf::Vector2f Entidade::getPos()
{
	return corpo.getPosition();
}

const sf::Vector2f Entidade::getTam() const
{
	return tam;
}

const bool Entidade::getRemover() const
{
	return poderemover;
}

void Entidade::desenhar()
{
	pGG->desenhaElementos(corpo);
}