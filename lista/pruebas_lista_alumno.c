#include "lista.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


/* ******************************************************************
 *                   FUNCION ITERADOR EXTERNO
 * *****************************************************************/

int m = 8;
int d = 5;
char p = 'g';
int v[5] = {1,2,3,4,5};
void imprimir_iter_externo(lista_t *lista){
	lista_iter_t *iter = lista_iter_crear(lista);
	int posicion = 0;
	int x= 0;

	while (!lista_iter_al_final(iter)){
		void* elemento = lista_iter_ver_actual(iter);

		posicion ++;
		printf("%d. %p\n", posicion, elemento);

		if(posicion == 1){
			//prueba al principio
			print_test("inserto el primer elemento",lista_iter_insertar(iter,&m)== true);
			print_test("elimino el primer elemento",lista_iter_borrar(iter) == &m);
			print_test("inserto el primer elemento",lista_iter_insertar(iter,&m)== true);
		}
		if(posicion == lista_largo(lista)/2){
			//prueba en la mitad
			print_test("inserto en la mitad",lista_iter_insertar(iter,&v[0+x])== true);
			print_test("elimino el de la mitad",lista_iter_borrar(iter) == &v[0+x]);
			print_test("inserto el la mitad",lista_iter_insertar(iter,&v[0+x])== true);
			x++;
		}
		if(posicion == lista_largo(lista)){
			//prueba al final
			print_test("inserto al final",lista_iter_insertar(iter,&v[x])== true);
			print_test("elimino el ultimo",lista_iter_borrar(iter) == &v[x]);
			print_test("inserto el en final",lista_iter_insertar(iter,&v[x])== true);
		}
		lista_iter_avanzar(iter);
	}
	printf("hay %d elementos\n", posicion);
	lista_iter_destruir(iter);
}
/* ******************************************************************
 *                   FUNCION ITERADOR INTERNO
 * *****************************************************************/
bool imprimir_dato(void *elemento, void *extra)
{
    
    printf("%d\n", *(int*)elemento);

    return true; // seguir iterando
}

void imprimir_iter_interno(lista_t *lista)
{
	
    lista_iterar(lista, imprimir_dato, NULL);
}
/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/
#define VACIO NULL //no es dato
void pruebas_crear_lista_vacia(){
	printf("PRUEBAS LISTA VACIA\n");
	lista_t* lista = lista_crear();
	print_test("Prueba esta_vacia sin elementos", lista_esta_vacia(lista) == true);
	print_test("prueba borrar_primero sin elementos", lista_borrar_primero(lista) == VACIO);
	print_test("prueba ver_primero sin elementos", lista_ver_primero(lista) == VACIO);
	print_test("prueba ver_ultimo sin elementos", lista_ver_ultimo(lista) == VACIO);
	print_test("prueba largo sin elementos 0", lista_largo(lista) == 0);

	lista_iter_t *iter = lista_iter_crear(lista);
	print_test("inserto el primer elemento",lista_iter_insertar(iter,&m)== true);
	print_test("prueba largo sin elementos 1", lista_largo(lista) == 1);
	print_test("ver actual",lista_iter_ver_actual(iter)== &m);
	print_test("prueba ver_primero", lista_ver_primero(lista) == &m);
	print_test("prueba ver_ultimo", lista_ver_ultimo(lista) == &m);


	lista_iter_destruir(iter);

   
    lista_destruir(lista,NULL);
}

void pruebas_valor_null(){
	printf("PRUEBAS LISTA NULL\n");
	lista_t* lista = lista_crear();
	print_test("Prueba inserta primero con elemento null", lista_insertar_primero(lista,NULL) == true);
	print_test("prueba ver_primero con el elemento null", lista_ver_primero(lista) == NULL);
	print_test("prueba ver_ultimo con el elemento null", lista_ver_ultimo(lista) == NULL);
	print_test("Prueba ver el largo con 1 elemento", lista_largo(lista) == 1);
	print_test("prueba borrar_primero con elemento null", lista_borrar_primero(lista) == NULL);
	print_test("Prueba inserta primero con elemento null", lista_insertar_primero(lista,NULL) == true);


	lista_iter_t *iter = lista_iter_crear(lista);
	print_test("inserto el primer elemento",lista_iter_insertar(iter,&m)== true);
	print_test("prueba largo sin elementos 2", lista_largo(lista) == 2);
	print_test("ver actual",lista_iter_ver_actual(iter)== &m);
	print_test("prueba ver_primero", lista_ver_primero(lista) == &m);
	print_test("prueba ver_ultimo", lista_ver_ultimo(lista) == NULL);
	
	
	print_test("prueba borrar primero", lista_iter_borrar(iter) == &m);

	lista_iter_destruir(iter);



	lista_destruir(lista,NULL);
}



void pruebas_con_valores(){
	printf("PRUEBAS LISTA CON VALORES \n");
	lista_t* lista = lista_crear();
	print_test("Prueba inserta primero con elemento 5", lista_insertar_primero(lista,&p) == true);

	print_test("Prueba inserta primero con elemento g", lista_insertar_ultimo(lista,&d) == true);
	print_test("prueba ver_primero con el elemento g", lista_ver_primero(lista) == &p);
	print_test("prueba ver_ultimo con el elemento 5", lista_ver_ultimo(lista) == &d);
	print_test("Prueba ver el largo con 2 elemento", lista_largo(lista) == 2);

	print_test("prueba borrar_primero con elemento g", lista_borrar_primero(lista) == &p);
	print_test("prueba ver_primero con el elemento 5", lista_ver_primero(lista) == &d);
	print_test("prueba ver_ultimo con el elemento 5", lista_ver_ultimo(lista) == &d);
	print_test("prueba largo con 1 elemento", lista_largo(lista) == 1);
	print_test("Prueba inserta primero con elemento g", lista_insertar_primero(lista,&p) == true);

	//iterador con dos elementos en la lista [p='g',d=5]
	imprimir_iter_externo(lista);
	print_test("prueba largo con 6", lista_largo(lista) == 6); //[v[0]=1,v[1]=2,m=3,p='g',d=5
	print_test("prueba ver_ultimo con el elemento 2", lista_ver_ultimo(lista) == &v[2]);
	print_test("prueba ver primero con el elemento 0", lista_ver_primero(lista) == &v[0]);

	imprimir_iter_interno(lista);

	lista_destruir(lista,NULL);


}
void pruebas_borrar(){
	lista_t* lista = lista_crear();
	lista_iter_t *iter = lista_iter_crear(lista);
	print_test("inserto el primer elemento",lista_iter_insertar(iter,&v[0])== true);
	print_test("inserto el primer elemento",lista_iter_insertar(iter,&v[1])== true);
	print_test("inserto el primer elemento",lista_iter_insertar(iter,&v[2])== true);
	print_test("inserto el primer elemento",lista_iter_insertar(iter,&v[3])== true);
	print_test("inserto el primer elemento",lista_iter_insertar(iter,&v[4])== true);
	int contador =0;
	while(!lista_iter_al_final(iter)){
		contador = 0;

		if(contador <= 4){
			printf("elimino el primer elemento%d\n",*(int*)lista_iter_borrar(iter));

			lista_iter_avanzar(iter);
			continue;
		}

	}

	lista_iter_destruir(iter);
	lista_destruir(lista,NULL);

}


void pruebas_volumen(){
	lista_t* lista = lista_crear();
	bool ok = true;
	int j[200];
	for (int i = 0; i < 100; ++i){
		j[i] = i;
		ok &= lista_insertar_primero(lista,&j[i]);
	}
	print_test("se pudieron alistar todos los elementos", ok);
	for (int i = 100; i < 200; ++i){
		j[i] = i;
		ok &= lista_insertar_ultimo(lista,&j[i]);
	}
	print_test("se pudieron alistar todos los elementos", ok);

	for (int i = 0; i < 100; ++i){
		lista_borrar_primero(lista);
	}
	print_test("se pudieron desalistar todos los elementos", ok);

	lista_destruir(lista,NULL);
}
static void liberar(void* punteros){
	free(punteros);
}
void pruebas_punteros_dinamicos(){
	int* h;
	float* r;
	lista_t* lista = lista_crear();
	h = malloc(sizeof(int));
	r = malloc(sizeof(float));
	print_test("se pudo guardar puntero", lista_insertar_primero(lista,h));
	print_test("se pudo guardar puntero", lista_insertar_ultimo(lista,r));
	lista_destruir(lista,liberar);
}

void pruebas_lista_alumno() {
    lista_t* ejemplo = NULL;

    print_test("Puntero inicializado a NULL", ejemplo == NULL);
    pruebas_crear_lista_vacia();
    pruebas_valor_null();
    pruebas_con_valores();
    pruebas_volumen();
    pruebas_punteros_dinamicos();
    pruebas_borrar();
}
