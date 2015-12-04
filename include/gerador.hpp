#ifndef _GERADOR_H
#define _GERADOR_H

#include "interconexao.hpp"

class Gerador : public Elemento
{
	private:
		int recursoProduzido;
		int custoGerador;
		
	public:
		Gerador(string nome, Elemento::Posicao posicaoInicial, Elemento::Posicao posicaoFinal, int recursoProduzido, int custoGerador) :
		Elemento(nome, posicaoInicial, posicaoFinal)
		{
			this->recursoProduzido = recursoProduzido;
			this->custoGerador = custoGerador;
		};

		int getRecursoProduzido() ;

		int getCustoGerador() ;

		void emitirCarga() ;

		void draw(SDL_Renderer* gRenderer, int spacing, int min_x_y) ;
};

#endif // _GERADOR_H
