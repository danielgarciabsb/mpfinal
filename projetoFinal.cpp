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
	
	srand(1);
	
	Repositorio::lerElementos("rede_distribuicao.conf");
	
	set<Elemento*> elementos = *(Repositorio::getElementos());
	set<Cidade*> cidades = *(Repositorio::getCidades());
	set<Gerador*> geradores = *(Repositorio::getGeradores());
	set<Adaptador*> adaptadores = *(Repositorio::getAdaptadores());
	set<Interconexao*> interconexoes = *(Repositorio::getInterconexoes());
	
	/*cout << "\n\t>> Cidades:" << endl;
	vector<Cidade*>::iterator iCidades;
	for(iCidades = cidades.begin(); iCidades != cidades.end(); iCidades++)
		cout << "\t\t- " << (*iCidades)->getNome() << endl;*/
	
	cout << "\n\t>> Elementos:" << endl;
	set<Elemento*>::iterator iElementos;
	for(iElementos = elementos.begin(); iElementos != elementos.end(); iElementos++)
	{
		cout << "\t\t- " << (*iElementos)->getNome() << endl;
	}
		
	cout << "\n\t>> Calculando conexoes..." << endl;
	set<Interconexao*>::iterator iInterconexoes;
	int numInterconexoes = interconexoes.size();
	int progresso = 0;
	for(iInterconexoes = interconexoes.begin(); iInterconexoes != interconexoes.end(); iInterconexoes++)
	{
		// Conectar saidas dos Geradores às interconexoes
		set<Gerador*>::iterator iGeradores;
		for(iGeradores = geradores.begin(); iGeradores != geradores.end(); iGeradores++)
		{
			if((*iGeradores)->getPosicaoFinal().x == (*iInterconexoes)->getPosicaoInicial().x &&
				(*iGeradores)->getPosicaoFinal().y == (*iInterconexoes)->getPosicaoInicial().y)
			{
				(*iGeradores)->getSaidas()->insert(*iInterconexoes);
			}
		}
		
		// Conectar saidas dos Adaptadores às interconexoes
		set<Adaptador*>::iterator iAdaptadores;
		for(iAdaptadores = adaptadores.begin(); iAdaptadores != adaptadores.end(); iAdaptadores++)
		{
			if((*iAdaptadores)->getPosicaoFinal().x == (*iInterconexoes)->getPosicaoInicial().x &&
				(*iAdaptadores)->getPosicaoFinal().y == (*iInterconexoes)->getPosicaoInicial().y)
			{
				(*iAdaptadores)->getSaidas()->insert(*iInterconexoes);
			}
			
			if((*iAdaptadores)->getPosicaoFinal().x == (*iInterconexoes)->getPosicaoFinal().x &&
				(*iAdaptadores)->getPosicaoFinal().y == (*iInterconexoes)->getPosicaoFinal().y &&
				(*iInterconexoes)->getSaidas()->size() == 0)
			{
				(*iInterconexoes)->getSaidas()->insert(*iAdaptadores);
			}
		}
		
		// Conectar Cidades às interconexoes
		set<Cidade*>::iterator iCidades;
		for(iCidades = cidades.begin(); iCidades != cidades.end(); iCidades++)
		{
			if((*iCidades)->getPosicaoFinal().x == (*iInterconexoes)->getPosicaoFinal().x &&
				(*iCidades)->getPosicaoFinal().y == (*iInterconexoes)->getPosicaoFinal().y &&
				(*iInterconexoes)->getSaidas()->size() == 0)
			{
				(*iInterconexoes)->getSaidas()->insert(*iCidades);
			}
			
		}
		
		// Conectar interconexoes às outras interconexoes
		set<Interconexao*>::iterator iOutras;
		for(iOutras = interconexoes.begin(); iOutras != interconexoes.end(); iOutras++)
		{
			if((*iOutras)->getPosicaoInicial().x == (*iInterconexoes)->getPosicaoFinal().x &&
				(*iOutras)->getPosicaoInicial().y == (*iInterconexoes)->getPosicaoFinal().y &&
				(*iInterconexoes)->getSaidas()->size() == 0)
			{
				(*iInterconexoes)->getSaidas()->insert(*iOutras);
			}
			
			if((*iOutras)->getPosicaoFinal().x == (*iInterconexoes)->getPosicaoInicial().x &&
				(*iOutras)->getPosicaoFinal().y == (*iInterconexoes)->getPosicaoInicial().y &&
				(*iOutras)->getSaidas()->size() == 0)
			{
				(*iOutras)->getSaidas()->insert(*iInterconexoes);
			}
		}
		/*for(iElementos = elementos.begin(); iElementos != elementos.end(); iElementos++)
		{
			// Verificar se o ponto inicial da interconexao eh saida de algum elemento
			if(((*iInterconexoes)->getPosicaoInicial().x == (*iElementos)->getPosicaoFinal().x) &&
			   ((*iInterconexoes)->getPosicaoInicial().y == (*iElementos)->getPosicaoFinal().y) )
			{
				
		  		(*iElementos)->getSaidas()->insert(*iInterconexoes);
		  	}
		  	
		  	// Verificar se o ponto final da interconexao se conecta a algum elemento
		  	if((*iInterconexoes)->getPosicaoFinal().x == (*iElementos)->getPosicaoInicial().x &&
		  	   (*iInterconexoes)->getPosicaoFinal().y == (*iElementos)->getPosicaoInicial().y)
		  	{
		  		(*iInterconexoes)->getSaidas()->insert(*iElementos);
		  	}
		}*/
	}
	cout << "\t\t>> OK" << endl;
	
	for(iInterconexoes = interconexoes.begin(); iInterconexoes != interconexoes.end(); iInterconexoes++)
		(*iInterconexoes)->aplicarChanceDeFalha();
	
	set<Gerador*>::iterator iGeradores;
	for(iGeradores = geradores.begin(); iGeradores != geradores.end(); iGeradores++)
		(*iGeradores)->emitirCarga();
}
