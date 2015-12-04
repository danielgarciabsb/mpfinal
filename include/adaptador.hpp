#ifndef _ADAPTADOR_H
#define _ADAPTADOR_H

#include "interconexao.hpp"

class Adaptador : public Elemento
{		
	public:						
		Adaptador(string nome, Elemento::Posicao posicaoInicial, Elemento::Posicao posicaoFinal) :
		Elemento(nome, posicaoInicial, posicaoFinal) {} ;
		
		void transmitirCarga(int carga) ;
		
		// A carga emitida para cada interconexão é dada pela fórmula:
		// (carga * max_interJ) / (max_inter1 + max_inter2 + ..... + max_interN)
		void emitirCarga() ;

		void receberCarga(int carga) ;

		void draw(SDL_Renderer* gRenderer, int spacing, int min_x_y) ;		
};

#endif // _ADAPTADOR_H
