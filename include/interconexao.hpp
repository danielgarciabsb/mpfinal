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

		enum Validacao{
			FALHA_TRANSPORTE, EXITO_TRANSPORTE
		};
		
		int getCapacidadeMax() ;
		
		float getChanceFalha() ;
		
		int getTempoConserto() ;
		
		int getCustoConserto() ;
		
		void aplicarChanceDeFalha();

		bool isWorking() ;
		
		void transmitirCarga(int carga) ;

		void emitirCarga(int carga) ;

		void receberCarga(int carga) ;

		void draw(SDL_Renderer* gRenderer, int spacing, int min_x_y) ;
};

#endif // _INTERCONEXAO_H
