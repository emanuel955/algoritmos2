#include "heap.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comparar_min(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}
int comparar_max(const void *a, const void *b){
	return *(int*)b - *(int*)a;
}
int comp_cad(const void *a, const void *b){
	printf("comparacion = %d\n",strcmp(a,b));
	return strcmp(a,b);
}

int a = 3;
int b = 8;
int c = 7;


int x=5,y=9,z=10,w=2,q=7,r=1;
/*void prueba_heap_min(){
	printf("PRUEBA HEAP MIN\n");
	heap_t* heap = heap_crear(comparar_min);

	print_test("encolar x = 5", heap_encolar(heap,&x) == true);
	print_test("encolar y = 9", heap_encolar(heap,&y) == true);
	print_test("ver maximo es x = 5",heap_ver_max(heap) == &x);
	print_test("no esta vacio", heap_esta_vacio(heap) == false);

	print_test("encolar z = 10", heap_encolar(heap,&z) == true);
	print_test("ver maximo es x = 5",heap_ver_max(heap) == &x);

	print_test("encolar w = 2", heap_encolar(heap,&w) == true);
	print_test("ver maximo es w = 2",heap_ver_max(heap) == &w);

	print_test("encolar q = 7", heap_encolar(heap,&q) == true);
	print_test("ver maximo es w = 2",heap_ver_max(heap) == &w);

	print_test("encolar r = 1", heap_encolar(heap,&r) == true);
	print_test("ver maximo es r = 1",heap_ver_max(heap) == &r);

	print_test("cantidad es 6",heap_cantidad(heap) == 6);
	//----------------------------------------------------------------
	print_test("desencolar r = 1", heap_desencolar(heap) == &r);
	print_test("ver maximo es w = 2",heap_ver_max(heap) == &w);
	print_test("cantidad es 5",heap_cantidad(heap) == 5);

	//-----------------------------------------------------
	print_test("desencolar w = 2", heap_desencolar(heap) == &w);
	print_test("ver maximo es x = 5",heap_ver_max(heap) == &x);
	print_test("cantidad es 4",heap_cantidad(heap) == 4);
	//---------------------------------------------------------
	print_test("desencolar x = 5", heap_desencolar(heap) == &x);
	print_test("desencolar q = 7", heap_desencolar(heap) == &q);
	print_test("desencolar y = 9", heap_desencolar(heap) == &y);
	print_test("desencolar z = 10", heap_desencolar(heap) == &z);
	print_test("cantidad es 0",heap_cantidad(heap) == 0);
	//------------------------------------------------------------
	print_test("desencolar es null",heap_desencolar(heap) == NULL);
	print_test("esta vacio", heap_esta_vacio(heap) == true);
	print_test("ver maximo es null",heap_ver_max(heap) == NULL);

	print_test("encolar x = 5", heap_encolar(heap,&x) == true);
	print_test("encolar y = 9", heap_encolar(heap,&y) == true);

	heap_destruir(heap,NULL);

}
void prueba_heap_max(){
	printf("PRUEBA HEAP MAX\n");
	heap_t* heap = heap_crear(comparar_max);

	print_test("encolar a = 5", heap_encolar(heap,&a) == true);
	print_test("encolar b = 8", heap_encolar(heap,&b) == true);
	print_test("ver maximo es B = 8",heap_ver_max(heap) == &b);

	print_test("encolar c = 7", heap_encolar(heap,&c) == true);
	print_test("ver maximo es B = 8",heap_ver_max(heap) == &b);
	print_test("cantidad es 3",heap_cantidad(heap) == 3);

	print_test("desencolar b = 8", heap_desencolar(heap) == &b);
	print_test("ver maximo es c = 7",heap_ver_max(heap) == &c);

	heap_destruir(heap,NULL);
	print_test("DESTRUYO EL HEAP",true);

}*/
void pruebas_cadena(){
	printf("PRUEBA CON CADENAS \n");
	heap_t* heap = heap_crear(comp_cad);

	char i[] = "chau";
	char e[] = "hola";
	char f[] = "como";
	char k[] = "abc";
	
	print_test("encolar chau", heap_encolar(heap,&i) == true);
	print_test("encolar abc", heap_encolar(heap,&k) == true);
	print_test("ver maximo es como",heap_ver_max(heap) == &k);

	print_test("encolar hola", heap_encolar(heap,&e) == true);
	print_test("ver maximo es hola",heap_ver_max(heap) == &k);

	print_test("cantidad es 3",heap_cantidad(heap) == 3);
	print_test("encolar como", heap_encolar(heap,&f) == true);
	print_test("ver maximo es abc",heap_ver_max(heap) == &k);

	print_test("desencolar abc", heap_desencolar(heap) == &k);
	print_test("ver maximo es chau",heap_ver_max(heap) == &i);

	print_test("desencolar chau", heap_desencolar(heap) == &i);
	//print_test("ver maximo es como",heap_ver_max(heap) == &f);

	heap_destruir(heap,NULL);
	print_test("DESTRUYO EL HEAP",true);

}


void pruebas_heap_alumno(void){
	//prueba_vacio_y_null();
	//prueba_un_elemento();
	//pruebas_destruir();
	//prueba_heap_min();
	pruebas_cadena();

}