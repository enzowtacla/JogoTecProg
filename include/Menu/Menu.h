#pragma once

#include "Ente.h"
#include "Botao/BotaoTexto.h"
#include "Botao/Texto.h"
#include <list>

#define TAMANHO_BOTAO_X 350.f
#define TAMANHO_BOTAO_Y 50.f

namespace Jogo
{
    namespace Observadores{
        class ObservadorMenu;
    }
    namespace Menus
    {
        class Menu : public Ente
        {
        protected:
            Observadores::ObservadorMenu* observadorMenu;
            std::list<Botoes::BotaoTexto*> listaBotaoTexto;
            std::list<Botoes::BotaoTexto*>::iterator it;
            const sf::Vector2f tamBotao;
            const sf::Vector2f tamJanela;
            //sf::Vector2f posFundo;
            Botoes::Texto titulo;
            bool mouseSelecionado;

            //void atualizarPosicaoFundo();
            //virtual void criarFundo(){};
            virtual void criarBotoes() = 0;
            void inicializarIterator();

        public:
            Menu(const IDs::ID id, const sf::Vector2f tamBotao, const std::string nome, const unsigned int tamFonte);
            ~Menu();
            void addBotao(const std::string info, const sf::Vector2f pos, const IDs::ID id, const sf::Color corSelecionado);
            void mudarEstadoObservador();
            void selecionaCima();
            void selecionaBaixo();
            virtual void selecionaEsquerda(){}
            virtual void selecionaDireita(){}
            const IDs::ID getIDBotaoSelecionado() const;
            void eventoMouse(const sf::Vector2f posMouse);
            const bool getMouseSelecionado() const;
            virtual void executar() = 0;
            void desenhar();
        };
    }
}