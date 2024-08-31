#include "../include/Entidades/Obstaculos/Plataforma.h"

using namespace Jogo;
using namespace Entidades;
using namespace Obstaculos;

Plataforma::Plataforma(const Vector2f pos, const Vector2f tam) :Obstaculo(pos, tam, VELOCIDADE_PLATAFORMA,IDs::ID::plataforma)
{
	textura = pGG->carregarTextura("./Assets/plataforma.png");
	corpo.setTexture(&textura);
}

Plataforma::~Plataforma()
{

}

void Plataforma::colisao(Entidade* outra, sf::Vector2f ds)
{
	if (outra->getId() == IDs::ID::jogador ||
	outra->getId() == IDs::ID::cogumelo ||
	outra->getId() == IDs::ID::perseguidor ||
    outra->getId() == IDs::ID::chefao
	)
	{
		colisaoObstaculo(ds, static_cast<Personagens::Personagem*>(outra));
	}
}

void Plataforma::colisaoObstaculo(Vector2f ds, Personagens::Personagem* pPersonagem)
{
    sf::Vector2f posOutro = pPersonagem->getPos();
    sf::Vector2f tamOutro = pPersonagem->getTam();
    sf::Vector2f velFinal = pPersonagem->getVelFinal();
    if (ds.x < 0.0f && ds.y < 0.0f) { //houve colisao
        if (ds.x > ds.y) {
            if (posOutro.x < pos.x) { //colis�o em x
                posOutro.x += ds.x;
            }
            else {
                posOutro.x -= ds.x;
            }
            velFinal.x = 0.0f;
        }
        else {
            if (posOutro.y < pos.y) { //colis�o em y
                posOutro.y += ds.y;
                if (pPersonagem->getId() == IDs::ID::jogador) {
                    Personagens::Jogadores::Jogador* pJogador = static_cast<Personagens::Jogadores::Jogador*>(pPersonagem);
                    pJogador->podePular();
                }
            }
            else {
                posOutro.y -= ds.y;
            }
            velFinal.y = 0.0f;
        }
    }
    pPersonagem->setPos(posOutro);
    pPersonagem->setVelFinal(velFinal);
}

void Plataforma::atualizar()
{
    //desenhar();
    gravidadeObstaculo();
}