#ifndef _GERADOR_H
#define _GERADOR_H

#include "interconexao.hpp"

class Gerador : public Elemento
{
	private:
		int recursoProduzido;
		int custoGerador;
		
	public:
		int getRecursoProduzido();
		int getCustoGerador();

		Gerador(string nome, Posicao posicaoInicial, Posicao posicaoFinal, int recursoProduzido, int custoGerador) :
			Elemento(nome, posicaoInicial, posicaoFinal)
		{
			this->recursoProduzido = recursoProduzido;
			this->custoGerador = custoGerador;
		};
		
		void transmitirCarga(int carga) {} ;

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
				(*iSaidas)->transmitirCarga((int) (proporcao * this->recursoProduzido));
			}
		};

		void receberCarga(int carga) 
		{
			//Elemento::receberCarga(0);
		} ;
};

#endif // _GERADOR_H
