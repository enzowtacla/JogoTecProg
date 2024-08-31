#pragma once

#include "../Entidade.h"
#include "../include/Entidades/Personagens/Personagem.h"
#include "../include/Entidades/Personagens/Jogadores/Jogador.h"

#define ALCANCE_MAX 1000.0f

namespace Jogo {
    namespace Entidades {
        class Projetil : public Entidade {
        private:
            sf::Vector2f direcao;
            float velocidade;
            float dano;
            float distanciaPercorrida;
            float alcanceMaximo;
            bool ativo;

        public:
            Projetil(const sf::Vector2f pos, const sf::Vector2f tam, const sf::Vector2f direcao, const float velocidade, const float dano, const float alcanceMaximo);
            ~Projetil();

            void atualizar() override;
            void desenhar() override;
            void colisao(Entidade* outra, sf::Vector2f ds = sf::Vector2f(0.f, 0.f));

            const float getDano() const;
            const bool getAtivo();
            void setAtivo(bool ativo);
        };
    }
}