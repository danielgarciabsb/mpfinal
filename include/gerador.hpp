#ifndef _GERADOR_H
#define _GERADOR_H

#include "interconexao.hpp"

class Gerador : public Elemento
{
	private:
		int recursoProduzido;
		int custoGerador;
		
	public:
		Gerador(string nome, Posicao posicaoInicial, Posicao posicaoFinal, int recursoProduzido, int custoGerador) :
		Elemento(nome, posicaoInicial, posicaoFinal)
		{
			this->recursoProduzido = recursoProduzido;
			this->custoGerador = custoGerador;
		};

		int getRecursoProduzido() ;

		int getCustoGerador() ;

		void emitirCarga(int carga) ;
};

#endif // _GERADOR_H
