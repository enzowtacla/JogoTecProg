#pragma once

namespace Jogo
{
    namespace Estados
    {
        class MaquinaEstados;

        enum IDestado
        {
            desconhecido = -1,
            menuPrincipal = 0,
            novoJogo, //1
            jogando, //2
            menuPause, //3
            carregarJogo, //4
            ranking, //5
            fimJogo //6
        };

        class Estado
        {
        private:
            MaquinaEstados* pME;
            IDestado ide;

        public:
            Estado(MaquinaEstados* pME = nullptr, Estados::IDestado ide = desconhecido);
            virtual ~Estado();
            void setMaquinaEstado(MaquinaEstados* pME);
            void mudarEstado(Estados::IDestado ide);
            Estados::IDestado getIDE() const;
            virtual void atualizar(float dt) = 0;
            virtual void renderizar() = 0;
            virtual void resetarEstado() = 0;  
        };
    }
}