#include "adaptador.hpp"

void Adaptador::transmitirCarga(int carga)
{
	this->receberCarga(carga);
	Elemento::transmitirCarga(this->getCarga());
	this->emitirCarga();
} 

void Adaptador::emitirCarga() 
{ 
	set<Elemento*> * saidas = this->getSaidas();
	int totalCargaSaidas = 0;
	float proporcao;

	// Calcula a capacidade total das interconẽxões.
	set<Elemento*>::iterator iSaidas;
	for(iSaidas = saidas->begin(); iSaidas != saidas->end(); iSaidas++)
	{
		if(((Interconexao*)(*iSaidas))->isWorking())
			totalCargaSaidas += ((Interconexao*)(*iSaidas))->getCapacidadeMax();
	}
	
	// Calcula a proporção de carga recebida por cada interconexão.	
	for(iSaidas = saidas->begin(); iSaidas != saidas->end(); iSaidas++)
	{
		proporcao = (float) ((Interconexao*)(*iSaidas))->getCapacidadeMax() / totalCargaSaidas;

		(*iSaidas)->transmitirCarga((int) (proporcao * this->getCarga()));
	}
} 

void Adaptador::receberCarga(int carga) 
{ 
	this->setCarga(carga); 
} 

void Adaptador::draw(SDL_Renderer* gRenderer, int spacing, int min_x_y) {
	filledCircleColor(gRenderer, log(1 + this->getPosicaoInicial().x - min_x_y) * spacing + 30, log(1 + this->getPosicaoInicial().y - min_x_y) * spacing + 30, 30, 0XFF00FF00);
}