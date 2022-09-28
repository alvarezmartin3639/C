/*
 * utnArray.c
 *
 *  Created on: 12 sept 2022
 *      Author: kenyn
 */

//El valor que se le asigna al espacio no inicializado de un array
#define NOINICIALIZADO -1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utnValidacion.h"

int incializarArrayInt(int enteros[], int tamEnteros, int valor) {

	int retorno = -1;

	if (enteros != NULL && tamEnteros > 0) {

		for (int i = 0; i < tamEnteros; i++)
			enteros[i] = valor;

		retorno = 0;
	}

	return retorno;

}

int incializarArrayFloat(float flotantes[], int tamFlotantes, float valor) {

	int retorno = -1;

	if (flotantes != NULL && tamFlotantes > 0) {

		for (int i = 0; i < tamFlotantes; i++)
			flotantes[i] = valor;

		retorno = 0;
	}

	return retorno;

}

int incializarArrayChar(char caracteres[], int tamString, char valor) {

	int retorno = -1;

	if (caracteres != NULL && tamString > 0) {

		for (int i = 0; i < tamString; i++)
			caracteres[i] = valor;

		retorno = 0;
	}

	return retorno;

}

int incializarArrayString(int tamString, int tamMatriz,
		char string[][tamString], char valor[]) {

	int retorno = -1;

	if (string != NULL && tamString > 0 && tamMatriz > 0) {

		for (int i = 0; i < tamMatriz; i++)
			strcpy(string[i], valor);

		retorno = 0;
	}

	return retorno;

}

int ordenarEnteros(int numeros[], int tamNumeros, int orden) {

	int retorno = -1;
	int aux;

	if (numeros != NULL && tamNumeros > 0 && (orden == 1 || orden == 0)) {

		retorno = 1;

		if (orden == 0) {

			for (int i = 0; i < tamNumeros - 1; i++) {

				for (int j = i + 1; j < tamNumeros; j++) {

					if (numeros[i] < numeros[j]) {
						aux = numeros[i];
						numeros[i] = numeros[j];
						numeros[j] = aux;
					}
				}
			}

		}

		if (orden == 1) {

			for (int i = 0; i < tamNumeros - 1; i++) {

				for (int j = i + 1; j < tamNumeros; j++) {

					if (numeros[i] > numeros[j]) {
						aux = numeros[i];
						numeros[i] = numeros[j];
						numeros[j] = aux;
					}
				}
			}

		}
	}

	return retorno;
}

int ordenarFlotantes(float numeros[], int tamNumeros, int orden) {

	int retorno = -1;
	float aux;

	if (numeros != NULL && tamNumeros > 0 && (orden == 1 || orden == 0)) {

		retorno = 0;

		if (orden == 0) {

			for (int i = 0; i < tamNumeros - 1; i++) {

				for (int j = i + 1; j < tamNumeros; j++) {

					if (numeros[i] < numeros[j]) {
						aux = numeros[i];
						numeros[i] = numeros[j];
						numeros[j] = aux;
					}
				}
			}
		}

		if (orden == 1) {

			for (int i = 0; i < tamNumeros - 1; i++) {

				for (int j = i + 1; j > tamNumeros; j++) {

					if (numeros[i] > numeros[j]) {
						aux = numeros[i];
						numeros[i] = numeros[j];
						numeros[j] = aux;
					}
				}
			}
		}

	}

	return retorno;
}

int ordenarString(char texto[][20], int tamMatrizTexto, int orden) {

	int retorno = -1;
	char aux[20];

	if (texto != NULL && tamMatrizTexto > 0 && (orden == 1 || orden == 0)) {

		retorno = 0;

		if (orden == 0) {

			for (int i = 0; i < tamMatrizTexto - 1; i++) {

				for (int j = i + 1; j < tamMatrizTexto; j++) {

					if (strcmp(texto[i], texto[j]) < 0) {
						strcpy(aux, texto[i]);
						strcpy(texto[i], texto[j]);
						strcpy(texto[j], aux);
					}
				}
			}
		}

		if (orden == 1) {

			for (int i = 0; i < tamMatrizTexto - 1; i++) {

				for (int j = i + 1; j > tamMatrizTexto; j++) {

					if (strcmp(texto[i], texto[j]) > 0) {
						strcpy(aux, texto[i]);
						strcpy(texto[i], texto[j]);
						strcpy(texto[j], aux);
					}
				}
			}
		}

		else
			retorno = 1;

	}

	return retorno;
}

//NO LOGRE HACERLO ANDAR, HAY QUE REVISARLO
int ordenarAlfanumerico(char texto[][20], int tamMatrizTexto, int orden) {

	int retorno = -1;
	char aux[20];

	if (texto != NULL && tamMatrizTexto > 0 && (orden == 1 || orden == 0)) {

		retorno = 0;

		if (orden == 0) {

			for (int i = 0; i < tamMatrizTexto - 1; i++) {

				for (int j = i + 1; j < tamMatrizTexto; j++) {

					for (int k = 0; k < 20; k++) {

						if (texto[i][k] < texto[j][k]) {
							strcpy(aux, texto[i]);
							strcpy(texto[i], texto[j]);
							strcpy(texto[j], aux);
						}

					}
				}
			}
		}

		if (orden == 1) {

			for (int i = 0; i < tamMatrizTexto - 1; i++) {

				for (int j = i + 1; j < tamMatrizTexto; j++) {

					for (int k = 0; k < 20; k++) {

						if (texto[i][k] > texto[j][k]) {
							strcpy(aux, texto[i]);
							strcpy(texto[i], texto[j]);
							strcpy(texto[j], aux);
						}

					}
				}
			}
		}

		else
			retorno = 1;
	}

	return retorno;
}

int buscarMinimoArrayInt(int array[], int tam) {
	int i;
	int valorDeRetorno;

	//Si el espacio esta libre
	if (array[0] != NOINICIALIZADO) {
		valorDeRetorno = array[0];
	}

	for (i = 0; i < tam; i++) {
		if (valorDeRetorno > array[i] && array[i] != -1) {
			valorDeRetorno = array[i];
		}
	}
	return valorDeRetorno;

}

int buscarMaximoArrayInt(int array[], int tam) {
	int i;
	int valorDeRetorno;

	//Si el espacio esta libre
	if (array[0] != NOINICIALIZADO) {
		valorDeRetorno = array[0];
	}

	for (i = 0; i < tam; i++) {
		if (valorDeRetorno < array[i] && array[i] != -1) {
			valorDeRetorno = array[i];
		}
	}
	return valorDeRetorno;

}

int contarParesArrayInt(int array[], int tam) {

	int i;
	int valorDeRetorno = 0;

	for (i = 0; i < tam; i++) {
		if (array[i] % 2 == 0) {
			valorDeRetorno++;
		}
	}
	return valorDeRetorno;
}

int contarCantDeNumerosEnArrayInt(int array[], int tam, int numeroParaBuscar) {

	int i;
	int valorDeRetorno = 0;

	for (i = 0; i < tam; i++) {
		if (array[i] == numeroParaBuscar) {
			valorDeRetorno++;
		}
	}
	return valorDeRetorno;
}

int acumularArrayInt(int array[], int tam) {

	int suma = 0;
	int i;

	for (i = 0; i < tam; i++) {
		if (array[i] != -1) {
			suma = suma + array[i];
		}
	}

	return suma;
}

float promediarArrayInt(int array[], int tam) {

	//Busca y acumula los array iniciados (los que no son (-1)) y calcula el promedio
	return (float) acumularArrayInt(array, tam) / tam
			- contarCantDeNumerosEnArrayInt(array, tam, NOINICIALIZADO);

}
