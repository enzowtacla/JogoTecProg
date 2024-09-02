#include "../include/Entidades/Personagens/Jogadores/Jogador.h"

using namespace Jogo;
using namespace Entidades;
using namespace Personagens;
using namespace Jogadores;

int Jogador::cont_j(0);
unsigned int Jogador::pontuacao(0);

Jogador::Jogador(const Vector2f pos, const Vector2f tam) : Personagem(pos, tam, VELOCIDADE_JOGADOR_X, IDs::ID::jogador), noChao(false), num_jogador(cont_j++)
{
    corpo.setFillColor(Color::Cyan);
    corpo.setPosition(pos);
    inicializa();
}

Jogador::~Jogador()
{
}

void Jogador::inicializa()
{
    // Inicialização de animações e outros recursos
}

const RectangleShape Jogador::getCorpo()
{
    return corpo;
}

void Jogador::atualizar()
{
    if (vida <= 0.f)
    {
        poderemover = true;
    }
    atualizarPosicao();
}

void Jogador::desenhar()
{
    pGG->desenhaElementos(corpo);
}

void Jogador::atualizarAnimacao()
{
    if (andando)
    {
        animacao.atualizar(paraEsquerda, "ANDA");
    }
    else if (!andando)
    {
        animacao.atualizar(paraEsquerda, "PARADO");
    }
}

void Jogador::podePular()
{
    noChao = true;
}

void Jogador::pular()
{
    if (noChao)
    {
        velFinal.y = -sqrt(2.f * GRAVIDADE * TAMANHO_PULO);
        noChao = false;
    }
}

const bool Jogador::getAndando() const
{
    return andando;
}

const int Jogador::getNum() const
{
    return num_jogador;
}

void Jogador::colisao(Entidade *outra, sf::Vector2f ds)
{
    if (outra->getId() == IDs::ID::chefao ||
        outra->getId() == IDs::ID::cogumelo ||
        outra->getId() == IDs::ID::perseguidor)
    {
        colisaoJogador(ds, static_cast<Personagens::Personagem *>(outra));
    }
}

void Jogador::colisaoJogador(Vector2f ds, Personagens::Personagem *pPersonagem)
{
    sf::Vector2f posOutro = pPersonagem->getPos();
    sf::Vector2f tamOutro = pPersonagem->getTam();
    sf::Vector2f velFinal = pPersonagem->getVelFinal();
    if (ds.x < 0.0f && ds.y < 0.0f) { //houve colisao
        if(!(ds.x > ds.y)) {
            if(posOutro.y >- pos.y) {
                posOutro.y -= ds.y;
                pPersonagem->tomarDano(100);
            }
            velFinal.y = 0.0f;
        }
    }
    pPersonagem->setPos(posOutro);
    pPersonagem->setVelFinal(velFinal);
}

float Jogador::getVelocidadeMovimento() const
{
    return velFinal.x;
}

float Jogador::getVelocidadePulo() const
{
    return TAMANHO_PULO;
}

void Jogador::restaurarValoresOriginais()
{
    velFinal.x = VELOCIDADE_JOGADOR_X;
}

void Jogador::setVelocidadeMovimento(float velocidade)
{
    velFinal.x = velocidade;
}

void Jogador::knockBack(float dist)
{
    velFinal.y = -sqrt(2.f * GRAVIDADE * (TAMANHO_PULO / 2));

    if (dist > 75)
    {
        velFinal.x = velFinal.x * -dist;
    }
}

const bool Jogador::getVivo() const
{
    return (vida > 0.f);
}

void Jogador::aumentaPontuacao(const IDs::ID id)
{   
    switch (id)
	{
	case IDs::ID::cogumelo:
		pontuacao += 10;
		break;
	case IDs::ID::perseguidor:
		pontuacao += 20;
		break;
	case IDs::ID::chefao:
		pontuacao += 50;
		break;
	}
    std::cout << "Pontos: " << pontuacao <<std::endl;
}

unsigned int Jogador::getPontuacao()
{
    return pontuacao;
}