#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;
namespace Jogo
{
    namespace Menus
    {
        namespace Botoes
        {
            class Texto
            {
            private:
                const Font fonte;
                std::string info;

            protected:
                Text texto;
                Vector2f tam;
                Vector2f pos;
                unsigned int tamFonte;
                Color corTexto;
                Color corBorda;

                void inicializa();

            public:
                Texto(const Font fonte, const std::string info, const unsigned int tamFonte = 50);
                virtual ~Texto();
                const Text getTexto() const;
                void setPos(const Vector2f pos);
                const Vector2f getPos() const;
                const Vector2f getTam() const;
                void setCorTexto(const Color corTexto);
                void setTamanhoBorda(const float tamBorda);
                void setEspacamento(const float tamEspaco);
                void setString(std::string nome);
                const std::string getString() const;
                void setTamFonte(const unsigned int tamFonte);

            };
        }
    }
}