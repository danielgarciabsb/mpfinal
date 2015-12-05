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

void Gerador::draw(SDL_Renderer* gRenderer, int spacing, int min_x_y) {
	// Psição do vertice superior do triângulo.
	// Os elementos são impressos em escala logarítmica. Por isso esses "logs".
	// Se quiser deslocar a posição a ser impressa é só somar ou diminuir a quantidade
	// de pixels de pos_x ou pos_y.
	int pos_first_point_x = log(1 + this->getPosicaoInicial().x - min_x_y) * spacing;
	int pos_first_point_y = log(1 + this->getPosicaoInicial().y - min_x_y) * spacing + 60;

	filledTrigonColor(gRenderer, pos_first_point_x, pos_first_point_y, pos_first_point_x + 30, pos_first_point_y - 60, 
					  pos_first_point_x + 60, pos_first_point_y,  0xFF00FF00);
}