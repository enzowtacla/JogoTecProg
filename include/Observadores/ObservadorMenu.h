#pragma once

#include "Observador.h"
#include "Menu.h"
#include "Botao.h"

namespace Jogo
{
    namespace Observadores
    {
        class ObservadorMenu : public Observador
        {
        private:
            Menus::Menu* menu;

        public:
            ObservadorMenu(Menus::Menu* menu);
            ~ObservadorMenu();
            void notificarPressionada(std::string tecla);
            void notificarSolta(std::string tecla);
            void moveMouse(const sf::Vector2f posMouse);
            void botaoMouseSolta(const sf::Mouse::Button botaoMouse);
        };
    }
}