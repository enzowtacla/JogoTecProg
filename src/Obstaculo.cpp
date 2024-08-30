#include "../include/Entidades/Obstaculos/Obstaculo.h"

using namespace Jogo;
using namespace Entidades;
using namespace Obstaculos;

Obstaculo::Obstaculo(const Vector2f pos, const Vector2f tam, const IDs::ID id) : Entidade(pos, tam,VELOCIDADE, id), danoso(false)
{
	//corpo.setPosition(pos);
	//textura = pGG->carregarTextura("./Assets/plataforma.png");
	//corpo.setTexture(&textura);
}

Obstaculo::~Obstaculo()
{

}

void Obstaculo::atualizar()
{
    atualizarPosicao();
}

void Obstaculo::colisao(Entidade* outra, sf::Vector2f ds)
{

}

const bool Obstaculo::getDanoso() const
{
    return danoso;
}

void Obstaculo::atualizarPosicao()
{
	dt = pGG->getTempo();
	
	Vector2f ds(0.f, 0.f);

	const float Vy = velFinal.y;
	velFinal.y = (velFinal.y + GRAVIDADE * dt) + (velFinal.y + EMPUXO * dt);
	ds.y = Vy * dt + (GRAVIDADE * dt * dt) / 2.0f;

	setPos(Vector2f(pos.x + ds.x, pos.y + ds.y));

	velFinal.x = velMax;

}


/*
//código inspirado no jogo do Murilo; https://github.com/Lillo-M/TheWizard
void Obstaculo::Save(std::ofstream& savefile)
{
    savefile << this->getID() << std::endl;
	savefile << Position.x << std::endl;
	savefile << Position.y << std::endl; 
    savefile << Velocity.x << std::endl;
	savefile << Velocity.y << std::endl;
}

void Obstaculo::Load(std::ifstream& savefile)
{
    int iread;
    savefile >> iread;
	savefile >> Position.x;
	savefile >> Position.y; 
    savefile >> Velocity.x;
	savefile >> Velocity.y;
}
*/