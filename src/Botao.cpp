#include "Botao.h"

using namespace sf;
using namespace Jogo;
using namespace Menus;
using namespace Botoes;

Botao::Botao(const Vector2f tam, const Vector2f pos, const IDs::ID id, const float tempoTroca, const Vector2f tamMax):
Ente(id), pos(pos), tam(tam), tempoTroca(tempoTroca), textura(new Texture()), tamMax(tamMax == sf::Vector2f(0.0f, 0.0f) ? tam : tamMax), tamInicial(tam), aumentando(true)
{
    caixa.setPosition(pos);
    caixa.setSize(tam);
}

Botao::~Botao()
{
    if(textura)
    {
        delete textura;
        textura = nullptr;
    }
}

void Botao::atualizarPosicaoCaixa(const Vector2f pos)
{
    this->pos = pos;
    caixa.setPosition(pos);
}

const Vector2f Botao::getPos() const
{
    return caixa.getPosition();
}

void Botao::setTexture(Texture* textura)
{
    this->textura = textura;
    caixa.setTexture(textura);
}

void Botao::desenhar()
{
    pGG->desenhaElementos(caixa);
}

void Botao::atualizarAnimacao()
{
    this->tempo += pGG->getTempo();
    if(this->tempo < tempoTroca)
    {
        const float acres = tempo * (aumentando ? 1 : -1);
        tam = Vector2f(tam.x + acres, tam.y + acres);
        if(tam.x > tamMax.x || tam.x < tamInicial.x){
            aumentando != aumentando;
        }
        else{
            caixa.setSize(tam);
        }
    }
    else{
        this->tempo = 0.f;
    }
}