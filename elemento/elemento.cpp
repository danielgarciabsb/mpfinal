#include "elemento.hpp"

string Elemento::getNome() { return this->nome; }

int Elemento::getCarga() { return this->carga; }

void Elemento::setCarga(int carga) { this->carga = carga; }

Elemento::Posicao Elemento::getPosicaoInicial() { return this->posicaoInicial; }

Elemento::Posicao Elemento::getPosicaoFinal() { return this->posicaoFinal; }

set<Elemento*> * Elemento::getSaidas() { return &this->saidas; }
