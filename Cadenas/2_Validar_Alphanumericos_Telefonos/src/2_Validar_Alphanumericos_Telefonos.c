/*
 ============================================================================
 Name        : 2_Validar_Alphanumericos_Telefonos.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
Ejercicio 7-2: Realizar funciones para validar y obtener:
Alfanumericos, ej. ab555gT6
Teléfonos, ej. 4XXX-XXXX
 */

#include <stdio.h>
#include <stdlib.h>
#include "utnValidacion.h"

int main(void) {
	setbuf(stdout,NULL);
	char alfanumerico[24] = "ab555gT6";
	char telefono[24] = "4232-2322";

	if(esAlfanumerico(alfanumerico) == 1)
		printf("\nEs alfanumerico!");
	else
		printf("\nNo es alfanumerico!");

	if(esNumeroTelefonico(telefono) == 1)
		printf("\nEs telefono!");
	else
		printf("\nNo es telefono!");

	return EXIT_SUCCESS;
}
