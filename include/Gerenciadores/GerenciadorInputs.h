//Chain of Responsability - Padrão de projeto
//Código inpirado no do monitor Giovane
#pragma once

#include <list>
#include <map>
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;

namespace Jogo
{
    namespace Observadores{
        class Observador;
    }
    
    namespace Gerenciadores
    {
        
        class GerenciadorInputs
        {
        private:
            list<Observadores::Observador*> listaObservadores;
            list<Observadores::Observador*>::iterator it;

            map<sf::Keyboard::Key, string> mapaTeclas;

            static GerenciadorInputs* pInputs;
            GerenciadorInputs();

        public:
            ~GerenciadorInputs();
            static GerenciadorInputs* getGerenciadorInputs();
            void incluir(Observadores::Observador* pObserver);
            void excluir(Observadores::Observador* pObserver);
            void tratarTeclaPressionada(sf::Keyboard::Key tecla);
            void tratarTeclaSolta(sf::Keyboard::Key tecla);
            std::string getTeclaString(sf::Keyboard::Key tecla);
        };
        
    }
}