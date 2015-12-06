#ifndef _CIDADE_H
#define _CIDADE_H

#include "elemento.hpp"

class Cidade : public Elemento
{
	private:
		int recursoNecessario;
		
	public:
		Cidade(string nome, Elemento::Posicao posicaoInicial, Elemento::Posicao posicaoFinal, int recursoNecessario) : 
				Elemento(nome, posicaoInicial, posicaoFinal)
		{
			this->recursoNecessario = recursoNecessario;
		};
		
		~Cidade(){};

		int getRecursoNecessario();

		void consumirCarga();
		
		// métodos da super classe
		
		void Delete();
		
		// Esse método é equivalente ao receber somente no caso da cidade. Isso se deve a interconexão
		// sempre chamar o método transmitir carga (do método que vai receber a carga) para emitir a carga.
		void transmitirCarga(int carga);
		
		void receberCarga(int carga);
		
		void emitirCarga(int carga);
		
		void draw(SDL_Renderer* gRenderer, SDL_Surface* screen_sf, TTF_Font* font, Elemento::Posicao spacing, Elemento::Posicao min_x_y) ;
};

#endif // _CIDADE_H
