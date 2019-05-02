#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

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

/* Definición del struct lista
 */
struct lista {
    nodo_t* primero; //referencia al primer nodo
    nodo_t* ultimo;	//referencia al ultimo nodo
    size_t contador;
};

struct lista_iter{
	nodo_t* anterior; //referencia al nodo anterior
	nodo_t* actual; //referencia al primer nodo
	lista_t* list;
};

/* *****************************************************************
 *                    PRIMITIVAS DE LA lista
 * *****************************************************************/

lista_t *lista_crear(void){
	lista_t* lista = malloc(sizeof(lista_t));

	if (lista == NULL) {
		return NULL;
	}
	lista -> primero = NULL;
	lista -> ultimo = NULL;
	lista -> contador = 0;
	
	return lista;
}
bool lista_esta_vacia(const lista_t *lista){
	return !lista -> primero;
}
bool lista_insertar_primero(lista_t *lista, void *dato){
	nodo_t* nodo = crear_nodo(dato);
	if(nodo == NULL) return false;
	if (lista -> primero){
		nodo -> siguiente = lista -> primero;	
	}else{
		lista -> ultimo = nodo;
	}
	lista -> primero = nodo;
	lista -> contador ++;
	return true;
}
bool lista_insertar_ultimo(lista_t *lista, void *dato){
	nodo_t* nodo = crear_nodo(dato);
	if(nodo == NULL) return false;
	if(lista -> ultimo){
		lista -> ultimo -> siguiente = nodo;
	}else{
		lista -> primero = nodo;
	}
	lista -> ultimo = nodo;
	lista -> contador ++;
	return true;
}
void *lista_borrar_primero(lista_t *lista){
	if(lista_esta_vacia(lista)) return NULL;
	void* valor = lista -> primero -> dato;
	void* borrar = lista -> primero;
	lista -> primero = lista -> primero -> siguiente;
	if(lista -> primero == NULL){
		lista -> ultimo = NULL;
	}
	free(borrar);
	lista -> contador --;
	return valor;
}
void *lista_ver_primero(const lista_t *lista){
	if(!lista_esta_vacia(lista)) return lista -> primero -> dato;
	return NULL;
}
void *lista_ver_ultimo(const lista_t* lista){
	if(!lista_esta_vacia(lista)) return lista -> ultimo -> dato;
	return NULL;
}
size_t lista_largo(const lista_t *lista){
	return lista -> contador;
}
void lista_destruir(lista_t *lista, void destruir_dato(void *)){
	while(!lista_esta_vacia(lista)){
		void* dato = lista_borrar_primero(lista);
		if (destruir_dato){
			destruir_dato(dato);
		}
	}
	free(lista);

}

/* *****************************************************************
 *                    PRIMITIVAS ITERADOR EXTERNO
 * *****************************************************************/

lista_iter_t *lista_iter_crear(lista_t *lista){
	lista_iter_t* lista_iter = malloc(sizeof(lista_iter_t));

	if (lista_iter == NULL) {
		return NULL;
	}
	lista_iter -> anterior = NULL;
	lista_iter -> actual = lista -> primero;
	lista_iter -> list = lista;
	return lista_iter;

}
bool lista_iter_avanzar(lista_iter_t *iter){
	if(lista_iter_al_final(iter))return false;
	iter -> anterior = iter -> actual;
	iter -> actual = (iter -> actual) -> siguiente;
	return true;

}
void *lista_iter_ver_actual(const lista_iter_t *iter){
	if (!iter -> actual)return NULL;
	return iter -> actual -> dato;
}
bool lista_iter_al_final(const lista_iter_t *iter){
	return !iter -> actual;
}
void lista_iter_destruir(lista_iter_t *iter){
	free(iter);
}
bool lista_iter_insertar(lista_iter_t *iter, void *dato){
	nodo_t* nodo = crear_nodo(dato);
	if(nodo == NULL) return false;
	if(iter -> actual == iter -> list -> primero){
		iter -> list -> primero = nodo;
	}else{
		if(!lista_iter_al_final(iter)){
			iter -> list -> ultimo = nodo;
		iter -> anterior -> siguiente = nodo;
		}
	}
	nodo -> siguiente = iter -> actual;
	iter -> actual = nodo;
	iter -> list -> contador++;
	return true;
}
void *lista_iter_borrar(lista_iter_t *iter){
	if (lista_iter_al_final(iter)) return NULL;
	void* dato = iter -> actual -> dato;
	nodo_t* borrar = iter -> actual;
	if(iter -> actual == iter->list -> primero){
		void* valor = lista_borrar_primero(iter -> list);
		iter -> actual = iter -> list -> primero;
		return valor;
	}else if(iter -> actual == iter -> list -> ultimo){
		iter -> anterior -> siguiente = iter -> actual -> siguiente;
		iter -> list -> ultimo = iter -> anterior;
		iter -> actual = iter -> anterior -> siguiente;
		
	}else{
		iter -> anterior -> siguiente = iter -> actual -> siguiente;
		iter -> actual = iter -> anterior -> siguiente;
	}
	iter -> list -> contador --;
	free(borrar);
	return dato;

}
/* *****************************************************************
 *                    PRIMITIVAS ITERADOR INTERNO
 * *****************************************************************/

void lista_iterar(lista_t *lista, bool visitar(void *dato, void *extra), void *extra){
	lista_iter_t* iter = lista_iter_crear(lista);

	while(iter -> actual){
		void* valor = lista_iter_ver_actual(iter);
		bool estado = visitar(valor,extra);
		if(!estado) break;
		iter -> actual = iter -> actual -> siguiente;
	}
	lista_iter_destruir(iter);
}
