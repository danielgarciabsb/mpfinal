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
