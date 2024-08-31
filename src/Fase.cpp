#include "../include/Fases/Fase.h"
#include "../include/Entidades/Personagens/Inimigos/Cogumelo.h"
#include "../include/Entidades/Personagens/Inimigos/Perseguidor.h"
#include "../include/Entidades/Obstaculos/Plataforma.h"
#include "../include/Entidades/Obstaculos/Slime.h"
#include "../include/Entidades/Obstaculos/Espinho.h"
#include "../include/Entidades/Obstaculos/Lava.h"

using namespace Jogo;
using namespace Fases;
using namespace Entidades;
using namespace Personagens;
using namespace Inimigos;
using namespace Jogadores;
using namespace Obstaculos;

int Fase::qtdCogu(0);
int Fase::qtdEsp(0);


Fase::Fase(const IDs::ID id) :Ente(id), listaObstaculos(), listaInimigos(), listaJogadores(), colisor(&listaJogadores, &listaInimigos, &listaObstaculos), pInputs(pInputs->getGerenciadorInputs()), fundo(Vector2f(1280.f, 720.f),pGG->carregarTextura("./Assets/Fundo1.jpg")), numCogu(rand()%3 + 3), numEsp(rand()%3 + 3)
{

}

Fase::~Fase()
{
	listaInimigos.limparLista();
	listaObstaculos.limparLista();
	listaJogadores.limparLista();
}

void Fase::criarCogumelo(const sf::Vector2f pos)
{
	if(qtdCogu < numCogu)
	{
		Cogumelo* cogumelo = new Entidades::Personagens::Inimigos::Cogumelo(pos, sf::Vector2f(50.f, 50.f));

		if (!cogumelo){
			std::cout << "Nao foi possivel criar o inimigo" << std::endl;
		}

		listaInimigos.addEntidade(static_cast<Entidades::Entidade*>(cogumelo));
		qtdCogu++;
	}
	else{
		if(rand()%100 < 25)
		{
			Cogumelo* cogumelo = new Entidades::Personagens::Inimigos::Cogumelo(pos, sf::Vector2f(50.f, 50.f));

			if (!cogumelo){
				std::cout << "Nao foi possivel criar o inimigo" << std::endl;
			}

			listaInimigos.addEntidade(static_cast<Entidades::Entidade*>(cogumelo));
			qtdCogu++;
		}
	}

}

void Fase::criarPerseguidor(const sf::Vector2f pos)
{
	Perseguidor* perseguidor = new Entidades::Personagens::Inimigos::Perseguidor(pos, sf::Vector2f(50.f, 50.f));

	if (!perseguidor) {
		std::cout << "Nao foi possivel criar o inimigo" << std::endl;
	}

	listaInimigos.addEntidade(static_cast<Entidades::Entidade*>(perseguidor));

}

void Fase::criarPlataforma(const sf::Vector2f pos)
{
	Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(pos, Vector2f(350.0f, 50.0f));


	if (!plataforma) {
		std::cout << "Nao foi possivel criar a plataforma" << std::endl;
	}

	listaObstaculos.addEntidade(static_cast<Entidades::Entidade*>(plataforma));
}

void Fase::criarSlime(const sf::Vector2f pos)
{
	Entidades::Obstaculos::Slime* slime = new Entidades::Obstaculos::Slime(pos, Vector2f(100.0f, 35.0f));


	if (!slime) {
		std::cout << "Nao foi possivel criar o slime" << std::endl;
	}

	listaObstaculos.addEntidade(static_cast<Entidades::Entidade*>(slime));
}

void Fase::criarEspinho(const sf::Vector2f pos)
{
	if(qtdEsp < numEsp)
	{
		Entidades::Obstaculos::Espinho* espinho = new Entidades::Obstaculos::Espinho(pos, Vector2f(80.0f, 50.0f));


		if (!espinho) {
			std::cout << "Nao foi possivel criar o slime" << std::endl;
		}

		listaObstaculos.addEntidade(static_cast<Entidades::Entidade*>(espinho));
		qtdEsp++;
	}
	else{
		if(rand()%100 < 25)
		{
			Entidades::Obstaculos::Espinho* espinho = new Entidades::Obstaculos::Espinho(pos, Vector2f(80.0f, 50.0f));


			if (!espinho) {
				std::cout << "Nao foi possivel criar o slime" << std::endl;
			}

			listaObstaculos.addEntidade(static_cast<Entidades::Entidade*>(espinho));
			qtdEsp++;
		}
	}
}

void Fase::criarLava(const sf::Vector2f pos)
{
	Entidades::Obstaculos::Lava* lava1 = new Entidades::Obstaculos::Lava(pos, Vector2f(110.0f, 25.0f));


	if (!lava1) {
		std::cout << "Nao foi possivel criar a lava" << std::endl;
	}

	listaObstaculos.addEntidade(static_cast<Entidades::Entidade*>(lava1));
}

void Fase::criarEntidade(char letra, const sf::Vector2i pos)
{
	switch (letra)
	{
		case('a'):
		{
			criarCogumelo(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
		}
		break;

		case('p'):
		{
			criarPerseguidor(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
		}
		break;

		case('o'):
		{
			criarPlataforma(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
		}
		break;

		case('j'):
		{
			criarJogador(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
		}
		break;

		case('s'):
		{
			criarSlime(sf::Vector2f(pos.x * 50.0f, pos.y * 49.0f));
		}
		break;

		case('e'):
		{
			criarEspinho(sf::Vector2f(pos.x * 50.0f, pos.y * 49.0f));
		}
		break;

		case('L'):
		{
			criarLava(sf::Vector2f(pos.x * 50.0f, pos.y * 49.0f));
		}
		break;
	}

}

void Fase::desenhar()
{
	if(listaJogadores.getTam() == 0)
	{
		pGG->fecharJanela();
	}
	fundo.desenhar();
	listaJogadores.executar();
	listaInimigos.executar();
	listaObstaculos.executar();

}

void Fase::executar()
{
	desenhar();
	colisor.executar();
	pGG->resetarRelogio();
}

int Fase::getNumInimigos()
{
	//std::cout << " " << listaInimigos.getTam() << std::endl;
	return ((int)listaInimigos.getTam());
}