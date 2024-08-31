#include "../include/Entidades/Personagens/Inimigos/Chefao.h"

using namespace Jogo;
using namespace Entidades;
using namespace Personagens;
using namespace Inimigos;

Entidades::Personagens::Jogadores::Jogador *Chefao::pJogador = nullptr;
Entidades::Personagens::Jogadores::Jogador *Chefao::pJogador2 = nullptr;

Chefao::Chefao (const Vector2f pos, const Vector2f tam) : Inimigo(pos, tam, IDs::ID::chefao), forcaAtaque(DANAR), delayAtaque(2.0f), tempoUltimoAtaque(0.0f)
{
    corpo.setFillColor(Color::Yellow);
    //void inicializa();
}

Chefao::~Chefao()
{
    for (auto projetil : projeteis) {
        delete projetil;
    }
    projeteis.clear();
}

void Chefao::setJogador(Entidades::Personagens::Jogadores::Jogador *j)
{
	pJogador = j;
}

void Chefao::setJogador2(Entidades::Personagens::Jogadores::Jogador *j)
{
	pJogador2 = j;
}

void Chefao::atiraJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo) 
{
    auto agora = std::chrono::steady_clock::now();
    std::chrono::duration<float> duracao = agora - ultimoAtaque;
    if (duracao.count() >= delayAtaque) {
         sf::Vector2f direcao = posJogador - posInimigo;
        float magnitude = sqrt(direcao.x * direcao.x + direcao.y * direcao.y);
        direcao /= magnitude;

        Projetil* novoProjetil = new Projetil(posInimigo, sf::Vector2f(20.0f, 20.0f), direcao, 0.1f, 8.0f, 1000.0f);
        projeteis.push_back(novoProjetil);

        ultimoAtaque = agora; // Reset do tempo do último ataque
    }
}

void Chefao::moveInimigo()
{
	if (pJogador->getVivo() && pJogador2->getVivo())
    {
        sf::Vector2f posJogador1 = pJogador->getCorpo().getPosition();
        sf::Vector2f posJogador2 = pJogador2->getCorpo().getPosition();
        sf::Vector2f posInimigo = corpo.getPosition();
        float dist1 = fabs(posJogador1.x - posInimigo.x);
        float dist2 = fabs(posJogador2.x - posInimigo.x);

        if (dist1 <= ALCANCE_X && dist1 <= ALCANCE_Y &&
            (dist1 < dist2 || dist2 > ALCANCE_X || dist2 > ALCANCE_Y))
        {
            atiraJogador(posJogador1, posInimigo);
        }
        else if (dist2 <= ALCANCE_X && dist2 <= ALCANCE_Y)
        {
            atiraJogador(posJogador2, posInimigo);
        }
        else
        {
            atualizaMovimentoAleatorio();
        }
    }
    else if (pJogador->getVivo()) 
    {
        sf::Vector2f posJogador1 = pJogador->getCorpo().getPosition();
        sf::Vector2f posInimigo = corpo.getPosition();
        atiraJogador(posJogador1, posInimigo);
    }
    else if (pJogador2->getVivo()) 
    {
        sf::Vector2f posJogador2 = pJogador2->getCorpo().getPosition();
        sf::Vector2f posInimigo = corpo.getPosition();
        atiraJogador(posJogador2, posInimigo);
    }
    else
    {
        atualizaMovimentoAleatorio();
    }
}

void Chefao::colisao(Entidade *outra, sf::Vector2f ds)
{
	if (outra->getId() == IDs::ID::jogador)
	{
		
	}
}

void Chefao::atualizarAnimacao()
{
	if (moveAleatorio == 0)
	{
		paraEsquerda = false;
	}
	else
	{
		paraEsquerda = true;
	}
}

void Chefao::atualizaProjeteis()
{
    for (int i = 0; i < projeteis.size(); i++)
    {
        if (projeteis.at(i) && projeteis.at(i)->getAtivo())
        {
            projeteis.at(i)->atualizar();

            if (pJogador && pJogador->getCorpo().getGlobalBounds().intersects(projeteis.at(i)->getCorpo().getGlobalBounds()))
            {
                projeteis.at(i)->setAtivo(false);
                pJogador->tomarDano(projeteis.at(i)->getDano());
            }

            if (pJogador2 && pJogador2->getCorpo().getGlobalBounds().intersects(projeteis.at(i)->getCorpo().getGlobalBounds()))
            {
                projeteis.at(i)->setAtivo(false);
                pJogador2->tomarDano(projeteis.at(i)->getDano());
            }
        }
    }
}


void Chefao::atualizar()
{
    if(getVida() <= 0.f){
		poderemover = true;
	}
	moveInimigo();
    atualizaProjeteis();
	atualizarPosicao();

	tempoMover += pGG->getTempo();
}

void Chefao::desenhar()
{
    pGG->desenhaElementos(corpo);
    for (int i = 0; i < projeteis.size(); i++)
    {   
        if(projeteis[i]->getAtivo())
            projeteis[i]->desenhar();
    }
}

std::vector<Entidades::Projetil*>* Chefao::getListaProjetil()
{
    return &projeteis;
}