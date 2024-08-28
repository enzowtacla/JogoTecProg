#include "../include/Entidades/Obstaculos/Espinho.h"
#include "../include/Entidades/Personagens/Jogadores/Jogador.h"

namespace Jogo {

    namespace Entidades {

        namespace Obstaculos {

            Espinho::Espinho(const sf::Vector2f pos, const sf::Vector2f tam) :
                Obstaculo(pos, tam, IDs::ID::espinho), dano(DANO_ESPINHO_PADRAO), impulso(IMPULSO)
            {
                //inicializarAnimacao();
                corpo = sf::RectangleShape(tam);
                corpo.setPosition(pos);
                corpo.setFillColor(Color::Black);
            }

            Espinho::~Espinho() 
            {

            }

            void Espinho::colisao(Entidade* outra, sf::Vector2f ds)
            {
	            if(outra->getId() == IDs::ID::jogador)
	            {
		            //std::cout << "entrou na envenenar" << std::endl;
		            espetar(static_cast<Personagens::Personagem*>(outra));
	            }
            }           

            void Espinho::espetar(Personagens::Personagem* pPersonagem)
            {
	            if(pPersonagem){
		            Personagens::Jogadores::Jogador* pJogador = static_cast<Personagens::Jogadores::Jogador*>(pPersonagem);
		            pJogador->tomarDano(DANO_ESPINHO_PADRAO);
                    pJogador->knockBack(impulso);
	            }
            }

            /*void Espinho::inicializarAnimacao() {
                textura = pGrafico->carregarTextura(CAMINHO_TEXTURA_ESPINHO);
                corpo.setTexture(&textura);
            }*/

        }

    }

}