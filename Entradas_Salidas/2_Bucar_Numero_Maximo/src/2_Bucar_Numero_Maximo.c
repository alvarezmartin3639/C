/*
 ============================================================================
 Name        : 2_Bucar_Numero_Maximo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


/*
 Ejercicio 1-2: ingresar 3 números y mostrar cuál de los tres es el mayor.
 Ejemplo: Si ingresamos 5, 9 y 3 el programa mostrará: “El mayor de los números es el
 segundo: 9”
 */

#include <stdio.h>
#include <stdlib.h>

#define FAIL -1

int main(void) {

	setbuf(stdout, NULL);

	int numeroA;
	int numeroB;
	int numeroC;
	int indiceDelMayorNumero;
	int mayorDeLosNumeros;

	printf("\nIngrese el primer numero: ");
	fflush(stdin);
	scanf("%d", &numeroA);

	printf("\nIngrese el segundo numero: ");
	fflush(stdin);
	scanf("%d", &numeroB);

	printf("\nIngrese el tercer numero: ");
	fflush(stdin);
	scanf("%d", &numeroC);

	if (numeroA > numeroB && numeroA > numeroC) {
		indiceDelMayorNumero = 1;
		mayorDeLosNumeros = numeroA;
	} else if (numeroB > numeroC) {
		indiceDelMayorNumero = 2;
		mayorDeLosNumeros = numeroB;
	} else if (numeroC > numeroA) {
		indiceDelMayorNumero = 3;
		mayorDeLosNumeros = numeroC;
	} else {
		puts("\nLos tres numeros son iguales!");
		return EXIT_SUCCESS;
	}

	printf("\nEl mayor de los numeros es el %d: %d", indiceDelMayorNumero,
			mayorDeLosNumeros); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}

