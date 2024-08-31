#pragma once

#include "../Obstaculos/Obstaculo.h"
#include <SFML/System/Clock.hpp>

#define DANO_LAVA 0.5f
#define INTERVALO_DANOS 2.5f
#define VELOCIDADE_LAVA 0.f

namespace Jogo
{
    namespace Entidades
    {
        namespace Obstaculos
        {
            class Lava : public Obstaculo
            {
            private:
                float dano;
                float intervaloDano;
                sf::Clock relogio1, relogio2;
                Personagens::Jogadores::Jogador* jogador1;
                Personagens::Jogadores::Jogador* jogador2;
                int danosRestantes1;
                int danosRestantes2;

            public:
                Lava(const sf::Vector2f pos, const sf::Vector2f tam);
                ~Lava();
                void atualizar();
                void colisao(Entidade* outra, sf::Vector2f ds) override;
                void aplicarDanoContinuo(Personagens::Jogadores::Jogador* pJogador, sf::Clock& relogio, int& danosRestantes);
            };
        }
    }
}