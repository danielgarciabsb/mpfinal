#include "cidade.hpp"

int Cidade::getRecursoNecessario() { return this->recursoNecessario; }

void Cidade::consumirCarga()
{
	this->setCarga(0);
}

void Cidade::transmitirCarga(int carga) 
{
	this->receberCarga(carga);
 	return; 
}

void Cidade::receberCarga(int carga) 
{ 
	//if(this->getCarga() + carga > this->recursoNecessario)
		//this->setCarga(this->recursoNecessario);
	//else
		this->setCarga(this->getCarga() + carga); 
		
	cout << "- " << this->getNome() << " recebeu +" << carga << " de carga (Total: " << this->getCarga() << ")" << endl;
}
