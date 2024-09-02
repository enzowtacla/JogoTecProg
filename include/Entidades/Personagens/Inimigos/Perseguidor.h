#pragma once
#include "Inimigo.h"
#include "../Jogadores/Jogador.h"
#define ALCANCE_X 200.0f
#define ALCANCE_Y 200.0f
#define EMPURRAO 75.0f
#define CABECADA 0.2f

namespace Jogo
{
	namespace Entidades
	{
		namespace Personagens
		{
			namespace Inimigos
			{
				class Perseguidor :public Inimigo
				{
				private:
					static Entidades::Personagens::Jogadores::Jogador* pJogador;
					static Entidades::Personagens::Jogadores::Jogador* pJogador2;
					float forcaEmpurrao;
					float forcaCabecada;
					bool perseguindo;
					void inicializa();
				public:
					Perseguidor(const Vector2f pos, const Vector2f tam);
					~Perseguidor();
					static void setJogador(Entidades::Personagens::Jogadores::Jogador* pJogador);
					static void setJogador2(Entidades::Personagens::Jogadores::Jogador* pJogador2);
					void moveInimigo();
					void persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo);
					void colisao(Entidade* outra, sf::Vector2f ds);
					void cabeciar(Personagem* pPersonagem);
				};
			}
		}
	}
}