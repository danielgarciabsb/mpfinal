#ifndef _CONTROLADORA_H
#define _CONTROLADORA_H

#include "repositorio.hpp"
#include "relatorio.hpp"

#define TAMANHO_ELEMENTOS 70
#define SCREEN_WIDTH 700
#define SCREEN_HEIGHT 700

class Controladora
{
	private:
		bool quit = false;
		SDL_Event e;
		bool success = true;
		SDL_Window* window = NULL;
		SDL_Surface* screen_sf = NULL;
		SDL_Renderer* gRenderer = NULL;
		SDL_Texture* gTexture = NULL;
		TTF_Font* font;
		
		Elemento::Posicao pontoMinimo;
		Elemento::Posicao spacing;
	
	public:
		bool inicializarAmbiente();
		Repositorio::rLeitura lerElementos(string nomeArq);
		void mostrarElementos();
		void descobrirConexoes();
		void calcularPropriedadesDiagrama();
		void rodarSimulacao(int segundos);
		void update();
		void render();
		void handleEvents();
		void finalizar();
		
		Controladora();
		
};

#endif // _CONTROLADORA_H
