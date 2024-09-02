//Código inpirado no do monitor Burda
#pragma once

#include "GerenciadorInputs.h"

namespace Jogo
{
    namespace Observadores
    {
        class Observador
        {
        private:
            Gerenciadores::GerenciadorInputs* pGI;

        public:
            Observador();
            ~Observador();
            virtual void notificarPressionada(std::string tecla) = 0;
            virtual void notificarSolta(std::string tecla) = 0;
        };
    }
}