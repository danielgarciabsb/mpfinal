#include "projetoFinal_testes.hpp"
#include "projetoFinal.hpp"
#include <ctime>
#include <cstdlib>

int main(int argc, char **argv)
{
	#if _TEST_MODE == 1
	
	
	testing::InitGoogleTest(&argc, argv);
	
	UnitTest& unit_test = *UnitTest::GetInstance();
	TestEventListeners& listeners = unit_test.listeners();
	
	delete listeners.Release(listeners.default_result_printer());
	
	listeners.Append(new Log((char*) "logTestes.txt", (char*) "logErros.txt"));
	
	return RUN_ALL_TESTS();
	
	#endif
	
	srand(time(NULL));
	
	// Metodo estatico para ler os elementos da rede e instanciar os objetos
	Repositorio::lerElementos("rede_distribuicao.conf");
	
	// Referenciar os objetos para uso no programa
	set<Elemento*> elementos = *(Repositorio::getElementos());
	set<Cidade*> cidades = *(Repositorio::getCidades());
	set<Gerador*> geradores = *(Repositorio::getGeradores());
	set<Adaptador*> adaptadores = *(Repositorio::getAdaptadores());
	set<Interconexao*> interconexoes = *(Repositorio::getInterconexoes());
	
	set<Elemento*> elementosDesconectados = *(Repositorio::getElementosDesconectados());
	set<Cidade*> cidadesDesconectadas = *(Repositorio::getCidadesDesconectadas());
	set<Gerador*> geradoresDesconectados = *(Repositorio::getGeradoresDesconectados());
	set<Adaptador*> adaptadoresDesconectados = *(Repositorio::getAdaptadoresDesconectados());
	set<Interconexao*> interconexoesDesconectadas = *(Repositorio::getInterconexoesDesconectadas());
	
	
	set<Elemento*>::iterator iElementos;
	set<Cidade*>::iterator iCidades;
	set<Gerador*>::iterator iGeradores;
	set<Adaptador*>::iterator iAdaptadores;
	set<Interconexao*>::iterator iInterconexoes;
	
	// Mostrar todos os elementos da rede
	cout << "\n\t>> Elementos:" << endl;
	
	for(iElementos = elementos.begin(); iElementos != elementos.end(); iElementos++)
	{
		cout << "\t\t- " << (*iElementos)->getNome() << endl;
	}
		
	// Descobrir as conexoes entre os elementos
	cout << "\n\n\t>> Calculando conexoes..." << endl;
	
	for(iInterconexoes = interconexoes.begin(); iInterconexoes != interconexoes.end(); iInterconexoes++)
	{		
		// Conectar saidas dos Geradores às interconexoes
		for(iGeradores = geradores.begin(); iGeradores != geradores.end(); iGeradores++)
		{
			// Se a posicao do gerador for a mesma que a posicao inicial da interconexao da iteracao:
			//		-> entao a saida do gerador eh a interconexao da iteracao
			//		-> e a entrada da interconexao eh o gerador da iteracao
			// G ------> I (o contrario nao eh possivel)
			if((*iGeradores)->getPosicaoFinal().x == (*iInterconexoes)->getPosicaoInicial().x &&
				(*iGeradores)->getPosicaoFinal().y == (*iInterconexoes)->getPosicaoInicial().y)
			{
				(*iGeradores)->getSaidas()->insert(*iInterconexoes);
				(*iInterconexoes)->getEntradas()->insert(*iGeradores);
			}
		} // fim do For: nesse ponto, os geradores ja possuem saidas definidas
		
		// Conectar Adaptadores às interconexoes
		for(iAdaptadores = adaptadores.begin(); iAdaptadores != adaptadores.end(); iAdaptadores++)
		{
			// Se a posicao do adaptador for a mesma que a posicao inicial da interconexao da iteracao:
			//		-> entao a saida do adaptador eh a interconexao da iteracao
			//		-> e a entrada da interconexao eh o adaptador da iteracao
			// A -------> I
			if((*iAdaptadores)->getPosicaoFinal().x == (*iInterconexoes)->getPosicaoInicial().x &&
				(*iAdaptadores)->getPosicaoFinal().y == (*iInterconexoes)->getPosicaoInicial().y)
			{
				(*iAdaptadores)->getSaidas()->insert(*iInterconexoes);
				(*iInterconexoes)->getEntradas()->insert(*iAdaptadores);
			}
			
			// Se a posicao do adaptador for a mesma que a posicao final da interconexao da iteracao,
			//		E
			// Se a interconexao nao tiver uma saida ja definida (interconexao possui apenas 1 saida):
			//		-> entao a saida da interconexao eh o adaptador da iteracao
			//		-> e a entrada do adaptador eh a interconexao da iteracao
			// I -------> A
			if((*iAdaptadores)->getPosicaoFinal().x == (*iInterconexoes)->getPosicaoFinal().x &&
				(*iAdaptadores)->getPosicaoFinal().y == (*iInterconexoes)->getPosicaoFinal().y &&
				(*iInterconexoes)->getSaidas()->size() == 0)
			{
				(*iInterconexoes)->getSaidas()->insert(*iAdaptadores);
				(*iAdaptadores)->getEntradas()->insert(*iInterconexoes);
			}			
			// Nota: como os geradores nao possuem entradas (apenas saidas), nesse ponto, apenas adaptadores
			// podem ser saidas das interconexoes. Se, por acaso, alguma cidade ou outra interconexao estiver
			// em posicao de ligacao com alguma interconexao que ja tenha uma saida definida, 
			// a preferencia sera dada aos adaptadores, ignorando que aquela cidade ou outra interconexao esteja
			// conectada a interconexao.
			// DISCUTIR A QUAL ELEMENTO DAREMOS PREFERENCIA NO CASO DE UMA INTERCONEXAO ESTIVER CONECTADA A MAIS 
			// DE UM ELEMENTO.
		}// fim das conexoes entre adaptadores e interconexoes
		
		// Conectar Cidades às interconexoes
		for(iCidades = cidades.begin(); iCidades != cidades.end(); iCidades++)
		{
			// Se a posicao da cidade for a mesma que a posicao final da interconexao da iteracao
			//   E
			// Se a saida da interconexao nao tiver uma saida definida:
			//		-> entao a saida da interconexao eh a cidade da iteracao
			//		-> e a entrada da cidade eh a interconexao da iteracao
			// I -------> C (o contrario nao eh possivel)
			if((*iCidades)->getPosicaoFinal().x == (*iInterconexoes)->getPosicaoFinal().x &&
				(*iCidades)->getPosicaoFinal().y == (*iInterconexoes)->getPosicaoFinal().y &&
				(*iInterconexoes)->getSaidas()->size() == 0)
			{
				(*iInterconexoes)->getSaidas()->insert(*iCidades);
				(*iCidades)->getEntradas()->insert(*iInterconexoes);
			}
			// Nota: Cidades nao possuem saidas (apenas entradas), entao a unica possibilidade de conexao
			// nesse caso eh a cidade sendo saida da interconexao
		}// fim das conexoes entre cidades e interconexoes
		
		// Conectar interconexoes às outras interconexoes
		set<Interconexao*>::iterator iOutras;
		for(iOutras = interconexoes.begin(); iOutras != interconexoes.end(); iOutras++)
		{
			// Se a posicao inicial de uma interconexao for igual a posicao final de outra
			// I1 (pFinal) -------> I2 (pInicial)
			//		E
			// I1 (pFinal) nao tiver uma saida ja definida:
			//		-> entao saida de I1 eh I2
			//		-> e a entrada de I2 eh I1
			if((*iOutras)->getPosicaoInicial().x == (*iInterconexoes)->getPosicaoFinal().x &&
				(*iOutras)->getPosicaoInicial().y == (*iInterconexoes)->getPosicaoFinal().y &&
				(*iInterconexoes)->getSaidas()->size() == 0 &&
				(*iOutras)->getEntradas()->size() == 0)
			{
				(*iInterconexoes)->getSaidas()->insert(*iOutras);
				(*iOutras)->getEntradas()->insert(*iInterconexoes);
			}
			
			// Caso contrario ao de cima
			// I2(pFinal) --------> I1 (pInicial)
			if((*iOutras)->getPosicaoFinal().x == (*iInterconexoes)->getPosicaoInicial().x &&
				(*iOutras)->getPosicaoFinal().y == (*iInterconexoes)->getPosicaoInicial().y &&
				(*iOutras)->getSaidas()->size() == 0 &&
				(*iInterconexoes)->getEntradas()->size() == 0)
			{
				(*iOutras)->getSaidas()->insert(*iInterconexoes);
				(*iInterconexoes)->getEntradas()->insert(*iOutras);
			}
		}// fim das conexoes entre interconexoes
		
		// Verificar se a interconexao transmite carga (tem entrada e saida)
		if((*iInterconexoes)->getEntradas()->size() == 0 ||
		   (*iInterconexoes)->getSaidas()->size() == 0)
		{
			cout << "\tInterconexao " << (*iInterconexoes)->getNome() << " nao transmite carga" << endl;
			interconexoesDesconectadas.insert(*iInterconexoes);
		}
	}// fim do for do vetor de interconexoes
	
	// Descobrir elementos desconectados
	
	// Geradores desconectados
	for(iGeradores = geradores.begin(); iGeradores != geradores.end(); iGeradores++)
	{
		if((*iGeradores)->getSaidas()->size() == 0)
		{
			cout << "\tGerador " << (*iGeradores)->getNome() << " desconectado" << endl;
			geradoresDesconectados.insert(*iGeradores);
		}
	}
	
	// Cidades desconectadas
	for(iCidades = cidades.begin(); iCidades != cidades.end(); iCidades++)
	{
		if((*iCidades)->getEntradas()->size() == 0)
		{
			cout << "\tCidade " << (*iCidades)->getNome() << " desconectada" << endl;
			cidadesDesconectadas.insert(*iCidades);
		}
	}
	
	// Adaptadores desconectados
	for(iAdaptadores = adaptadores.begin(); iAdaptadores != adaptadores.end(); iAdaptadores++)
	{
		if((*iAdaptadores)->getEntradas()->size() == 0 && 
	       (*iAdaptadores)->getSaidas()->size() == 0)
	    {
	    	cout << "\tAdaptador " << (*iAdaptadores)->getNome() << " nao tem entrada, nem saida" << endl;
	    	adaptadoresDesconectados.insert(*iAdaptadores);
	    }
		else if((*iAdaptadores)->getEntradas()->size() == 0)
		{
			cout << "\tAdaptador " << (*iAdaptadores)->getNome() << " nao tem entrada" << endl;
			adaptadoresDesconectados.insert(*iAdaptadores);
		}
		else if((*iAdaptadores)->getSaidas()->size() == 0)
		{
			cout << "\tAdaptador " << (*iAdaptadores)->getNome() << " nao tem saida" << endl;
			adaptadoresDesconectados.insert(*iAdaptadores);
		}
	}
	cout << "\t\t>> OK\n\n" << endl; // Mensagem indicando fim de calculos das conexoes
	
	int i;
	
	int tempoSimulacao = 5;
	for(i = 0; i < tempoSimulacao; i++)
	{
		cout << "\n\t===== Segundo atual: " << i + 1 << "=====" << endl;
		// Calcular chance de falha das interconexoes (Feita apenas uma vez, com objetivo de verificar funcionamento)
		// Esse processo sera feito para cada segundo da simulacao
		for(iInterconexoes = interconexoes.begin(); iInterconexoes != interconexoes.end(); iInterconexoes++)
			(*iInterconexoes)->aplicarChanceDeFalha();
	
		// Mostrar caminho percorrido pelas cargas (as funcoes responsaveis por essa funcionalidade estao
		// imprimindo mensagem na tela com objetivo de verificar funcionamento)
		// TIRAR EMISSOES DE MENSAGENS NA TELA DOS METODOS NAS CLASSES
		for(iGeradores = geradores.begin(); iGeradores != geradores.end(); iGeradores++)
			(*iGeradores)->emitirCarga();
		
		// Atualizar Relatorio
		Relatorio::tempoTotal++;
		// 	Atualizar carga total produzida e custo gerado pelos geradores
		for(iGeradores = geradores.begin(); iGeradores != geradores.end(); iGeradores++)
		{
			Relatorio::cargaTotalProduzida += (*iGeradores)->getRecursoProduzido();
			Relatorio::custoTotal += (*iGeradores)->getCustoGerador();
		}
		
		//	Atualizar carga total consumida, numero de cidades sem recurso e tempo sem recurso
		
		bool temMenosRecurso = false;
		bool temAbaixo30 = false;
			
		for(iCidades = cidades.begin(); iCidades != cidades.end(); iCidades++)
		{
			Relatorio::cargaTotalConsumida += (*iCidades)->getCarga();
			
			if((*iCidades)->getCarga() < (*iCidades)->getRecursoNecessario())
			{
				Relatorio::cidadesMenosRecurso.insert(*iCidades);
				temMenosRecurso = true;
			}
			if((*iCidades)->getCarga() < 0.3 * (float) (*iCidades)->getRecursoNecessario())
			{
				Relatorio::cidadesAbaixo30.insert(*iCidades);
				temAbaixo30 = true;
			}
			
			(*iCidades)->consumirCarga();
		}
		
		if(temMenosRecurso)
			Relatorio::tempoCidadesSemRecurso++;
		if(temAbaixo30)
			Relatorio::tempoCidadesAbaixo30++;
	
		// Mostrar relatorio parcial
		Relatorio::mostrarRelatorio();
		
		// Esperar 1 segundo
		clock_t start = clock();
		while((clock() - start) / CLOCKS_PER_SEC < 1);
	}
}
