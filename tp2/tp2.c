#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strutil.h"
#include "hash.h"
#include "lista.h"

#define CANTIDAD 128
#define MAX 15 //long max de nombre usuario

void eliminar(void** vector, int contador2){
	for (int i = 0; i < CANTIDAD; ++i){
		lista_destruir(vector[i],NULL);
	}
	free(vector);
}

void couting_sort_simple(hash_t* hash){
	char** arr = malloc(sizeof(char*) * CANTIDAD);
	int contador = 0;

	hash_iter_t* iter = hash_iter_crear(hash);
	while(!hash_iter_al_final(iter)){
		char* clave = (char*)hash_iter_ver_actual(iter);
		arr[contador] = clave;
		contador++;
		hash_iter_avanzar(iter);
	}
	hash_iter_destruir(iter);

	void** baldes = malloc(sizeof(void*) * CANTIDAD);
	for(int k = 0; k < CANTIDAD; k++)baldes[k] = lista_crear();//inicializo los baldes
	lista_t* listas;
	lista_t* lista;

	for(size_t i = 0; i < MAX; i++){//recorre por letra
		for(int j = 0; j < contador;j++){//recorre la lista de usuarios
			char* usuario = arr[j];
			int posicion;
			if((strlen(usuario)-1) < i){
				posicion = usuario[0];
			}else{
				posicion = usuario[strlen(arr[j])-1-i];
			}
			printf("---------%s||%c\n",usuario,posicion);
			listas = baldes[posicion];
			lista_insertar_ultimo(listas,usuario);
		}
		int contador2 = 0;
		for(int p = 0; p < CANTIDAD; p++){
			
			if(lista_esta_vacia(baldes[p]))continue;
			lista = baldes[p];
			lista_iter_t* iter1 = lista_iter_crear(lista);

			while(!lista_iter_al_final(iter1)){
				char* nombre = (char*)lista_iter_borrar(iter1);
				arr[contador2] = nombre;
				contador2++;	
			}
			lista_iter_destruir(iter1);
		}
		size_t cant = hash_cantidad(hash);
		for(size_t w = 0; w < cant;w++){
			printf("%s\n",arr[w]);
		}
		printf("\n");
	}

	/*size_t cant = hash_cantidad(hash);
	for(size_t w = 0; w < cant;w++){
		printf("%s\n",arr[w]);
	}*/
	
	eliminar(baldes,contador);
	free(arr);
}
void destruir_dato(void* dato){
	hash_destruir(dato);
}
void cant_tuit_por_usuario(const char* linea, hash_t* hash){
	char** vector = split(linea,',');
	if(strlen(vector[0]) > 15)return;

	hash_t* hash_tuit = hash_obtener(hash, vector[0]); //devulve un hash o NULL
	if(!hash_tuit){
		hash_tuit = hash_crear(free);//si no esta el usuario lo guarda junto con un hash
		hash_guardar(hash,vector[0],hash_tuit);
	}
	free(vector[0]);
	for(size_t i = 1; vector[i] != NULL; i++){
		hash_guardar(hash_tuit,vector[i],NULL);
		free(vector[i]);
	}
	free(vector);
}

void leer_archivo(FILE* archivo){
	hash_t* hash_usuario = hash_crear(destruir_dato);

	char* linea = NULL;
	size_t bytes_leidos;
	while((getline( &linea, &bytes_leidos, archivo)) > 0){
		linea[strlen(linea) - 1] = '\0';//elimina \n
		cant_tuit_por_usuario(linea,hash_usuario);
	};
	free(linea);
	couting_sort_simple(hash_usuario);

	hash_destruir(hash_usuario);
}
int main(int argc, char const *argv[]){
	FILE* archivo = fopen(argv[1], "r");
		if( archivo == NULL ){
			fprintf( stderr, "Error: archivo fuente inaccesible" );
			return 1;
		} 
		leer_archivo(archivo);
		fclose(archivo);
	return 0;
}