#include "projetoFinal.hpp"

#define _TEST_MODE 0

#if _TEST_MODE == 1

#include "gtest/gtest.h"

using ::testing::EmptyTestEventListener;
using ::testing::InitGoogleTest;
using ::testing::Test;
using ::testing::TestCase;
using ::testing::TestEventListeners;
using ::testing::TestInfo;
using ::testing::TestPartResult;
using ::testing::UnitTest;

FILE* arqLogTestes;

class Log : public EmptyTestEventListener {
	private:
		FILE* arqLogTestes;
		FILE* arqLogErros;

  		virtual void OnTestProgramStart(const UnitTest&) {
  			fprintf(arqLogTestes,"\n--------------------------\n Arquivo Log Testes\n--------------------------\n");
  		}

  		// Relatar resultados do teste
  		virtual void OnTestProgramEnd(const UnitTest& unit_test) {
    		//fprintf(arqLogTestes, "TESTE %s\n", unit_test.Passed() ? "PASSOU" : "FALHOU");
    		fprintf(arqLogTestes,"\n--------------------------\n Fim Arquivo Log Testes\n--------------------------\n");
  		}

  		// Relatar inicio do teste
  		virtual void OnTestStart(const TestInfo& test_info) {
    		fprintf(arqLogTestes, "\n\n\t*** Teste: [%s - %s].\n\t*",
            test_info.test_case_name(),
            test_info.name());
 		}

  		// Relatar sucesso ou falha de uma comparacao
  		virtual void OnTestPartResult(const TestPartResult& test_part_result) {
  			if(test_part_result.failed())
  			{
  				fprintf(arqLogErros, "%s em %s:%d\n%s\n\n\n", 
  					"## Falha",
  					test_part_result.file_name(),
  					test_part_result.line_number(),
  					test_part_result.summary());
  			}
  			
			fprintf(arqLogTestes,
		        	"\n\t*\t %s em %s:%d\n\t*", 
		        	test_part_result.failed() ? "## Falha" : ">> Sucesso",
		        	test_part_result.file_name(),
		        	test_part_result.line_number());
  		}

  		// Finalizar teste
  		virtual void OnTestEnd(const TestInfo& test_info) {
    		fprintf(arqLogTestes,
            	"\n\t*** Fim do Teste [%s - %s].\n",
            	test_info.test_case_name(),
            	test_info.name());
  		}
  	
  	public:
  		Log(char* nomeArqTestes, char* nomeArqErros)
  		{
  			this->arqLogTestes = fopen(nomeArqTestes, "w");
  			this->arqLogErros = fopen(nomeArqErros, "w");
  		}
};

TEST(Elemento, InstanciarAndGetters)
{
	Elemento::Posicao posicao;
	posicao.x = 10;
	posicao.y = 20;

	Elemento* e = new Elemento("Elemento", posicao);
	
	// Verificar instanciacao
	ASSERT_TRUE(e != NULL);
	if(e != NULL)
		SUCCEED();
	
	// Verificar getNome	
	if(e->getNome() == ("Elemento"))
		SUCCEED();
	else
		EXPECT_EQ("Elemento", e->getNome());
	
	// Verificar getPosicao
	if(e->getPosicao().x == 10)
		SUCCEED();
	else
		EXPECT_EQ(10, e->getPosicao().x);	
	
	if(e->getPosicao().y == 20)
		SUCCEED();
	else
		EXPECT_EQ(20, e->getPosicao().y);

	delete e;
}

TEST(Gerador, InstanciarAndGetters)
{
	Elemento::Posicao posicao;
	posicao.x = 10;
	posicao.y = 20;
	Gerador* g = new Gerador("Gerador", posicao, 100, 200);
	
	// Verificar instanciacao
	if(g != NULL)
		SUCCEED();
	else
		ASSERT_TRUE(g != NULL);
			
	// Verificar getNome
	if(g->getNome() == "Gerador")
		SUCCEED();
	else
		EXPECT_EQ("Gerador", g->getNome());
	
	// Verificar getPosicao
	if(g->getPosicao().x == 10)
		SUCCEED();
	else
		EXPECT_EQ(10, g->getPosicao().x);	
		
	if(g->getPosicao().y == 20)
		SUCCEED();
	else
		EXPECT_EQ(20, g->getPosicao().y);
		
	// Verificar Recurso Produzido
	if(g->getRecursoProduzido() == 100)
		SUCCEED();
	else
		EXPECT_EQ(100, g->getRecursoProduzido());
	
	// Verificar Custo Gerador
	if(g->getCustoGerador() == 200)
		SUCCEED();
	else
		EXPECT_EQ(200, g->getCustoGerador());
}

TEST(Cidade, InstanciarAndGetters)
{
	Elemento::Posicao posicao;
	posicao.x = 10;
	posicao.y = 20;
	Cidade* c = new Cidade("Cidade", posicao, 100);
	
	// Verificar instanciacao
	if(c != NULL)
		SUCCEED();
	else
		ASSERT_TRUE(c != NULL);
			
	// Verificar getNome
	if(c->getNome() == "Cidade")
		SUCCEED();
	else
		EXPECT_EQ("Cidade", c->getNome());
		
	// Verificar getPosicao	
	if(c->getPosicao().x == 10)
		SUCCEED();
	else
		EXPECT_EQ(10, c->getPosicao().x);
	
	if(c->getPosicao().y == 20)
		SUCCEED();
	else
		EXPECT_EQ(20, c->getPosicao().y);
			
	// Verificar Recurso Necessario
	if(c->getRecursoNecessario() == 100)
		SUCCEED();
	else
		EXPECT_EQ(100, c->getRecursoNecessario());
}

TEST(Adaptador, InstanciarAndGetters)
{
	Elemento::Posicao posicao;
	posicao.x = 10;
	posicao.y = 20;
	Adaptador* a = new Adaptador("Adaptador", posicao);
	
	// Verificar instanciacao
	if(a != NULL)
		SUCCEED();
	else
		ASSERT_TRUE(a != NULL);
			
	// Verificar getNome
	if(a->getNome() == "Adaptador")
		SUCCEED();
	else
		EXPECT_EQ("Adaptador", a->getNome());
		
	// Verificar getPosicao	
	if(a->getPosicao().x == 10)
		SUCCEED();
	else
		EXPECT_EQ(10, a->getPosicao().x);
	
	if(a->getPosicao().y == 20)
		SUCCEED();
	else
		EXPECT_EQ(20, a->getPosicao().y);
}

TEST(Interconexao, InstanciarAndGetters)
{
	Elemento::Posicao posicaoInicial, posicaoFinal;
	posicaoInicial.x = 10;
	posicaoInicial.y = 20;
	posicaoFinal.x = 30;
	posicaoFinal.y = 40;
	
	Elemento::Posicao posicaoEmissor, posicaoReceptor;
	posicaoEmissor.x = 50;
	posicaoEmissor.y = 60;
	posicaoReceptor.x = 70;
	posicaoReceptor.y = 80;
	
	Elemento* emissor = new Elemento("Emissor", posicaoEmissor);
	Elemento* receptor = new Elemento("Receptor", posicaoReceptor);
	
	Interconexao* i = new Interconexao("Interconexao", posicaoInicial, posicaoFinal, 100, 0.1, 200, 300);
	
	// Verificar instanciacao
	if(i != NULL)
		SUCCEED();
	else
		ASSERT_TRUE(i != NULL);
			
	// Verificar getNome
	if(i->getNome() == "Interconexao")
		SUCCEED();
	else
		EXPECT_EQ("Interconexao", i->getNome());
		
	// Verificar getPosicaoInicial	
	if(i->getPosicaoInicial().x == 10)
		SUCCEED();
	else
		EXPECT_EQ(10, i->getPosicaoInicial().x);
	
	if(i->getPosicaoInicial().y == 20)
		SUCCEED();
	else
		EXPECT_EQ(20, i->getPosicaoInicial().y);
		
	// Verificar getPosicaoFinal
	if(i->getPosicaoFinal().x == 30)
		SUCCEED();
	else
		EXPECT_EQ(30, i->getPosicaoFinal().x);
	
	if(i->getPosicaoFinal().y == 40)
		SUCCEED();
	else
		EXPECT_EQ(40, i->getPosicaoFinal().y);
	
	// Verificar getCapacidadeMax
	if(i->getCapacidadeMax() == 100)
		SUCCEED();
	else
		EXPECT_EQ(100, i->getCapacidadeMax());
	
	// Verificar getChanceFalha
	if(i->getChanceFalha() == (float) 0.1)
		SUCCEED();
	else
		EXPECT_EQ((float) 0.1, i->getChanceFalha());
		
	// Verificar getTempoConserto
	if(i->getTempoConserto() == 200)
		SUCCEED();
	else
		EXPECT_EQ(200, i->getTempoConserto());
		
	// Verificar getCustoConserto
	if(i->getCustoConserto() == 300)
		SUCCEED();
	else
		EXPECT_EQ(300, i->getCustoConserto());
}

TEST(Repositorio, LeituraArquivo)
{
	string nomeArq = "rede_distribuicao.conf";
	Repositorio::lerElementos(nomeArq);
	
	vector<Gerador*> geradores = *(Repositorio::getGeradores());
	vector<Cidade*> cidades = *(Repositorio::getCidades());
	vector<Adaptador*> adaptadores = *(Repositorio::getAdaptadores());
	vector<Interconexao*> interconexoes = *(Repositorio::getInterconexoes());
	
	ifstream fin("rede_distribuicao.conf");
	Elemento::Posicao posicao;
	string nome;
	
	bool erroLeitura = false;
	
	vector<Gerador*>::iterator iGeradores = geradores.begin();
	vector<Cidade*>::iterator iCidades = cidades.begin();
	vector<Adaptador*>::iterator iAdaptadores = adaptadores.begin();
	vector<Interconexao*>::iterator iInterconexoes = interconexoes.begin();
	
	while((iGeradores   != geradores.end() ||
		   iCidades     != cidades.end() ||
		   iAdaptadores != adaptadores.end() ) 
		 && 
		  (!erroLeitura))
	{
		char identificador;
		fin >> identificador;
		bool ehInterconexao = false;
		
		switch(identificador)
		{
			case 'G':			
				int recursoProduzido, custoGerador;
				fin >> nome >> posicao.x >> posicao.y >> recursoProduzido >> custoGerador;
				
				if((*iGeradores)->getNome() != nome)
					erroLeitura = true;
				iGeradores++;
				
				break;
				
			case 'C':				
				int recursoNecessario;				
				fin >> nome >> posicao.x >> posicao.y >> recursoNecessario;
				
				if((*iCidades)->getNome() != nome)
					erroLeitura = true;
				iCidades++;
				
				break;
			
			case 'A':
				fin >> nome >> posicao.x >> posicao.y;

				if((*iAdaptadores)->getNome() != nome)
					erroLeitura = true;
				iAdaptadores++;
				
				break;
				
			case 'I':
				Elemento::Posicao posicaoInicial, posicaoFinal;
				int capacidadeMax, tempoConserto, custoConserto;
				float chanceFalha;
				ehInterconexao = true;
				fin >> nome >> posicaoInicial.x >> posicaoInicial.y >> posicaoFinal.x >> posicaoFinal.y 
					>> capacidadeMax >> chanceFalha >> tempoConserto >> custoConserto;
					
				if((*iInterconexoes)->getNome() != nome)
					erroLeitura = true;
				iInterconexoes++;
				
				
				break;
		}		
	}
	
	if(!erroLeitura)
		SUCCEED();
	else
		EXPECT_EQ(false, erroLeitura);
	
}

#endif // _TEST_MODE == ON
