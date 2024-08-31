#pragma once

#include "Obstaculo.h"
#define VELOCIDADE_PLATAFORMA 0.f

namespace Jogo
{
	namespace Entidades
	{
		namespace Obstaculos
		{
			class Plataforma :public Obstaculo
			{
			private:
				Texture textura;

			public:
				Plataforma(const Vector2f pos, const Vector2f tam);
				~Plataforma();
				void colisao(Entidade* outra, sf::Vector2f ds);
				void colisaoObstaculo(Vector2f ds, Personagens::Personagem* pPersonagem);
				void atualizar();
			};
		}
	}
}