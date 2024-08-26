#include "../include/Entidades/Obstaculos/Obstaculo.h"

using namespace Jogo;
using namespace Entidades;
using namespace Obstaculos;

Obstaculo::Obstaculo(const Vector2f pos, const Vector2f tam, const IDs::ID id) : Entidade(pos, tam, id), danoso(false)
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
    // desenhar();
}

void Obstaculo::colisao(Entidade* outra, sf::Vector2f ds)
{

}

const bool Obstaculo::getDanoso() const
{
    return danoso;
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