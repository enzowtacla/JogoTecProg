//Código inpirado no do monitor Burda
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

			static GerenciadorEventos* pEventos;
			GerenciadorEventos();

		public:
			~GerenciadorEventos();
			static GerenciadorEventos* getGerenciadorEventos();
			void executar();
		};
	}
}