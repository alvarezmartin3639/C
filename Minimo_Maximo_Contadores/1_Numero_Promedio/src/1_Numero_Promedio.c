/*
 ============================================================================
 Name        : 1_Numero_Promedio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 Ejercicio 2-1: Ingresar 7 números negativos distintos de 0 calcular y mostrar el
 promedio de los números. Probar la aplicación con distintos valores.
 Ejemplo 1: (-7)( - 5)( - 12) (- 1)( - 2)
 Ejemplo 2: (-9)( - 15)( - 12) (- 1)( - 21)
 */

#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

int main(void) {

	setbuf(stdout, NULL);
	int i;
	int acumulador = 0;
	int numeroCorrecto = TRUE;
	int numero;
	float promedio;

	for (i = 0; i != 7; i++) {
		do {

			printf("\nIngrese un numero: ");
			fflush(stdin);
			scanf(" %d", &numero);

			if (numero > -1){
				printf("\n*Error al ingresar el numero %d, este tiene que ser menor a 0*",numero);
				numeroCorrecto = FALSE;
			}

		} while (numeroCorrecto == FALSE);

		acumulador += numero;
	}

	promedio = (float) acumulador / 7;
	printf("\nEl promedio es: %2.f", promedio);
	return EXIT_SUCCESS;
}
