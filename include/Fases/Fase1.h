#pragma once
#include "Fase.h"


namespace Jogo
{
	namespace Fases
	{
		class Fase1 :public Fase
		{
		private:
			static int qtdePers;
			static int qtdeSlimes;
			const int numPers;
			const int numSlimes;
		public:
			Fase1();
			~Fase1();
			void criarMapa(const std::string& arquivoTxt);
			void criarPerseguidor(const sf::Vector2f pos);
			void criarJogador(const sf::Vector2f pos);
			void criarSlime(const sf::Vector2f pos);
			void criarChefao(const sf::Vector2f pos);
			//void criarLava(const sf::Vector2f pos);
		};
	}
}