#include "ObservadorMenu.h"
#include "../include/Menus/Menu.h"

using namespace Jogo;
using namespace Observadores;

bool ObservadorMenu::teclaApertada(false);

ObservadorMenu::ObservadorMenu(Menus::Menu* menu): Observador(), menu(menu), baixo("Down"), cima("Up"), seleciona("Enter")
{

}

ObservadorMenu::~ObservadorMenu()
{
    menu = nullptr;
}


void ObservadorMenu::notificarPressionada(std::string tecla) 
{
    //static bool teclaApertada = false;

    if (!teclaApertada) {
        if (tecla == baixo) {
            menu->moveBaixo();
        } else if (tecla == cima) {
            menu->moveCima();
        } else if (tecla == seleciona) {
            int selecionado = menu->getPosSelecionada();
            menu->selecionado(selecionado);
        }

        teclaApertada = true;
    }

    /*if (tecla != baixo && tecla != cima && tecla != seleciona) {
        teclaApertada = false;
    }*/
}


void ObservadorMenu::notificarSolta(std::string tecla)
{
    if(tecla == baixo || tecla == cima || tecla == seleciona){
        teclaApertada = false;
    }
}