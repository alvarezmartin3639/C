/*
 * utnValidacion.c
 *
 *  Created on: 12 sept 2022
 *      Author: kenyn
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utnValidacion.h"
#include "utnCadenas.h"

int getInt(int *pResultado) {

	int retorno = -1;
	char buffer[64];

	if (pResultado != NULL) {

		if (myGets(buffer, sizeof(buffer)) == 0 && esNumero(buffer) == 0) {
			*pResultado = atoi(buffer);
			retorno = 0;
		}

	}

	return retorno;
}

int getFloat(float *pResultado) {

	int retorno = -1;
	char buffer[64];

	if (pResultado != NULL) {

		if (myGets(buffer, sizeof(buffer)) == 0 && esFlotante(buffer) == 0) {
			*pResultado = atof(buffer);
			retorno = 0;
		}

	}

	return retorno;
}

int getCharDeLetra(char *pResultado) {

	int retorno = -1;
	char buffer;

	if (pResultado != NULL) {

		if (scanf("%c", &buffer) == 1 && isalpha(buffer)) {
			*pResultado = buffer;
			retorno = 0;
		}

	}

	return retorno;

}

int getStringDeLetras(char *pResultado) {

	int retorno = -1;
	char buffer[64];

	if (pResultado != NULL) {

		if (myGets(buffer, sizeof(buffer)) == 0 && esLetra(buffer) == 0) {
			strcpy(pResultado, buffer);
			retorno = 0;
		}

	}

	return retorno;

}

int getFecha(char *pResultado) {

	int retorno = -1;
	char buffer[64];

	if (pResultado != NULL) {

		if (myGets(buffer, sizeof(buffer)) == 0 && esFecha(buffer) == 0) {
			strcpy(pResultado, buffer);
			retorno = 0;
		}

	}

	return retorno;
}

int getAlfanumerico(char *pResultado) {

	int retorno = -1;
	char buffer[64];

	if (pResultado != NULL) {

		if (myGets(buffer, sizeof(buffer)) == 0
				&& esAlfanumerico(buffer) == 0) {
			strcpy(pResultado, buffer);
			retorno = 0;
		}

	}

	return retorno;
}

int getPedirInt(int *pNumero, char *mensaje, char *mensajeError, int minimo,
		int maximo, int reintentos) {

	int retorno = -1;
	int num;

	if (pNumero != NULL && mensaje != NULL && mensajeError != NULL
			&& reintentos > 0) {

		while (reintentos > 0) {

			printf(mensaje);

			if (getInt(&num) == 0) {
				if (num <= maximo && num >= minimo)
					break;
			}

			printf(mensajeError);

		}

		reintentos--;

		if (reintentos > 0) {
			retorno = 0;
			*pNumero = num;
		}
	}

	return retorno;
}

int getPedirFloat(float *pNumero, char *mensaje, char *mensajeError,
		float minimo, float maximo, int reintentos) {

	int retorno = -1;
	float num;

	if (pNumero != NULL && mensaje != NULL && mensajeError != NULL
			&& reintentos > 0) {

		while (reintentos > 0) {

			printf(mensaje);

			if (getFloat(&num) == 0) {
				if (num <= maximo && num >= minimo)
					break;
			}

			fflush(stdin);
			reintentos--;
			printf(mensajeError);

		}

		if (reintentos > 0) {
			retorno = 0;
			*pNumero = num;
		}
	}

	return retorno;

}

int getPedirCharDeLetra(char *pChar, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos) {

	int retorno = -1;
	char caracter;

	if (pChar != NULL && mensaje != NULL && mensajeError != NULL
			&& reintentos > 0) {

		while (reintentos > 0) {

			printf(mensaje);

			if (getCharDeLetra(&caracter) == 0) {
				if (caracter <= maximo && caracter >= minimo)
					break;
			}

			fflush(stdin);
			reintentos--;
			printf(mensajeError);

		}

		if (reintentos > 0) {
			retorno = 0;
			*pChar = caracter;
		}
	}

	return retorno;
}

int getPedirStringDeLetras(char *pArrayChar, char *mensaje, char *mensajeError,
		int reintentos) {

	int retorno = -1;
	char cadena[64];

	if (pArrayChar != NULL && mensaje != NULL && mensajeError != NULL
			&& reintentos > 0) {

		while (reintentos > 0) {

			printf(mensaje);

			if (getStringDeLetras(cadena) == 0)
				break;

			fflush(stdin);
			reintentos--;
			printf(mensajeError);

		}

		if (reintentos > 0) {
			retorno = 0;
			strcpy(pArrayChar, cadena);
		}
	}

	return retorno;

}

int getPedirAlfanumerico(char *pArrayChar, char *mensaje, char *mensajeError,
		int reintentos) {

	int retorno = -1;
	char cadena[64];

	if (pArrayChar != NULL && mensaje != NULL && mensajeError != NULL
			&& reintentos > 0) {

		while (reintentos > 0) {

			printf(mensaje);

			if (getAlfanumerico(cadena) == 0)
				break;

			fflush(stdin);
			reintentos--;
			printf(mensajeError);

		}

		if (reintentos > 0) {
			retorno = 0;
			strcpy(pArrayChar, cadena);
		}
	}

	return retorno;

}

int getPedirFecha(char *pChar, char *mensaje, char *mensajeError,
		int reintentos) {

	int retorno = -1;
	char fecha[50];

	if (pChar != NULL && mensaje != NULL && mensajeError != NULL
			&& reintentos > 0) {

		while (reintentos > 0) {

			printf(mensaje);

			if (getFecha(fecha) == 0) {
				break;
			}

			fflush(stdin);
			printf(mensajeError);
			reintentos--;

		}

		if (reintentos > 0) {
			retorno = 0;
			strcpy(pChar, fecha);
		}
	}

	return retorno;
}

int esNumero(char *cadena) {

	int i = 0;
	int retorno = 0;

	if (cadena != NULL && strlen(cadena) > 0) {

		while (cadena[i] != '\0') {

			if ((cadena[i] < '0' || cadena[i] > '9') && (cadena[i] != '-')) {
				retorno = -1;
				break;
			}

			i++;
		}
	}

	return retorno;
}

int esFlotante(char *cadena) {

	int retorno = 0;
	int tienePunto = 0;

	for (int i = 0; i < strlen(cadena); i++) {

		if (cadena[i] == '.')
			tienePunto++;

		if ((!isdigit(cadena[i]) && cadena[i] != '.') || tienePunto > 1) {
			retorno = -1;
		}

	}

	return retorno;
}

int esFlotanteSinDecimal(char *cadena) {

	int retorno = 0;
	int esDecimal = 1;
	int esEnteroDecimal = 1;
	int tienePunto = 0;

	for (int i = 0; i < strlen(cadena); i++) {

		if (cadena[i] == '.')
			tienePunto++;

		if ((!isdigit(cadena[i]) && cadena[i] != '.') || tienePunto > 1) {
			esDecimal = 0;
			retorno = -1;
		}

		if (esDecimal == 0 && cadena[i] > 0) {
			esEnteroDecimal = 0;
		}
	}

	if (esDecimal == 1 && esEnteroDecimal == 1)
		retorno = 1;

	return retorno;
}

int esLetra(char *cadena) {

	int retorno = 0;

	for (int i = 0; i < strlen(cadena); i++) {

		if (!isalpha(cadena[i]))
			retorno = -1;

	}

	return retorno;

}

int esAlfanumerico(char *cadena) {

	int retorno = 0;

	for (int i = 0; i < strlen(cadena); i++) {

		if (!isalpha(cadena[i]) && !isdigit(cadena[i])) {
			retorno = -1;
			break;
		}

	}

	return retorno;

}

int esFecha(char *fecha) {

	int retorno = 0;

	// formato esperado xx/xx/xxxx
	if (fecha != NULL) {

		for (int i = 0; i < strlen(fecha); i++) {

			if (i != 2 && i != 5) {

				//Si no tiene los '/' donde deberia, si no es numero o si tiene mas dias (ej40) o mas meses (ej13) retorna -1
				if ((fecha[2] != '/' || fecha[5] != '/')
						|| ((i != 2 && i != 5) && !isdigit(fecha[i]))
						|| (fecha[0] > '3'
								|| (fecha[0] == '3' && fecha[1] > '0')
								|| fecha[3] > '1'
								|| (fecha[3] > '0' && fecha[4] > '2'))) {

					retorno = -1;
					break;

				}

			}

		}

	}
	return retorno;
}

int elegirEntreOpciones(char mensaje[60], char condicionParaContinuar[60],
		char condicionParaSalir[60]) {

	int retorno = -1;
	char respuestaUsuario[60];

	do {

		printf(mensaje);
		myGets(respuestaUsuario, 60);

	} while ((strcmp(condicionParaContinuar, respuestaUsuario) != 0)
			&& (strcmp(condicionParaSalir, respuestaUsuario) != 0));

	//Si desea continuar retorná 1, si no desea continuar 0, en caso de error -1.
	if (strcmp(condicionParaContinuar, respuestaUsuario) == 0) {
		retorno = 1;
	} else
		retorno = 0;

	return retorno;
}
