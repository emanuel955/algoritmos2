#define _GNU_SOURCE
#include "strutil.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void imprimir_br(FILE* archivo){
	char caracter;
	int v[1000];

	int i = 0;
	while((caracter = getc(archivo)) != EOF){
		if(caracter == '.') putchar(v[i]);
		if(caracter == '<') i--;
		if(caracter == '>') i++;
		if(caracter == ',') v[i] = getchar();
		if(caracter == '+') v[i]++;
		if(caracter == '-') v[i]--;
		if(caracter == '['){
			while(caracter != ']'){
				if(caracter == '.') putchar(v[i]);
				if(caracter == '<') i--;
				if(caracter == '>') i++;
				if(caracter == ',') v[i] = getchar();
				if(caracter == '+') v[i]++;
				if(caracter == '-') v[i]--;
			}
		}
	}
}

int main(int argc, char* argv[]){
	if(argc == 1){
		//stdin
		//por consola
	}else if(argc == 2){
		FILE* archivo = fopen(argv[1], "r");
		if(archivo == NULL){
			fprintf(stderr, "No se pudo leer el archivo \n");
			return 1;
		} 
		imprimir_br(archivo);
	}
	printf("falta un argumento\n");
		return 1;
}
