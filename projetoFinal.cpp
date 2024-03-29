#include <ctime>
#include <cstdlib>
#include "controladora.hpp"

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
	
	Controladora* c = new Controladora();
	Repositorio::rLeitura leitura;
	
	c->inicializarAmbiente();
	
	// Metodo estatico para ler os elementos da rede e instanciar os objetos
	cout << "\t\t>> Digite o nome do arquivo de configuracao: ";
	
	string nomeArq;
	
	cin >> nomeArq;
	
	leitura = c->lerElementos(nomeArq);
	switch(leitura)
	{
		case Repositorio::ARQUIVO_INEXISTENTE:
			cout << "\tArquivo nao existe" << endl;
			c->finalizar();
			exit(-1);
		
		case Repositorio::FORMATO_INVALIDO:
			cout << "\tArquivo em formato invalido" << endl;
			c->finalizar();
			exit(-1);
	}
		
	c->mostrarElementos();
	c->descobrirConexoes();
	c->calcularPropriedadesDiagrama();
	
	int tempoSimulacao;
	
	cout << "\t\t>> Digite o tempo de simulacao: ";
	cin >> tempoSimulacao;
	c->rodarSimulacao(tempoSimulacao);
	c->finalizar();
	delete c;
	
    return 0;
}
