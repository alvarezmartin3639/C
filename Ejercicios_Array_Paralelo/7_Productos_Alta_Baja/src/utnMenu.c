/*
 * utnMenu.c
 *
 *  Created on: 26 sept 2022
 *      Author: kenyn
 */

#include "utnMenu.h"
#include "utnValidacion.h"
#include "utnCadenas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int altaProducto(char codigo[][5], char fechaIngreso[][25],
		char descripcion[][15], int *estaLibre, int tamProducto) {

	int indiceLibre = -1;
	int retorno = -1;
	char auxCodigo[5];
	char auxFechaIngreso[25];
	char auxDescripcion[15];

	if (codigo != NULL && fechaIngreso != NULL && descripcion != NULL
			&& estaLibre != NULL && tamProducto > 0) {

		do {

			retorno = 1;

			for (int i = 0; i < tamProducto; i++) {

				if (estaLibre[i] == 1) {

					indiceLibre = i;
					break;

				}
			}

			if (indiceLibre == -1)
				continue;

			else if (getPedirAlfanumerico(auxCodigo,
					"\nIngrese el código alfanumerico (max 5 caracteres): ",
					"\n***Error, no es un código alfanumerico valido o contiene mas de 5 caracteres***",
					1) == -1) {

				if (strlen(auxCodigo) > 5)
					printf( "\n***Error, El numero de caracteres supera el permitido!");

			}

			else if (getPedirFecha(auxFechaIngreso,
					"\nIngrese una fecha: (xx/xx/xxxx)",
					"\n***Error, no es una fecha valida, esta debe estar con el siguiente formato (xx/xx/xxxx) en donde 'x' son numeros positivos***",
					4) == -1) {
				continue;
			}

			else if (getPedirStringDeLetras(auxDescripcion,
					"\nIngrese una descripción: ",
					"\n***Error, no es una descripción valida***", 1) == -1) {

				if (strlen(auxDescripcion) > 15)
					printf( "\n***Error, El numero de caracteres supera el permitido!");
			}

			else {

				printf("\nCodigo -> %s", auxCodigo);
				printf("\nFecha -> %s", auxFechaIngreso);
				printf("\nDescripción -> %s", auxDescripcion);

				if (deseaContinuar("\n¿Desea crear este producto? (si/no)",
						"si", "no") == 1) {

					strcpy(codigo[indiceLibre], auxCodigo);
					strcpy(fechaIngreso[indiceLibre], auxFechaIngreso);
					strcpy(descripcion[indiceLibre], auxDescripcion);
					*estaLibre = 0;

					retorno = 0;
				}

			}

			if (retorno == 1)
				printf("\nSe acabaron los re-intentos!...");
			else
				printf("\nProducto creado con exito!");

		} while (deseaContinuar(
				"\n¿Desea continuar ingresando productos? (si/no)", "si", "no")
				== 1);

	}

	return indiceLibre;
}

int bajaProducto(char codigo[][5], char fechaIngreso[][25],
		char descripcion[][15], int *estaLibre, int tamProducto) {

	char codigoParaBorrar[5];
	int indiceDelProductoParaBorrar;

	if (codigo != NULL && fechaIngreso != NULL && descripcion != NULL
			&& estaLibre != NULL && tamProducto > 0
			&& buscarValorIntEnArray(estaLibre, 0, tamProducto) != -1) {

		do {

			printf("\n Indice = %d", indiceDelProductoParaBorrar);

			if (getPedirAlfanumerico(codigoParaBorrar,
					"\nIngrese el codigo del producto para eliminar: ",
					"\n***Error, codigo invalido*** ", 4) == -1)
				printf(
						"\n\n¡Se canceló la baja del producto debido a que se agotaron los re-intentos!...");

			indiceDelProductoParaBorrar = buscarValorStringEnArray(5,
					tamProducto, codigo, codigoParaBorrar);

			if (indiceDelProductoParaBorrar == -1
					|| estaLibre[indiceDelProductoParaBorrar] == 1)
				printf(
						"\n\n***Error, no existe un producto con ese código!***");
			else {

				printf("\nCodigo -> %s", codigo[indiceDelProductoParaBorrar]);
				printf("\nFecha -> %s",
						fechaIngreso[indiceDelProductoParaBorrar]);
				printf("\nDescripción -> %s",
						descripcion[indiceDelProductoParaBorrar]);

				if (deseaContinuar("\n¿Desea borrar este producto? (si/no)",
						"si", "no") == 1) {

					estaLibre[indiceDelProductoParaBorrar] = 1;

				}

			}

		} while (deseaContinuar(
				"\n¿Desea continuar eliminando productos? (si/no)", "si", "no")
				== 1);
	}

	return indiceDelProductoParaBorrar;
}

int buscarValorIntEnArray(int arrayInt[], int valorBuscado, int tamArrayString) {

	int retorno = -1;

	if (arrayInt != NULL && tamArrayString > 0) {

		for (int i = 0; i < tamArrayString; i++) {

			if (arrayInt[i] == valorBuscado) {
				retorno = i;
				break;
			}

		}
	}

	return retorno;
}

int buscarValorStringEnArray(int tamCaracteres, int tamArrayString,
		char arrayString[][tamCaracteres], char *valorBuscado) {

	int retorno = -1;

	if (arrayString != NULL && valorBuscado != NULL && tamArrayString > 0) {

		for (int i = 0; i < tamArrayString; i++) {

			if (strcmp(arrayString[i], valorBuscado) == 0) {
				retorno = i;
				break;
			}

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
			reintentos--;
			printf(mensajeError);

		}

		if (reintentos > 0) {
			retorno = 0;
			strcpy(pChar, fecha);
		}
	}

	return retorno;
}
