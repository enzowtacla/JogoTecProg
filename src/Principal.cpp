#include "../include/Principal.h"
using namespace sf;
using namespace Jogo;
using namespace Fases;

Jogo::Principal::Principal() :
	pGG(pGG->getGrafico()), pEventos(pEventos->getGerenciadorEventos()), fase1(nullptr), fase2(nullptr), menu(menu->getMenu()), pInputs(pInputs->getGerenciadorInputs()), numInimigos(0)
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
	if (fase1) {
		delete(fase1);
		fase1 = nullptr;
	}

	if (fase2) {
		delete(fase2);
		fase2 = nullptr;
	}
}

void Jogo::Principal::inicializar()
{
	criarMenu();
	criarFase1();
	criarFase2();
	Executar();
}

void Jogo::Principal::criarFase1() 
{
    Fases::FlorestaGosmenta* aux = new Fases::FlorestaGosmenta();

    if (!aux) {
        std::cout << "Nao foi possivel criar a fase na Principal" << std::endl;
        exit(1);
    }
    fase1 = static_cast<Fases::Fase*>(aux);

    fase1->criarMapa("./Niveis/fase1_mapa.txt");
}

void Jogo::Principal::criarFase2()
{
    Fases::FlorestaLava* aux = new Fases::FlorestaLava();
    if (!aux) {
        std::cout << "Nao foi possivel criar a fase na Principal" << std::endl;
        exit(1);
    }
    fase2 = static_cast<Fases::Fase*>(aux);

    fase2->criarMapa("./Niveis/fase2_mapa.txt");
}


void Jogo::Principal::criarMenu()
{
	menu = menu->getMenu();
	if(menu){
		Observadores::ObservadorMenu* obsMenu = new Observadores::ObservadorMenu(menu);
		pInputs->incluir(static_cast<Observadores::ObservadorMenu*>(obsMenu));
	}	
}

void Jogo::Principal::Executar() {
    while (pGG->verificaJanelaAberta()) {
        pEventos->executar();
        pGG->limpaJanela();

        if (!menu->getCriarFase()) {
            menu->desenhar();
            pGG->resetarRelogio();
        } else {
            if (menu->getNumFase() == 1) {
                fase1->executar();
                if (fase1->getNumInimigos() == 0) {
                    // Finaliza a Fase 1 e inicia a Fase 2
                    menu->setNumFase(2); // Muda a fase atual para 2
                }
            } else if (menu->getNumFase() == 2) {
                fase2->executar();
                if (fase2->getNumInimigos() == 0) {
                    Fases::Fase::salvarPontuacao();
                    pGG->fecharJanela(); // Fecha o jogo
                }
            }
        }

        pGG->mostraElementos();
    }
}
