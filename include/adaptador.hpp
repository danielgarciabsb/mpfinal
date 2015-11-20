#ifndef _ADAPTADOR_H
#define _ADAPTADOR_H

#include "interconexao.hpp"

class Adaptador : public Elemento
{		
	public:						
		Adaptador(string nome, Elemento::Posicao posicaoInicial, Elemento::Posicao posicaoFinal) :
		Elemento(nome, posicaoInicial, posicaoFinal) {} ;
		
		void transmitirCarga(int carga)
		{
			this->receberCarga(carga);
			Elemento::transmitirCarga(this->getCarga());
			this->emitirCarga();
		} ;
		
		void emitirCarga() 
		{ 
			set<Elemento*> * saidas = this->getSaidas();
			int totalCargaSaidas = 0;
			float proporcao;
	
			set<Elemento*>::iterator iSaidas;
			for(iSaidas = saidas->begin(); iSaidas != saidas->end(); iSaidas++)
			{
				if(((Interconexao*)(*iSaidas))->isWorking())
					totalCargaSaidas += ((Interconexao*)(*iSaidas))->getCapacidadeMax();
			}
				
			for(iSaidas = saidas->begin(); iSaidas != saidas->end(); iSaidas++)
			{
				//if((*iSaidas)->isWorking())
					proporcao = (float) ((Interconexao*)(*iSaidas))->getCapacidadeMax() / totalCargaSaidas;
				//else
					//proporcao = 0;
				(*iSaidas)->transmitirCarga((int) (proporcao * this->getCarga()));
			}
		} ;

		void receberCarga(int carga) 
		{ 
			this->setCarga(carga); 
		} ;
};

#endif // _ADAPTADOR_H
