/*
 ============================================================================
 Name        : 3-5_VariantesDeFunciones.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "restas.h"

int main(void) {
	setbuf(stdout, NULL);
	int numeroUno;
	int numeroDos;

	printf("\nIngrese el primer numero: ");
	fflush(stdin);
	scanf("%d", &numeroUno);

	printf("\nIngrese el segundo numero: ");
	fflush(stdin);
	scanf("%d", &numeroDos);

	printf("\n****RESTAR 1****");
	printf("\n%d - %d = %d", numeroUno, numeroDos, restar1(numeroUno, numeroDos));

	printf("\n\n****RESTAR 2****");
	printf("\n?? - ?? = %d", restar2());

	printf("\n\n****RESTAR 3****");
	restar3(numeroUno, numeroDos);

	printf("\n\n****RESTAR 4****");
	restar4();

	return EXIT_SUCCESS;
}
