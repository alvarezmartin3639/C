/*
 ============================================================================
 Name        : 1_Pedir_Numero_Filtrar_Por_Paridad.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 Ejercicio 5-1: Pedir 5 números enteros, guardarlos en un Array. Calcular la sumatorio
 de los mismos y mostrar los impares ingresados.
 */

#include <stdio.h>
#include <stdlib.h>
#include "utnValidacion.h"
#define TAMNUMEROS 5
int main(void) {

	setbuf(stdout, NULL);
	int numeroInput[TAMNUMEROS];
	int acumuladorNumerosInput = 0;

	for (int i = 0; i < TAMNUMEROS; i++) {
		getPedirInt(&numeroInput[i], "\nIngrese un numero entero: ",
				"\n***Error, el numero ingresado no es entero***\n", -99999,
				+99999, 2);
		printf("\n%d",numeroInput[i]);
		acumuladorNumerosInput += numeroInput[i];
	}

	printf("\nLa suma de todos los numeros es de  %d", acumuladorNumerosInput);

	printf("\nMostrando los impares ingresados: ");
	for (int i = 0; i < TAMNUMEROS; i++) {
		if(numeroInput[i] % 2 ==1)
			printf("\n%d-%d",i+1,numeroInput[i]);
	}

	return EXIT_SUCCESS;
}
