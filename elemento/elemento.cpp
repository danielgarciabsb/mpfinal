#include "elemento.hpp"

string Elemento::getNome() { return this->nome; }

int Elemento::getCarga() { return this->carga; }

void Elemento::setCarga(int carga) { this->carga = carga; }

Elemento::Posicao Elemento::getPosicaoInicial() { return this->posicaoInicial; }

Elemento::Posicao Elemento::getPosicaoFinal() { return this->posicaoFinal; }

set<Elemento*> * Elemento::getEntradas() { return &this->entradas; }

set<Elemento*> * Elemento::getSaidas() { return &this->saidas; }

Elemento::Elemento(string nome, Posicao posicaoInicial, Posicao posicaoFinal)
{
	this->nome = nome;
	this->posicaoInicial = posicaoInicial;
	this->posicaoFinal = posicaoFinal;
};

void Elemento::transmitirCarga(int carga)
{
	cout << "\t- " << this->getNome() << " transmitiu +" << carga << " de carga." << endl;
}
