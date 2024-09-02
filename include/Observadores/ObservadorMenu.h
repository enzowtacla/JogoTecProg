//Código inpirado no do monitor Burda
#pragma once

#include "Observador.h"


namespace Jogo
{
    namespace Menus{
        class Menu;
    }
    namespace Observadores
    {
        class ObservadorMenu : public Observador
        {
        private:
            Menus::Menu* menu;

            std::string baixo;
            std::string cima;
            std::string seleciona;
            static bool teclaApertada;

        public:
            ObservadorMenu(Menus::Menu* menu);
            ~ObservadorMenu();
            void notificarPressionada(std::string tecla);
            void notificarSolta(std::string tecla);
        };
    }
}