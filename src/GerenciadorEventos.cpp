#include "../include/Gerenciadores/GerenciadorEventos.h"

using namespace Jogo;
using namespace Gerenciadores;

GerenciadorEventos* GerenciadorEventos::pEventos(nullptr);

GerenciadorEventos::GerenciadorEventos():
pGG(pGG->getGrafico()), pInputs(pInputs->getGerenciadorInputs())
{

}

GerenciadorEventos::~GerenciadorEventos()
{

}

GerenciadorEventos* GerenciadorEventos::getGerenciadorEventos()
{
	if (!pEventos) {
		pEventos = new GerenciadorEventos();
	}
	return pEventos;
}

void GerenciadorEventos::executar()
{
	sf::Event evento;

	if(pGG->getJanela()->pollEvent(evento))
	{
		if (evento.type == sf::Event::KeyPressed) {
			pInputs->tratarTeclaPressionada(evento.key.code);
		}
		else if (evento.type == sf::Event::KeyReleased) {
			pInputs->tratarTeclaSolta(evento.key.code);
		}
		else if (evento.type == sf::Event::Closed) {
			pGG->fecharJanela();
		}
	}
}

