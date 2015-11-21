#ifndef _ELEMENTO_H
#define _ELEMENTO_H

#include <iostream>
#include <string>
#include <set>
#include "relatorio.hpp"
using namespace std;

class Elemento
{
	public:
		typedef struct Posicao
		{
			int x;
			int y;
		}Posicao;
		
		string getNome();
		Posicao getPosicaoInicial();
		Posicao getPosicaoFinal();
		set<Elemento*> * getSaidas();
		int getCarga();
		void setCarga(int carga);
		
	private:
		string nome;
		Posicao posicaoInicial;
		Posicao posicaoFinal;
		int carga;
		set<Elemento*> saidas;
				
	public:		
		~Elemento() {};
		
		Elemento(string nome, Posicao posicaoInicial, Posicao posicaoFinal)
		{
			this->nome = nome;
			this->posicaoInicial = posicaoInicial;
			this->posicaoFinal = posicaoFinal;
		};
		
		virtual void receberCarga(int carga) {} ; 
		virtual void emitirCarga() {} ;
		
		virtual void transmitirCarga(int carga)
		{
			cout << "\t- " << this->getNome() << " transmitiu " << carga << " de carga." << endl;
		};
				
		virtual void draw() {} ;
};

#endif // _ELEMENTO_H
