#ifndef _ELEMENTO_H
#define _ELEMENTO_H

#include <iostream>
#include <string>
#include <set>
#include <stdio.h>
#include <assert.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_ttf.h>

using namespace std;

class Elemento
{	
	public:
		typedef struct Posicao
		{
			int x;
			int y;
		}Posicao;

	// Variáveis de instância.	
	private:
		string nome;
		Posicao posicaoInicial;
		Posicao posicaoFinal;
		int carga;
		set<Elemento*> entradas;
		set<Elemento*> saidas;

	public:
		// Destructor.	
		~Elemento() {};
		
		// Constructor.
		Elemento(string nome, Posicao posicaoInicial, Posicao posicaoFinal);

		// Gets e sets.	
		string getNome();
		Posicao getPosicaoInicial();
		Posicao getPosicaoFinal();
		set<Elemento*> * getEntradas();
		set<Elemento*> * getSaidas();
		int getCarga();
		void setCarga(int carga);
		
		// Métodos virtuais.
		virtual void Delete() = 0;
		
		virtual void receberCarga(int carga) = 0 ; 

		virtual void emitirCarga(int carga) = 0;
		
		// No maioria dos casos esse método transmite a carga, ou seja, recebe e reenvia.
		// Porém, no caso da cidade esse método somente recebe a carga.
		virtual void transmitirCarga(int carga) = 0 ;
				
		virtual void draw(SDL_Renderer* gRenderer, SDL_Surface* screen_sf, TTF_Font* font, Posicao spacing, Posicao min_x_y) {};
};

#endif // _ELEMENTO_H
