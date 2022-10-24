/*
 ============================================================================
 Name        : 1_Calculador.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int Calculador(int, int (*pFunc)(int, int), int, int*);

int Sumar(int a, int b);

int main(void) {

	setbuf(stdout, NULL);
	int resultado;

	Calculador(5, &Sumar, 6, &resultado);
	printf("\nLa suma de 5 + 6 = %d", resultado);

	return EXIT_SUCCESS;
}

int Calculador(int a, int (*pFunc)(int, int), int b, int *pResultado) {

	int retorno = -1;

	if (pFunc != NULL) {

		*pResultado = pFunc(a, b);
		retorno = *pResultado;

	}

	return retorno;
}

int Sumar(int a, int b) {

	return a + b;

}
