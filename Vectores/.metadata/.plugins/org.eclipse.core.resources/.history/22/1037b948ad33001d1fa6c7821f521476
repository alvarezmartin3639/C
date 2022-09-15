/*
 * utnCadenas.c
 *
 *  Created on: 13 sept 2022
 *      Author: kenyn
 */
#include <stdio.h>

int myGets(char *cadena, int longitud) {

	int retorno = -1;

	if (cadena != NULL && longitud > 0
			&& fgets(cadena, longitud, stdin) == cadena) {

		fflush(stdin);
		if (cadena[strlen(cadena) - 1] == '\n') {
			cadena[strlen(cadena) - 1] = '\0';

		}

		retorno = 0;
	}

	return retorno;
}

