#ifndef _CIDADE_H
#define _CIDADE_H

#include "elemento.hpp"

class Cidade : public Elemento
{
	private:
		int recursoNecessario;
		
	public:
		Cidade(string nome, Elemento::Posicao posicaoInicial, Elemento::Posicao posicaoFinal, int recursoNecessario) : 
				Elemento(nome, posicaoInicial, posicaoFinal)
		{
			this->recursoNecessario = recursoNecessario;
		};

		int getRecursoNecessario();

		void consumirCarga();
		
		// Esse método é equivalente ao receber somente no caso da cidade. Isso se deve a interconexão
		// sempre chamar o método transmitir carga (do método que vai receber a carga) para emitir a carga.
		void transmitirCarga(int carga) ;
		
		void receberCarga(int carga) ;
		
		// A cidade não emite carga.
		void emitirCarga() { return; } ;
};

#endif // _CIDADE_H
