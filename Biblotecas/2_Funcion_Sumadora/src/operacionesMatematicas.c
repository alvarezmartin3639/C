/*
 * operacionesMatematicas.c
 *
 *  Created on: 3 sept 2022
 *      Author: kenyn
 */

#include "operacionesMatematicas.h"

int sumar(int num1, int num2, int *resultado) {

	int retorno = ERROR;
	int resultadoLocal = num1 + num2;

	*resultado = num1 + num2;
	//En el enunciado obligaba a comprar algo
	if (resultadoLocal == *resultado)
		retorno = 0;

	return retorno;
}
