#include "../include/Entidades/Personagens/Inimigos/Cogumelo.h"
#include "../include/Entidades/Personagens/Jogadores/Jogador.h"

using namespace Jogo;
using namespace Entidades;
using namespace Personagens;
using namespace Inimigos;
using namespace Jogadores;

Cogumelo::Cogumelo(const Vector2f pos, const Vector2f tam) : Inimigo(pos, tam, IDs::ID::cogumelo), forçaVeneno(DANO)
{

	corpo.setFillColor(Color::Red);

	inicializa();
}

Cogumelo::~Cogumelo()
{

}

void Cogumelo::inicializa()
{
	/*animacao.addAnimacao("./Assets/CogumeloAndando.png", "ANDANDO", 16, 0.12f, sf::Vector2f(2, 2));
	corpo.setOrigin(sf::Vector2f(tam.x / 2.5f, tam.y / 2.0f));*/
	
}

void Cogumelo::moveInimigo()
{
	atualizaMovimentoAleatorio();
}

void Cogumelo::atualizarAnimacao()
{
	
	if (moveAleatorio == 0) {
		paraEsquerda = false;
		animacao.atualizar(paraEsquerda, "ANDANDO");
	}
	else
	{
		paraEsquerda = true;
		animacao.atualizar(paraEsquerda, "ANDANDO");
	}
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