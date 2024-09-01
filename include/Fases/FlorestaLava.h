#pragma once
#include "Fase.h"


namespace Jogo
{
	namespace Fases
	{
		class FlorestaLava :public Fase
		{
		private:
			static int qtdeChefao;
			static int qtdeLavas;
			const int numChefao;
			const int numLavas;

		public:
			FlorestaLava();
			~FlorestaLava();
			void criarMapa(const std::string& arquivoTxt);
			void criarJogador(const sf::Vector2f pos);
			void criarLava(const sf::Vector2f pos);
			void criarChefao(const sf::Vector2f pos);
		};
	}
}
