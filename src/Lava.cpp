#include "../include/Entidades/Obstaculos/Lava.h"
#include "../include/Entidades/Personagens/Jogadores/Jogador.h"
#include <iostream>

using namespace Jogo;
using namespace Entidades;
using namespace Obstaculos;
using namespace sf;

Lava::Lava(const sf::Vector2f pos, const sf::Vector2f tam)
    : Obstaculo(pos, tam, VELOCIDADE_LAVA,IDs::ID::lava), dano(DANO_LAVA), intervaloDano(INTERVALO_DANOS),
      jogador1(nullptr), jogador2(nullptr), danosRestantes1(0), danosRestantes2(0)
{
    textura = pGG->carregarTextura("./Assets/lava.png");
	corpo.setTexture(&textura);;
}

Lava::~Lava()
{
}

void Lava::atualizar()
{
    atualizarPosicao();
    if (jogador1)
    {
        aplicarDanoContinuo(jogador1, relogio1, danosRestantes1);
    }

    if (jogador2)
    {
        aplicarDanoContinuo(jogador2, relogio2, danosRestantes2);
    }
}

void Lava::colisao(Entidade* outra, sf::Vector2f ds)
{
    if (outra->getId() == IDs::ID::jogador)
    {
        Personagens::Jogadores::Jogador* jogador = static_cast<Personagens::Jogadores::Jogador*>(outra);

        if (jogador == jogador1 || jogador == jogador2)
        {
            aplicarDanoContinuo(jogador, jogador == jogador1 ? relogio1 : relogio2, jogador == jogador1 ? danosRestantes1 : danosRestantes2);
        }
        else if (!jogador1)
        {
            //std::cout << "Aplicando dano da lava." << std::endl;
            jogador1 = jogador;
            danosRestantes1 = 2;
            jogador1->tomarDano(dano);
            relogio1.restart();
        }
        else if (!jogador2)
        {
            jogador2 = jogador;
            danosRestantes2 = 2;
            jogador2->tomarDano(dano);
            relogio2.restart();
        }
    }
    else
    {
        if (outra == jogador1)
        {
            jogador1 = nullptr;
            relogio1.restart();
        }
        else if (outra == jogador2)
        {
            jogador2 = nullptr;
            relogio2.restart();
        }
    }
}

void Lava::aplicarDanoContinuo(Personagens::Jogadores::Jogador* pJogador, sf::Clock& relogio, int& danosRestantes)
{
    if (pJogador && danosRestantes > 0)
    {
        if (relogio.getElapsedTime().asSeconds() >= intervaloDano)
        {
            //std::cout << "Aplicando dano da lava CONTINUA." << std::endl;
            pJogador->tomarDano(dano);
            danosRestantes--;
            relogio.restart();

            // Se não houver mais danos restantes, resetar o ponteiro do jogador
            if (danosRestantes <= 0)
            {
                if (pJogador == jogador1)
                    jogador1 = nullptr;
                else if (pJogador == jogador2)
                    jogador2 = nullptr;
            }
        }
    }
}