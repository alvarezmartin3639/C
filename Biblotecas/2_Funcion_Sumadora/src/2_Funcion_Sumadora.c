/*
 ============================================================================
 Name        : 2_Funcion_Sumadora.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 Realizar una función Suma que reciba como parámetros dos enteros (los que
 va a sumar) y un puntero a entero que guardara el resultado de esta. La función retorna 0 si
 pudo realizar la suma y -1 en caso de no haberla podido realizar.
 */

#include <stdio.h>
#include <stdlib.h>
#include "operacionesMatematicas.h"
#define ERROR -1

int main(void) {

	int resultado;

	if (sumar(2, 2, &resultado) == ERROR)
		printf("\nError al sumar");
	else
		printf("\n2 + 2 = %d (tendria que dar 4) ", resultado);

	return EXIT_SUCCESS;
}
