#ifndef _REPOSITORIO_H
#define _REPOSITORIO_H

#include "elemento.hpp"
#include "gerador.hpp"
#include "adaptador.hpp"
#include "cidade.hpp"
#include "interconexao.hpp"
#include <fstream>
#include <iostream>
#include <cmath>


class Repositorio
{
	private:
		static set<Elemento*> elementos;
		static set<Gerador*> geradores;
		static set<Adaptador*> adaptadores;
		static set<Cidade*> cidades;
		static set<Interconexao*> interconexoes;
		
		static set<Elemento*> elementosDesconectados;
		static set<Cidade*> cidadesDesconectadas;
		static set<Gerador*> geradoresDesconectados;
		static set<Adaptador*> adaptadoresDesconectados;
		static set<Interconexao*> interconexoesDesconectadas;
		
	public:
		
		enum rLeitura
		{
			ARQUIVO_INEXISTENTE, FORMATO_INVALIDO, OK
		};
		
		static set<Elemento*> * getElementos() { return &Repositorio::elementos; }
		static set<Gerador*> * getGeradores() { return &Repositorio::geradores; }
		static set<Adaptador*> * getAdaptadores() { return &Repositorio::adaptadores; }
		static set<Cidade*> * getCidades() { return &Repositorio::cidades; }
		static set<Interconexao*> * getInterconexoes() { return &Repositorio::interconexoes; }
		
		static set<Elemento*> * getElementosDesconectados() { return &Repositorio::elementosDesconectados; }
		static set<Gerador*> * getGeradoresDesconectados() { return &Repositorio::geradoresDesconectados; }
		static set<Cidade*> * getCidadesDesconectadas() { return &Repositorio::cidadesDesconectadas; }
		static set<Adaptador*> * getAdaptadoresDesconectados() { return &Repositorio::adaptadoresDesconectados; }
		static set<Interconexao*> * getInterconexoesDesconectadas() { return &Repositorio::interconexoesDesconectadas; }
		
		static rLeitura lerElementos(string nomeArquivo);
		
};

#endif // _REPOSITORIO_H
