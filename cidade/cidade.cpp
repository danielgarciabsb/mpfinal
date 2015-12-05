#include "cidade.hpp"

int Cidade::getRecursoNecessario() { return this->recursoNecessario; }

void Cidade::consumirCarga()
{
	this->setCarga(0);
}

void Cidade::transmitirCarga(int carga) 
{
	this->receberCarga(carga);
 	return; 
}

void Cidade::receberCarga(int carga) 
{ 
	//if(this->getCarga() + carga > this->recursoNecessario)
		//this->setCarga(this->recursoNecessario);
	//else
		this->setCarga(this->getCarga() + carga); 
		
	cout << "- " << this->getNome() << " recebeu +" << carga << " de carga (Total: " << this->getCarga() << ")" << endl;
}

void Cidade::draw(SDL_Renderer* gRenderer, SDL_Surface* screen_sf, TTF_Font* font, int spacing, int min_x_y) {
	assert(spacing < 600);
	const char* string = NULL;
	SDL_Color preto = {00, 00, 00, 0xFF};

	// Superfície com o texto.
	SDL_Surface *text_sf = NULL;

	// Váriaveis utilizadas para definir a cor impressa.
	uint32_t r = 0x00, g = 0xFF, b = 0;

	// Posição do canto superior esquerdo do quadrado.
	// Os elementos são impressos em escala logarítmica. Por isso esses "logs".
	// Se quiser deslocar a posição a ser impressa é só somar ou diminuir a quantidade
	// de pixels de pos_x ou pos_y.
	int	pos_x = log(1 + this->getPosicaoInicial().x - min_x_y) * spacing;
	int pos_y = log(1 + this->getPosicaoInicial().y - min_x_y) * spacing;
	
	// Caso a carga recebida seja menor que a carga necessária, porém maior que 30%.
	if (this->getCarga() < this->getRecursoNecessario() && this->getCarga() > 0.3 * (float) this->getRecursoNecessario()) {
		// Amarelo, e não me pergunte porque tem vermelho.
		r = 0xFF; g = 0xFF; b = 0;
	}
	// Caso a carga recebida seja menor que 30% da carga necessária.
	else if (this->getCarga() < 0.3 * (float) this->getRecursoNecessario()) {
		r = 0xFF; g = 0; b = 0;
	}

	//// Imprimindo a figura geométrica.
	SDL_Rect fillRect = { pos_x,  pos_y, 60, 60};
    SDL_SetRenderDrawColor( gRenderer, r, g, b, 0xFF );        
    SDL_RenderFillRect( gRenderer, &fillRect );

	//// Imprimindo texto.
	// Criando a superfície com o texto.
	string = (this->getNome() + "(" + std::to_string(this->getPosicaoInicial().x) + "," + 
	  		  std::to_string(this->getPosicaoInicial().y) + ")").c_str();
	text_sf = TTF_RenderText_Solid(font, string, preto);

	//Setup the location on the screen to blit to
	SDL_Rect rect = { pos_x , pos_y , 0, 0};

	//Blit text_surface surface to the screen surface
	SDL_BlitSurface(text_sf, NULL, screen_sf, &rect);

	//Free the text surface
	SDL_FreeSurface(text_sf);

	string = "Consumo:";
	text_sf = TTF_RenderText_Solid(font, string, preto);
	rect = { pos_x , pos_y + 13 , 0, 0};
	SDL_BlitSurface(text_sf, NULL, screen_sf, &rect);
	SDL_FreeSurface(text_sf);

	string = std::to_string(this->recursoNecessario).c_str();
	text_sf = TTF_RenderText_Solid(font, string, preto);
	rect = { pos_x , pos_y + 26 , 0, 0};
	SDL_BlitSurface(text_sf, NULL, screen_sf, &rect);
	SDL_FreeSurface(text_sf);
}
