#pragma once

#include "../Gerenciadores/GerenciadorGrafico.h"
#include "../Gerenciadores/GerenciadorInputs.h"

namespace Jogo 
{
	namespace Gerenciadores
	{
		class GerenciadorEventos
		{
		private:
			GerenciadorGrafico* pGG;
			GerenciadorInputs* pInputs;
			RenderWindow* pJanela;

			static GerenciadorEventos* pEventos;
			GerenciadorEventos();

		public:
			~GerenciadorEventos();
			static GerenciadorEventos* getGerenciadorEventos();
			void executar();
		};
	}
}