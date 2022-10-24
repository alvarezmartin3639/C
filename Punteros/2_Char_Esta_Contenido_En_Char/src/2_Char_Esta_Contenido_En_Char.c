/*
 ============================================================================
 Name        : 2_Char_Esta_Contenido_En_Char.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/**
 Ejercicio 11-2: Realizar una función que reciba como parámetros dos vectores. La
 función deberá determinar si el segundo vector está contenido en el primero.
 */

// FALTA COMPLETAR!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int estaContenidoEnChar(char *primero, char *segundo);

int main(void) {

	setbuf(stdout, NULL);
	char primero[] = "ABCDE";
	char segundo[] = "ABCD";

	if (estaContenidoEnChar(primero, segundo) == 1)
		printf("\n\nEstá contenido!");
	else
		printf("\n\nNo está contenido!");

	return EXIT_SUCCESS;
}

int estaContenidoEnChar(char *primero, char *segundo) {

	int retorno = -1;
	int indiceUltimoAcierto = 0;
	int contAciertosConsecutivos = 0;

	if (primero != NULL && segundo != NULL) {
		retorno = 0;

		for (int i = 0; i < strlen(segundo); i++) {
			for (int j = indiceUltimoAcierto; j < strlen(primero); j++) {
				if (*(segundo + i) == *(primero + j)) {
					contAciertosConsecutivos++;
					indiceUltimoAcierto = j;
					break;
				}

				else if (contAciertosConsecutivos == strlen(segundo)) {
					retorno = 1;
					break;
				}

				else
					contAciertosConsecutivos = 0;
			}
		}
	}

	return retorno;
}
