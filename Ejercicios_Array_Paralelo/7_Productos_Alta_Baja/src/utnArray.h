/*
 * utnArrays.h
 *
 *  Created on: 12 sept 2022
 *      Author: kenyn
 */

#ifndef UTNARRAY_H_
#define UTNARRAY_H_

int incializarArrayInt(int enteros[], int tamEnteros, int valor);

int incializarArrayFloat(float flotantes[], int tamFlotantes, float valor);

int incializarArrayChar(char caracteres[], int tamString, char valor);

int incializarArrayString(int tamString, int tamMatriz,
		char string[][tamString], char valor[]);

int ordenarEnteros(int numeros[], int tamNumeros, int orden);

int ordenarFlotantes(float numeros[], int tamNumeros, int orden);

int ordenarString(char texto[][20], int tamMatrizTexto, int orden);

int ordenarAlfanumerico(char texto[][20], int tamMatrizTexto, int orden);

int buscarMinimoArrayInt(int array[],int tam);

int buscarMaximoArray(int array[],int tam);

int contarParesArrayInt(int array[], int tam);

int contarCantDeNumerosEnArrayInt(int array[], int tam, int numeroParaBuscar);

int acumularArrayInt(int array[], int tam);

float promediarArrayInt(int array[], int tam);

#endif /* UTNARRAY_H_ */
