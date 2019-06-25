#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strutil.h"
#include "hash.h"

void couting_sort_simple(hash_t* hash){
	hash_iter_t* iter = hash_iter_crear(hash);

	while(!hash_iter_al_final(iter)){
		const char* clave = hash_iter_ver_actual(iter);
		hash_t* valor = hash_obtener(hash,clave);

		size_t cant = hash_cantidad(valor);
		printf("%s||%ld\n", clave,cant );
		hash_iter_avanzar(iter);
	}
	hash_iter_destruir(iter);
}
void cant_tuit_por_usuario(const char* linea, hash_t* hash){
	char** vector = split(linea,',');
	if(strlen(vector[0]) > 15)return;
	//printf("FUNCION usuario = %s\n", vector[0]);
	hash_t* hash_tuit = hash_obtener(hash, vector[0]); //devulve un hash o NULL
	if(!hash_tuit){
		//printf("ENTRO EN EL DATO NO ES HASH\n");
		hash_tuit = hash_crear(free);//si no esta el usuario lo guarda junto con un hash
		hash_guardar(hash,vector[0],hash_tuit);
	}
	free(vector[0]);
	for(size_t i = 1; vector[i] != NULL; i++){
		//printf("------- %s\n", vector[i]);
		char* tag = vector[]//sacar en /n
		hash_guardar(hash_tuit,vector[i],NULL);
		free(vector[i]);
	}
	free(vector);
	//printf("\n");
}
void destruir_dato(void* dato){
	hash_destruir(dato);
}
void leer_archivo(FILE* archivo){
	hash_t* hash_usuario = hash_crear(destruir_dato);

	char* linea = NULL;
	size_t bytes_leidos;
	while((getline( &linea, &bytes_leidos, archivo)) > 0){
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