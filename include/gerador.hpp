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
		
		~Gerador(){};

		int getRecursoProduzido() ;

		int getCustoGerador() ;

		//metodos da super classe
		
		void Delete();
		
		void transmitirCarga(int carga);
		
		void receberCarga(int carga);
		
		void emitirCarga(int carga);

		void draw(SDL_Renderer* gRenderer, SDL_Surface* screen_sf, TTF_Font* font, Elemento::Posicao spacing, Elemento::Posicao min_x_y) ;
};

#endif // _GERADOR_H
