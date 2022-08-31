/*
 ============================================================================
 Name        : 4_ComparacionesEntreNumeros_Producto.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 Ejercicio 2-4:
 Ingresar 8 números enteros, distintos de cero. Mostrar:
 a. El menor número ingresado.
 b. De los pares el mayor número ingresado.
 c. Producto de los negativos.
 d. En qué lugar fue ingresado el mayor numero
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);

	int numberInput;
	int numberMin;
	int numberMax;
	int numberMaxPair;
	int numberProductOfAllNegative;
	int numberGreaterIndex;

	numberMaxPair = 1;
	numberProductOfAllNegative = 1;

	for (int i = 0; i < 8; ++i) {
		printf("\nIngrese el %d número: ", i + 1);
		fflush(stdin);
		scanf("%d", &numberInput);

		if (i == 0) {
			numberMin = numberInput;
			numberMax = numberInput;
			numberGreaterIndex = i;
		}

		if (numberInput < numberMin)
			numberMin = numberInput;

		//Initialized in case it is the first even number
		if (numberInput % 2 == 0 && numberMaxPair == 1)
			numberMaxPair = numberInput;

		if (numberInput > numberMax) {
			numberMax = numberInput;
			numberGreaterIndex = i;
			if (numberMax % 2 == 0)
				numberMaxPair = numberMax;
		}

		if (numberInput < 0) {
			printf("\nEntro: %d * %d = %d", numberProductOfAllNegative,
					numberInput, numberProductOfAllNegative * numberInput);
		}
		numberProductOfAllNegative = numberProductOfAllNegative * numberInput;
	}

	printf("\na. Menor numero ingresado = %d", numberMin);
	printf("\nb. Mayor numero par ingresado = %d", numberMaxPair);
	printf("\nc. Producto de los negativos = %d", numberProductOfAllNegative);
	printf("\nd. Indice del mayor numero = %d", numberGreaterIndex);

	return EXIT_SUCCESS;
}
