#include "gerador.hpp"

int Gerador::getRecursoProduzido() { return this->recursoProduzido;}

int Gerador::getCustoGerador() { return this->custoGerador;}

void Gerador::emitirCarga(int carga)
{
	set<Elemento*> * saidas = this->getSaidas();
	int totalCargaSaidas = 0;
	float proporcao;

	set<Elemento*>::iterator iSaidas;
	for(iSaidas = saidas->begin(); iSaidas != saidas->end(); iSaidas++)
	{
		if(((Interconexao*)(*iSaidas))->isWorking())
			totalCargaSaidas += ((Interconexao*)(*iSaidas))->getCapacidadeMax();
	}
		
	for(iSaidas = saidas->begin(); iSaidas != saidas->end(); iSaidas++)
	{
		proporcao = (float) ((Interconexao*)(*iSaidas))->getCapacidadeMax() / totalCargaSaidas;

		(*iSaidas)->transmitirCarga((int) (proporcao * carga));
	}
}

void Gerador::draw(SDL_Renderer* gRenderer, SDL_Surface* screen_sf, TTF_Font* font, int spacing, int min_x_y) {
	const char* string = NULL;
	SDL_Color preto = {00, 00, 00, 0xFF};

	// Superfície com o texto.
	SDL_Surface *text_sf = NULL;

	// Posição do vertice superior do triângulo.
	// Os elementos são impressos em escala logarítmica. Por isso esses "logs".
	// Se quiser deslocar a posição a ser impressa é só somar ou diminuir a quantidade
	// de pixels de pos_x ou pos_y.
	int pos_first_point_x = log(1 + this->getPosicaoInicial().x - min_x_y) * spacing;
	int pos_first_point_y = log(1 + this->getPosicaoInicial().y - min_x_y) * spacing + 60;

	//// Imprimindo a figura geométrica.
	filledTrigonColor(gRenderer, pos_first_point_x, pos_first_point_y, pos_first_point_x + 30, pos_first_point_y - 60, 
					  pos_first_point_x + 60, pos_first_point_y,  0xFF00FF00);

	//// Imprimindo texto.
	// Criando a superfície com o texto.
	string = (this->getNome() + "(" + std::to_string(this->getPosicaoInicial().x) + "," + 
	  		  std::to_string(this->getPosicaoInicial().y) + ")").c_str();
	text_sf = TTF_RenderText_Solid(font, string, preto);

	//Setup the location on the screen to blit to
	SDL_Rect rect = { pos_first_point_x , pos_first_point_y - 60, 0, 0};

	//Blit text_surface surface to the screen surface
	SDL_BlitSurface(text_sf, NULL, screen_sf, &rect);

	//Free the text surface
	SDL_FreeSurface(text_sf);

	string = ("Carga:" + std::to_string(this->recursoProduzido)).c_str();
	text_sf = TTF_RenderText_Solid(font, string , preto);
	rect = { pos_first_point_x , pos_first_point_y - 60 + 13, 0, 0};
	SDL_BlitSurface(text_sf, NULL, screen_sf, &rect);
	SDL_FreeSurface(text_sf);

	string = ("Custo:" + std::to_string(this->custoGerador)).c_str();
	text_sf = TTF_RenderText_Solid(font, string , preto);
	rect = { pos_first_point_x , pos_first_point_y - 60 + 26, 0, 0};
	SDL_BlitSurface(text_sf, NULL, screen_sf, &rect);
	SDL_FreeSurface(text_sf);
}