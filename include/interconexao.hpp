#ifndef _INTERCONEXAO_H
#define _INTERCONEXAO_H

#include "elemento.hpp"
#include "relatorio.hpp"

class Interconexao: public Elemento
{
	private:
		int capacidadeMax;
		float chanceFalha;
		int tempoConserto;
		int custoConserto;
		int previsaoTerminoConserto;
		bool working;
		
	public:
		enum Validacao{
			FALHA_TRANSPORTE, EXITO_TRANSPORTE
		};
		int getCapacidadeMax() { return this->capacidadeMax; }
		float getChanceFalha();
		int getTempoConserto();
		int getCustoConserto();
		
		void aplicarChanceDeFalha();
		bool isWorking() { return this->working; };
				
		Interconexao(string nome, Elemento::Posicao posicaoInicial, Elemento::Posicao posicaoFinal,
					 int capacidadeMax, float chanceFalha, int tempoConserto, int custoConserto):
			Elemento(nome, posicaoInicial, posicaoFinal)
		{
			this->capacidadeMax = capacidadeMax;
			this->chanceFalha = chanceFalha;
			this->tempoConserto = tempoConserto;
			this->custoConserto = custoConserto;
			this->working = true;
		};
		
		void transmitirCarga(int carga)
		{
			this->receberCarga(carga);
			Elemento::transmitirCarga(this->getCarga());
			this->emitirCarga();
		}

		void emitirCarga()
		{
			set<Elemento*> * saidas = this->getSaidas();
			
			set<Elemento*>::iterator iSaidas;
			for(iSaidas = saidas->begin(); iSaidas != saidas->end(); iSaidas++)
				(*iSaidas)->transmitirCarga(this->getCarga());
			
		} ;

		void receberCarga(int carga) 
		{ 		
			if(!this->isWorking())
			{
				this->setCarga(0);
				//Elemento::receberCarga(this->getCarga());
				return;
			}
			
			if(carga > this->capacidadeMax)
				this->setCarga(this->capacidadeMax);
			else				
				this->setCarga(carga); 
			
			Elemento::receberCarga(this->getCarga());
		} ;
};

#endif // _INTERCONEXAO_H
