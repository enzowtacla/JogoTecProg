#include "../include/Entidades/Personagens/Inimigos/Perseguidor.h"

using namespace Jogo;
using namespace Entidades;
using namespace Personagens;
using namespace Inimigos;

Entidades::Personagens::Jogadores::Jogador *Perseguidor::pJogador = nullptr;
Entidades::Personagens::Jogadores::Jogador *Perseguidor::pJogador2 = nullptr;

Perseguidor::Perseguidor(const Vector2f pos, const Vector2f tam) : Inimigo(pos, tam, IDs::ID::perseguidor), forcaCabecada(CABECADA), forcaEmpurrao(EMPURRAO), perseguindo(false)
{
	textura = pGG->carregarTextura("./Assets/perseguidor.png");
    corpo.setTexture(&textura);
    //corpo.setOrigin(tam.x, 0);
    //corpo.setFillColor(Color::Magenta);
	
}

Perseguidor::~Perseguidor()
{
}

void Perseguidor::inicializa()
{

}

void Perseguidor::setJogador(Entidades::Personagens::Jogadores::Jogador *j)
{
	pJogador = j;
}

void Perseguidor::setJogador2(Entidades::Personagens::Jogadores::Jogador *j)
{
	pJogador2 = j;
}

void Perseguidor::persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo)
{
    perseguindo = true;
	if (posJogador.x - posInimigo.x > 0.f)
	{
		paraEsquerda = false;
		andar(paraEsquerda);
	}
	else
	{
		paraEsquerda = true;
		andar(paraEsquerda);
        //corpo.setScale(-1.f,1.f);
	}
}


void Perseguidor::moveInimigo()
{
    sf::Vector2f posInimigo = corpo.getPosition();
    bool jogador1NoAlcance = false;
    bool jogador2NoAlcance = false;
    sf::Vector2f posJogador1;
    sf::Vector2f posJogador2;

    if (pJogador->getVivo()) 
    {
        posJogador1 = pJogador->getCorpo().getPosition();
        float dist1_x = fabs(posJogador1.x - posInimigo.x);
        float dist1_y = fabs(posJogador1.y - posInimigo.y);

        if (dist1_x <= ALCANCE_X && dist1_y <= ALCANCE_Y)
        {
            jogador1NoAlcance = true;
        }
    }

    if (pJogador2->getVivo()) 
    {
        posJogador2 = pJogador2->getCorpo().getPosition();
        float dist2_x = fabs(posJogador2.x - posInimigo.x);
        float dist2_y = fabs(posJogador2.y - posInimigo.y);

        if (dist2_x <= ALCANCE_X && dist2_y <= ALCANCE_Y)
        {
            jogador2NoAlcance = true;
        }
    }

    if (jogador1NoAlcance && jogador2NoAlcance)
    {
        // Se ambos estão no alcance, persegue o mais próximo
        if (fabs(posJogador1.x - posInimigo.x) < fabs(posJogador2.x - posInimigo.x))
        {
            persegueJogador(posJogador1, posInimigo);
        }
        else
        {
            persegueJogador(posJogador2, posInimigo);
        }
    }
    else if (jogador1NoAlcance) 
    {
        persegueJogador(posJogador1, posInimigo);
    }
    else if (jogador2NoAlcance) 
    {
        persegueJogador(posJogador2, posInimigo);
    }
    else
    {
        perseguindo = false;
        atualizaMovimentoAleatorio();
    }
}


void Perseguidor::colisao(Entidade *outra, sf::Vector2f ds)
{
	if (outra->getId() == IDs::ID::jogador)
	{
		cabeciar(static_cast<Personagens::Personagem *>(outra));
	}
}

void Perseguidor::cabeciar (Personagem* pPersonagem)
{
	if(pPersonagem){
		Personagens::Jogadores::Jogador* pJogador = static_cast<Personagens::Jogadores::Jogador*>(pPersonagem);
		pJogador->knockBack(forcaEmpurrao);
		pJogador->tomarDano(forcaCabecada);
	}
}