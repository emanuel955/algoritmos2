#include "heap.h"
#include <stdio.h>

struct heap{
	void** datos;
	size_t cant;
	size_t tam;
	cmp_func_t cmp;
};
/**************************************************/
/*			funciones para heap 				  */
/**************************************************/
void upheap(void** arreglo, size_t pos, cmp_func_t cmp){
	if(pos == 0)return;
	size_t padre = (pos - 1) / 2;
	if(cmp(arreglo[padre],arreglo[pos])>0){
		swap(&arreglo[padre],&arreglo[pos]);
		upheap(arreglo,padre,cmp);
	}

}
void downheap(void** arreglo, size_t tam, size_t pos, cmp_func_t cmp)
void swap (int* x, int* y) {
	int a = *x, b = *y;
	*x = b;
	*y = a;
}
//size_t burcar_padre(size_t pos_hijo){
//	return (pos - 1) / 2;
//}

/**************************************************/
/*			primitivas del heap 				  */
/**************************************************/
#define VALOR_INICIAL 20
heap_t *heap_crear(cmp_func_t cmp){
	heap_t* heap = malloc(sizeof(heap_t));
	if(!heap) return NULL;

	heap -> tam = VALOR_INICIAL;
	heap -> cant = 0;
	heap -> datos = malloc(heap -> capacidad * sizeof(void*));
	if(!datos){
		free(heap);
		return NULL;
	}
	heap -> cmp = cmp;
	return heap;

}
heap_t *heap_crear_arr(void *arreglo[], size_t n, cmp_func_t cmp){
	heap_t* heap = heap_crear(cmp);
	if(!heap) return NULL;

}
bool heap_encolar(heap_t *heap, void *elem){
	if(!heap || !elem) return false;
	heap -> datos[heap -> cant] = elem;
	heap -> heap_cantidad++;
	upheap(heap -> datos, heap -> cant -1, heap -> cmp);
	return true;
}
void *heap_desencolar(heap_t *heap){
	if(!heap)return NULL;
	if(heap_esta_vacio(heap)) return NULL;

	size_t raiz = heap -> datos[0];
	if(heap -> cant == 1){
		heap -> cant--;
		return raiz;
	}
	size_t ultimo = heap -> dato[heap -> cant - 1];
	swap(&raiz,&ultimo);
	heap -> cant --;

	downheap(heap -> datos,heap -> tam,,heap -> cmp);
	
	return ultimo;
}
size_t heap_cantidad(const heap_t *heap){
	return heap -> cant;
}
bool heap_esta_vacio(const heap_t *heap){
	if(!heap) return false;
	return heap -> cant == 0;
}
void *heap_ver_max(const heap_t *heap){
	if(!heap)return NULL;
	return heap -> datos[0];
}