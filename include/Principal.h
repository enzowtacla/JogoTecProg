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
		
		Fases::Fase* fase;
		Menus::Menu* menu;

		void inicializar();
		void criarFase();
		void criarMenu();
	public:
		Principal();
		~Principal();
		void Executar();
	};
}