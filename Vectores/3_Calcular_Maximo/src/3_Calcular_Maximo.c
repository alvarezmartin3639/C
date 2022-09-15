/*
 ============================================================================
 Name        : 3_Calcular_Maximo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 Ejercicio 5-3: Realizar una función que reciba como parámetros un array de enteros y
 un entero por referencia. La función calculara el máximo valor de ese array y utilizara
 el valor por referencia para retornar ese valor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "calculosMatematicos.h"
#define TAMNUMEROS 4
int main(void) {
	setbuf(stdout, NULL);
	int numeros[TAMNUMEROS];
	int maximoDeNumeros;

	for (int i = 0; i < TAMNUMEROS; i++) {
		numeros[i] = i + 1;
		if (i == 3)
			numeros[i] = 100;
	}

	calcularMaximo(numeros, TAMNUMEROS, &maximoDeNumeros);
	printf("\nEl maximo entre %d, %d, %d, %d es %d", numeros[0], numeros[1],
			numeros[2], numeros[3],
			maximoDeNumeros);
	return EXIT_SUCCESS;
}
