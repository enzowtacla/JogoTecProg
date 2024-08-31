#include "../include/Entidades/Projetil.h"

using namespace Jogo;
using namespace Entidades;

Projetil::Projetil(const sf::Vector2f pos, const sf::Vector2f tam, const sf::Vector2f direcao, const float velocidade, const float dano, const float alcanceMaximo)
    : Entidade(pos, tam, IDs::ID::projetil), direcao(direcao), velocidade(0.1f), dano(8.f), distanciaPercorrida(0.f), alcanceMaximo(ALCANCE_MAX), ativo(true)
{
    corpo.setFillColor(sf::Color::Blue); 
}

Projetil::~Projetil() 
{
}

void Projetil::atualizar() {
    
    sf::Vector2f movimento = direcao * velocidade;
    setPos(getPos() + movimento);
    distanciaPercorrida += std::sqrt(movimento.x * movimento.x + movimento.y * movimento.y);

    if (distanciaPercorrida >= alcanceMaximo) 
    {
        ativo = false;
    }
}

void Projetil::desenhar() {
    pGG->desenhaElementos(corpo);
}

void Projetil::colisao(Entidade* outra, sf::Vector2f ds) 
{   
    ativo = false;

    if (outra->getId() == IDs::ID::jogador) 
    { 
        static_cast<Personagens::Personagem*>(outra);
        Personagens::Jogadores::Jogador* pJogador = static_cast<Personagens::Jogadores::Jogador*>(outra);
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