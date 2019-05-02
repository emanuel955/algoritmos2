#include "strutil.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *substr(const char *str, size_t n){
	

	size_t largo = strlen(str);

	if(n <= 0  || largo == 0) return "";

	char* nueva = malloc(n+1 * sizeof(char));
	if(nueva == NULL) return NULL;

	//n mayor que cadena
	if(largo <= n){
		memcpy(nueva,str,largo);
		nueva[largo] = '\0';
	}else{
		memcpy(nueva,str,n);
		nueva[n+1] = '\0';
	}
	return nueva;
	
}
/***************************************************
*			FUNCIONES AUXILIARES				   *
***************************************************/
size_t obtener_cantidad_separadores(const char *str, char sep){
	size_t elementos = 1;
	for(size_t i = 0; i < strlen(str); ++i){
		if(str[i] == sep) elementos++;
	}
	return elementos;
}
char* cadena(const char* str, size_t contador){
	if(contador <=1) return "";
	char* aux = malloc(sizeof(char) *2);
	if(aux == NULL) return NULL;

	memcpy(aux, str, contador);
	printf(" aux %s\n", aux );
	aux[strlen(aux)] = '\0';
	return aux;
}
size_t cantidad_elementos(const char* str);
/***************************************************
*			FUNCIONES STR 						   *
***************************************************/
char **split(const char *str, char sep){
	size_t cantidad = obtener_cantidad_separadores(str,sep);

	char** strv = malloc(sizeof(char*) * cantidad);
	if(strv == NULL) return NULL;

	size_t contador = 0;
	size_t pos_inicial = 0;
	size_t pos = 0;
	for(size_t i = 0; i <= strlen(str); i++){
		if(str[i] == sep || i == strlen(str)){
			strv[pos] = cadena(str + pos_inicial, contador);
			pos_inicial = i+1;
			contador = 0;
			pos++;
		}else{
			contador++;
		}
	}
	strv[cantidad] = NULL;
	return strv;
}
/***********************************************************/
char *join(char **strv, char sep){
	char* cadena = malloc(sizeof(char)*2);
	if(cadena == NULL) return NULL;

	for(size_t i = 0; strv[i] != NULL; i++){
		strcat(cadena,strv[i]);
		if(strlen(strv) > 1){
			cadena[strlen(cadena)] = ',';
		}

	}
	return cadena;
}

int main(){
	/*char* s = "holacomoestas";
	printf("%s\n", substr(s, 4));
	printf("%s\n", substr(s+2, 4));
	printf("%s\n", substr(s, 35));
	printf("%s\n", substr("", 4));
	*/

	
	char** str = split("abc,,def", ',');//  →  ["abc", "", "def"]
	for(int i = 0; str[i] != NULL;i++){
		printf("%s\n", str[i]);
	}
	free(str);
	printf("-----------\n");
	char* p = join(str,',');
	printf("%s\n", p );
	/*
	char** str1 = split("abc,def,", ',');//  →  ["abc", "def", ""]
	for(int i = 0; str1[i] != NULL;i++){
		printf("%s\n", str1[i]);
	}
	free(str1);
	printf("////////////\n");
	
	char** str3 = split(",abc,def", ',');//  →  ["", "abc", "def"]
	for(int i = 0; str3[i] != NULL;i++){
		printf("%s\n", str3[i]);
	}
	free(str3);
	printf("------------\n");
	
	char** str4 = split("abc", '\0');//      →  ["abc"]
	for(int i = 0; str4[i] != NULL;i++){
		printf("%s\n", str4[i]);
	}
	free(str4);
	printf("----------------\n");
	
	char** str5 = split("", ',');//  →  [""]
	for(int i = 0; str5[i] != NULL;i++){
		printf("%s\n", str5[i]);
	}
	free(str5);
	printf("------------------\n");
	
	char** str6 = split(",", ',');// →  ["", ""]
	for(int i = 0; str6[i] != NULL;i++){
		printf("impi%s\n", str6[i]);
	}
	free(str6);
	/*
	
}
	

