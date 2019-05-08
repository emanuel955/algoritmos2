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

size_t cantidad_separadores(char** strv){
	//obtiene la cantidad de separadores que necesita la cadena
	int contador = -1;
	for(size_t i = 0; strv[i] != NULL; i++){
		contador++;
	}
	return (size_t)contador;

}
/***************************************************
*			FUNCIONES STR 						   *
***************************************************/
char **split(const char *str, char sep){
	size_t cantidad = obtener_cantidad_posiciones(str,sep);
	printf("cant = %ld\n", cantidad );

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
	size_t separadores = cantidad_separadores(strv);
	char* cadena = malloc(sizeof(char) * (sizeof(strv) + separadores));
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
	
	
	char** str = split("abc,,def", ',');//  →  ["abc", "", "def"]
	for(size_t i = 0; str[i] != NULL;i++){
		printf("%s\n", str[i]);
	}
	printf("-----------\n");
	char* p = join(str,',');
	printf("%s\n", p );
	free_strv(str);
	free(p);
	printf("-----------\n");
	char** str1 = split("abc,def,", ',');//  →  ["abc", "def", ""]
	for(int i = 0; str1[i] != NULL;i++){
		printf("%s\n", str1[i]);
	}
	char* m = join(str1,',');
	printf("%s\n", m );
	free_strv(str1);
	free(m);
	printf("////////////\n");
	
	char** str3 = split(",abc,def", ',');//  →  ["", "abc", "def"]
	for(int i = 0; str3[i] != NULL;i++){
		printf("%s\n", str3[i]);
	}
	char* b = join(str3,',');
	printf("%s\n", b );
	free_strv(str3);
	free(b);
	printf("------------\n");
	
	char** str4 = split("abc", '\0');//      →  ["abc"]
	for(int i = 0; str4[i] != NULL;i++){
		printf("%s\n", str4[i]);
	}
	char* c = join(str4,',');
	printf("%s\n", c );
	free_strv(str4);
	free(c);
	printf("----------------\n");
	
	char** str5 = split("", ',');//  →  [""]
	for(int i = 0; str5[i] != NULL;i++){
		printf("%s\n", str5[i]);
	}
	char* z = join(str5,',');
	printf("%s\n", z );
	free_strv(str5);
	free(z);
	printf("------------------\n");

	char** str6 = split(",", ',');// →  ["", ""]
	for(int i = 0; str6[i] != NULL;i++){
		printf("impi%s\n", str6[i]);
	}
	char* k = join(str6,',');
	printf("%s\n", k );
	free_strv(str6);
	free(k);
	*/

	//----------------------
	//join([], ',')               →  "" // Join de arreglo vacío, {NULL} en C.
	char* q[] = {NULL};
	char* d = join(q,',');
	printf("%s\n", d);
	free(d);
	//join(["abc", "def"], '\0')  →  "abcdef"


	
}
	

