#include "../include/Entidades/Personagens/Jogadores/Jogador.h"

using namespace Jogo;
using namespace Entidades;
using namespace Personagens;
using namespace Jogadores;

int Jogador::cont_j(0);

Jogador::Jogador(const Vector2f pos, const Vector2f tam) :
    Personagem(pos, tam, VELOCIDADE_JOGADOR_X, IDs::ID::jogador), noChao(false), num_jogador(cont_j++)
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
    if (andando) {
        animacao.atualizar(paraEsquerda, "ANDA");
    }
    else if (!andando) {
        animacao.atualizar(paraEsquerda, "PARADO");
    }
}

void Jogador::podePular()
{
    noChao = true;
}

void Jogador::pular()
{
    if (noChao) {
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

void Jogador::tomarDano(float dano)
{
    vida -= dano;
    std::cout << "Jogador: " << getNum() << " tomou dano" << std::endl;
}

void Jogador::colisao(Entidade* outra, sf::Vector2f ds)
{
    // Lógica de colisão aqui
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
	velFinal.x = velFinal.x * -dist;
}

const bool Jogador::getVivo() const
{
    return (vida > 0.f);
}
