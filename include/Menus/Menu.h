#pragma once
#include "Ente.h"
#include <vector>

#define TAMANHO_BOTAO_X 350.f
#define TAMANHO_BOTAO_Y 50.f

namespace Jogo
{
    namespace Menus
    {
        class Menu : public Ente
        {
        private:
            int posSelecionada;
            sf::Font fonte;
            std::vector<sf::Text> botoesMenu;
            float largura;
            float altura;
            bool criarFase;
            int numFase;
            int numJogadores;

            static Menu* pMenu;
            Menu();

        public:
            ~Menu();
            static Menu* getMenu();
            void moveCima();
            void moveBaixo();
            void selecionado(int pos);
            int getPosSelecionada();
            void setPos(int pos);
            void desenhar();
            const bool getCriarFase() const;
            const int getNumFase() const;
            const int getNumJogadores() const;
            void setNumFase(int nf);
        };
    }
}
