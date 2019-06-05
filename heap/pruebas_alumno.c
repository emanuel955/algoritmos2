#include "heap.h"
#include "testing.h"
#include <stddef.h>

int comparar_min(const void *a, const void *b){
	if(a < b)return -1;
	if(a > b)return 1;
	if(a == b)return 0;
}
int comparar_max(const void *a, const void *b){
	if(a < b)return -1;
	if(a > b)return 1;
	if(a == b)return 0;
}

void prueba_NULL(){
	heap_t* = crear_heap(comparar_min);
	
}



void pruebas_heap_alumno(void){

}