CC = g++
CFLAGS = -g -ftest-coverage -fprofile-arcs -pthread
INCLUDES = -iquote./include
OBJS = projetoFinal.o adaptador.o cidade.o elemento.o gerador.o interconexao.o relatorio.o repositorio.o

########################## Geracao dos executaveis ##########################
projetoFinal: $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o projetoFinal $(OBJS) -lgtest
	make clean

########################## Geracao dos .o ##########################
projetoFinal.o: projetoFinal.cpp projetoFinal_testes.hpp projetoFinal.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c ./projetoFinal.cpp

adaptador.o: adaptador/adaptador.cpp include/adaptador.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c ./adaptador/adaptador.cpp

cidade.o: cidade/cidade.cpp include/cidade.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c ./cidade/cidade.cpp
	
elemento.o: elemento/elemento.cpp include/elemento.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c ./elemento/elemento.cpp

gerador.o: gerador/gerador.cpp include/gerador.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c gerador/gerador.cpp

interconexao.o: interconexao/interconexao.cpp include/interconexao.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c interconexao/interconexao.cpp

relatorio.o: relatorio/relatorio.cpp include/relatorio.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c relatorio/relatorio.cpp

repositorio.o: repositorio/repositorio.cpp include/repositorio.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c repositorio/repositorio.cpp

########################## Clean ##########################
clean:
	rm projetoFinal.o
	rm adaptador.o
	rm cidade.o
	rm elemento.o
	rm gerador.o
	rm interconexao.o
