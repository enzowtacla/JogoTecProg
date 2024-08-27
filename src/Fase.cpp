#include "../include/Fases/Fase.h"
#include "../include/Entidades/Personagens/Inimigos/Cogumelo.h"
#include "../include/Entidades/Personagens/Inimigos/Perseguidor.h"
#include "../include/Entidades/Obstaculos/Plataforma.h"
#include "../include/Entidades/Obstaculos/Slime.h"
#include "../include/Entidades/Obstaculos/Espinho.h"

using namespace Jogo;
using namespace Fases;
using namespace Entidades;
using namespace Personagens;
using namespace Inimigos;
using namespace Jogadores;
using namespace Obstaculos;


Fase::Fase(const IDs::ID id) :Ente(id), listaObstaculos(), listaInimigos(), listaJogadores(), colisor(&listaJogadores, &listaInimigos, &listaObstaculos), pInputs(pInputs->getGerenciadorInputs()), fundo(Vector2f(800.0, 600.f),pGG->carregarTextura("./Assets/Fundo1.jpg"))//, numAleatorio(0)
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
	Cogumelo* cogumelo = new Entidades::Personagens::Inimigos::Cogumelo(pos, sf::Vector2f(34.f, 50.f));

	if (!cogumelo){
		std::cout << "Nao foi possivel criar o inimigo" << std::endl;
	}

	listaInimigos.addEntidade(static_cast<Entidades::Entidade*>(cogumelo));

}

void Fase::criarPerseguidor(const sf::Vector2f pos)
{
	Perseguidor* inimigo2 = new Entidades::Personagens::Inimigos::Perseguidor(pos, sf::Vector2f(52.f, 34.f));

	if (!inimigo2) {
		std::cout << "Nao foi possivel criar o inimigo" << std::endl;
	}

	listaInimigos.addEntidade(static_cast<Entidades::Entidade*>(inimigo2));

}

void Fase::criarObstaculo(const sf::Vector2f pos)
{
	Entidades::Obstaculos::Plataforma* plataforma1 = new Entidades::Obstaculos::Plataforma(pos, Vector2f(350.0f, 50.0f));


	if (!plataforma1) {
		std::cout << "Nao foi possivel criar a plataforma" << std::endl;
	}

	listaObstaculos.addEntidade(static_cast<Entidades::Entidade*>(plataforma1));
}

void Fase::criarSlime(const sf::Vector2f pos)
{
	Entidades::Obstaculos::Slime* slime1 = new Entidades::Obstaculos::Slime(pos, Vector2f(100.0f, 35.0f));


	if (!slime1) {
		std::cout << "Nao foi possivel criar o slime" << std::endl;
	}

	listaObstaculos.addEntidade(static_cast<Entidades::Entidade*>(slime1));
}

void Fase::criarEspinho(const sf::Vector2f pos)
{
	Entidades::Obstaculos::Espinho* espinho1 = new Entidades::Obstaculos::Espinho(pos, Vector2f(80.0f, 50.0f));


	if (!espinho1) {
		std::cout << "Nao foi possivel criar o slime" << std::endl;
	}

	listaObstaculos.addEntidade(static_cast<Entidades::Entidade*>(espinho1));
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
			criarObstaculo(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
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
	}

}

void Fase::desenhar()
{
	listaJogadores.executar();
	listaInimigos.executar();
	listaObstaculos.executar();
}

void Fase::executar()
{
	fundo.desenhar();
	desenhar();
	colisor.executar();
	pGG->resetarRelogio();
}