CC := gcc
CFLAGS := -g -Wall -Werror -pedantic -std=c99 -Wconversion -Wno-sign-conversion
EXE := pruebas
OBJS := $(patsubst %.c,%.o,$(wildcar *.c))
HEADERS := $(patsubst %.c,%.h,$(wildcar *.c))

all: compilar valgrind
#`make` compila el programa
compilar:	$(OBJS)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJS)

%.o: %.c $(HEADERS)
# `make run` corre el programa sin valgrind
run:	$(EXE)
	./$(EXE)
#`make valgrind` corre el programa con valgrind
valgrind:	$(EXE)
	valgrind	--leak-check=full	--track-origins=yes	--show-reachable=yes	./$(EXE)

#`make clean` elimina el ejecutable y archivos objetos (para entregar)
clean:
	rm -f *.o $(EXE)
