#pragma once

#include "Texto.h"

namespace Jogo
{
    namespace Menus
    {
        namespace Botoes
        {
            class TextoAnimado : public Texto
            {
            private:
                int transparente;
                bool clareando;
                void atualizar();

            public:
                TextoAnimado(const sf::Font fonte, const std::string info);
                ~TextoAnimado();
                void mudarClareando();
                const bool getClareando() const;
                const int getTransparente() const;
                void setTransparente(int transparente);
                void resetar();
            };
        }
    }
}