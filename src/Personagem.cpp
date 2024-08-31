#include "../include/Entidades/Personagens/Personagem.h"
using namespace Jogo;
using namespace Entidades;
using namespace Personagens;
using namespace sf;

Personagem::Personagem(const Vector2f pos, const Vector2f tam, const float vel, const IDs::ID id) :
	Entidade(pos, tam, id), velFinal(vel, 0.0f), velMax(vel), andando(false), paraEsquerda(false), dt(0.0f), animacao(&corpo), vida(VIDA)
{

}

Personagem::~Personagem()
{

}

void Personagem::andar(const bool paraEsquerda)
{
	andando = true;
	this->paraEsquerda = paraEsquerda;
}

void Personagem::parar()
{
	andando = false;
}

void Personagem::atualizarPosicao()
{

	dt = pGG->getTempo();
	
	Vector2f ds(0.f, 0.f);

	if (andando) {
		ds.x = velFinal.x * dt;
		if (paraEsquerda) {
			ds.x *= -1;
		}
	}
	
	const float Vy = velFinal.y;
	velFinal.y = velFinal.y + GRAVIDADE * dt;
	ds.y = Vy * dt + (GRAVIDADE * dt * dt) / 2.0f;

	setPos(Vector2f(pos.x + ds.x, pos.y + ds.y));

	velFinal.x = velMax;

}

Vector2f Personagem::getVelFinal()
{
	return velFinal;
}

void Personagem::tomarDano(float dano)
{
	vida -= dano;
}
void Personagem::desenhar()
{
	pGG->desenhaElementos(corpo);
}


void Personagem::setVelFinal(const Vector2f velFinal)
{
	this->velFinal = velFinal;
}

const float Personagem::getVida() const
{
	return vida;
}