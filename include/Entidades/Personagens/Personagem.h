#pragma once

#include <time.h>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Entidade.h"

#define VELOCIDADE 0
#define GRAVIDADE 800.0f
#define VIDA 100.0f

using namespace sf;

namespace Jogo
{
	namespace Entidades
	{
		namespace Personagens
		{
			class Personagem :public Entidade
			{
			protected:
				Vector2f velFinal;
				bool paraEsquerda;
				float dt;
				bool andando;
				const float velMax;
				Animacoes::Animacao animacao;
				float vida;

			public:
				Personagem(const Vector2f pos, const Vector2f tam, const float vel, const IDs::ID id);
				virtual ~Personagem();
				void andar(const bool paraEsquerda);
				void parar();
				virtual void atualizar() = 0;
				virtual void atualizarAnimacao() =0;
				void atualizarPosicao();
				Vector2f getVelFinal();
				void setVelFinal(const Vector2f velFinal);
				virtual void desenhar();
				virtual void colisao(Entidade* outra, sf::Vector2f ds = sf::Vector2f(0.f, 0.f)) = 0;
				const float getVida() const;
				void tomarDano(float dano);
			};
		}
	}
}