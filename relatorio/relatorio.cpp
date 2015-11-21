#include "relatorio.hpp"

// Definicao das variaveis globais estaticas
int Relatorio::tempoTotal;
int Relatorio::custoTotal;
int Relatorio::numGeradores;
int Relatorio::cargaTotalProduzida;
int Relatorio::numCidades;
int Relatorio::cargaTotalConsumida;
int Relatorio::tamanhoTotalInterconexoes;
int Relatorio::numFalhasInterconexoes;
int Relatorio::numCidadesMenosRecurso;
int Relatorio::tempoCidadesSemRecurso;
int Relatorio::numCidadesAbaixo30;
int Relatorio::tempoCidadesAbaixo30;

void Relatorio::mostrarRelatorio()
{
	cout << "\nTempo total da simulacao: " 			<< Relatorio::tempoTotal << 
			"\nCusto total na simulacao: " 			<< Relatorio::custoTotal <<
			"\nTotal de geradores: " 	   			<< Relatorio::numGeradores <<
			"\nEnergia total gerada: "     			<< Relatorio::cargaTotalProduzida <<
			"\nTotal de cidades: "         			<< Relatorio::numCidades <<
			"\nEnergia total gasta pelas cidades: " << Relatorio::cargaTotalConsumida <<
			"\nTamanho total das interconexoes: "   << Relatorio::tamanhoTotalInterconexoes <<
			"\nNumero de falhas nas interconexoes: "<< Relatorio::numFalhasInterconexoes <<
			"\nNumero de cidades que ficaram com menos recurso que o necessario: " 
													<< Relatorio::numCidadesMenosRecurso <<
			"\nTempo que ficaram sem recurso: "     << Relatorio::tempoCidadesSemRecurso <<
			"\nNumero de cidades que ficaram com menos de 30p.c. dos recursos: "
													<< Relatorio::numCidadesAbaixo30 <<
			"\nTempo que ficaram com menos de 30p.c. de recurso: "
													<< Relatorio::tempoCidadesAbaixo30 
													<< endl;
}