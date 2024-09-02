#include "../include/Fases/FlorestaLava.h"
#include "../Jogadores/Jogador.h"
#include "../include/Entidades/Personagens/Inimigos/Chefao.h"
#include "../include/Entidades/Obstaculos/Lava.h"

using namespace Jogo;
using namespace Fases;
using namespace Entidades;
using namespace Personagens;
using namespace Inimigos;
using namespace Jogadores;
using namespace Obstaculos;

int FlorestaLava::qtdeChefao(0);
int FlorestaLava::qtdeLavas(0);

FlorestaLava::FlorestaLava() : Fase(IDs::ID::fase2, "Assets/Fundo2.png"), numChefao(rand() % 2 + 3), numLavas(rand() % 2 + 3)
{
}

FlorestaLava::~FlorestaLava()
{
}

void FlorestaLava::criarMapa(const std::string &arquivoTxt)
{
	std::ifstream arquivo(arquivoTxt);
	std::string linha;

	if (!arquivo.is_open())
	{
		std::cout << "Nao foi possivel abrir o mapa da fase 2" << std::endl;
		exit(1);
	}
	int j = 0;
	while (std::getline(arquivo, linha))
	{
		for (int i = 0; i < linha.size(); i++)
		{
			if (linha[i] != ' ')
			{
				criarEntidade(linha[i], sf::Vector2i(i, j));
			}
		}
		j++;
	}
	arquivo.close();
}

void FlorestaLava::criarJogador(const sf::Vector2f pos)
{
	Entidades::Personagens::Jogadores::Jogador *jogador = new Entidades::Personagens::Jogadores::Jogador(pos, Vector2f(50.f, 50.f));

	if (jogador->getNum() == 2)
	{
		if (!jogador)
		{
			std::cout << "Nao foi possivel criar o jogador 1" << std::endl;
		}

		listaJogadores.addEntidade(static_cast<Entidades::Entidade *>(jogador));

		Observadores::ObservadorJogador *obsJ1 = new Observadores::ObservadorJogador(jogador);
		pInputs->incluir(static_cast<Observadores::Observador *>(obsJ1));
		Chefao::setJogador(jogador);
	}
	else
	{
		if (!jogador)
		{
			std::cout << "Nao foi possivel criar o jogador 1" << std::endl;
		}

		listaJogadores.addEntidade(static_cast<Entidades::Entidade *>(jogador));

		Observadores::ObservadorJogador *obsJ2 = new Observadores::ObservadorJogador(jogador);
		obsJ2->setTeclas("Up", "Left", "Right");
		pInputs->incluir(static_cast<Observadores::Observador *>(obsJ2));
		Chefao::setJogador2(jogador);
	}
}

void FlorestaLava::criarChefao(const sf::Vector2f pos)
{
	if (qtdeChefao < numChefao)
	{
		Chefao *chefao = new Entidades::Personagens::Inimigos::Chefao(pos, sf::Vector2f(45.f, 75.f));
		colisor.setProjetil(chefao->getListaProjetil());

		if (!chefao)
		{
			std::cout << "Nao foi possivel criar o inimigo" << std::endl;
		}

		listaInimigos.addEntidade(static_cast<Entidades::Entidade *>(chefao));
		qtdeChefao++;
	}
	else
	{
		if (rand() % 100 < 25)
		{
			Chefao *chefao = new Entidades::Personagens::Inimigos::Chefao(pos, sf::Vector2f(45.f, 75.f));
			colisor.setProjetil(chefao->getListaProjetil());

			if (!chefao)
			{
				std::cout << "Nao foi possivel criar o inimigo" << std::endl;
			}

			listaInimigos.addEntidade(static_cast<Entidades::Entidade *>(chefao));
			qtdeChefao++;
		}
	}
}

void FlorestaLava::criarLava(const sf::Vector2f pos)
{
	if (qtdeLavas < numLavas)
	{
		Lava *lava = new Entidades::Obstaculos::Lava(pos, Vector2f(50.0f, 50.0f));
		if (!lava)
		{
			std::cout << "Nao foi possivel criar a Lava" << std::endl;
		}
		listaObstaculos.addEntidade(static_cast<Entidades::Entidade *>(lava));
		qtdeLavas++;
	}
	else
	{
		if (rand() % 100 < 25)
		{
			Lava *lava = new Entidades::Obstaculos::Lava(pos, Vector2f(50.0f, 50.0f));
			if (!lava)
			{
				std::cout << "Nao foi possivel criar a Lava" << std::endl;
			}
			listaObstaculos.addEntidade(static_cast<Entidades::Entidade *>(lava));
			qtdeLavas++;
		}
	}
}