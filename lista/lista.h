#ifndef PILA_H
#define PILA_H

#include <stdbool.h>
#include <stdlib.h>

/* ******************************************************************
 *                DEFINICION DE LOS TIPOS DE DATOS
 * *****************************************************************/

/* La cola está planteada como una cola de punteros genéricos. */
typedef struct lista lista_t;

/* ******************************************************************
 *                    PRIMITIVAS DE LA COLA
 * *****************************************************************/

// Crea una lista.
// Post: devuelve una nueva lista vacía.
lista_t *lista_crear(void);

// Devuelve verdadero si la lista no tiene elementos encolados, false en caso contrario.
// Pre: la lista fue creada.
bool lista_esta_vacia(const lista_t *lista);

//inserta un elemento al principio de la lista
//devuelve true si inserto elemento, false en caso contrario
//pre: lista fue creada
//post: inserta elemento el principio de la lista
bool lista_insertar_primero(lista_t *lista, void *dato);

//inserta un elemento al final de la lista
//devuelve true si inserto elemento, false en caso contrario
//pre: lista fue creada
//post: inserta elemento al final de la lista
bool lista_insertar_ultimo(lista_t *lista, void *dato);

//elimina un elemento al principio de la lista
//devuelve el elemento, si la lista esta vacia devuelve null
//pre: lista fue creada
//post: elimina elemento al principio de la lista
void *lista_borrar_primero(lista_t *lista);

// Obtiene el valor del primer elemento de la lista. Si la lista tiene
// elementos, se devuelve el valor del primero, si está vacía devuelve NULL.
// Pre: la lista fue creada.
// Post: se devolvió el primer elemento de la lista, cuando no está vacía.
void *lista_ver_primero(const lista_t *lista);

// Obtiene el valor del ultimo elemento de la lista. Si la lista tiene
// elementos, se devuelve el valor del ultimo, si está vacía devuelve NULL.
// Pre: la lista fue creada.
// Post: se devolvió el ultimo elemento de la lista, cuando no está vacía.
void *lista_ver_ultimo(const lista_t* lista);

//obtiene el largo de la lista
size_t lista_largo(const lista_t *lista);

// Destruye la lista. Si se recibe la función destruir_dato por parámetro,
// para cada uno de los elementos de la lista llama a destruir_dato.
// Pre: la lista fue creada. destruir_dato es una función capaz de destruir
// los datos de la lista, o NULL en caso de que no se la utilice.
// Post: se eliminaron todos los elementos de la lista.
void lista_destruir(lista_t *lista, void destruir_dato(void *));

/* ******************************************************************
 *                    PRIMITIVAS ITERADOR EXTERNO
 * *****************************************************************/
typedef struct lista_iter lista_iter_t;

// Crea un iterador.
// Post: devuelve un iterador apuntando al primer elemento.
lista_iter_t *lista_iter_crear(lista_t *lista);

//cambia la referencias del anterior y del actual al siguiente respectivamente
//si la lista esta vacia devuelve null, caso contrario true
//pre: lista creada
//post: devuelve true si se puede avanzar
bool lista_iter_avanzar(lista_iter_t *iter);

//
void *lista_iter_ver_actual(const lista_iter_t *iter);
bool lista_iter_al_final(const lista_iter_t *iter);
void lista_iter_destruir(lista_iter_t *iter);
bool lista_iter_insertar(lista_iter_t *iter, void *dato);
void *lista_iter_borrar(lista_iter_t *iter);

/* ******************************************************************
 *                    PRIMITIVAS ITERADOR INTERNO
 * *****************************************************************/
void lista_iterar(lista_t *lista, bool visitar(void *dato, void *extra), void *extra);


/* *****************************************************************
 *                      PRUEBAS UNITARIAS
 * *****************************************************************/

// Realiza pruebas sobre la implementación del alumno.
//
// Las pruebas deben emplazarse en el archivo ‘pruebas_alumno.c’, y
// solamente pueden emplear la interfaz pública tal y como aparece en lista.h
// (esto es, las pruebas no pueden acceder a los miembros del struct lista).
//
// Para la implementación de las pruebas se debe emplear la función
// print_test(), como se ha visto en TPs anteriores.
void pruebas_lista_alumno(void);

#endif // PILA_H
