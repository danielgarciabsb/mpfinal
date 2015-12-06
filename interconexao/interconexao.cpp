#include "interconexao.hpp"
#include <cstdlib>

void Interconexao::Delete()
{
	this->~Interconexao();
}
	
//string Interconexao::getNome() { return this->nome; }

//Elemento::Posicao Interconexao::getPosicaoInicial() { return this->posicaoInicial; }

//Elemento::Posicao Interconexao::getPosicaoFinal() { return ((Elemento* )this)->getPosicaoFinal(); }

int Interconexao::getCapacidadeMax() { return this->capacidadeMax; }

float Interconexao::getChanceFalha() { return this->chanceFalha; }

int Interconexao::getTempoConserto() { return this->tempoConserto; }

int Interconexao::getCustoConserto() { return this->custoConserto; }

void Interconexao::aplicarChanceDeFalha()
{
	float num = ((float) rand()) / RAND_MAX;
	
	// Trata a falha de um interconexão.
	if((this->chanceFalha > 0.) && (num <= this->chanceFalha) && this->working)
	{
		cout << "- " << this->getNome() << " falhou" << endl;
		Relatorio::numFalhasInterconexoes++;
		Relatorio::custoTotal += this->custoConserto;
		this->previsaoTerminoConserto = this->tempoConserto;
		this->working = false;
	}
	else if((this->previsaoTerminoConserto)-- == 0)
		this->working = true;
	else if(this->previsaoTerminoConserto > 0)
	{
		cout << "- " << this->getNome() 
		<< " esta em conserto (previsao de termino: " << this->previsaoTerminoConserto 
		<< ")" << endl;
	}
		
	if(this->getSaidas()->size() == 0)
		this->working = false;
}

bool Interconexao::isWorking() { return this->working; }

void Interconexao::transmitirCarga(int carga)
{
	if(!this->isWorking())
		return;
		
	int cargaJaTransmitida = this->getCarga();
	
	// Mostrar carga que passou pela interconexao na transmissao atual
	if(carga + cargaJaTransmitida > this->capacidadeMax)
		Elemento::transmitirCarga(this->capacidadeMax - cargaJaTransmitida);
	else
		Elemento::transmitirCarga(carga);
		
	// Receber e emitir carga
	this->receberCarga(carga);
	this->emitirCarga(this->getCarga() - cargaJaTransmitida);
}

void Interconexao::emitirCarga(int carga)
{		
	set<Elemento*> * saidas = this->getSaidas();
	
	set<Elemento*>::iterator iSaidas;
	for(iSaidas = saidas->begin(); iSaidas != saidas->end(); iSaidas++)
		(*iSaidas)->transmitirCarga(carga);
	
} ;

void Interconexao::receberCarga(int carga) 
{ 	
	// Caso a interconeão receba uma carga maior que sua capacidade.
	if(carga + this->getCarga() > this->capacidadeMax)
		this->setCarga(this->capacidadeMax);
	// Caso a interconeão receba uma carga menor que sua capacidade.
	else				
		this->setCarga(carga + this->getCarga());
	
	
} ;

void Interconexao::draw(SDL_Renderer* gRenderer, SDL_Surface* screen_sf, TTF_Font* font, Elemento::Posicao spacing, Elemento::Posicao min_x_y) {
	assert(spacing.x < 600 && spacing.y < 600);
	const char* string = NULL;
	SDL_Color preto = {00, 00, 00, 0xFF};

	// Superfície com o texto.
	SDL_Surface *text_sf = NULL;

	// Posição do canto superior esquerdo do quadrado.
	// Os elementos são impressos em escala logarítmica. Por isso esses "logs".
	// Se quiser deslocar a posição a ser impressa é só somar ou diminuir a quantidade
	// de pixels de pos_x ou pos_y.
	int	pos_ini_x = log(1 + this->getPosicaoInicial().x - min_x_y.x) * spacing.x + 30;
	int pos_ini_y = log(1 + this->getPosicaoInicial().y - min_x_y.y) * spacing.y + 30;
	int pos_fi_x = log(1 + this->getPosicaoFinal().x - min_x_y.x) * spacing.x + 30;
	int pos_fi_y = log(1 + this->getPosicaoFinal().y - min_x_y.y) * spacing.y + 30;

	uint32_t color = 0xFF00FF00;
	
	if (this->isWorking() == false)
		color = 0xFF0000FF;
	lineColor(gRenderer, pos_ini_x, pos_ini_y, pos_fi_x, pos_fi_y, color);
	
	string = (this->getNome() + "-> " + to_string(this->getCarga())).c_str();
			  
	text_sf = TTF_RenderText_Solid(font, string, preto);
	SDL_Rect rect = { (pos_ini_x + pos_fi_x - 30) / 2, (pos_ini_y + pos_fi_y) / 2, 0, 0 };
	SDL_BlitSurface(text_sf, NULL, screen_sf, &rect);
	SDL_FreeSurface(text_sf);

}
