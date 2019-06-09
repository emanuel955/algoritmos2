#include "heap.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int comparar_min(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}
int comparar_max(const void *a, const void *b){
	return *(int*)b - *(int*)a;
}

void prueba_vacio_y_null(){
	printf("PRUEBAS VACIO Y NULL\n");
	heap_t* heap = heap_crear(comparar_min);

	print_test("esta vacio", heap_esta_vacio(heap) == true);
	print_test("desencolar es null",heap_desencolar(heap) == NULL);
	print_test("ver maximo es null",heap_ver_max(heap) == NULL);
	print_test("cantidad es 0",heap_cantidad(heap) == 0);

	print_test("encolar null", heap_encolar(heap,NULL) == false);

	heap_destruir(heap,NULL);
	print_test("DESTRUYO EL HEAP",true);
	
}

int a = 5;
void prueba_un_elemento(){
	printf("PRUEBA UN ELEMENTO\n");
	heap_t* heap = heap_crear(comparar_min);

	print_test("encolar null", heap_encolar(heap,&a) == true);
	print_test("esta vacio", heap_esta_vacio(heap) == false);
	print_test("ver maximo es a = 5",heap_ver_max(heap) == &a);
	print_test("cantidad es 0",heap_cantidad(heap) == 1);

	print_test("desencolar es null",heap_desencolar(heap) == &a);
	print_test("esta vacio", heap_esta_vacio(heap) == true);
	print_test("ver maximo es a = 5",heap_ver_max(heap) == NULL);
	print_test("cantidad es 0",heap_cantidad(heap) == 0);

	heap_destruir(heap,NULL);
	print_test("DESTRUYO EL HEAP",true);
}
int b = 8;
int c = 7;
void prueba_3_elementos(){
	printf("PRUEBA 3 ELEMENTO\n");
	heap_t* heap = heap_crear(comparar_min);

	print_test("encolar a = 5", heap_encolar(heap,&a) == true);
	print_test("no esta vacio", heap_esta_vacio(heap) == false);
	print_test("ver maximo es a = 5",heap_ver_max(heap) == &a);
	print_test("cantidad es 1",heap_cantidad(heap) == 1);

	print_test("encolar b = 8", heap_encolar(heap,&b) == true);
	print_test("no esta vacio", heap_esta_vacio(heap) == false);
	print_test("ver maximo es a = 5",heap_ver_max(heap) == &a);
	print_test("cantidad es 2",heap_cantidad(heap) == 2);

	print_test("encolar c = 7", heap_encolar(heap,&c) == true);
	print_test("no esta vacio", heap_esta_vacio(heap) == false);
	print_test("ver maximo es a = 5",heap_ver_max(heap) == &a);
	print_test("cantidad es 3",heap_cantidad(heap) == 3);

	print_test("desencolar es a = 5",heap_desencolar(heap) == &a);
	print_test("no esta vacio", heap_esta_vacio(heap) == false);
	print_test("ver maximo es c = 7",heap_ver_max(heap) == &c);
	print_test("cantidad es 2",heap_cantidad(heap) == 2);

	print_test("desencolar es c = 7",heap_desencolar(heap) == &c);
	print_test("no esta vacio", heap_esta_vacio(heap) == false);
	print_test("ver maximo es b = 8",heap_ver_max(heap) == &b);
	print_test("cantidad es 1",heap_cantidad(heap) == 1);

	print_test("desencolar es b = 8",heap_desencolar(heap) == &b);
	print_test("esta vacio", heap_esta_vacio(heap) == true);
	print_test("ver maximo es null",heap_ver_max(heap) == NULL);
	print_test("cantidad es 0",heap_cantidad(heap) == 0);

	heap_destruir(heap,NULL);
}
void pruebas_destruir(){
	printf("PRUEBA DESTRUIR\n");
	heap_t* heap = heap_crear(comparar_min);

	print_test("encolar a = 5", heap_encolar(heap,&a) == true);
	print_test("encolar b = 8", heap_encolar(heap,&b) == true);
	print_test("encolar c = 7", heap_encolar(heap,&c) == true);
	print_test("cantidad es 3",heap_cantidad(heap) == 3);

	heap_destruir(heap,NULL);
	print_test("DESTRUYO EL HEAP",true);
}
int x=5,y=9,z=10,w=12,q=11,r=2;
void prueba_heap_min(){
	printf("PRUEBA HEAP MIN\n");
	heap_t* heap = heap_crear(comparar_min);

	print_test("encolar x = 5", heap_encolar(heap,&a) == true);
	print_test("encolar y = 9", heap_encolar(heap,&b) == true);
	print_test("ver maximo es x = 5",heap_ver_max(heap) == &x);
	print_test("ver maximo es x = 5",heap_ver_max(heap) == &y);

	print_test("encolar z = 10", heap_encolar(heap,&c) == true);
	print_test("ver maximo es x = 5",heap_ver_max(heap) == &x);

	print_test("encolar w = 12", heap_encolar(heap,&a) == true);
	print_test("ver maximo es x = 5",heap_ver_max(heap) == &x);

	print_test("encolar q = 11", heap_encolar(heap,&b) == true);
	print_test("ver maximo es x = 5",heap_ver_max(heap) == &x);

	print_test("encolar r = 2", heap_encolar(heap,&c) == true);
	print_test("ver maximo es r = 2",heap_ver_max(heap) == &r);

	print_test("cantidad es 6",heap_cantidad(heap) == 6);



}


void pruebas_heap_alumno(void){
	prueba_vacio_y_null();
	prueba_un_elemento();
	prueba_3_elementos();
	pruebas_destruir();
	prueba_heap_min();

}