/*
 * ordienamiento.c
 *
 *  Created on: 12 sept 2022
 *      Author: kenyn
 */
#include <stdio.h>
#include <stdlib.h>
#include "ordenamiento.h"

int ordenarEnterosDescendiente(int numeros[], int tamNumeros) {
	int retorno = -1;
	int aux;

	if (numeros != NULL && tamNumeros > 0) {
		for (int i = 0; i < tamNumeros - 1; i++) {
			for (int j = i + 1; j < tamNumeros; j++) {
				if (numeros[i] < numeros[j]) {
					aux = numeros[i];
					numeros[i] = numeros[j];
					numeros[j] = aux;
				}
			}
		}

		retorno = 1;
	}

	return retorno;
}

int ordenarEnterosAscendiente(int numeros[], int tamNumeros) {
	int retorno = -1;
	int aux;

	if (numeros != NULL && tamNumeros > 0) {
		for (int i = 0; i < tamNumeros - 1; i++) {
			for (int j = i + 1; j < tamNumeros; j++) {
				if (numeros[i] > numeros[j]) {
					aux = numeros[i];
					numeros[i] = numeros[j];
					numeros[j] = aux;
				}
			}
		}

		retorno = 1;
	}

	return retorno;
}
