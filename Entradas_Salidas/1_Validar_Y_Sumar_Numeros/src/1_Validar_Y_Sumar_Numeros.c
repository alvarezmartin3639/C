/*
 ============================================================================
 Name        : 1_Validar_El_Mayor_Numero.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 Ejercicio 1-1: Ingresar dos números enteros entre -50 y 100, sumarlos y mostrar el
 resultado. Ejemplo: Si ingresamos 3 y 2 el programa mostrará: “La suma entre 3 y 2
 da como resultado 5”
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);
	int numeroA;
	int numeroB;
	int resultado;

	do {
		printf("\nIngrese el primer numero: ");
		fflush(stdin);
		scanf("%d", &numeroA);
	} while (numeroA < -50 || numeroA > 100);

	do {
		printf("\nIngrese el segundo numero: ");
		fflush(stdin);
		scanf("%d", &numeroB);
	} while (numeroB < -50 || numeroB > 100);

	resultado = numeroA + numeroB;

	printf("\nLa suma entre %d y %d da como resultado %d ", numeroA, numeroB,
			resultado);
	return EXIT_SUCCESS;
}

