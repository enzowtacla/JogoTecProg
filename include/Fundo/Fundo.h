#pragma once
#include "../Ente.h"

using namespace sf;

namespace Jogo
{
	namespace Fundos
	{
		class Fundo :public Ente
		{
		private:
			const Vector2f tamJanela;
			IntRect dimensao;
			Texture textura;
			RectangleShape fundo;

		public:
			Fundo(const Vector2f tamJanela, Texture textura);
			~Fundo();
			void desenhar();
		};
	}

}