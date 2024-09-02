#include "../include/Entidades/Projetil.h"

using namespace Jogo;
using namespace Entidades;

Projetil::Projetil(const sf::Vector2f pos, const sf::Vector2f tam, const sf::Vector2f direcao, const float velocidade, const float dano, const float alcanceMaximo)
    : Entidade(pos, tam, VELOCIDADE_GRAVIDADE, IDs::ID::projetil), direcao(direcao), velocidade(0.15f), dano(8.f), distanciaPercorrida(0.f), alcanceMaximo(ALCANCE_MAX), ativo(true)
{
    textura = pGG->carregarTextura("./Assets/projetil.png");
	corpo.setTexture(&textura);
}

Projetil::~Projetil()
{
}

void Projetil::atualizar()
{

    atualizarPosicao();
    sf::Vector2f movimento = direcao * velocidade;
    setPos(getPos() + movimento);
    distanciaPercorrida += std::sqrt(movimento.x * movimento.x + movimento.y * movimento.y);

    if (distanciaPercorrida >= alcanceMaximo)
    {
        ativo = false;
    }
}

void Projetil::desenhar()
{
    pGG->desenhaElementos(corpo);
}

void Projetil::colisao(Entidade *outra, sf::Vector2f ds)
{
    ativo = false;

    if (outra->getId() == IDs::ID::jogador)
    {
        static_cast<Personagens::Personagem *>(outra);
        Personagens::Jogadores::Jogador *pJogador = static_cast<Personagens::Jogadores::Jogador *>(outra);
        pJogador->tomarDano(dano);
    }
}

const float Projetil::getDano() const
{
    return dano;
}

const bool Projetil::getAtivo()
{
    return ativo;
}

void Projetil::setAtivo(bool ativo)
{
    this->ativo = ativo;
}

void Projetil::atualizarPosicao()
{
    dt = pGG->getTempo();

    Vector2f ds(0.f, 0.f);

    const float Vy = velFinal.y;
    velFinal.y = (velFinal.y + GRAVIDADE * dt) + (velFinal.y + EMPUXO * dt);
    ds.y = Vy * dt + ((GRAVIDADE + EMPUXO) * dt * dt) / 2.0f;

    setPos(Vector2f(pos.x + ds.x, pos.y + ds.y));
}