#pragma once
#include "Fase.h"


namespace Jogo
{
	namespace Fases
	{
		class Fase2 :public Fase
		{
		private:
			//static int qtdLava;
			//const int numLava;
		public:
			Fase2();
			~Fase2();
			void criarMapa(const std::string& arquivoTxt);
			void criarJogador(const sf::Vector2f pos);
			//void criarLava(const sf::Vector2f pos);
			//void criarChefao(const sf::Vector2f pos);
		};
	}
}
