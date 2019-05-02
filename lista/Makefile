CC := gcc
CFLAGS := -g -Wall -Werror -pedantic -std=c99 -Wconversion -Wno-sign-conversion
EXE := pruebas
#OBJS := $(patsubst %.c,%.o,$(wildcar *.c))
#HEADERS := $(patsubst %.c,%.h,$(wildcar *.c))

all: compilar valgrind	clean
#`make` compila el programa
compilar:	lista.o	testing.o	main.o	pruebas_lista_alumno.o
	$(CC) $(CFLAGS) -o $(EXE) lista.o	testing.o	main.o	pruebas_lista_alumno.o

# `make run` corre el programa sin valgrind
run:	$(EXE)
	./$(EXE)
#`make valgrind` corre el programa con valgrind
valgrind:	$(EXE)
	valgrind	--leak-check=full	--track-origins=yes	--show-reachable=yes	./$(EXE)

#`make clean` elimina el ejecutable y archivos objetos (para entregar)
clean:
	rm -f *.o $(EXE)
