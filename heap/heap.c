#include "heap.h"
#include <stdio.h>

#define AUMENTA 2
#define REDUCE 4

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
void downheap(void** arreglo, size_t cantidad, size_t pos, cmp_func_t cmp){
	if(pos >= cantidad)return;
	size_t padre = pos;
	size_t izq = 2 * pos + 1;
	size_t der = 2 * pos + 2;
	if(izq < cantidad && cmp(arreglo[izq],arreglo[padre])<0){
		padre = izq;
	}
	if(der < cantidad && cmp(arreglo[der],arreglo[padre])<0){
		padre = der;
	}
	if(padre != pos){
		swap(&arreglo[pos],&arreglo[padre]);
		downheap(arreglo,cantidad,padre,cmp);
	}
}
void swap (int* x, int* y) {
	int a = *x, b = *y;
	*x = b;
	*y = a;
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
	for(size_t i = n; i >= 0; i--){
		downheap(arreglo, cant, i,cmp);
	}
}

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

	for(size_t i = 0; i < n; i++){
		heap -> datos[i] = arreglo[i];
		heap -> cant++;
	}
	heapify(heap -> datos,heap -> cant,cmp);
	return heap;

}
bool heap_encolar(heap_t *heap, void *elem){
	if(!heap || !elem) return false;
	heap -> datos[heap -> cant] = elem;
	heap -> heap_cantidad++;
	upheap(heap -> datos, heap -> cant -1, heap -> cmp);

	if(heap -> cant == heap -> tam){
		bool estado = heap_redimensionar(heap, AUMENTA * heap -> tam);
		if(!estado) return false;
	}
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

	downheap(heap -> datos,heap -> cant,raiz,heap -> cmp);

	if (heap -> cant == heap -> tam/REDUCE && heap -> cant / REDUCE > VALOR_INICIAL){
		heap_redimensionar(heap, heap -> tam / REDUCE);
	}
	
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
/**************************************************/
/*			 heapsort							  */
/**************************************************/
void heap_sort(void *elementos[], size_t cant, cmp_func_t cmp){
	for(size_t i = cant - 1; i >= 0; i--){
		swap(&elementos[0],&elementos[i]);
		heapify(elementos,i,cmp);
	}

}