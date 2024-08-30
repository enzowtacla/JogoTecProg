#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Personagem.h"

#define VELOCIDADE_JOGADOR_X 200.0f
#define TAMANHO_PULO 120.f

using namespace sf;

namespace Jogo
{
    namespace Entidades
    {
        namespace Personagens
        {
            namespace Jogadores
            {
                class Jogador : public Personagem
                {
                private:
                    int num_jogador;
                    static int cont_j;
                    bool noChao;
                    void inicializa();
                    float velocidadeMovimento;
                    float velocidadePulo;
                    bool noSlime;

                public:
                    Jogador(const Vector2f pos, const Vector2f tam);
                    ~Jogador();
                    const RectangleShape getCorpo();
                    void atualizar();
                    void atualizarAnimacao();
                    void desenhar();
                    void podePular();
                    void pular();
                    const int getNum() const;
                    const bool getAndando() const;
                    void tomarDano(float dano);
                    void colisao(Entidade* outra, sf::Vector2f ds);
                    float getVelocidadeMovimento() const;
                    float getVelocidadePulo() const;
                    void restaurarValoresOriginais();
                    void setVelocidadeMovimento(float velocidade);
                    void knockBack(float dist);
                    const bool getVivo() const;
                };
            }
        }
    }
}