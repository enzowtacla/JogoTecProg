#pragma once
#include <fstream>
#include <iostream>
#include "../Listas/ListaEntidade.h"
#include "../Ente.h"
#include "../Gerenciadores/GerenciadorColisao.h"
#include "../oBSERVADORES/ObservadorJogador.h"
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
			Gerenciadores::GerenciadorInputs* pInputs;
			Fundos::Fundo fundo;

			//controle de geração
			static int qtdCogu;
			static int qtdEsp;
			const int numCogu;
			const int numEsp;

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
			virtual void criarPerseguidor(const sf::Vector2f pos);
			//virtual void criarChefao(const sf::Vector2f pos);
			virtual void criarJogador(const sf::Vector2f pos) = 0;
			void criarPlataforma(const sf::Vector2f pos);
			virtual void criarSlime(const sf::Vector2f pos);
			//virtual void criarLava(const sf::Vector2f pos);
			void criarEspinho(const sf::Vector2f pos);

		};

	}
}