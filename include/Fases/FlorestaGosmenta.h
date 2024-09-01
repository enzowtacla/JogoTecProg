#pragma once
#include "Fase.h"


namespace Jogo
{
	namespace Fases
	{
		class FlorestaGosmenta :public Fase
		{
		private:
			static int qtdePers;
			static int qtdeSlimes;
			const int numPers;
			const int numSlimes;
			
		public:
			FlorestaGosmenta();
			~FlorestaGosmenta();
			void criarMapa(const std::string& arquivoTxt);
			void criarJogador(const sf::Vector2f pos);
			void criarSlime(const sf::Vector2f pos);
			void criarPerseguidor(const sf::Vector2f pos);
		};
	}
}