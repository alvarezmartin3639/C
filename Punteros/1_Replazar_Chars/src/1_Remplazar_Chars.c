/*
 ============================================================================
 Name        : 1_Puntero_Chars.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/**
 * Ejercicio 11-1: Realizar una función que reciba un puntero a char y dos char. La función
 deberá reemplazar en la cadena cada ocurrencia del primer carácter recibido, por el
 segundo. Retornando la cantidad de reemplazos o -1 en caso de error.
 */
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int remplazarChars(char *punteroChar, char charUno, char charDos);

int main(void) {

	setbuf(stdout, NULL);
	char punteroChar[21] = "aaabbb";

	remplazarChars(punteroChar, 'a', 'b');
	printf("\nDeberia ser bbbbbb y es %s ", punteroChar);

	return EXIT_SUCCESS;
}

int remplazarChars(char *punteroChar, char charUno, char charDos) {

	int contRemplazos = -1;

	if (punteroChar != NULL) {

		contRemplazos = 0;

		for (int i = 0; i < strlen(punteroChar); i++)
			if (*(punteroChar + i) == charUno) {
				*(punteroChar + i) = charDos;
				contRemplazos++;
			}

	}

	return contRemplazos;
}
