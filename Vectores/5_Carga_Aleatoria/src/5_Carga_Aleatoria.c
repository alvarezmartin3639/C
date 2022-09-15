/*
 ============================================================================
 Name        : 5_Carga_Aleatoria.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 Ejercicio 5-5: Pedir 10 números enteros distintos de cero entre -50 y 75. La carga
 deberá ser aleatoria (todos los elementos se inicializan en cero por default).
 Determinar el promedio de los positivos. Desde el mayor de los negativos los
 números negativos hasta llegar a cero.
 */

#include <stdio.h>
#include <stdlib.h>
#include "utnValidacion.h"
#include "utnArray.h"
#define TAMNUMEROS 10

int main(void) {
	setbuf(stdout, NULL);

	int numeros[TAMNUMEROS];
	int i = 0;
	int contPositivos = 0;
	int acumPositivos = 0;

	incializarArrayInt(numeros, TAMNUMEROS, 0);

	do {
		getPedirInt(&numeros[i], "\nIngrese un numero: ",
				"\n***Error, no ingresó un numero válido\n", -50, 75, 2);

		if (numeros[i] > 0) {
			contPositivos++;
			acumPositivos += numeros[i];
		}

		i++;

	} while (deseaContinuar("\n¿Desea continuar ingresando numeros?(si/no)",
			"si", "no") == 1 || i == 10);

	ordenarEnterosDescendiente(numeros, TAMNUMEROS);

	printf("\nEl promedio de los positivos es: %.2f",
			(float) acumPositivos / contPositivos);

	if (numeros[9] > 0) {

		printf("\nNo hay numeros negativos!");

	} else {

		for (int i = 0; i < TAMNUMEROS; i++) {

			if (numeros[i] < 0)
				printf("\n%d", numeros[i]);

		}
	}

	return EXIT_SUCCESS;
}
