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

void Cidade::draw(SDL_Renderer* gRenderer, int spacing, int min_x_y) {
	assert(spacing < 600);
	uint32_t r = 0x00, g = 0xFF, b = 0;

	// Caso a carga recebida seja menor que a carga necessária, porém maior que 30%.
	if (this->getCarga() < this->getRecursoNecessario() && this->getCarga() > 0.3 * (float) this->getRecursoNecessario()) {
		// Amarelo, e não me pergunte porque tem vermelho.
		r = 0xFF; g = 0xFF; b = 0;
	}
	// Caso a carga recebida seja menor que 30% da carga necessária.
	else if (this->getCarga() < 0.3 * (float) this->getRecursoNecessario()) {
		r = 0xFF; g = 0; b = 0;
	}
	SDL_Rect fillRect = { log(1 + this->getPosicaoInicial().x - min_x_y) * spacing,  log(1 + this->getPosicaoInicial().y - min_x_y) * spacing, 60, 60};
    SDL_SetRenderDrawColor( gRenderer, r, g, b, 0xFF );        
    SDL_RenderFillRect( gRenderer, &fillRect );
}
