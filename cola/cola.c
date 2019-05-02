#include "cola.h"
#include <stdlib.h>

//definicion de struct nodo
typedef struct nodo{
	void* dato;
	struct nodo* siguiente;
}nodo_t;

nodo_t* crear_nodo(void* valor){
	nodo_t* nodo = malloc(sizeof(nodo_t));
	if(nodo == NULL) return NULL;
	nodo -> dato = valor;
	nodo -> siguiente = NULL;
	return nodo;
}
/* Definición del struct cola proporcionado por la cátedra.
 */
struct cola {
    nodo_t* primero; //referencia al primer nodo
    nodo_t* ultimo;	//referencia al ultimo nodo
};

/* *****************************************************************
 *                    PRIMITIVAS DE LA COLA
 * *****************************************************************/

cola_t* cola_crear(void){
	cola_t* cola = malloc(sizeof(cola_t));

	if (cola == NULL) {
		return NULL;
	}
	 cola -> primero = NULL;
	 cola -> ultimo = NULL;
	
	return cola;
}


void cola_destruir(cola_t *cola, void destruir_dato(void*)){
	while (!cola_esta_vacia(cola)){
		void* dato = cola_desencolar(cola);
		if(destruir_dato != NULL){
			destruir_dato(dato);
		}		
	}
	free(cola);
}


bool cola_esta_vacia(const cola_t *cola){
	return cola -> primero == NULL;
}

bool cola_encolar(cola_t *cola, void* valor){
	nodo_t* nodo = crear_nodo(valor);
	if(nodo == NULL) return false;
	if(cola -> ultimo){
		cola -> ultimo -> siguiente = nodo;
	}else{
		cola -> primero = nodo;
	}
	cola -> ultimo = nodo;
	return true;

}


void* cola_ver_primero(const cola_t *cola){
	if(cola -> primero) return cola -> primero -> dato;
	return NULL;
}


void* cola_desencolar(cola_t *cola){
	if(cola_esta_vacia(cola)) return NULL;
	void* valor = cola -> primero -> dato;
	void* borrar = cola -> primero;
	cola -> primero = cola -> primero -> siguiente;
	if(cola -> primero == NULL){
		cola -> ultimo = NULL;
	}
	free(borrar);
	return valor;
}
