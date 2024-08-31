#include "../include/Fases/Fase1.h"
#include "../include/Entidades/Personagens/Inimigos/Perseguidor.h"
#include "../include/Entidades/Obstaculos/Slime.h"

using namespace Jogo;
using namespace Fases;
using namespace Entidades;
using namespace Personagens;
using namespace Inimigos;
using namespace Jogadores;
using namespace Obstaculos;

int Fase1::qtdePers(0);
int Fase1::qtdeSlimes(0);

Fase1::Fase1() : Fase(IDs::ID::fase1), numPers(rand()%3 + 3), numSlimes(rand()%3 + 3)
{
	
}

Fase1::~Fase1()
{

}

void Fase1::criarMapa(const std::string& arquivoTxt)
{
	std::ifstream arquivo(arquivoTxt);
	std::string linha;
	
	if (!arquivo.is_open())
	{
		std::cout << "Nao foi possivel abrir o mapa da fase 1" << std::endl;
		exit(1);
	}
	int j = 0;
	while (std::getline(arquivo, linha))
	{
		for (int i = 0; i < linha.size(); i++)
		{
			if (linha[i] != ' ') {
				criarEntidade(linha[i], sf::Vector2i(i, j));
			}
		}
		j++;
	}
	arquivo.close();
}

void Fase1::criarJogador(const sf::Vector2f pos)
{
	
	Entidades::Personagens::Jogadores::Jogador* jogador = new Entidades::Personagens::Jogadores::Jogador(pos, Vector2f(50.f, 50.f));

	if(jogador->getNum() == 0)
	{
		if (!jogador) {
			std::cout << "Nao foi possivel criar o jogador 1" << std::endl;
		}

		listaJogadores.addEntidade(static_cast<Entidades::Entidade*>(jogador));

		Observadores::ObservadorJogador* obsJ1 = new Observadores::ObservadorJogador(jogador);
		//obsJ1->setTeclas("W", "A", "D", "S");
		pInputs->incluir(static_cast<Observadores::Observador*>(obsJ1));
		Perseguidor::setJogador(jogador);
	}
	else
	{
		if (!jogador) {
			std::cout << "Nao foi possivel criar o jogador 1" << std::endl;
		}

		listaJogadores.addEntidade(static_cast<Entidades::Entidade*>(jogador));

		Observadores::ObservadorJogador* obsJ2 = new Observadores::ObservadorJogador(jogador);
		obsJ2->setTeclas("Up", "Left", "Right", "Down");
		pInputs->incluir(static_cast<Observadores::Observador*>(obsJ2));
		Perseguidor::setJogador2(jogador);
	}
}

void Fase1::criarSlime(const sf::Vector2f pos)
{
	if(qtdeSlimes < numSlimes)
	{
		Entidades::Obstaculos::Slime* slime = new Entidades::Obstaculos::Slime(pos, Vector2f(100.0f, 35.0f));


		if (!slime) {
			std::cout << "Nao foi possivel criar o slime" << std::endl;
		}

		listaObstaculos.addEntidade(static_cast<Entidades::Entidade*>(slime));
		qtdeSlimes++;
	}
	else{
		if(rand()%100 < 25){
			Entidades::Obstaculos::Slime* slime = new Entidades::Obstaculos::Slime(pos, Vector2f(100.0f, 35.0f));

			if (!slime) {
				std::cout << "Nao foi possivel criar o inimigo" << std::endl;
			}

			listaObstaculos.addEntidade(static_cast<Entidades::Entidade*>(slime));
			qtdeSlimes++;
		}
	}
}

void Fase1::criarPerseguidor(const sf::Vector2f pos)
{
	if(qtdePers < numPers)
	{
		Perseguidor* perseguidor = new Entidades::Personagens::Inimigos::Perseguidor(pos, sf::Vector2f(52.f, 34.f));

		if (!perseguidor) {
			std::cout << "Nao foi possivel criar o inimigo" << std::endl;
		}

		listaInimigos.addEntidade(static_cast<Entidades::Entidade*>(perseguidor));
		qtdePers++;
	}
	else 
	{
		if(rand()%100 < 25){
			Perseguidor* perseguidor = new Entidades::Personagens::Inimigos::Perseguidor(pos, sf::Vector2f(52.f, 34.f));

			if (!perseguidor) {
				std::cout << "Nao foi possivel criar o inimigo" << std::endl;
			}

			listaInimigos.addEntidade(static_cast<Entidades::Entidade*>(perseguidor));
			qtdePers++;
		}
	}
}
