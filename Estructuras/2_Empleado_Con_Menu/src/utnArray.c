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

/**
 * @fn int inicializarArrayInt(int[], int, int)
 * @brief incializa un array int con el valor pasado por parametro
 *
 * @param enteros array de los numeros enteros que se van a inicializar
 * @param tamEnteros tamaño del array
 * @param valor el valor en el cual se va a inicializar el array
 * @return -1 = error , 0 = sin error
 */
int inicializarArrayInt(int enteros[], int tamEnteros, int valor) {
	int retorno = -1;

	if (enteros != NULL && tamEnteros > 0) {

		for (int i = 0; i < tamEnteros; i++)
			enteros[i] = valor;

		retorno = 0;
	}

	return retorno;
}


/**
 * @fn int inicializarArrayFloat(float[], int, float)
 * @brief inicializa un array float con el valor pasado por parametro
 *
 * @param flotantes array de los numeros enteros que se van a inicializar
 * @param tamFlotantes tamaño del array
 * @param valor el valor en el cual se va a inicializar el array
 * @return  -1 = error , 0 = sin error
 */
int inicializarArrayFloat(float flotantes[], int tamFlotantes, float valor) {

	int retorno = -1;

	if (flotantes != NULL && tamFlotantes > 0) {

		for (int i = 0; i < tamFlotantes; i++)
			flotantes[i] = valor;

		retorno = 0;
	}

	return retorno;

}

/**
 * @fn int inicializarArrayChar(char[], int, char)
 * @brief inicializa un array char con el valor pasado por parametro
 *
 * @param caracteres array con los caracteres que se van a incializar
 * @param tamString tamaño del array
 * @param valor el valor en el cual se va a inicializar el array
 * @return  -1 = error , 0 = sin error
 */
int inicializarArrayChar(char caracteres[], int tamString, char valor) {

	int retorno = -1;

	if (caracteres != NULL && tamString > 0) {

		for (int i = 0; i < tamString; i++)
			caracteres[i] = valor;

		retorno = 0;
	}

	return retorno;

}

/**
 * @fn int inicializarArrayString(int, int, char[][], char[])
 * @brief incializa un array string con el valor pasado por parametro
 *
 * @param tamString tamaño del array
 * @param tamMatriz tamaño de la matriz
 * @param string el string el cual se va a incializar con el array
 * @param valor el valor en el cual se va a inicializar el array
 * @return  -1 = error , 0 = sin error
 */
int inicializarArrayString(int tamString, int tamMatriz, char string[][tamString], char valor[]) {

	int retorno = -1;

	if (string != NULL && tamString > 0 && tamMatriz > 0) {

		for (int i = 0; i < tamMatriz; i++)
			strcpy(string[i], valor);

		retorno = 0;
	}

	return retorno;

}

/**
 * @fn int ordenarEnteros(int[], int, int)
 * @brief ordena el array con el orden pasado por parametro
 *
 * @param numeros array de los numeros enteros que se van a ordenar
 * @param tamNumeros tamaño del array
 * @param orden el orden de ordenamiento 1 = Descendiente (mayor a menor), 0 = Ascendiente (menor a mayor)
 * @return  -1 = error , 0 = sin error
 */
int ordenarEnteros(int numeros[], int tamNumeros, int orden) {

	int retorno = -1;
	int aux;

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

	if (array != NULL && tam > 0) {

		//Si el espacio esta libre
		if (array[0] != NOINICIALIZADO) {
			valorDeRetorno = array[0];
		}

		for (i = 0; i < tam; i++) {
			if (valorDeRetorno > array[i] && array[i] != -1) {
				valorDeRetorno = array[i];
			}
		}
	}

	return valorDeRetorno;
}

int buscarMaximoArrayInt(int array[], int tam) {
	int i;
	int valorDeRetorno;

	if (array != NULL && tam > 0) {

		if (array[0] != NOINICIALIZADO)
			valorDeRetorno = array[0];

		for (i = 0; i < tam; i++) {

			if (valorDeRetorno < array[i] && array[i] != -1)
				valorDeRetorno = array[i];

		}
	}

	return valorDeRetorno;
}

int buscarIndiceMaximoArrayInt(int array[], int tam) {
	int i;
	int valorDeRetorno;

	if (array != NULL && tam > 0) {

		if (array[0] != NOINICIALIZADO)
			valorDeRetorno = array[0];

		for (i = 0; i < tam; i++) {

			if (valorDeRetorno < array[i] && array[i] != -1)
				valorDeRetorno = i;

		}
	}

	return valorDeRetorno;
}

int buscarIndiceMaximoArrayFloat(float array[], int tam) {
	int i;
	int valorDeRetorno;

	if (array != NULL && tam > 0) {

		if (array[0] != NOINICIALIZADO)
			valorDeRetorno = array[0];

		for (i = 0; i < tam; i++) {

			if (valorDeRetorno < array[i] && array[i] != -1)
				valorDeRetorno = i;

		}
	}

	return valorDeRetorno;
}

int contarParesArrayInt(int array[], int tam) {

	int i;
	int valorDeRetorno = 0;

	if (array != NULL && tam > 0) {

		for (i = 0; i < tam; i++) {

			if (array[i] % 2 == 0)
				valorDeRetorno++;

		}
	}

	return valorDeRetorno;
}

int contarCantDeNumerosEnArrayInt(int array[], int tam, int numeroParaBuscar) {

	int i;
	int valorDeRetorno = 0;

	if (array != NULL && tam > 0) {

		for (i = 0; i < tam; i++) {

			if (array[i] == numeroParaBuscar) {
				valorDeRetorno++;
			}

		}

	}

	return valorDeRetorno;
}

int acumularArrayInt(int array[], int tam) {

	int suma = 0;
	int i;

	if (array != NULL && tam > 0) {

		for (i = 0; i < tam; i++) {

			if (array[i] != -1)
				suma = suma + array[i];

		}
	}

	return suma;
}

float promediarArrayInt(int array[], int tam) {

	//Busca y acumula los array iniciados (los que no son (-1)) y calcula el promedio
	return (float) acumularArrayInt(array, tam) / tam - contarCantDeNumerosEnArrayInt(array, tam, NOINICIALIZADO);

}

int buscarIntEnArray(int *array, int tam, int valorBuscado) {

	int retorno = -1;

	if (array != NULL && tam > 0) {

		for (int i = 0; i < tam; i++) {

			if (array[i] == valorBuscado) {
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

