#pragma once
#include "../include/Menus/Menu.h"
#include "../include/Fases/Fase1.h"
#include "../include/Fases/Fase2.h"
#include "../include/Gerenciadores/GerenciadorGrafico.h"
#include "../include/Gerenciadores/GerenciadorEventos.h"
#include "../include/Gerenciadores/GerenciadorInputs.h"
#include "../include/Observadores/ObservadorMenu.h"


namespace Jogo {

	class Principal
	{
	private:
		Gerenciadores::GerenciadorGrafico* pGG;
		Gerenciadores::GerenciadorEventos* pEventos;
		Gerenciadores::GerenciadorInputs* pInputs;
		
		Fases::Fase* fase1;
		Fases::Fase* fase2;
		Menus::Menu* menu;
		int numInimigos;

		void inicializar();
		void criarFase1();
		void criarFase2();
		void criarMenu();
	public:
		Principal();
		~Principal();
		void Executar();
	};
}