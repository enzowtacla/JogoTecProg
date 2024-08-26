#pragma once

#include "../Entidade.h"
#include "../Personagens/Jogadores/Jogador.h"
#include "../Personagens/Inimigos/Inimigo.h"


using namespace sf;

namespace Jogo
{
	namespace Entidades
	{
		namespace Obstaculos
		{
			class Obstaculo : public Entidade
			{
			protected:
				bool danoso;
				bool colidir;
				//sf::Texture textura;
			public:
				Obstaculo(const Vector2f pos, const Vector2f tam, const IDs::ID id);
				virtual ~Obstaculo();
				virtual void atualizar(); //desenhar
				const bool getDanoso() const;
				virtual void colisao(Entidade* outra, sf::Vector2f ds) = 0;
				//void Save(std::ofstream& savefile);
            	//void Load(std::ifstream& savefile);
			};
		}
	}
}