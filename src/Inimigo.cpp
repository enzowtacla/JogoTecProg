#include "../include/Entidades/Personagens/Inimigos/Inimigo.h"
#include "../include/Entidades/Personagens/Jogadores/Jogador.h"

using namespace Jogo;
using namespace Entidades;
using namespace Personagens;
using namespace Inimigos;

Inimigo::Inimigo(const Vector2f pos, const Vector2f tam, const IDs::ID id) :
	Personagem(pos, tam, VELOCIDADE_INIMIGO_X, id), tempoMover(0.0f)
{
	inicializa();
	moveAleatorio = rand() % 3;

	if (moveAleatorio == 0)
	{
		parar();
	}
	else if (moveAleatorio == 1)
	{
		andar(true);
	}
	else
	{
		andar(false);
	}
}

Inimigo::~Inimigo()
{

}

void Inimigo::inicializa()
{
	
}

void Inimigo::desenhar()
{
	pGG->desenhaElementos(corpo);
}

void Inimigo::atualizaMovimentoAleatorio()
{
	if (tempoMover > TEMPO_MOVER_ALEATORIO)
	{
		moveAleatorio = rand() % 3;
		if (moveAleatorio == 0) {
			parar();
		}
		else if (moveAleatorio == 1) {
			andar(true);
		}
		else {
			andar(false);
		}
		tempoMover = 0.0f;
	}
}

void Inimigo::moveInimigo()
{
	
}

void Inimigo::atualizar()
{
	if(getVida() <= 0.f){
		poderemover = true;
		Jogadores::Jogador::aumentaPontuacao(id);
	}
	moveInimigo();

	atualizarPosicao();

	tempoMover += pGG->getTempo();
}

void Inimigo::tomarDano(float dano) 
{
    vida -= dano;
    std::cout << "Inimigo tomou dano. Vida restante: " << vida << std::endl;

    if (vida <= 0.0f) 
	{
        poderemover = true;  // Marca o inimigo para remoção

    }
}