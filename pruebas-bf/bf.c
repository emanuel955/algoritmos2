#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void imprimir_br(int* vector){
    //INICIALIZACION DE VALORES DEL ARREGLO A 0
	char* br_vector = malloc(sizeof(char)*300000);
    for( int i = 0 ; i < 300000 ; i++ )br_vector[i] = 0;
	//////////////////////////////////////////////

	int pos = 0;
	int corchetes[500];//vector donde se guarda la pos de los [
	int pos_corchete = 0;
	for(int i = 0; vector[i] != '\0'; i++){
		if(vector[i] == '.') putchar(br_vector[pos]);
		if(vector[i] == '>') pos++;
		if(vector[i] == '<') pos--;
		if(vector[i] == '+') br_vector[pos]++;
		if(vector[i] == '-') br_vector[pos]--;
		if(vector[i] == ',') br_vector[pos] = (char)getchar();
		if(vector[i] == '['){
			if(br_vector[pos] == 0){
				int cant_corch = 0;
				while(true){ //cuenta todos los corchetes desde que empieza al final
					if(vector[i] == '[')cant_corch++;
					if(vector[i] == ']')cant_corch--;
					if(cant_corch == 0)break;
					i++;
				}
				continue;
			}
			//guardo la pos del corchete inicial
			corchetes[pos_corchete] = i;
			
			pos_corchete++;
		}
		if(vector[i] == ']'){
			//si br_vector se encuentra en 0 no vuelve al inicio del [
			if(br_vector[pos] == 0){
				corchetes[pos_corchete] = 0;
				pos_corchete--;
				continue;
			}
			i = corchetes[pos_corchete - 1];
		}
	}
    //SE LIBERA BR_VECTOR
    free(br_vector);
}
bool validos(int caracter){
	if(caracter == '.') return true;
	if(caracter == '>') return true;
	if(caracter == '<') return true;
	if(caracter == '+') return true;
	if(caracter == '-') return true;
	if(caracter == '[') return true;
	if(caracter == ']') return true;
	if(caracter == ',') return true;
	return false;
}
void leer_stdin(char* linea, ssize_t tam){
	int vector_std[30000];
	int j = 0;
	for(int i = 0; i < tam; i++){
		int caracter = linea[i];
        if(validos(caracter)){
			vector_std[j] = caracter;
			j++;
		}
	}
	vector_std[j] = '\0';
	imprimir_br(vector_std);
}

void leer_lineas_br(FILE* archivo){
	int vector_br[30000];
	int char_leido;
	int i = 0;
	while((char_leido = fgetc(archivo)) != EOF){
		if(validos(char_leido)){
			vector_br[i] = char_leido;
			i++;
		}
	}
	vector_br[i] = '\0';
	fclose(archivo);

	imprimir_br(vector_br);
}

int main(int argc, char** argv){
    //ACA YA PUSE LAS CADENAS DE ERRRORES QUE DEBERIAN IR, SI NO TE VA A FALLAR EN LAS PRUEBAS 
    if(argc > 2){
        fprintf( stderr, "Error: Cantidad erronea de parametros" );
        return 1;
    }

    if(argc == 1){
		char* linea = NULL;
        size_t bytes_leidos;		
        ssize_t tam = getline( &linea, &bytes_leidos, stdin);
		leer_stdin(linea,tam);
		free(linea);
	}

    if(argc == 2){
		FILE* archivo = fopen(argv[1], "r");
		if( archivo == NULL ){
			fprintf( stderr, "Error: archivo fuente inaccesible" );
			return 1;
		} 
		leer_lineas_br( archivo );
	}

	return 0;
}
