#pragma once
#include "../include/Fases/Fase1.h"
#include "../include/Fases/Fase2.h"
#include "../include/Gerenciadores/GerenciadorGrafico.h"
#include "../include/Gerenciadores/GerenciadorEventos.h"


namespace Jogo {

	class Principal
	{
	private:
		Gerenciadores::GerenciadorGrafico* pGG;
		Gerenciadores::GerenciadorEventos* pEventos;
		
		Fases::Fase* fase;

		void criarFase();
	public:
		Principal();
		~Principal();
		void Executar();
	};
}