#include "../include/Fases/Fase2.h"

using namespace Jogo;
using namespace Fases;
using namespace Entidades;
using namespace Personagens;
using namespace Jogadores;


Fase2::Fase2() : Fase(IDs::ID::fase2)
{

}

Fase2::~Fase2()
{

}

void Fase2::criarMapa(const std::string& arquivoTxt)
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
			if (linha[i] != ' ') {
				criarEntidade(linha[i], sf::Vector2i(i, j));
			}
		}
		j++;
	}
	arquivo.close();
}

void Fase2::criarJogador(const sf::Vector2f pos)
{
	Entidades::Personagens::Jogadores::Jogador* jogador = new Entidades::Personagens::Jogadores::Jogador(pos, Vector2f(50.f, 50.f));

	if(jogador->getNum() == 0)
	{
		if (!jogador) {
			std::cout << "Nao foi possivel criar o jogador 1" << std::endl;
		}

		listaJogadores.addEntidade(static_cast<Entidades::Entidade*>(jogador));

		pEventos->setJogador(jogador);
	}
	else
	{
		if (!jogador) {
			std::cout << "Nao foi possivel criar o jogador 1" << std::endl;
		}

		listaJogadores.addEntidade(static_cast<Entidades::Entidade*>(jogador));

		pEventos->setJogador2(jogador);
	}
}