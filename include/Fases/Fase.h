#pragma once
#include <fstream>
#include <iostream>
#include "../Listas/ListaEntidade.h"
#include "../Ente.h"
#include "../Gerenciadores/GerenciadorColisao.h"
#include "../Gerenciadores/GerenciadorEventos.h"
#include "../Fundo/Fundo.h"


namespace Jogo
{
	namespace Fases
	{
		class Fase : public Ente
		{
		protected:
			Listas::ListaEntidade listaInimigos;
			Listas::ListaEntidade listaObstaculos;
			Listas::ListaEntidade listaJogadores;
			Gerenciadores::GerenciadorColisao colisor;
			Gerenciadores::GerenciadorEventos* pEventos;
			Fundos::Fundo fundo;
			//int numAleatorio;

		public:
			Fase(const IDs::ID id);
			~Fase();
			virtual void criarMapa(const std::string& arquivoTxt) = 0;
			void criarEntidade(char letra, const sf::Vector2i pos); //Método template
			void executar();
			void desenhar();

		//Template Method
		protected:
			void criarCogumelo(const sf::Vector2f pos);
			virtual void criarPerseguidor(const sf::Vector2f pos)= 0;
			virtual void criarJogador(const sf::Vector2f pos) = 0;
			void criarObstaculo(const sf::Vector2f pos);
			virtual void criarSlime(const sf::Vector2f pos) = 0;
			void criarEspinho(const sf::Vector2f pos);
		};

	}
}