/*
 ============================================================================
 Name        : 2_Calcular_Promedio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
Ejercicio 5-2: Hacer una función que calcule el promedio de los valores del Array que
recibe y me devuelva el promedio.
 */

#include <stdio.h>
#include <stdlib.h>
#include "calculosMatematicos.h"

#define TAMNUMERO 5

int main(void) {
	setbuf(stdout, NULL);
	int numeroInput[TAMNUMERO];

	for(int i = 0 ; i<TAMNUMERO;i++){
		printf("\nIngrese el numero %d: ", i+1);
		fflush(stdin);
		scanf("%d",&numeroInput[i]);
	}

	printf("\nEl promedio de los %d numeros es de %d",TAMNUMERO,calcularPromedio(numeroInput, TAMNUMERO));
	return EXIT_SUCCESS;
}
