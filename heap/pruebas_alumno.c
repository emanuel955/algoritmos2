#include "heap.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comparar_a_b(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}
int comparar_b_a(const void *a, const void *b){
	return *(int*)b - *(int*)a;
}
int comp_cad(const void *a, const void *b){
	printf("restultado de la comparacion = %d\n",strcmp(a,b));
	return strcmp(a,b);
}
int a = 3;
int b = 8;
int c = 7;
void prueba_vacio_y_null(){
	printf("PRUEBAS VACIO Y NULL\n");
	heap_t* heap = heap_crear(comparar_a_b);

	print_test("esta vacio", heap_esta_vacio(heap) == true);
	print_test("desencolar es null",heap_desencolar(heap) == NULL);
	print_test("ver maximo es null",heap_ver_max(heap) == NULL);
	print_test("cantidad es 0",heap_cantidad(heap) == 0);

	print_test("encolar null", heap_encolar(heap,NULL) == false);

	heap_destruir(heap,NULL);
	print_test("DESTRUYO EL HEAP",true);
	
}
void prueba_un_elemento(){
	printf("PRUEBA UN ELEMENTO\n");
	heap_t* heap = heap_crear(comparar_a_b);

	print_test("encolar a = 3", heap_encolar(heap,&a) == true);
	print_test("no esta vacio", heap_esta_vacio(heap) == false);
	print_test("ver maximo es a = 3",heap_ver_max(heap) == &a);
	print_test("cantidad es 1",heap_cantidad(heap) == 1);

	print_test("desencolar es a =",heap_desencolar(heap) == &a);
	print_test("esta vacio", heap_esta_vacio(heap) == true);
	print_test("ver maximo es NULL",heap_ver_max(heap) == NULL);
	print_test("cantidad es 0",heap_cantidad(heap) == 0);

	heap_destruir(heap,NULL);
	print_test("DESTRUYO EL HEAP",true);
}

int x=5,y=9,z=10,w=2,q=71,r=1;
void prueba_heap_min(){
	printf("PRUEBA HEAP Max\n");
	heap_t* heap = heap_crear(comparar_a_b);

	print_test("encolar x = 5", heap_encolar(heap,&x) == true);
	print_test("encolar y = 9", heap_encolar(heap,&y) == true);
	print_test("ver maximo es y = 9",heap_ver_max(heap) == &y);
	print_test("no esta vacio", heap_esta_vacio(heap) == false);

	print_test("encolar z = 10", heap_encolar(heap,&z) == true);
	print_test("ver maximo es z = 10",heap_ver_max(heap) == &z);

	print_test("encolar w = 2", heap_encolar(heap,&w) == true);
	print_test("ver maximo es z = 10",heap_ver_max(heap) == &z);

	print_test("encolar q = 71", heap_encolar(heap,&q) == true);
	print_test("ver maximo es q = 71",heap_ver_max(heap) == &q);

	print_test("encolar r = 1", heap_encolar(heap,&r) == true);
	print_test("ver maximo es q = 71",heap_ver_max(heap) == &q);

	print_test("cantidad es 6",heap_cantidad(heap) == 6);
	//----------------------------------------------------------------
	print_test("desencolar q = 71", heap_desencolar(heap) == &q);
	print_test("ver maximo es z = 10",heap_ver_max(heap) == &z);
	print_test("cantidad es 5",heap_cantidad(heap) == 5);

	//-----------------------------------------------------
	print_test("desencolar z = 10", heap_desencolar(heap) == &z);
	print_test("ver maximo es y = 9",heap_ver_max(heap) == &y);
	print_test("cantidad es 4",heap_cantidad(heap) == 4);
	//---------------------------------------------------------
	print_test("desencolar y = 9", heap_desencolar(heap) == &y);
	print_test("desencolar x = 5", heap_desencolar(heap) == &x);
	print_test("desencolar w = 2", heap_desencolar(heap) == &w);
	print_test("desencolar r = 1", heap_desencolar(heap) == &r);
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
	printf("PRUEBA HEAP Min\n");
	heap_t* heap = heap_crear(comparar_b_a);

	print_test("encolar x = 5", heap_encolar(heap,&x) == true);
	print_test("encolar y = 9", heap_encolar(heap,&y) == true);
	print_test("ver maximo es x = 5",heap_ver_max(heap) == &x);
	print_test("no esta vacio", heap_esta_vacio(heap) == false);

	print_test("encolar z = 10", heap_encolar(heap,&z) == true);
	print_test("ver maximo es x = 5",heap_ver_max(heap) == &x);

	print_test("encolar w = 2", heap_encolar(heap,&w) == true);
	print_test("ver maximo es w = 2",heap_ver_max(heap) == &w);

	print_test("encolar q = 71", heap_encolar(heap,&q) == true);
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
	print_test("desencolar y = 9", heap_desencolar(heap) == &y);
	print_test("desencolar z = 10", heap_desencolar(heap) == &z);
	print_test("desencolar q = 71", heap_desencolar(heap) == &q);
	print_test("cantidad es 0",heap_cantidad(heap) == 0);
	//------------------------------------------------------------
	print_test("desencolar es null",heap_desencolar(heap) == NULL);
	print_test("esta vacio", heap_esta_vacio(heap) == true);
	print_test("ver maximo es null",heap_ver_max(heap) == NULL);

	print_test("encolar x = 5", heap_encolar(heap,&x) == true);
	print_test("encolar y = 9", heap_encolar(heap,&y) == true);
	
	heap_destruir(heap,NULL);
}
void prueba_arreglo(){
	printf("PRUEBA ARREGLO \n");
	int pos1 = 5, pos2 = 9, pos3 = 10, pos4 = 2, pos5 = 71, pos6 = 1;
	void* arreglo[] = {&pos1,&pos2,&pos3,&pos4,&pos5,&pos6};
	heap_t* heap = heap_crear_arr(arreglo,6,comparar_a_b);

	print_test("el maximo es 71", heap_ver_max(heap) == &pos5);
	print_test("cantidad es 6",heap_cantidad(heap) == 6);
	print_test("desencolar  71", heap_desencolar(heap) == &pos5);

	print_test("el maximo es 10", heap_ver_max(heap) == &pos3);
	print_test("cantidad es 6",heap_cantidad(heap) == 5);

	heap_destruir(heap,NULL);

}
static void borrar(void* num){
	free(num);
}
void pruebas_destruir(){
	printf("PRUEBA DESTRUIR \n");
	heap_t* heap = heap_crear(comparar_a_b);

	int* uno = malloc(sizeof(int));
	int* dos = malloc(sizeof(int));

	*uno = 1;
	*dos = 2;

	print_test("encolar uno", heap_encolar(heap,uno) == true);
	print_test("encolar dos", heap_encolar(heap,dos) == true);

	heap_destruir(heap,borrar);
	print_test("DESTRUYO EL HEAP",true);

}

void prueba_heapsort(){
	printf("PRUEBA heapsort \n");
	int pos1 = 5, pos2 = 9, pos3 = 10, pos4 = 2, pos5 = 71, pos6 = 1;
	void* arreglo[6] = {&pos1,&pos2,&pos3,&pos4,&pos5,&pos6};

	heap_sort(arreglo,6,comparar_a_b);

	for(int i = 0; i < 6; i++){
		printf("%d\n",*(int*)arreglo[i]);
	}

}
void prueba_volumen(){
	bool ok = true;
	heap_t* heap = heap_crear(comparar_a_b);
	int v[500];
	for(int i=0; i < 500; i++){
		v[i] = i;
		ok &= heap_encolar(heap, &v[i]);
	}
	print_test("se pudieron guardar todos los elementos", ok);
	for(int i=0; i < 200 ; i++){
		heap_desencolar(heap);
	}
	print_test("se pudieron desencolar 200 los elementos", ok);
	heap_destruir(heap,NULL);
}

void pruebas_heap_alumno(void){
	prueba_vacio_y_null();
	prueba_un_elemento();
	prueba_heap_min();
	prueba_heap_max();
	prueba_arreglo();
	pruebas_destruir();
	prueba_heapsort();
	prueba_volumen();

}
