#include "Observador.h"

using namespace Jogo;
using namespace Observadores;

Observador::Observador():
pGI(pGI->getGerenciadorInputs())
{
    pGI->incluir(this);
}

Observador::~Observador()
{
    pGI->excluir(this);
}