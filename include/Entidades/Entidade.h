#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
//#include "GerenciadorGrafico.h"
#include "../Ente.h"

#define GRAVIDADE 800.0f
#define EMPUXO -800.0f

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
			float dt;
			bool andando;
			const float velMax;
			sf::Texture textura;

		public:
			Entidade(const sf::Vector2f pos, const sf::Vector2f tam, const float vel, const IDs::ID id);
			~Entidade();
			const sf::RectangleShape getCorpo() const;
			virtual void atualizar() = 0;
			void setPos(const sf::Vector2f pos);
			void setTam(const sf::Vector2f tam);
			sf::Vector2f getPos();
			const sf::Vector2f getTam() const;
			const bool getRemover() const;
			virtual void desenhar();
			virtual void colisao(Entidade* outra, sf::Vector2f ds = sf::Vector2f(0.f, 0.f)) = 0;
			void setRemover(bool remover);
			virtual void atualizarPosicao() = 0;
		};
	}
}