#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strutil.h"
#include "hash.h"

#define CANTIDAD 128
void destruir_dato(void* dato){
	hash_destruir(dato);
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

	size_t cant = hash_cantidad(hash);

	for(size_t i = 0; i < cant;i++){
		printf("%s\n",arr[i]);
		free(arr[i]);
	}
	//free(arr);
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