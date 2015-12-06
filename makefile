CC = g++
CFLAGS = -std=c++11 -g -ftest-coverage -fprofile-arcs -pthread
INCLUDES = -iquote./include
OBJS_DIR = obj
_OBJS = projetoFinal.o adaptador.o cidade.o elemento.o gerador.o interconexao.o relatorio.o repositorio.o controladora.o
OBJS = $(patsubst %,$(OBJS_DIR)/%,$(_OBJS))

########################## Geracao dos executaveis ##########################
projetoFinal: $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o projetoFinal $(OBJS) -lgtest -lSDL2 -lSDL2_gfx -lSDL2_ttf

########################## Geracao dos .o ##########################
$(OBJS_DIR)/projetoFinal.o: projetoFinal.cpp projetoFinal_testes.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ ./projetoFinal.cpp

$(OBJS_DIR)/adaptador.o: adaptador/adaptador.cpp include/adaptador.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ ./adaptador/adaptador.cpp

$(OBJS_DIR)/cidade.o: cidade/cidade.cpp include/cidade.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ ./cidade/cidade.cpp
	
$(OBJS_DIR)/elemento.o: elemento/elemento.cpp include/elemento.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ ./elemento/elemento.cpp

$(OBJS_DIR)/gerador.o: gerador/gerador.cpp include/gerador.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ gerador/gerador.cpp

$(OBJS_DIR)/interconexao.o: interconexao/interconexao.cpp include/interconexao.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ interconexao/interconexao.cpp

$(OBJS_DIR)/relatorio.o: relatorio/relatorio.cpp include/relatorio.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ relatorio/relatorio.cpp

$(OBJS_DIR)/repositorio.o: repositorio/repositorio.cpp include/repositorio.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ repositorio/repositorio.cpp

$(OBJS_DIR)/controladora.o: controladora/controladora.cpp include/controladora.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ controladora/controladora.cpp

########################## Clean ##########################
clean:
	rm $(OBJS_DIR)/*.o
	rm $(OBJS_DIR)/*.gcno
	rm $(OBJS_DIR)/*.gcda
