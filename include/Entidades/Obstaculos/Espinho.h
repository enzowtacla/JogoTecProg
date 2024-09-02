#pragma once

#include "Obstaculo.h"  

#define DANO_ESPINHO_PADRAO 10.0f
#define ESPINHO_ESPETAR 150.0f
#define CAMINHO_TEXTURA_ESPINHO ""
#define VELOCIDADE_ESPINHO 0.f

namespace Jogo
{

    namespace Entidades
    {

        namespace Obstaculos
        {

            class Espinho : public Obstaculo {
            private:
                float dano;
                float empurrar;
                //Texture textura;
                //void inicializarAnimacao();

            public:
                Espinho(const sf::Vector2f pos, const sf::Vector2f tam);
                ~Espinho();
                void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
                void espetar(Personagens::Personagem* pPersonagem);
                void atualizar();
                //void atualizarPosicao();
                //const std::string salvar();
            };
        }
    }
}