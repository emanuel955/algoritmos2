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
void orden_numerico(hash_t* hash, char** arr){
	//creo baldes
	void** baldes = malloc(sizeof(void*) * CANTIDAD);
	for(int k = 0; k < CANTIDAD; k++)baldes[k] = lista_crear();//inicializo los baldes

	size_t cant = hash_cantidad(hash);
	for(int i = 0; i < cant; i++){
		char* usuario = arr[i];
		hash_t* hash_tag = hash_obtener(hash, arr[i]);
		size_t posicion = hash_cantidad(hash_tag);

		lista_t* lista = baldes[posicion];
		lista_insertar_ultimo(lista,usuario);
	}

	int contador = 1;
	for(int p = 0; p < CANTIDAD; p++){//recorre la lista que hat dentro de los baldes
			
		if(lista_esta_vacia(baldes[p]))continue;
		lista_t* lista = baldes[p];
		lista_iter_t* iter1 = lista_iter_crear(lista);
		printf("%d. ",p );
		while(!lista_iter_al_final(iter1)){
			char* nombre = (char*)lista_iter_borrar(iter1);
			printf("%s. ",nombre );
			contador++;	
		}
		printf("\n");
		lista_iter_destruir(iter1);
	}
	eliminar(baldes,CANTIDAD);

}

void orden_alfabetico(hash_t* hash, size_t tam){
	char** arr = malloc(sizeof(char*) * tam);
	int contador = 0;

	//pongo los usuarios en un arreglo
	hash_iter_t* iter = hash_iter_crear(hash);
	while(!hash_iter_al_final(iter)){
		char* clave = (char*)hash_iter_ver_actual(iter);
		arr[contador] = clave;
		contador++;
		hash_iter_avanzar(iter);
	}
	hash_iter_destruir(iter);

	//creo baldes
	void** baldes = malloc(sizeof(void*) * CANTIDAD);
	for(int k = 0; k < CANTIDAD; k++)baldes[k] = lista_crear();//inicializo los baldes

	for(size_t i = 0; i < MAX; i++){//recorre por letra
		for(int j = 0; j < contador;j++){//recorre la lista de usuarios
			char* usuario = arr[j];
			int posicion;
			if((strlen(usuario)-1) < (MAX-1)-i){
				posicion = '_';
			}else{
				posicion = usuario[MAX-1-i];
			}
			lista_t* listas = baldes[posicion];
			lista_insertar_ultimo(listas,usuario);
		}
		int contador2 = 0;
		for(int p = 0; p < CANTIDAD; p++){//recorre la lista que hat dentro de los baldes
			
			if(lista_esta_vacia(baldes[p]))continue;
			lista_t* lista = baldes[p];
			lista_iter_t* iter1 = lista_iter_crear(lista);

			while(!lista_iter_al_final(iter1)){
				char* nombre = (char*)lista_iter_borrar(iter1);
				arr[contador2] = nombre;
				contador2++;	
			}
			lista_iter_destruir(iter1);
		}
	}
	orden_numerico(hash,arr);
	
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
	size_t tam = hash_cantidad(hash_usuario);
	orden_alfabetico(hash_usuario, tam);

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