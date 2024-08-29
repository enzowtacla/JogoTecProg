#include "../include/Principal.h"
using namespace sf;

Jogo::Principal::Principal() :
	pGG(pGG->getGrafico()), pEventos(pEventos->getGerenciadorEventos()), fase(nullptr), menu(nullptr), pInputs(pInputs->getGerenciadorInputs())
{
	if (!pGG) {
		std::cout << "Nao foi possivel criar o gerenciador grafico" << std::endl;
		exit(1);
	}

	if (!pEventos) {
		std::cout << "Nao foi possivel criar o gerenciador de eventos" << std::endl;
		exit(1);
	}
	srand(time(NULL));

	inicializar();
}

Jogo::Principal::~Principal()
{
	if (fase) {
		delete(fase);
		fase = nullptr;
	}
}

void Jogo::Principal::inicializar()
{
	criarFase();
	criarMenu();
	Executar();
}

void Jogo::Principal::criarFase() 
{

    Fases::Fase1* aux = new Fases::Fase1();
    //Fases::Fase2* aux = new Fases::Fase2();
    if (!aux) {
        std::cout << "Nao foi possivel criar a fase na Principal" << std::endl;
        exit(1);
    }
    fase = static_cast<Fases::Fase*>(aux);

    fase->criarMapa("./Niveis/fase1_mapa.txt");

}


void Jogo::Principal::criarMenu()
{
	menu = new Menus::Menu();
	if(menu){
		Observadores::ObservadorMenu* obsMenu = new Observadores::ObservadorMenu(menu);
		pInputs->incluir(static_cast<Observadores::ObservadorMenu*>(obsMenu));
	}	
}

void Jogo::Principal::Executar()
{
	while (pGG->verificaJanelaAberta()) {
		
		pEventos->executar();

		pGG->limpaJanela();

		if(!menu->getCriarFase()){
			menu->desenhar();
		}
		else {
			fase->executar();
		}
		
		pGG->mostraElementos();
	}

}

