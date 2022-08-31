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

int restar1(int, int);
int restar2(void);
void restar3(int, int);
void restar4(void);

int main(void) {
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

int restar1(int numeroUno, int numeroDos) {
	return numeroUno - numeroDos;
}

int restar2() {

	int numeroUno;
	int numeroDos;

	printf("\nIngrese el primer numero");
	scanf("%d", &numeroUno);

	printf("\nIngrese el segundo numero");
	scanf("%d", &numeroDos);

	return restar1(numeroUno, numeroDos);
}

void restar3(int numeroUno, int numeroDos) {
	printf("\n%d - %d = %d", numeroUno, numeroDos, restar1(numeroUno, numeroDos));
}

void restar4() {
	printf("\n%d", restar2());
}
