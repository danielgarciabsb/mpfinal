#include "controladora.hpp"

Controladora::Controladora()
{
	this->quit = false;
	this->success = true;
	this->window = NULL;
	this->screen_sf = NULL;
	this->gRenderer = NULL;
	this->gTexture = NULL;
}

bool Controladora::inicializarAmbiente()
{
	if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }
    else
    {
        //Create window
        this->window = SDL_CreateWindow("Simulaçao", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        							SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if( this->window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            return false;
        }
        else
        {
            // Create renderer for window
            this->gRenderer = SDL_CreateRenderer( this->window, -1, SDL_RENDERER_SOFTWARE );
            if( this->gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                this->success = false;
                return false;
            }

           	SDL_SetRenderDrawColor( this->gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
            SDL_RenderClear( this->gRenderer );
			SDL_RenderPresent( this->gRenderer );

			//Get window surface
            this->screen_sf = SDL_GetWindowSurface( this->window );

            // //Fill the surface white
            // SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
            
            // //Update the surface
            // SDL_UpdateWindowSurface( window );
        }
    }

    // Inicialização da biblioteca utilizada para imprimir caracteres na tela.
	if (TTF_Init() == -1) 
	{
		printf("Unable to initialize SDL_ttf: %s \n", TTF_GetError());
		return false;
	}

	// Definição da fonte a ser utilizada.
    this->font = TTF_OpenFont("DroidSans.ttf", 12);
    if (this->font == NULL){
		printf("Unable to load font: %s \n", TTF_GetError());
		return false;
    }
 
 	return true;   
}


Repositorio::rLeitura Controladora::lerElementos(string nomeArq)
{
	return Repositorio::lerElementos(nomeArq);
}

void Controladora::mostrarElementos()
{
	cout << "\n\t>> Elementos:" << endl;
	set<Elemento*> elementos = *(Repositorio::getElementos());
	
	set<Elemento*>::iterator iElementos;
	for(iElementos = elementos.begin(); iElementos != elementos.end(); iElementos++)
	{
		cout << "\t\t- " << (*iElementos)->getNome() << endl;
	}
}

void Controladora::descobrirConexoes()
{
	cout << "\n\n\t>> Calculando conexoes..." << endl;
	
	set<Cidade*> cidades = *(Repositorio::getCidades());
	set<Gerador*> geradores = *(Repositorio::getGeradores());
	set<Adaptador*> adaptadores = *(Repositorio::getAdaptadores());
	set<Interconexao*> interconexoes = *(Repositorio::getInterconexoes());
	
	set<Cidade*> cidadesDesconectadas = *(Repositorio::getCidadesDesconectadas());
	set<Gerador*> geradoresDesconectados = *(Repositorio::getGeradoresDesconectados());
	set<Adaptador*> adaptadoresDesconectados = *(Repositorio::getAdaptadoresDesconectados());
	set<Interconexao*> interconexoesDesconectadas = *(Repositorio::getInterconexoesDesconectadas());
	
	set<Cidade*>::iterator iCidades;
	set<Gerador*>::iterator iGeradores;
	set<Adaptador*>::iterator iAdaptadores;
	set<Interconexao*>::iterator iInterconexoes;
	
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
}

void Controladora::calcularPropriedadesDiagrama()
{
	set<Elemento*> elementos = *(Repositorio::getElementos());
	set<Elemento*>::iterator iElementos;
	
	// Variáveis utilizadas para desenhar os elementos.
	// Definindo espaçamento
	iElementos = elementos.begin();
	int max_x = (*elementos.begin())->getPosicaoInicial().x;
	int max_y = (*elementos.begin())->getPosicaoInicial().y;
	int min_x = (*elementos.begin())->getPosicaoInicial().x;
	int min_y = (*elementos.begin())->getPosicaoInicial().y;

	while(++iElementos != elementos.end()) {
		// Calculando max_x_y
		if ((*iElementos)->getPosicaoInicial().x > max_x)
			max_x = (*iElementos)->getPosicaoInicial().x;
		if ((*iElementos)->getPosicaoFinal().x > max_x)
			max_x = (*iElementos)->getPosicaoFinal().x;
		if ((*iElementos)->getPosicaoInicial().y > max_y)
			max_y = (*iElementos)->getPosicaoInicial().y;
		if ((*iElementos)->getPosicaoFinal().y > max_y)
			max_y = (*iElementos)->getPosicaoFinal().y;

		// Calculando min_x_y
		if ((*iElementos)->getPosicaoInicial().x < min_x)
			min_x = (*iElementos)->getPosicaoInicial().x;
		if ((*iElementos)->getPosicaoFinal().x < min_x)
			min_x = (*iElementos)->getPosicaoFinal().x;
		if ((*iElementos)->getPosicaoInicial().y < min_y)
			min_y = (*iElementos)->getPosicaoInicial().y;
		if ((*iElementos)->getPosicaoFinal().y < min_y)
			min_y = (*iElementos)->getPosicaoFinal().y;
	}
	
	Elemento::Posicao minimo;
	minimo.x = min_x;
	minimo.y = min_y;
	this->pontoMinimo = minimo;
	
	int diagonalDiagrama = sqrt( pow((min_x - max_x), 2) + pow((min_y - max_y), 2) );
	
	// Define a quantidade de pixels entre cada elemento que será desenhado.
	this->spacing.y = (SCREEN_HEIGHT - TAMANHO_ELEMENTOS) / log(1 + max_y - min_y);
	this->spacing.x = (SCREEN_WIDTH - TAMANHO_ELEMENTOS) / log(1 + max_x - min_x);
}

void Controladora::rodarSimulacao(int segundos)
{
	int i = 0;

	while(!this->quit)
	{
		if(i++ < segundos)
			this->update();
			
		this->render();
		this->handleEvents();
		clock_t start = clock();
		while((clock() - start) / CLOCKS_PER_SEC < 1);
	}

	
}

void Controladora::update()
{
	set<Elemento*> elementos = *(Repositorio::getElementos());
	set<Cidade*> cidades = *(Repositorio::getCidades());
	set<Gerador*> geradores = *(Repositorio::getGeradores());
	set<Interconexao*> interconexoes = *(Repositorio::getInterconexoes());
	
	set<Elemento*>::iterator iElementos;
	set<Cidade*>::iterator iCidades;
	set<Gerador*>::iterator iGeradores;
	set<Interconexao*>::iterator iInterconexoes;
	
	for(iElementos = elementos.begin(); iElementos != elementos.end(); iElementos++)
		(*iElementos)->setCarga(0);
		
	// Calcular chance de falha das interconexoes (Feita apenas uma vez, com objetivo de verificar funcionamento)
	// Esse processo sera feito para cada segundo da simulacao
	for(iInterconexoes = interconexoes.begin(); iInterconexoes != interconexoes.end(); iInterconexoes++)
		(*iInterconexoes)->aplicarChanceDeFalha();

	// Mostrar caminho percorrido pelas cargas (as funcoes responsaveis por essa funcionalidade estao
	// imprimindo mensagem na tela com objetivo de verificar funcionamento)
	// TIRAR EMISSOES DE MENSAGENS NA TELA DOS METODOS NAS CLASSES
	for(iGeradores = geradores.begin(); iGeradores != geradores.end(); iGeradores++)
		(*iGeradores)->emitirCarga((*iGeradores)->getRecursoProduzido());
	
	// Atualizar Relatorio
	Relatorio::tempoTotal++;
	// 	Atualizar carga total produzida e custo gerado pelos geradores
	for(iGeradores = geradores.begin(); iGeradores != geradores.end(); iGeradores++)
	{
		Relatorio::cargaTotalProduzida += (*iGeradores)->getRecursoProduzido();
		Relatorio::custoTotal += (*iGeradores)->getCustoGerador();
	}
	
	//	Atualizar carga total consumida, numero de cidades sem recurso e tempo sem recurso
		
	for(iCidades = cidades.begin(); iCidades != cidades.end(); iCidades++)
	{
		Relatorio::cargaTotalConsumida += (*iCidades)->getCarga() > (*iCidades)->getRecursoNecessario() ? 
											(*iCidades)->getRecursoNecessario() : (*iCidades)->getCarga();
		
		if((*iCidades)->getCarga() < (*iCidades)->getRecursoNecessario())
		{
			Relatorio::cidadesMenosRecurso.insert(*iCidades);
			Relatorio::tempoCidadesSemRecurso++;
		}
		if((*iCidades)->getCarga() < 0.3 * (float) (*iCidades)->getRecursoNecessario())
		{
			Relatorio::cidadesAbaixo30.insert(*iCidades);
			Relatorio::tempoCidadesAbaixo30++;
		}
	}
	
	// Mostrar relatorio parcial
	Relatorio::mostrarRelatorio();
}

void Controladora::render()
{
	set<Elemento*> elementos = *(Repositorio::getElementos());
	
	//Clear screen
	SDL_SetRenderDrawColor( this->gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
	SDL_RenderClear( this->gRenderer );
	
	set<Elemento*>::iterator iElementos;
	for(iElementos = elementos.begin(); iElementos != elementos.end(); iElementos++)
		(*iElementos)->draw(this->gRenderer, this->screen_sf, this->font, this->spacing, this->pontoMinimo);
	SDL_RenderPresent(this->gRenderer);
}

void Controladora::handleEvents()
{
	//Handle events on queue
	while( SDL_PollEvent( &this->e ) != 0 )
	{
		//User requests quit
		if( this->e.type == SDL_QUIT )
		{
			this->quit = true;
		}
	}
}

void Controladora::finalizar()
{		
	set<Elemento*> elementos = *(Repositorio::getElementos());
	set<Elemento*>::iterator iElementos;
	
	for(iElementos = elementos.begin(); iElementos != elementos.end(); iElementos++)
		(*iElementos)->Delete();
		
	//Destroy window
    SDL_DestroyRenderer( this->gRenderer );
    SDL_DestroyWindow( this->window );
    this->window = NULL;
    this->gRenderer = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}
