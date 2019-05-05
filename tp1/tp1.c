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
size_t obtener_cantidad_separadores(const char *str, char sep){
	size_t elementos = 1;
	for(size_t i = 0; i < strlen(str); ++i){
		if(str[i] == sep) elementos++;
	}
	return elementos;
}

size_t cantidad_elementos(char** strv){
	size_t contador = 0;
	for(size_t i = 0; strv[i] != NULL; i++){
		contador += strlen(strv[i]);
		contador++; //para los sep + Null
	}
	return contador;

}
/***************************************************
*			FUNCIONES STR 						   *
***************************************************/
char **split(const char *str, char sep){
	size_t cantidad = obtener_cantidad_separadores(str,sep);

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
	size_t contador = cantidad_elementos(strv);
	char* cadena = malloc(sizeof(char) * (contador + 1));
	if(cadena == NULL) return NULL;

	for(size_t i = 0; strv[i] != NULL; i++){
		strcat(cadena,strv[i]);
		if(i < *(int*)(strlen(*strv) -1)) strcat(cadena,&sep);
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
int main(){
	/*
	char* s = "holacomoestas";
	char* q = substr(s, 4);
	printf("%s\n", q);
	free(q);
	
	char* w = substr(s+2, 4);
	printf("%s\n",w);
	free(w);
	
	char* e = substr(s, 35);
	printf("%s\n",e);
	free(e);
	
	char* r = substr("", 4);
	printf("%s\n", r);
	
	*/
	char** str = split("abc,,def", ',');//  →  ["abc", "", "def"]
	for(size_t i = 0; str[i] != NULL;i++){
		printf("oka =%ld\n", strlen(str[i]));
		printf("%s\n", str[i]);
		size_t t = sizeof(str)/sizeof(char);
		printf("vb %ld\n", t);
	}
	printf("por = %ld\n", sizeof(str));
	printf("-----------\n");
	char* p = join(str,',');
	printf("%s\n", p );
	free_strv(str);
	printf("-----------\n");
	/*
	char** str1 = split("abc,def,", ',');//  →  ["abc", "def", ""]
	for(int i = 0; str1[i] != NULL;i++){
		printf("%s\n", str1[i]);
		free(str1[i]);
	}
	free(str1);
	printf("////////////\n");
	
	char** str3 = split(",abc,def", ',');//  →  ["", "abc", "def"]
	for(int i = 0; str3[i] != NULL;i++){
		printf("%s\n", str3[i]);
		free(str3[i]);
	}
	free(str3);
	printf("------------\n");
	
	char** str4 = split("abc", '\0');//      →  ["abc"]
	for(int i = 0; str4[i] != NULL;i++){
		printf("%s\n", str4[i]);
		free(str4[i]);
	}
	free(str4);
	printf("----------------\n");
	
	char** str5 = split("", ',');//  →  [""]
	for(int i = 0; str5[i] != NULL;i++){
		printf("%s\n", str5[i]);
		free(str5[i]);
	}
	free(str5);
	printf("------------------\n");
	
	char** str6 = split(",", ',');// →  ["", ""]
	for(int i = 0; str6[i] != NULL;i++){
		printf("impi%s\n", str6[i]);
		free(str6[i]);
	}
	free(str6);
	*/
	
}
	

