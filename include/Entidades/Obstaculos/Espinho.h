#pragma once

#include "Obstaculo.h"  

#define DANO_ESPINHO_PADRAO 0.10f
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
                //void inicializarAnimacao();

            public:
                Espinho(const sf::Vector2f pos, const sf::Vector2f tam);
                ~Espinho();
                void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
                void espetar(Personagens::Personagem* pPersonagem);
                void atualizar();
                //const std::string salvar();
            };
        }
    }
}