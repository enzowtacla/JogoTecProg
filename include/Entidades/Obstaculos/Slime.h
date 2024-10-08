#pragma once

#include "../Obstaculos/Obstaculo.h"
#define VELOCIDADE_SLIME 0.f

namespace Jogo
{
    namespace Entidades
    {
        namespace Obstaculos
        {
            class Slime : public Obstaculo
            {
            private:
                float pegajosidadeMovimento;

            public:
                Slime(const Vector2f pos, const Vector2f tam);
                ~Slime();
                void atualizar();
                void colisao(Entidade* outra, sf::Vector2f ds) override;
                void atrapalhar(Personagens::Jogadores::Jogador* pJogador);
                //void atualizarPosicao();
                //void Save(std::ofstream& savefile);
                //void Load(std::ifstream& savefile);
            };
        }
    }
}
