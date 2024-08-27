#include "../include/Estados/Estado.h"

using namespace Jogo;
using namespace Estados;

Estado::Estado(MaquinaEstados* pME, Estados::IDestado ide)
{

}

Estado::~Estado()
{
    pME = nullptr;
}

void Estado::setMaquinaEstado(MaquinaEstados* pME)
{
    this->pME = pME;
}

void Estado::mudarEstado(Estados::IDestado ide)
{
    
}

Estados::IDestado Estado::getIDE() const
{
    return ide;
}
