#define _GNU_SOURCE
//#include "strutil.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimir_linea(FILE* archivo,int n){

	int cont = 0;
	int caracter;
	while(!feof(archivo)){
		caracter = fgetc(archivo);
		if(caracter < 0)continue;
		if(caracter == '\n'){
			if(cont != 0){
				printf("\n");
			}
			cont = 0;
			continue;
		}
		printf("%c",caracter);
		cont++;

		if(cont == n){
			printf("\n");
			cont = 0;
		}	
	}
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