#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strutil.h"
#include "hash.h"

void couting_sort_simple(const char* clave, size_t cant){

}


void cant_tuit_por_usuario(const char* linea, hash_t* hash){
	char** vector = split(linea,',');
	hash_t* hash_tuit = hash_obtener(hash, vector[0]); //devulve un hash o NULL
	if(!hash_tuit){
		hash_tuit = hash_crear(free);//si no esta el usuario lo guarda junto con un hash
		hash_guardar(hash,vector[0],hash_tuit);
	}
	for(size_t i = 1; vector[i] != NULL; i++){
		hash_guardar(hash_tuit,vector[i],NULL);
	}
}

void leer_archivo(FILE* archivo){
	hash_t* hash_usuario = hash_crear(free);

	char* linea = NULL;
	size_t bytes_leidos;
	while((getline( &linea, &bytes_leidos, archivo)) > 0){
		cant_tuit_por_usuario(linea,hash_usuario);
	};
	free(linea);

	hash_iter_t* iter = hash_iter_crear(hash);
	while(!hash_iter_al_final(iter)){
		const char* clave = hash_iter_ver_actual(iter);
		hash_t* valor = hash_obtener(hash,clave);

		size_t cant = hash_cantidad(valor);
		couting_sort_simple(clave,cant);
	} 

}

int main(int argc, char const *argv[]){
	FILE* archivo = fopen(argv[1], "r");
		if( archivo == NULL ){
			fprintf( stderr, "Error: archivo fuente inaccesible" );
			return 1;
		} 
		leer_archivo(archivo);
	return 0;
}