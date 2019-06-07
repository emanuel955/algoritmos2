#define _GNU_SOURCE
#include "strutil.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimir_linea(FILE* archivo,int n){
	size_t col = (size_t) n;
	char* linea = NULL;
	size_t tam = 0;
	char* cadena;

	while(getline(&linea, &tam, archivo) > 0){
		size_t avanzar = 0;
		int cad_result = (int) strlen(linea);
		while(avanzar < strlen(linea)){
			if((cad_result - avanzar) < col){
				cadena = substr(linea + avanzar, (size_t) cad_result);
				printf("%s",cadena);
			}else{	
				cadena = substr(linea + avanzar, col);
				printf("%s\n",cadena);
			}
			avanzar += col;
			free(cadena);
		}
	}
	free(linea);
	fclose(archivo);
}

int main(int argc, char* argv[]){
	if(argc != 3){
		fprintf(stderr,"Error: Cantidad erronea de parametros\n");
		return 1;
	}
	FILE* archivo = fopen(argv[1], "r");
	if(archivo == NULL){
		fprintf(stderr, "Error: archivo fuente inaccesible \n");
		return 1;
	} 
	imprimir_linea(archivo,atoi(argv[2]));
}