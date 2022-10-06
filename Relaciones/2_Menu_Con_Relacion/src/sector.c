/*
 * sectores.c
 *
 *  Created on: 29 sept 2022
 *      Author: kenyn
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sector.h"
#include "utnValidacion.h"

int setSector(eSector *sector, int idSector, char *descripcion) {

	int retorno = -1;

	if (sector != NULL && descripcion != NULL) {

		strcpy(sector->descripcionSector, descripcion);
		sector->idSector = idSector;
		retorno = 0;
	}

	return retorno;
}

int esSectorValido(eSector *sectores, int tamSectores, char *nombreDelSector) {

	int retorno = -1;

	if (sectores != NULL && tamSectores > 0 && nombreDelSector != NULL) {

		for (int i = 0; i < tamSectores; i++) {

			if (strcmp(sectores[i].descripcionSector, nombreDelSector) == 0) {
				retorno = i;
				break;
			}

		}
	}

	return retorno;
}

int getPedirSectorValido(char *pResultado, char *mensaje, eSector *sectores, int tamSectores, char *mensajeError, int reintentos) {

	int retorno = -1;
	char cadena[64];

	if (mensaje != NULL && pResultado != NULL && sectores != NULL && tamSectores > 0 && mensajeError != NULL && reintentos > -1) {

		while (reintentos > 0) {

			if (elegirEntreOpciones("\n¿Desea ver los sectores antes de ingresar el nombre? (si/no)", "si", "no") == 1)
				mostrarDescripcionSector(sectores, tamSectores, 1);

			getPedirStringDeLetras(cadena, mensaje, mensajeError, reintentos);

			if (esSectorValido(sectores, tamSectores, cadena) > -1) {
				break;
			}

			fflush(stdin);
			reintentos--;
			printf(mensajeError);

		}

		if (reintentos > 0) {
			retorno = 0;
			strcpy(pResultado, cadena);
		}

	}

	return retorno;
}

int mostrarDescripcionSector(eSector *sector, int tamSector, int cabecera) {

	int retorno = -1;

	if (sector != NULL && tamSector > 0) {

		if (cabecera == 1)
			printf("\n\n       MOSTRAR DESCRIPCIÓNES DE SECTORES");
		for (int i = 0; i < tamSector; i++)
			printf("\n%s", sector[i].descripcionSector);

		retorno = 0;
	}

	return retorno;
}
