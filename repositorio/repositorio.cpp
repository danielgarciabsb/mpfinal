#include "repositorio.hpp"

set<Elemento*> Repositorio::elementos;
set<Gerador*> Repositorio::geradores;
set<Adaptador*> Repositorio::adaptadores;
set<Cidade*> Repositorio::cidades;
set<Interconexao*> Repositorio::interconexoes;

set<Elemento*> Repositorio::elementosDesconectados;
set<Cidade*> Repositorio::cidadesDesconectadas;
set<Gerador*> Repositorio::geradoresDesconectados;
set<Adaptador*> Repositorio::adaptadoresDesconectados;
set<Interconexao*> Repositorio::interconexoesDesconectadas;

//int Repositorio::numGeradores;

Repositorio::rLeitura Repositorio::lerElementos(string nomeArquivo)
{
	ifstream fin(nomeArquivo.c_str());
	
	if(! fin.is_open())
		return ARQUIVO_INEXISTENTE;
		
	char identificador;
	
	string nome;
	Elemento::Posicao posicao;
	
	Gerador* g;
	Cidade* c;
	Adaptador* a;
	Interconexao* i;
	
	while(fin >> identificador)
	{
		if(identificador != 'G' && identificador != 'A' && identificador != 'C' && identificador != 'I')
			return FORMATO_INVALIDO;
			
		switch(identificador)
		{
			case 'G':
				int recursoProduzido, custoGerador;
				
				fin >> nome >> posicao.x >> posicao.y >> recursoProduzido >> custoGerador;
				
				if(fin.fail())
					return FORMATO_INVALIDO;
				
				g = new Gerador(nome, posicao, posicao, recursoProduzido, custoGerador);
				
				Repositorio::getGeradores()->insert(g);
				Repositorio::getElementos()->insert(g);
				
				Relatorio::numGeradores++;
				
				break;
			
			case 'C':
				int recursoNecessario;
				
				fin >> nome >> posicao.x >> posicao.y >> recursoNecessario;
				
				if(fin.fail())
					return FORMATO_INVALIDO;

				c = new Cidade(nome, posicao, posicao, recursoNecessario);
				Repositorio::getCidades()->insert(c);
				Repositorio::getElementos()->insert(c);
				
				Relatorio::numCidades++;
				
				break;
				
			case 'A':
				
				fin >> nome >> posicao.x >> posicao.y;

				if(fin.fail())
					return FORMATO_INVALIDO;
					
				a = new Adaptador(nome, posicao, posicao);
				Repositorio::getAdaptadores()->insert(a);
				Repositorio::getElementos()->insert(a);
				 
				break;
				 
			case 'I':
				Elemento::Posicao posicaoInicial, posicaoFinal;
				int capacidadeMax, tempoConserto, custoConserto;
				float chanceFalha;
				
				fin >> nome >> posicaoInicial.x >> posicaoInicial.y >> posicaoFinal.x >> posicaoFinal.y 
					>> capacidadeMax >> chanceFalha >> tempoConserto >> custoConserto;
					
				if(fin.fail())
					return FORMATO_INVALIDO;

				i = new Interconexao(nome, posicaoInicial, posicaoFinal,
										capacidadeMax, chanceFalha, tempoConserto, custoConserto);
										
				Repositorio::getInterconexoes()->insert(i);
				Repositorio::getElementos()->insert(i);
				
				Relatorio::tamanhoTotalInterconexoes += sqrt( pow((posicaoInicial.x - posicaoFinal.x), 2) + 
														pow((posicaoInicial.y - posicaoFinal.y), 2) );
				
				break;
		}
	}
	
	return OK;
}

