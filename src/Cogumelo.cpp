#include "../include/Entidades/Personagens/Inimigos/Cogumelo.h"
#include "../include/Entidades/Personagens/Jogadores/Jogador.h"

using namespace Jogo;
using namespace Entidades;
using namespace Personagens;
using namespace Inimigos;
using namespace Jogadores;

Cogumelo::Cogumelo(const Vector2f pos, const Vector2f tam) : Inimigo(pos, tam, IDs::ID::cogumelo), forçaVeneno(DANO)
{
	textura = pGG->carregarTextura("./Assets/cogumelo.png");
	corpo.setTexture(&textura);	
}

Cogumelo::~Cogumelo()
{

}

void Cogumelo::inicializa()
{
	//animacao.addAnimacao("./Assets/CogumeloAndando.png", "ANDANDO", 16, 0.12f, sf::Vector2f(1, 1));
	//corpo.setOrigin(sf::Vector2f(tam.x / 2, tam.y / 2));
	
}

void Cogumelo::moveInimigo()
{
	atualizaMovimentoAleatorio();
	//atualizarAnimacao();
}


void Cogumelo::colisao(Entidade* outra, sf::Vector2f ds)
{
	if(outra->getId() == IDs::ID::jogador)
	{
		//std::cout << "entrou na envenenar" << std::endl;
		envenenar(static_cast<Personagens::Personagem*>(outra));
	}
}

void Cogumelo::envenenar(Personagem* pPersonagem)
{
	if(pPersonagem){
		Personagens::Jogadores::Jogador* pJogador = static_cast<Personagens::Jogadores::Jogador*>(pPersonagem);
		pJogador->tomarDano(forçaVeneno);
	}
}