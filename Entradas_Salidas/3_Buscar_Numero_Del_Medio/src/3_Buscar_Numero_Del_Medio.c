/*
 ============================================================================
 Name        : 3_Buscar_Numero_Del_Medio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


/*
 Ejercicio 1-3: ingresar 3 números y mostrar el número del medio, sólo si existe. En
 caso de que no exista también informarlo.
 Ejemplo:
 1 5 3 el 3 es del medio
 5 1 5 no hay número del medio
 3 5 1 el 3 es del medio
 3 1 5 el 3 es del medio
 5 3 1 el 3 es del medio
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);
	int numeroA;
	int numeroB;
	int numeroC;
	int numeroDelMedio;

	printf("\nIngrese el primer numero: ");
	fflush(stdin);
	scanf("%d", &numeroA);

	printf("\nIngrese el segundo numero: ");
	fflush(stdin);
	scanf("%d", &numeroB);

	printf("\nIngrese el tercer numero: ");
	fflush(stdin);
	scanf("%d", &numeroC);

	if ((numeroA > numeroB && numeroA < numeroC)
			|| (numeroA > numeroC && numeroA < numeroB))
		numeroDelMedio = numeroA;

	else if ((numeroB > numeroA && numeroB < numeroC)
			|| (numeroB > numeroC && numeroB < numeroA))
		numeroDelMedio = numeroB;

	else if ((numeroC > numeroA && numeroC < numeroB)
			|| (numeroC > numeroB && numeroC < numeroA))
		numeroDelMedio = numeroC;

	else {
		printf("\nNo hay numero medio");
		return EXIT_SUCCESS;
	}

	printf("\n%d %d %d el %d es del medio", numeroA, numeroB, numeroC,
			numeroDelMedio);
	return EXIT_SUCCESS;

}

