#pragma once

#include "Inimigo.h"

#define DANO 0.01f

namespace Jogo
{
	namespace Entidades
	{
		namespace Personagens
		{
			namespace Inimigos
			{
				class Cogumelo :public Inimigo
				{
				private:
					float forçaVeneno;
				public:
					Cogumelo(const Vector2f pos, const Vector2f tam);
					~Cogumelo();
					void moveInimigo();
					void colisao(Entidade* outra, sf::Vector2f ds);
					void envenenar(Personagem* pPersonagem);
				};
			}
		}
	}
}