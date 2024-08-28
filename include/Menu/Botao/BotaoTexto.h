#pragma once

#include "Botao.h"
#include "TextoAnimado.h"

#define CAMINHO_FONTE "Fonte/menu.ttf"
#define TEMPO_TROCAR_COR 0.01f

namespace Jogo
{
    namespace Menus
    {
        namespace Botoes
        {
            class BotaoTexto : public Botao
            {
            protected:
                bool selecionado;
                sf::Color corSelecionado;
                TextoAnimado texto;
                const sf::Vector2f getTamTexto() const;

            public:
                BotaoTexto(const std::string info, const sf::Vector2f pos, const sf::Vector2f tam, const IDs::ID ID, const sf::Color corSelecionado);
                ~BotaoTexto();
                void atualizarAnimacao();
                void atualizarPosicaoCaixa(const sf::Vector2f pos);
                void setSelecionado(bool selecionado);
                const bool getSelecionado() const;
                void desenhar();
            };
        }
    }
}
