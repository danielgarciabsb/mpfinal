#include "adaptador.hpp"

void Adaptador::Delete()
{
	this->~Adaptador();
}

void Adaptador::transmitirCarga(int carga)
{
	this->receberCarga(carga);
	Elemento::transmitirCarga(carga);
	this->emitirCarga(carga);
}

void Adaptador::emitirCarga(int carga)
{ 
	set<Elemento*> * saidas = this->getSaidas();
	int totalCargaSaidas = 0;
	float proporcao;

	// Calcula a capacidade total das interconẽxões.
	set<Elemento*>::iterator iSaidas;
	for(iSaidas = saidas->begin(); iSaidas != saidas->end(); iSaidas++)
	{
		if(((Interconexao*)(*iSaidas))->isWorking())
			totalCargaSaidas += ((Interconexao*)(*iSaidas))->getCapacidadeMax();
	}

	// Calcula a proporção de carga recebida por cada interconexão.	
	for(iSaidas = saidas->begin(); iSaidas != saidas->end(); iSaidas++)
	{
		proporcao = (float) ((Interconexao*)(*iSaidas))->getCapacidadeMax() / totalCargaSaidas;

		(*iSaidas)->transmitirCarga((int) (proporcao * carga));
	}
}

void Adaptador::receberCarga(int carga)
{
	this->setCarga(carga + this->getCarga()); 
}

void Adaptador::draw(SDL_Renderer* gRenderer, SDL_Surface* screen_sf, TTF_Font* font, Elemento::Posicao spacing, Elemento::Posicao min_x_y)
{
	assert(spacing.x < 600 && spacing.y < 600);
	const char* string = NULL;
	SDL_Color preto = {00, 00, 00, 0xFF};

	// Superfície com o texto.
	SDL_Surface *text_sf = NULL;

	// Posição do centro do círculo.
	// Os elementos são impressos em escala logarítmica. Por isso esses "logs".
	// Se quiser deslocar a posição a ser impressa é só somar ou diminuir a quantidade
	// de pixels de pos_x ou pos_y.
	int	pos_center_x = log(1 + this->getPosicaoInicial().x - min_x_y.x) * spacing.x + 30;
	int pos_center_y = log(1 + this->getPosicaoInicial().y - min_x_y.y) * spacing.y + 30;

	filledCircleColor(gRenderer, pos_center_x, pos_center_y, 30, 0XFF00FF00);

	//// Imprimindo texto.
	// Criando a superfície com o texto.
	string = (this->getNome() + "(" + std::to_string(this->getPosicaoInicial().x) + "," + 
	  		  std::to_string(this->getPosicaoInicial().y) + ")").c_str();
	text_sf = TTF_RenderText_Solid(font, string, preto);

	//Setup the location on the screen to blit to
	SDL_Rect rect = { pos_center_x - 30, pos_center_y - 30, 0, 0};

	//Blit text_surface surface to the screen surface
	SDL_BlitSurface(text_sf, NULL, screen_sf, &rect);

	//Free the text surface
	SDL_FreeSurface(text_sf);

	string = ("Carga: " + to_string(this->getCarga())).c_str();
	text_sf = TTF_RenderText_Solid(font, string, preto);
	rect = { pos_center_x - 30, pos_center_y - 30 + 13, 0, 0 };
	SDL_BlitSurface(text_sf, NULL, screen_sf, &rect);
	SDL_FreeSurface(text_sf);
}
