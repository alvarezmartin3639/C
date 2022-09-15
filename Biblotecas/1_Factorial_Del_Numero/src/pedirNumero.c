/*
 * pedirNumero.c
 *
 *  Created on: 3 sept 2022
 *      Author: kenyn
 */
#include <stdio.h>
#include <stdlib.h>

#include "pedirNumero.h"

float pedirNumero() {
	float numeroEscrito;

	printf("\nIngrese un numero del tipo flotante: ");
	fflush(stdin);
	scanf(" %f", &numeroEscrito);

	return numeroEscrito;
}
