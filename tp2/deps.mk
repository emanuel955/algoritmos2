CC	:=	gcc
CFLAGS	:=	-g -std=c99 -Wall -Wtype-limits -pedantic -Wconversion -Wno-sign-conversion 

procesar_tweets:
procesar_usuarios:	procesar_usuarios.o	strutil.o	hash.o	listas.o