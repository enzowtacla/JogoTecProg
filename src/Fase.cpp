#include "../include/Fases/Fase.h"
#include "../include/Entidades/Personagens/Inimigos/Cogumelo.h"
#include "../include/Entidades/Personagens/Inimigos/Perseguidor.h"
#include "../include/Entidades/Personagens/Inimigos/Chefao.h"
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

Fase::Fase(const IDs::ID id, const char* caminhoTextura) : Ente(id), listaObstaculos(), listaInimigos(), listaJogadores(), colisor(&listaJogadores, &listaInimigos, &listaObstaculos), pInputs(pInputs->getGerenciadorInputs()), fundo(Vector2f(1280.f, 720.f), caminhoTextura), numCogu(rand() % 2 + 3), numEsp(rand() % 2 + 3), qtdCogu(0),
qtdEsp(0), menu(menu->getMenu()), removeu(false)
{
	std::cout << "Num espinhos: " << numEsp << std::endl;
}

Fase::~Fase()
{
	listaInimigos.limparLista();
	listaObstaculos.limparLista();
	listaJogadores.limparLista();
}

void Fase::criarCogumelo(const sf::Vector2f pos)
{
	if (qtdCogu < numCogu)
	{
		Cogumelo *cogumelo = new Entidades::Personagens::Inimigos::Cogumelo(pos, sf::Vector2f(50.f, 50.f));

		if (!cogumelo)
		{
			std::cout << "Nao foi possivel criar o inimigo" << std::endl;
		}

		listaInimigos.addEntidade(static_cast<Entidades::Entidade *>(cogumelo));
		qtdCogu++;
	}
	else
	{
		if (rand() % 100 < 25)
		{
			Cogumelo *cogumelo = new Entidades::Personagens::Inimigos::Cogumelo(pos, sf::Vector2f(50.f, 50.f));

			if (!cogumelo)
			{
				std::cout << "Nao foi possivel criar o inimigo" << std::endl;
			}

			listaInimigos.addEntidade(static_cast<Entidades::Entidade *>(cogumelo));
			qtdCogu++;
		}
	}
}

void Fase::criarPerseguidor(const sf::Vector2f pos)
{
	Perseguidor *perseguidor = new Entidades::Personagens::Inimigos::Perseguidor(pos, sf::Vector2f(50.f, 50.f));

	if (!perseguidor)
	{
		std::cout << "Nao foi possivel criar o inimigo" << std::endl;
	}

	listaInimigos.addEntidade(static_cast<Entidades::Entidade *>(perseguidor));
}

void Fase::criarChefao(const sf::Vector2f pos)
{
	Chefao *inimigo3 = new Entidades::Personagens::Inimigos::Chefao(pos, sf::Vector2f(75.f, 45.f));

	if (!inimigo3)
	{
		std::cout << "Nao foi possivel criar o inimigo" << std::endl;
	}

	listaInimigos.addEntidade(static_cast<Entidades::Entidade *>(inimigo3));
}

void Fase::criarPlataforma(const sf::Vector2f pos)
{
	Entidades::Obstaculos::Plataforma *plataforma = new Entidades::Obstaculos::Plataforma(pos, Vector2f(50.0f, 50.0f));

	if (!plataforma)
	{
		std::cout << "Nao foi possivel criar a plataforma" << std::endl;
	}

	listaObstaculos.addEntidade(static_cast<Entidades::Entidade *>(plataforma));
}

void Fase::criarSlime(const sf::Vector2f pos)
{
	Entidades::Obstaculos::Slime *slime = new Entidades::Obstaculos::Slime(pos, Vector2f(50.0f, 35.0f));

	if (!slime)
	{
		std::cout << "Nao foi possivel criar o slime" << std::endl;
	}

	listaObstaculos.addEntidade(static_cast<Entidades::Entidade *>(slime));
}

void Fase::criarEspinho(const sf::Vector2f pos)
{
	if (qtdEsp < numEsp)
	{
		Entidades::Obstaculos::Espinho *espinho = new Entidades::Obstaculos::Espinho(pos, Vector2f(50.0f, 50.0f));

		if (!espinho)
		{
			std::cout << "Nao foi possivel criar o slime" << std::endl;
		}

		listaObstaculos.addEntidade(static_cast<Entidades::Entidade *>(espinho));
		qtdEsp++;
	}
	else
	{
		if (rand() % 100 < 25)
		{
			Entidades::Obstaculos::Espinho *espinho = new Entidades::Obstaculos::Espinho(pos, Vector2f(50.0f, 50.0f));

			if (!espinho)
			{
				std::cout << "Nao foi possivel criar o slime" << std::endl;
			}

			listaObstaculos.addEntidade(static_cast<Entidades::Entidade *>(espinho));
			qtdEsp++;
		}
	}
}

void Fase::criarLava(const sf::Vector2f pos)
{
	Entidades::Obstaculos::Lava *lava1 = new Entidades::Obstaculos::Lava(pos, Vector2f(50.0f, 50.0f));

	if (!lava1)
	{
		std::cout << "Nao foi possivel criar a lava" << std::endl;
		exit(1);
	}

	listaObstaculos.addEntidade(static_cast<Entidades::Entidade *>(lava1));
}

void Fase::criarEntidade(char letra, const sf::Vector2i pos)
{
	switch (letra)
	{
	case ('c'):
	{
		criarCogumelo(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
	}
	break;

	case ('p'):
	{
		criarPerseguidor(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
	}
	break;

	case ('C'):
	{
		criarChefao(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
	}
	break;

	case ('#'):
	{
		criarPlataforma(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
	}
	break;

	case ('s'):
	{
		criarSlime(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
	}
	break;

	case ('j'):
	{
		criarJogador(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
	}
	break;

	case ('e'):
	{
		criarEspinho(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
	}
	break;

	case ('L'):
	{
		criarLava(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
	}
	break;
	}
}

void Fase::desenhar()
{
	if (listaJogadores.getTam() == 0)
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
	if(!removeu){
		removeJogador();
	}
	desenhar();
	colisor.executar();
	pGG->resetarRelogio();
}

int Fase::getNumInimigos()
{
	return ((int)listaInimigos.getTam());
}

void Fase::removeJogador()
{
	if(menu->getNumJogadores() == 1)
	{
		for(int i = 0; i < listaJogadores.getTam(); i++){
			if(i % 2 != 0){
				Jogadores::Jogador* pAux = dynamic_cast<Jogadores::Jogador*>(listaJogadores.operator[](i));
				pAux->setRemover(true);
			}
		}
	}
	removeu = true;
}