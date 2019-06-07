#include "strutil.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *substr(const char *str, size_t n){
	

	size_t largo_cadena = strlen(str);

	char* nueva = malloc((n + 1) * sizeof(char));
	if(nueva == NULL) return NULL;

	if(n <= 0  || largo_cadena == 0){
		strcpy(nueva,"");
		return nueva;
	}
	//n mayor que cadena
	if(largo_cadena < n){
		memcpy(nueva,str,largo_cadena);
		nueva[largo_cadena] = '\0';
	}else{
		memcpy(nueva,str,n);
		nueva[n] = '\0';
	}
	return nueva;
	
}
/***************************************************
*			FUNCIONES AUXILIARES				   *
***************************************************/
size_t obtener_cantidad_posiciones(const char *str, char sep){
	//obtiene la cantidad de posiciones para el vector
	size_t elementos = 1;
	for(size_t i = 0; i < strlen(str); ++i){
		if(str[i] == sep) elementos++;
	}
	return elementos;
}

size_t cantidad_join(char** strv){
	//obtiene la cantidad de separadores que necesita la cadena
	int contador = -1;
	for(size_t i = 0; strv[i] != NULL; i++){
		contador++;
	}
	if(contador < 0)return 1;
	return (size_t)contador;
}
size_t tam_por_posicion(char** strv){
	//printf("total = %ld||%ld\n",strlen(strv[0]),strlen(strv[2]));
	size_t total = 1;
	for (int i = 0; strv[i] != NULL; ++i){
		total += strlen(strv[i]);
	}
	//printf("%ld\n",total );
	return total;

}
/***************************************************
*			FUNCIONES STR 						   *
***************************************************/
char **split(const char *str, char sep){
	size_t cantidad = obtener_cantidad_posiciones(str,sep);

	char** strv = malloc(sizeof(char*) * (cantidad + 1));
	if(strv == NULL) return NULL;
	
	char* aux = strchr(str,sep);
	size_t posicion = 0;
	for(size_t i = 0; i < cantidad; i++){
		if(!aux){
			strv[posicion] = substr(str, strlen(str));
			break;
		} 
		size_t pos_final = strlen(str) - strlen(aux);
		strv[posicion] = substr(str, pos_final);
		str += pos_final + 1;
		aux =strchr(str,sep);
		posicion++;	
	}
	strv[cantidad] = NULL;
	return strv;
}
/***********************************************************/
char *join(char **strv, char sep){
	size_t separadores = cantidad_join(strv);

	char* cadena = malloc(sizeof(char) * (tam_por_posicion(strv) + separadores));
	if(cadena == NULL) return NULL;
	cadena[0]= '\0';
	size_t posicion = 0;
	for(size_t i = 0; strv[i] != NULL; i++){
		strcat(cadena,strv[i]);
		posicion += strlen(strv[i]);
		if(i < separadores){
			cadena[posicion] = sep;
			posicion++;
			cadena[posicion] = '\0';
		}	
	}
	return cadena;
}
/***************************************************************/
void free_strv(char *strv[]){
	for(size_t i = 0; strv[i] != NULL; i++) free(strv[i]);
	free(strv);
}
//gcc -g -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -o pruebas *.c
//valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./pruebas


	


