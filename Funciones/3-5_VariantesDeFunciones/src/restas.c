/*
 * Restas.c
 *
 *  Created on: 1 sept 2022
 *      Author: kenyn
 */

#include <stdio.h>
#include <stdlib.h>

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
