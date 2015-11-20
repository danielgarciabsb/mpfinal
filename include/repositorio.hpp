#ifndef _REPOSITORIO_H
#define _REPOSITORIO_H

#include "elemento.hpp"
#include "gerador.hpp"
#include "adaptador.hpp"
#include "cidade.hpp"
#include "interconexao.hpp"
#include <fstream>


class Repositorio
{
	private:
		static set<Elemento*> elementos;
		static set<Gerador*> geradores;
		static set<Adaptador*> adaptadores;
		static set<Cidade*> cidades;
		static set<Interconexao*> interconexoes;
		
		
	public:
		static set<Elemento*> * getElementos() { return &Repositorio::elementos; }
		static set<Gerador*> * getGeradores() { return &Repositorio::geradores; }
		static set<Adaptador*> * getAdaptadores() { return &Repositorio::adaptadores; }
		static set<Cidade*> * getCidades() { return &Repositorio::cidades; }
		static set<Interconexao*> * getInterconexoes() { return &Repositorio::interconexoes; }
		
		static void lerElementos(string nomeArquivo);
};

#endif // _REPOSITORIO_H
