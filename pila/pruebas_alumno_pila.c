#include "pila.h"
#include "testing.h"
#include <stddef.h>


/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/


void pruebas_crear_pila_vacia(){
	pila_t* pila = pila_crear();
	print_test("Prueba esta_vacia sin elementos", pila_esta_vacia(pila) == true);
	print_test("prueba desapilar sin elementos", pila_desapilar(pila) == NULL);
	print_test("prueba ver_tope sin elementos", pila_ver_tope(pila) == NULL);
	pila_destruir(pila);
}
void pruebas_valor_null(){
	pila_t* pila = pila_crear();
	print_test("Prueba apilar con elemento null", pila_apilar(pila,NULL) == true);
	print_test("Prueba esta_vacia con un elemento", pila_esta_vacia(pila) == false);
	print_test("prueba ver_tope con un elemento", pila_ver_tope(pila) == NULL);
	print_test("prueba desapilar con un elemento", pila_desapilar(pila) == NULL);


	print_test("Prueba esta_vacia sin elementos", pila_esta_vacia(pila) == true);
	print_test("prueba desapilar sin elementos", pila_desapilar(pila) == NULL);
	print_test("prueba ver_tope sin elementos", pila_ver_tope(pila) == NULL);
	
	pila_destruir(pila);
}
int d = 5;
char p = 'g';

void pruebas_con_valores(){
	pila_t* pila = pila_crear();

	print_test("Prueba apilar con elemento null", pila_apilar(pila,&d) == true);
	print_test("Prueba apilar con elemento null", pila_apilar(pila,&p) == true);
	print_test("Prueba esta_vacia con un elemento", pila_esta_vacia(pila) == false);
	print_test("prueba ver_tope con un elemento", pila_ver_tope(pila) == &p);
	print_test("prueba desapilar con un elemento", pila_desapilar(pila) == &p);

	print_test("prueba ver_tope con un elemento", pila_ver_tope(pila) == &d);
	print_test("prueba desapilar con un elemento", pila_desapilar(pila) == &d);


	print_test("Prueba esta_vacia sin elementos", pila_esta_vacia(pila) == true);
	print_test("prueba desapilar sin elementos", pila_desapilar(pila) == NULL);
	print_test("prueba ver_tope sin elementos", pila_ver_tope(pila) == NULL);
	
	pila_destruir(pila);

}

int q = 5;
char r = 'g';
float z = 8.5;
void pruebas_con_redimencion(){
	pila_t* pila = pila_crear();

	print_test("Prueba apilar con elemento null", pila_apilar(pila,&d) == true);
	print_test("Prueba apilar con elemento null", pila_apilar(pila,&p) == true);
	print_test("Prueba apilar con elemento null", pila_apilar(pila,&q) == true);
	print_test("Prueba apilar con elemento null", pila_apilar(pila,&r) == true);
	print_test("Prueba apilar con elemento null", pila_apilar(pila,&z) == true);
	print_test("Prueba esta_vacia con un elemento", pila_esta_vacia(pila) == false);

	print_test("prueba ver_tope con un elemento", pila_ver_tope(pila) == &z);
	print_test("prueba desapilar con un elemento", pila_desapilar(pila) == &z);

	print_test("prueba ver_tope con un elemento", pila_ver_tope(pila) == &r);
	print_test("prueba desapilar con un elemento", pila_desapilar(pila) == &r);

	print_test("prueba ver_tope con un elemento", pila_ver_tope(pila) == &q);
	print_test("prueba desapilar con un elemento", pila_desapilar(pila) == &q);

	print_test("prueba ver_tope con un elemento", pila_ver_tope(pila) == &p);
	print_test("prueba desapilar con un elemento", pila_desapilar(pila) == &p);

	print_test("prueba ver_tope con un elemento", pila_ver_tope(pila) == &d);
	print_test("prueba desapilar con un elemento", pila_desapilar(pila) == &d);


	print_test("Prueba esta_vacia sin elementos", pila_esta_vacia(pila) == true);
	print_test("prueba desapilar sin elementos", pila_desapilar(pila) == NULL);
	print_test("prueba ver_tope sin elementos", pila_ver_tope(pila) == NULL);
	
	pila_destruir(pila);
}
void pruebas_volumen(){
	pila_t* pila = pila_crear();
	bool ok = true;
	int v[500];
	for (int i = 0; i < 500; ++i){
		v[i] = i;
		ok &= pila_apilar(pila,&v[i]);
	}
	print_test("se pudieron apilar todos los elementos", ok);

	for (int i = 0; i < 500; ++i){
		pila_desapilar(pila);
	}
	print_test("se pudieron desapilar todos los elementos", ok);

	pila_destruir(pila);
}

void pruebas_pila_alumno() {
    pila_t* ejemplo = NULL;

    print_test("Puntero inicializado a NULL", ejemplo == NULL);
    pruebas_crear_pila_vacia();
    pruebas_valor_null();
    pruebas_con_valores();
    pruebas_con_redimencion();
    pruebas_volumen();
}
