/*
 * utnCadenas.c
 *
 *  Created on: 13 sept 2022
 *      Author: kenyn
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

char* formatearString(char *str, char *a, char *b) {

	int len = strlen(str);
	int lena = strlen(a), lenb = strlen(b);
	char aux[54];

	strcpy(aux, str);

	for (char *p = aux; (p = strstr(p, a)); ++p) {

		if (lena != lenb)
			memmove(p + lenb, p + lena, len - (p - aux) + lenb);
		memcpy(p, b, lenb);

	}

	return strdup(aux);
}

/**
 * @brief convierte en mayusculas el string ingresado en el parametro cadena[]
 *
 * @param cadena
 * @param tam
 * @return void
 */

void ConvertirTodoMayuscula(char cadena[], int tam) {
	int i;

	for (i = 0; i < tam; i++) {
		cadena[i] = toupper(cadena[i]);
	}
}

/**
 * @brief convierte en minusculas el string ingresado en el parametro cadena[]
 *
 * @param cadena
 * @param tam
 * @return void
 */

void ConvertirTodoMinuscula(char cadena[], int tam) {
	int i;

	for (i = 0; i < tam; i++) {
		cadena[i] = tolower(cadena[i]);
	}
}

/**
 * @brief Convierte en mayuscula la primera letra del parametro cadena[],
 * detecta espacios y convierte en mayusculas la siguiente letra
 *
 * @param cadena
 * @param tam
 *
 * @return void
 */

void ConvertirPrimerLetraEnMayuscula(char cadena[], int tam) {

	int i;

	ConvertirTodoMinuscula(cadena, tam);

	cadena[0] = toupper(cadena[0]);

	for (i = 0; i < tam; i++) {
		if (cadena[i] == ' ') {
			cadena[i + 1] = toupper(cadena[i + 1]);
		}
	}

}

/**
 * @brief repite la cadena del parametro mensajeParaRepetir[] la cantidad de veces
 * que diga el parametro numeroDeVecesParaRepetir[]
 *
 * @param mensajeParaRepetir
 * @param numeroDeVecesParaRepetir
 *
 * @return void
 */

void RepetirCadena(char mensajeParaRepetir[], int numeroDeVecesParaRepetir) {

	int contadorDeRepeticiones;

	contadorDeRepeticiones = 0;

	while (contadorDeRepeticiones != numeroDeVecesParaRepetir) {
		puts(mensajeParaRepetir);
		contadorDeRepeticiones++;
	}
}
