//Código inpirado no do monitor Giovane
#pragma once

#include <SFML/Graphics.hpp>
#include "../Listas/ListaEntidade.h"
#include <cmath>
#include <vector>
#include "Entidades/Projetil.h"

namespace Jogo
{
	namespace Gerenciadores
	{
		class GerenciadorColisao
		{
		private:
			Listas::ListaEntidade* listaJogadores;
			Listas::ListaEntidade* listaInimigos;
			Listas::ListaEntidade* listaObstaculos;
			std::vector<std::vector<Entidades::Projetil*> *> ListaProjeteis;

		public:
			GerenciadorColisao(Listas::ListaEntidade* lJ, Listas::ListaEntidade* lI, Listas::ListaEntidade* lO, std::vector<Entidades::Projetil*> *lP = 0);
			~GerenciadorColisao();
			const sf::Vector2f calculaColisao(Entidades::Entidade* ent1, Entidades::Entidade* ent2);
			void executar();
			void setProjetil(std::vector<Entidades::Projetil*> *lP);
		};
	}
}