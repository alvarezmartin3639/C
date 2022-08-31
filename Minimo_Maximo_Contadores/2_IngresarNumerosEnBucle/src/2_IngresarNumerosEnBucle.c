/*
 ============================================================================
 Name        : 2-2_IngresarNumerosEnBucle.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 Ejercicio 2-2: Ingresar números enteros, hasta que el usuario pida. Mostrar:
 a) El promedio de los positivos y su mínimo.
 b) El promedio de los negativos y su máximo.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);
	int minimoPositivo;
	int maximoNegativo;
	int numeroActual;
	int acumuladorDeNumerosPositivos;
	int acumuladorDeNumerosNegativos;
	int contadorNumerosPositivos;
	int contadorNumerosNegativos;
	char deseaContinuar;

	acumuladorDeNumerosPositivos = 0;
	acumuladorDeNumerosNegativos = 0;
	contadorNumerosPositivos = 0;
	contadorNumerosNegativos = 0;
	deseaContinuar = 'y';

	while (deseaContinuar != 'n') {

		printf("\nIngrese un numero: ");
		fflush(stdin);
		scanf("%d", &numeroActual);

		//INCIALIZO MAXIMO Y MINIMO
		if (contadorNumerosPositivos == 0 && numeroActual > 0)
			minimoPositivo = numeroActual;
		if (contadorNumerosNegativos == 0 && numeroActual < 0)
			maximoNegativo = numeroActual;

		//BUSCO EL MINIMO POSITIVO Y ACUMULO LOS POSITIVOS
		if (numeroActual > 0) {
			if (numeroActual < minimoPositivo)
				minimoPositivo = numeroActual;

			acumuladorDeNumerosPositivos += numeroActual;
			contadorNumerosPositivos++;
		}

		//BUSCO EL MAXIMO NEGATIVO Y ACUMULO LOS NEGATIVOS
		if (numeroActual < 0) {
			if (numeroActual > maximoNegativo)
				maximoNegativo = numeroActual;

			acumuladorDeNumerosNegativos += numeroActual;
			contadorNumerosNegativos++;
		}

		do {
			printf("\nDesea continuar? [y/n]\n");
			fflush(stdin);
			scanf("%c", &deseaContinuar);

			if (deseaContinuar != 'n' && deseaContinuar != 'y')
				printf(
						"***Error, %c no es una opción valida, ingrese 'y' para continuar o 'n' para no continuar ",
						deseaContinuar);

		} while (deseaContinuar != 'n' && deseaContinuar != 'y');

	}

	if (contadorNumerosPositivos > 0) {
		printf("\na)Promedio positivo: %d",
				acumuladorDeNumerosPositivos / contadorNumerosPositivos);
		printf("\nMinimo positivo: %d", minimoPositivo);
	} else
		printf("\n\nNo se ingresaron numeros positivos");

	if (contadorNumerosPositivos > 0) {
		printf("\n\nb)Promedio negativo: %d",
				acumuladorDeNumerosNegativos / contadorNumerosNegativos);
		printf("\nMaximo negativo: %d", maximoNegativo);
	} else
		printf("\n\nNo se ingresaron numeros negativos");

	return EXIT_SUCCESS;
}
