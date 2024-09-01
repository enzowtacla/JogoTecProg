#include "../include/Fundo/Fundo.h"
#include <cmath>


using namespace sf;
using namespace Jogo;
using namespace Fundos;

Fundo::Fundo(const Vector2f tamJanela, const char* caminhoTextura) :Ente(IDs::ID::fundo), tamJanela(tamJanela), textura(textura), dimensao(0, 0, 0, 0)
{
	textura = pGG->carregarTextura(caminhoTextura);
	dimensao.width = -abs((int)textura.getSize().x);
	dimensao.height = textura.getSize().y;
	dimensao.left = textura.getSize().x;

	fundo.setSize(tamJanela);
	fundo.setTexture(&this->textura);
	fundo.setPosition(0.f, 0.f);
}

Fundo::~Fundo()
{

}

void Fundo::desenhar()
{
	RenderWindow* janela = pGG->getJanela();
	janela->draw(fundo);
}
