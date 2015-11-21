#ifndef _RELATORIO_H
#define _RELATORIO_H

#include <iostream>
#include "cidade.hpp"
#include <set>

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
		static set<Cidade*> cidadesMenosRecurso;
		static int tempoCidadesSemRecurso;
		static set<Cidade*> cidadesAbaixo30;
		static int tempoCidadesAbaixo30;
		
		static void mostrarRelatorio();		
};

#endif // _RELATORIO_H
