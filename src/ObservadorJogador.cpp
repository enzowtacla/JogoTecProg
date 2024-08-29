#include "Observadores/ObservadorJogador.h"
#include "Entidades/Personagens/Jogadores/Jogador.h"

using namespace Jogo;
using namespace Observadores;

ObservadorJogador::ObservadorJogador(Entidades::Personagens::Jogadores::Jogador* pJogador) : Observador(),
pJogador(pJogador), pular("W"), esquerda("A"), direita("D"), atacar("S")
{

}

ObservadorJogador::~ObservadorJogador()
{
    pJogador = nullptr;
}



void ObservadorJogador::notificarPressionada(std::string tecla)
{
    if(tecla == esquerda){
        pJogador->andar(true);
    }
    else if(tecla == direita){
        pJogador->andar(false);
    }
    else if(tecla == pular){
        pJogador->pular();
    }

}

void ObservadorJogador::notificarSolta(std::string tecla)
{
	if (tecla == esquerda || tecla == direita)
	{
		pJogador->parar();
	}
}

void ObservadorJogador::setTeclas(std::string pulo, std::string esquerda, std::string direita, std::string atacar)
{
    this->pular = pulo;
    this->esquerda = esquerda;
    this->direita = direita;
    this->atacar = atacar;
}
