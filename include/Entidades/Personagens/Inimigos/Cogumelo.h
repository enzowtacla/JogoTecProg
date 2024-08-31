#pragma once

#include "Inimigo.h"

#define DANO 0.01f
#define VIDA_COGU 50.0f

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
					void inicializa();
				public:
					Cogumelo(const Vector2f pos, const Vector2f tam);
					~Cogumelo();
					void atualizarAnimacao();
					void moveInimigo();
					void colisao(Entidade* outra, sf::Vector2f ds);
					void envenenar(Personagem* pPersonagem);
				};
			}
		}
	}
}