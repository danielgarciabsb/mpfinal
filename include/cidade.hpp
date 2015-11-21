#ifndef _CIDADE_H
#define _CIDADE_H

#include "elemento.hpp"

class Cidade : public Elemento
{
	private:
		int recursoNecessario;
		int cargaTotal;
		
	public:
		int getRecursoNecessario();
		
		Cidade(string nome, Elemento::Posicao posicaoInicial, Elemento::Posicao posicaoFinal, int recursoNecessario) : 
				Elemento(nome, posicaoInicial, posicaoFinal)
		{
			this->recursoNecessario = recursoNecessario;
		};
		
		void transmitirCarga(int carga) 
		{
			this->receberCarga(carga);
		 	return; 
	 	}
		
		void receberCarga(int carga) 
		{ 
			this->setCarga(this->getCarga() + carga); 
			cout << "- " << this->getNome() << " recebeu +" << carga << " de carga (Total: " << this->getCarga() << ")" << endl;
		} ; 

		void emitirCarga() { return; } ;
};

#endif // _CIDADE_H