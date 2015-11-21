#include "interconexao.hpp"
#include <cstdlib>

//string Interconexao::getNome() { return this->nome; }

//Elemento::Posicao Interconexao::getPosicaoInicial() { return this->posicaoInicial; }

//Elemento::Posicao Interconexao::getPosicaoFinal() { return ((Elemento* )this)->getPosicaoFinal(); }

//int Interconexao::getCapacidadeMax() { return this->capacidadeMax; }

float Interconexao::getChanceFalha() { return this->chanceFalha; }

int Interconexao::getTempoConserto() { return this->tempoConserto; }

int Interconexao::getCustoConserto() { return this->custoConserto; }

void Interconexao::aplicarChanceDeFalha()
{
	float num = ((float) rand()) / RAND_MAX;
	
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

//bool Interconexao::isWorking() { return this->working; }
