#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
//#include "GerenciadorGrafico.h"
#include "../Ente.h"
#include "../Animacoes/Animacao.h"
#define GRAVIDADE 800.0f


namespace Jogo
{
	namespace Entidades
	{
		class Entidade : public Ente
		{
		protected:
			sf::RectangleShape corpo;
			sf::Vector2f pos;
			sf::Vector2f tam;
			bool poderemover;
			Vector2f velFinal;
			bool paraEsquerda;
			float dt;
			bool andando;
			const float velMax;
		
			//static Gerenciadores::GerenciadorGrafico* pGG;

		public:
			Entidade(const Vector2f pos, const Vector2f tam, const float vel, const IDs::ID id);
			~Entidade();
			const sf::RectangleShape getCorpo() const;
			virtual void atualizar() = 0;
			virtual void atualizarPosicao();
			void setPos(const sf::Vector2f pos);
			void setTam(const sf::Vector2f tam);
			sf::Vector2f getPos();
			const sf::Vector2f getTam() const;
			const bool getRemover() const;
			virtual void desenhar();
			virtual void colisao(Entidade* outra, sf::Vector2f ds = sf::Vector2f(0.f, 0.f)) = 0;
		};
	}
}