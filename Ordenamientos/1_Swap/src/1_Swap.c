/*
 ============================================================================
 Name        : 1_Swap.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
Disponemos de dos variables numéricas (a y b). Realizar un algoritmo
que permita el intercambio de valores de dichas variables.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int a = 1;
	int b = 2;
	int aux;

	printf("\nAntes del swap: ");
	printf("\nA = %d, B = %d ",a ,b);

	aux = b;
	b = a;
	a = aux;

	printf("\n\nDespues del swap: ");
	printf("\nA = %d, B = %d ",a ,b);

	return EXIT_SUCCESS;
}
