/*
 ============================================================================
 Name        : 3_Calcular_Maximo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int buscarMayor(int *pArray, int *pRespuesta, int tam);

int main(void) {
	setbuf(stdout, NULL);
	int numeros[5] = { 1, 4, 2, 6, 3 };
	int respuesta;
	buscarMayor(numeros, &respuesta, 5);
	return EXIT_SUCCESS;
}

int buscarMayor(int *pArray, int *pRespuesta, int tamArray) {
	int retorno = -1;

	if (pArray != NULL && pRespuesta != NULL && tamArray > 0) {
		*pRespuesta = *pArray;
		retorno = 0;
		for (int i = 0; i < tamArray; i++)
			if (*(pArray + i) > *pRespuesta) {
				*pRespuesta = *(pArray + i);
			}
	}

	return retorno;
}
