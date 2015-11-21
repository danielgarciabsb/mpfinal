#ifndef _RELATORIO_H
#define _RELATORIO_H

#include <iostream>

using namespace std;

class Relatorio
{
	public:
		static int tempoTotal;
		static int custoTotal;
		static int numGeradores;
		static int cargaTotalProduzida;
		static int numCidades;
		static int cargaTotalConsumida;
		static int tamanhoTotalInterconexoes;
		static int numFalhasInterconexoes;
		static int numCidadesMenosRecurso;
		static int numCidadesSemRecurso;
		static int tempoCidadesSemRecurso;
		static int numCidadesAbaixo30;
		static int tempoCidadesAbaixo30;
		
		static void mostrarRelatorio();		
};

#endif // _RELATORIO_H
