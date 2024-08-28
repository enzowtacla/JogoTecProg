#pragma once

#include "Obstaculo.h"  

#define DANO_ESPINHO_PADRAO 0.15f
#define IMPULSO 150.0f
#define CAMINHO_TEXTURA_ESPINHO ""

namespace Jogo
{

    namespace Entidades
    {

        namespace Obstaculos
        {

            class Espinho : public Obstaculo {
            private:
                float dano;
                float impulso;
                //void inicializarAnimacao();

            public:
                Espinho(const sf::Vector2f pos, const sf::Vector2f tam);
                ~Espinho();
                void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
                void espetar(Personagens::Personagem* pPersonagem);
                //const std::string salvar();
            };
        }
    }
}