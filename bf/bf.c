#define _GNU_SOURCE
//#include "strutil.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimir_br(int vector[]){
	char br_vector[300000];
	int pos = 0;

	int corchetes[500];//vector donde se guarda la pos de los [
	int pos_corchete = 0;

	//int w = 0;
	for(int i = 0; vector[i] != '\n'; i++){
		//printf("%c\n", vector[i]);
		//printf("i = %d\n", i);
		if(vector[i] == '.')putchar(br_vector[pos]);
		if(vector[i] == '>') pos++;
		if(vector[i] == '<') pos--;
		if(vector[i] == '+') br_vector[pos]++;
		if(vector[i] == '-') br_vector[pos]--;
		if(vector[i] == '['){
			//guardo la pos del corchete inicial
			//printf("por i [ = %d\n", i );
			corchetes[pos_corchete] = i;
			//printf("aca esta guardado el corchete = %d||%d\n", corchetes[pos_corchete],pos_corchete);
			pos_corchete++;
		}
		if(vector[i] == ']'){
			//si br_vector se encuentra en 0 no vuelve al inicio del [
			if(br_vector[pos] == 0){
				pos_corchete--;
				continue;
			}
			i = corchetes[pos_corchete - 1];
		}
		//if(w == 70)return;
		//w++;
		//printf("br = %d||%d\n",br_vector[pos], pos);

	}
}

void leer_lineas_br(FILE* archivo){
	int vector_br[30000];
	int char_leido;
	int i = 0;
	while((char_leido = fgetc(archivo)) != EOF){
		vector_br[i] = char_leido;
		i++;
	}
	vector_br[i] = '\n';
	fclose(archivo);

	imprimir_br(vector_br);
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
		leer_lineas_br(archivo);
	}else{
		printf("falta un argumento\n");
		return 1;
	}
}
