#include "cola.h"
#include "testing.h"
#include <stddef.h>
#include <stdlib.h>

#define VACIO NULL
void pruebas_cola_vacia(){
	cola_t* cola = cola_crear();

	print_test("ve el primer elemento de la cola vacia",cola_ver_primero(cola)== VACIO);
	print_test("desencolar cola vacia",cola_desencolar(cola) == VACIO);
	cola_destruir(cola,NULL);
}
int a = 5;

void pruebas_con_un_elemento(){
	cola_t* cola = cola_crear();

	print_test("agrega NULL a la cola",cola_encolar(cola,NULL));
	print_test("ve el primer elemento de la cola",cola_ver_primero(cola)==NULL);
	print_test("desencola NULL",cola_desencolar(cola)== NULL);
	print_test("ve el primer elemento de la cola vacia",cola_ver_primero(cola)==VACIO);

	print_test("agrega un elemento a la cola a=5",cola_encolar(cola,&a));
	print_test("ve el primer elemento de la cola",cola_ver_primero(cola)==&a);
	print_test("desencola a=5",cola_desencolar(cola) == &a);
	print_test("ve el primer elemento de la cola vacia",cola_ver_primero(cola)==VACIO);
	print_test("desencolar cola vacia",cola_desencolar(cola) == VACIO);



	cola_destruir(cola,NULL);
}
char f = 'f';
void pruebas_con_elementos(){
	cola_t* cola = cola_crear();

	print_test("agrega a=5 a la cola",cola_encolar(cola,&a));
	print_test("agrega f='f' a la cola",cola_encolar(cola,&f));
	print_test("agrega NULL a la cola",cola_encolar(cola,NULL));
	print_test("ve el primer elemento de la cola",cola_ver_primero(cola)==&a);
	print_test("desencola 5",cola_desencolar(cola));

	print_test("ve el primer elemento de la cola",cola_ver_primero(cola)==&f);
	print_test("desencola f",cola_desencolar(cola)==&f);
	print_test("ve el primer elemento de la cola",cola_ver_primero(cola)==NULL);
	print_test("desencola nul",cola_desencolar(cola)==NULL);
	cola_destruir(cola,NULL);
}
bool ok = true;
void pruebas_cola_volumen(){
	cola_t* cola = cola_crear();


	int v[500];
	for(int i=0; i < 500; i++){
		v[i] = i;
		ok &= cola_encolar(cola, &v[i]);
	}
	print_test("se pudieron guardar todos los elementos", ok);
	print_test("ve el primer elemento de la cola",cola_ver_primero(cola)== v);
	for(int i=0; i < 100 ; i++){
		cola_desencolar(cola);
	}
	cola_destruir(cola,NULL);
}

static void liberar(void* punteros){
	free(punteros);
}
void pruebas_punteros_dinamicos(){
	int* p;
	float* r;
	cola_t* cola = cola_crear();
	p = malloc(sizeof(int));
	r = malloc(sizeof(float));
	print_test("se pudo guardar puntero", cola_encolar(cola,p));
	print_test("se pudo guardar puntero", cola_encolar(cola,r));
	cola_destruir(cola,liberar);
}


void pruebas_cola_alumno() {
    cola_t* ejemplo = NULL;

    print_test("Puntero inicializado a NULL", ejemplo == NULL);

    pruebas_cola_vacia();
    pruebas_con_un_elemento();
    pruebas_con_elementos();
    pruebas_cola_volumen();
    pruebas_punteros_dinamicos();  
}