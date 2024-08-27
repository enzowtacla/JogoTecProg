#pragma once

#include "Estados/Estado.h"
#include <map>

namespace Jogo
{
    namespace Estados
    {
        class MaquinaEstados
        {
        protected:
            Estados::IDestado IDEstadoAtual;
            std::map<IDestado, Estado*> mapaEstados;

        public:
            MaquinaEstados();
            virtual ~MaquinaEstados();
            void mudarEstadoAtual(Estados::IDestado ide);
            void execEstadoAtual(const float dt);
            Estados::IDestado getIDEstadoAtual() const;
            void inserirEstado(Estados::Estado* pEstado);
        };
    }
}