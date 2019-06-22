#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define AUMENTA 2
#define REDUCE 4
#define VALOR_INICIAL 20

struct heap{
	void** datos;
	size_t cant;
	size_t tam;
	cmp_func_t cmp;
};
/**************************************************/
/*			funciones para heap 				  */
/**************************************************/
void swap (void** x, void** y) {
	void* a = *x;
	*x = *y;
	*y = a;
}

void upheap(void** arreglo, size_t pos, cmp_func_t cmp){
	if(pos == 0)return;
	size_t padre = (pos - 1) / 2;
	if(cmp(arreglo[padre],arreglo[pos]) < 0){
		swap(&arreglo[padre],&arreglo[pos]);
		upheap(arreglo,padre,cmp);
	}

}
void downheap(void** arreglo, size_t cantidad, size_t pos, cmp_func_t cmp){
	if(pos >= cantidad)return;
	size_t max = pos;
	size_t izq = 2 * pos + 1;
	size_t der = 2 * pos + 2;
	if(izq < cantidad && cmp(arreglo[izq],arreglo[max]) > 0){
		max = izq;
	}
	if(der < cantidad && cmp(arreglo[der],arreglo[max]) > 0){
		max = der;
	}
	if(max != pos){
		swap(&arreglo[pos],&arreglo[max]);
		downheap(arreglo,cantidad,max,cmp);
	}
}


bool heap_redimensionar(heap_t* heap, size_t tam_nuevo) {
    void* datos_nuevo = realloc(heap->datos, tam_nuevo * sizeof(void*));

    if (datos_nuevo == NULL) {
        return false;
    }

    heap->datos = datos_nuevo;
    heap->tam = tam_nuevo;
    return true;
}
void heapify(void* arreglo[], size_t cant, cmp_func_t cmp){
	size_t n = (cant / 2) - 1;
	for(size_t i = n; i + 1 > 0; i--){
		downheap(arreglo, cant, i,cmp);
	}
}

/**************************************************/
/*			primitivas del heap 				  */
/**************************************************/

heap_t *heap_crear(cmp_func_t cmp){
	heap_t* heap = malloc(sizeof(heap_t));
	if(!heap) return NULL;

	heap -> tam = VALOR_INICIAL;
	heap -> cant = 0;
	heap -> datos = malloc(heap -> tam * sizeof(void*));
	if(! heap -> datos){
		free(heap);
		return NULL;
	}
	heap -> cmp = cmp;
	return heap;
}
heap_t *heap_crear_arr(void *arreglo[], size_t n, cmp_func_t cmp){
	heap_t* heap = heap_crear(cmp);
	if(!heap) return NULL;

	for(size_t i = 0; i < n; i++){
		heap -> datos[i] = arreglo[i];
		heap -> cant++;
	}
	heapify(heap -> datos,heap -> cant,cmp);
	return heap;

}
bool heap_encolar(heap_t *heap, void *elem){
	if(!heap || !elem) return false;
	if(heap -> cant == heap -> tam){
		bool estado = heap_redimensionar(heap, AUMENTA * heap -> tam);
		if(!estado) return false;
	}
	heap -> datos[heap -> cant] = elem;
	heap -> cant++;
	upheap(heap -> datos, heap -> cant - 1, heap -> cmp);
	return true;
}
void *heap_desencolar(heap_t *heap){
	if(!heap)return NULL;
	if(heap_esta_vacio(heap)) return NULL;

	swap(&heap -> datos[0],&heap -> datos[heap -> cant - 1]);

	heap -> cant --;

	downheap(heap -> datos, heap -> cant , 0, heap -> cmp);

	void* raiz = heap -> datos[heap -> cant];

	if (heap -> cant == heap -> tam/REDUCE && heap -> cant / REDUCE > VALOR_INICIAL){
		heap_redimensionar(heap, heap -> tam / REDUCE);
	}
	return raiz;
}
size_t heap_cantidad(const heap_t *heap){
	return heap -> cant;
}
bool heap_esta_vacio(const heap_t *heap){
	if(!heap) return false;
	return heap_cantidad(heap) == 0;
}
void *heap_ver_max(const heap_t *heap){
	if(!heap)return NULL;
	if(heap_esta_vacio(heap)) return NULL;
	return heap -> datos[0];
}
void heap_destruir(heap_t *heap, void destruir_elemento(void *e)){
	if(!heap)return;
	for(size_t i = 0; i < heap -> cant; i++){
		if(destruir_elemento){
			destruir_elemento(heap -> datos[i]);
		}
	}
	free(heap -> datos);
	free(heap);
}
/**************************************************/
/*			 heapsort							  */
/**************************************************/
void heap_sort(void *elementos[], size_t cant, cmp_func_t cmp){
	heapify(elementos,cant,cmp);

	size_t pos = 1;
	while(pos < cant){
		swap(&elementos[0],&elementos[cant - pos]);
		downheap(elementos,cant - pos,0,cmp);
		pos++;
	}

}