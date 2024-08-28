#pragma once

#include "Observadores/Observador.h"

namespace Jogo
{
    namespace Entidades{
        namespace Personagens{
            namespace Jogadores{
                class Jogador;
            }
        }
    }
    namespace Observadores
    {
        class ObservadorJogador : public Observador
        {
        private:
            Entidades::Personagens::Jogadores::Jogador* pJogador;

            std::string pular;
            std::string esquerda;
            std::string direita;
            std::string atacar;

        public:
            ObservadorJogador(Entidades::Personagens::Jogadores::Jogador* pJogador);
            ~ObservadorJogador();
            void notificarPressionada(std::string tecla);
            void notificarSolta(std::string tecla);
            void setTeclas(std::string pulo, std::string pesquerda, std::string direita, std::string atacar);
        };
    }
}