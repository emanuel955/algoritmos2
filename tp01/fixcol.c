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
		printf("%ld\n",col);
		cadena = substr(linea, col);
		printf("%s\n",cadena);

		int cad_result = (int)strlen(linea) - n; //la cantidad de caracter que queda en cadena
		if(cad_result < 0) continue;
		printf("%d\n", cad_result );

		cadena = substr(linea + col, (size_t) cad_result - 1);
		printf("%s\n",cadena);
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
		fprintf(stderr, "Error: archivo fuente inacesible \n");
		return 1;
	} 
	imprimir_linea(archivo,atoi(argv[2]));
}