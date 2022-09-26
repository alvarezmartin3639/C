/*
 * utnGUI.c
 *
 *  Created on: 12 sept 2022
 *      Author: kenyn
 */

#include <stdio.h>
#include "utnGUI.h"
#include <unistd.h>

int mostrarArrayInt(int enteros[], int tamEnteros) {

	int retorno = -1;

	if (enteros != NULL && tamEnteros > 0) {
		for (int i = 0; i < tamEnteros; i++)
			printf("\n%d", enteros[i]);
		retorno = 0;
	}

	return retorno;

}

int mostrarArrayFloat(float flotantes[], int tamFloat) {

	int retorno = -1;

	if (flotantes != NULL && tamFloat > 0) {
		for (int i = 0; i < tamFloat; i++)
			printf("\n%.2f", flotantes[i]);
		retorno = 0;
	}

	return retorno;

}

int mostrarArrayChar(char caracteres[], int tamCaracteres) {

	int retorno = -1;

	if (caracteres != NULL && tamCaracteres > 0) {
		for (int i = 0; i < tamCaracteres; i++)
			printf("\n%c", caracteres[i]);
		retorno = 0;
	}

	return retorno;

}

int mostrarArrayString(char texto[][50], int tamTexo) {

	int retorno = -1;

	if (texto != NULL && tamTexo > 0) {
		for (int i = 0; i < tamTexo; i++)
			printf("\n%s", texto[i]);
		retorno = 0;
	}

	return retorno;

}

void textoConEspera(char mensaje[60], int seconds) {

	puts(mensaje);
	sleep(seconds);

}

void limpiarPantalla(void) {

	for (int i = 0; i < 15; i++)
		printf("\n");

}

