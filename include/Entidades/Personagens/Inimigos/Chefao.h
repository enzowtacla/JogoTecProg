#pragma once
#include "Inimigo.h"
#include "../Jogadores/Jogador.h"
#define ALCANCE_X 200.0f
#define ALCANCE_Y 200.0f
#define DANAR 0.5f
#define EMPURRAR 5.f

namespace Jogo
{
	namespace Entidades
	{
		namespace Personagens
		{
			namespace Inimigos
			{
				class Chefao :public Inimigo
				{
				private:
					static Entidades::Personagens::Jogadores::Jogador* pJogador;
					static Entidades::Personagens::Jogadores::Jogador* pJogador2;
                    float forcaAtaque;
				public:
					Chefao(const Vector2f pos, const Vector2f tam);
					~Chefao();
					static void setJogador(Entidades::Personagens::Jogadores::Jogador* pJogador);
					static void setJogador2(Entidades::Personagens::Jogadores::Jogador* pJogador2);
					void moveInimigo();
					void persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo);
					void colisao(Entidade* outra, sf::Vector2f ds);
				};
			}
		}
	}
}