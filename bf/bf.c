#define _GNU_SOURCE
//#include "strutil.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
void imprimir_br(char* linea, int* j){
	printf("%ls\n",j );
	int v[20000];

	int i = 0, pos_inicial = 0;
	//int w = 0;
	for(int j; linea[j] != '\n'; j++){
		//if(w > 30) return;
		//w++;
		//printf("pos de linea = %c,j = %ld\n", linea[j],j);
		if(linea[j] == '.') putchar(v[i]);
		if(linea[j] == '<') i--;
		if(linea[j] == '>') i++;
		if(linea[j] == ',') v[i] = getchar();
		if(linea[j] == '+') v[i]++;
		if(linea[j] == '-') v[i]--;
		if(linea[j] == '['){
			pos_inicial = j;
			while(v[0] > 0){
				j ++ ;
				//if(w > 5) return;
				if(linea[j] == ']') j = pos_inicial;
				//printf("entra = %c,, %ld\n", linea[j],j);
				if(linea[j] == '.') putchar(v[i]);
				if(linea[j] == '<') i--;
				if(linea[j] == '>') i++;
				if(linea[j] == ',') v[i] = getchar();
				if(linea[j] == '+') v[i]++;
				if(linea[j] == '-') v[i]--;
				//printf(" fin c/w = %ld,%d\n",i,v[i]);
				//w++;
			}
		}
		//printf("pos vec = %ld, cant + = %d\n",i,v[i]);
	}
}
void leer_lineas(FILE* archivo){
	char* linea = NULL;
	size_t tam = 0;
	int pos = 0;
	while(getline(&linea, &tam, archivo) > 0){
		imprimir_br(linea, &pos);
	}
	free(linea);
	fclose(archivo);
}*/
void imprimir_br(FILE* archivo){
	char v[30000];
	int char_leido, i=0;
	int w = 30;
	while((char_leido = fgetc(archivo)) != EOF){
		printf("ini de linea = %d = %d\n",v[i],i);
		if(char_leido == '.') putchar(v[i]);
		if(char_leido == '<') i--;
		if(char_leido == '>') i++;
		//if(char_leido == ',') v[i] = getchar();
		if(char_leido == '+') v[i]++;
		if(char_leido == '-') v[i]--;
		if(char_leido == '['){
			long int pos = ftell(archivo); //posicion del primer corchete
			while(v[i] != 0){;
				fseek(archivo,pos,SEEK_SET);//regresa al primer corchete
				int caracter = fgetc(archivo);
				while(caracter != ']' && caracter != EOF){
					if(w == 0)return;
					w--;
					if(caracter == '.') putchar(v[i]);
					if(caracter == '<') i--;
					if(caracter == '>') i++;
					//if(caracter == ',') v[i] = getchar();
					if(caracter == '+') v[i]++;
					if(caracter == '-') v[i]--;
					caracter = fgetc(archivo);
					printf("fin de linea = %c || %d = %d\n", caracter,v[i],i);
				}

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
		//leer_lineas(archivo);
		imprimir_br(archivo);
	}else{
		printf("falta un argumento\n");
		return 1;
	}
}
