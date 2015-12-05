#include "adaptador.hpp"

void Adaptador::transmitirCarga(int carga)
{
	this->receberCarga(carga);
	Elemento::transmitirCarga(this->getCarga());
	this->emitirCarga(this->getCarga());
} 

void Adaptador::emitirCarga(int carga) 
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

		(*iSaidas)->transmitirCarga((int) (proporcao * carga));
	}
} 

void Adaptador::receberCarga(int carga) 
{ 
	this->setCarga(carga); 
} 

void Adaptador::draw(SDL_Renderer* gRenderer, int spacing, int min_x_y) {
	// Posição do centro do círculo.
	// Os elementos são impressos em escala logarítmica. Por isso esses "logs".
	// Se quiser deslocar a posição a ser impressa é só somar ou diminuir a quantidade
	// de pixels de pos_x ou pos_y.
	int	pos_center_x = log(1 + this->getPosicaoInicial().x - min_x_y) * spacing + 30;
	int pos_center_y = log(1 + this->getPosicaoInicial().y - min_x_y) * spacing + 30;

	filledCircleColor(gRenderer, pos_center_x, pos_center_y, 30, 0XFF00FF00);
}