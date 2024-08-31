#pragma once

#include "../Entidade.h"
#include "../Personagens/Jogadores/Jogador.h"
#include "../Personagens/Inimigos/Inimigo.h"

#define EMPUXO -800.f
#define VELOCIDADE 0.f

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
				float deltaT; //dt
				Vector2f velFinal;

				//sf::Texture textura;
			public:
				Obstaculo(const Vector2f pos, const Vector2f tam, const float vel, const IDs::ID id);
				virtual ~Obstaculo();
				virtual void atualizar() = 0; //desenhar
				void gravidadeObstaculo();
				const bool getDanoso() const;
				virtual void colisao(Entidade* outra, sf::Vector2f ds) = 0;
				//void Save(std::ofstream& savefile);
            	//void Load(std::ifstream& savefile);
			};
		}
	}
}