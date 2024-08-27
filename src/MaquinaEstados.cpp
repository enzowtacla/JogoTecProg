#include "MaquinaEstados.h"
#include "Estado.h"
#include <iostream>

using namespace Jogo;
using namespace Estados;

MaquinaEstados::MaquinaEstados():mapaEstados()
{

}

MaquinaEstados::~MaquinaEstados()
{
    std::map<IDestado, Estado*>::iterator it;
    
    for(it = mapaEstados.begin(); it != mapaEstados.end(); it++)
    {
        delete(it->second);
    }
}

void MaquinaEstados::mudarEstadoAtual(Estados::IDestado ide)
{
    IDEstadoAtual = ide;
    mapaEstados[IDEstadoAtual]->resetarEstado();
}

void MaquinaEstados::execEstadoAtual(float dt)
{
    mapaEstados[IDEstadoAtual]->atualizar(dt);
    mapaEstados[IDEstadoAtual]->renderizar();
}

IDestado MaquinaEstados::getIDEstadoAtual() const
{
    return IDEstadoAtual;
}

void MaquinaEstados::inserirEstado(Estados::Estado* pE)
{
    if(pE)
    {
        mapaEstados.insert(std::pair<IDestado, Estado*>(pE->getIDE(), pE));
    }
    else
    {
        std::cerr << "Nao foi possivel inserir estado na maquina de estados" << std::endl;
    }
}