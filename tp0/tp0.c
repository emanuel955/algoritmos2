#include "tp0.h"

/* ******************************************************************
 *                     FUNCIONES A COMPLETAR
 * *****************************************************************/

/* swap() intercambia dos valores enteros.
 */
void swap (int* x, int* y) {
	int a = *x, b = *y;
	*x = b;
	*y = a;
}

/* maximo() busca el mayor elemento del arreglo y devuelve su posicion.
 * Si el vector es de largo 0, devuelve -1.
 */
int maximo(int vector[], int n) {
	int max = 0;
	if (n == 0){
		return -1;
	}
	for (int i=0; i < n; i++){
		if (vector[i] > vector[max]){
			max = i;
		}
	} 
	return max;
}

/* La función comparar recibe dos vectores y sus respectivas longitudes
 * y devuelve -1 si el primer vector es menor que el segundo; 0 si son
 * iguales; y 1 si el segundo es menor.
 *
 * Un vector es menor a otro cuando al compararlos elemento a elemento,
 * el primer elemento en el que difieren no existe o es menor.
 */
int comparar(int vector1[], int n1, int vector2[], int n2){
	for(int i = 0; i < (n1+n2); i++){
		if(i >= n1 && i < n2){
			return -1;
		}
		if(i < n1 && i >= n2){
			return 1;
		}
		if(i < n1 && vector1[i] < vector2[i]){
			return -1;
		}
		if(i < n1 && vector1[i] > vector2[i]){
			return 1;
		}
	}
	return 0;
}

/* selection_sort() ordena el arreglo recibido mediante el algoritmo de
 * selección.
 */
void seleccion(int vector[], int n) {
	for(int i = 0; i < n; i++){
		int Nmayor = maximo(vector,n-i);
		swap(&vector[Nmayor],&vector[n-i-1]);	
	}

}
