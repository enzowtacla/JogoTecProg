#pragma once
#include "../include/Ente.h"

using namespace sf;
namespace Jogo
{
    namespace Menus
    {
        namespace Botoes
        {
            class Botao : public Ente
            {
            private:
                const Vector2f tamMax;
                const Vector2f tamInicial;
                bool aumentando;

            protected:
                RectangleShape caixa;
                Texture *textura;
                Vector2f pos;
                Vector2f tam;
                const float tempoTroca;
                float tempo;

            public:
                Botao(const Vector2f tam, const Vector2f pos, const IDs::ID id, const float tempoTroca = 0.0f, const Vector2f tamMax = Vector2f(0.0f, 0.0f));
                virtual ~Botao();
                virtual void desenhar();
                virtual void atualizarAnimacao();
                virtual void atualizarPosicaoCaixa(const Vector2f pos);
                void setTexture(Texture *textura);
                const Vector2f getPos() const;
            };
        }

    }
}