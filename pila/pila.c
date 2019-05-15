#include "pila.h"
#include <stdlib.h>

/* Definición del struct pila proporcionado por la cátedra.
 */
struct pila {
    void** datos;
    size_t cantidad;  // Cantidad de elementos almacenados.
    size_t capacidad;  // Capacidad del arreglo 'datos'.
};

/* *****************************************************************
 *                    PRIMITIVAS DE LA PILA
 * *****************************************************************/

// ...
#define VALOR_INICIAL 4
#define REDUCE 4
#define AUMENTA 2
pila_t* pila_crear(void){
	pila_t* pila = malloc(sizeof(pila_t));

	if (pila == NULL) {
		return NULL;
	}
	pila -> capacidad = VALOR_INICIAL;
	pila -> cantidad = 0;
	pila -> datos = malloc(pila ->capacidad * sizeof(void*));

	if (pila -> capacidad > 0 && pila->datos == NULL) {
		free(pila);
		return NULL;
	}
	
	return pila;
}
bool pila_redimensionar(pila_t* pila, size_t tam_nuevo) {
    void* datos_nuevo = realloc(pila->datos, tam_nuevo * sizeof(void*));

    if (datos_nuevo == NULL) {
        return false;
    }

    pila->datos = datos_nuevo;
    pila->capacidad = tam_nuevo;
    return true;
}
void pila_destruir(pila_t *pila){
	free(pila -> datos);
	free(pila);
}
bool pila_esta_vacia(const pila_t *pila){
	return pila -> cantidad == 0;
}
bool pila_apilar(pila_t *pila, void* valor){
	pila -> datos[pila -> cantidad] = valor;
	pila -> cantidad ++;
	if(pila -> cantidad == pila -> capacidad){
		bool estado = pila_redimensionar(pila, AUMENTA * pila->capacidad);
		if(!estado) return false;
	}
	return true;
}
void* pila_desapilar(pila_t *pila){
	if(pila_esta_vacia(pila)) return NULL;
	if (pila -> cantidad == pila -> capacidad/REDUCE && pila -> cantidad / REDUCE > VALOR_INICIAL){
		pila_redimensionar(pila,pila->capacidad / REDUCE);
	}
	pila -> cantidad --;
	return pila -> datos[pila -> cantidad];
}
void* pila_ver_tope(const pila_t *pila){
	if(pila_esta_vacia(pila))return NULL;
	return pila -> datos[pila -> cantidad -1];

}
