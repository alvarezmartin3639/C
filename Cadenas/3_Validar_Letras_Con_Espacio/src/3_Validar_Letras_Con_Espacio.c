/*
 ============================================================================
 Name        : 3_Validar_Letras_Con_Espacio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/**
 * \brief valida que la cadena son solo letras y espacio en el medio
 * \param cadena es un puntero al espacio de memoria donde se dejara el
 resultado de la funcion
 * return Retorna 1 si todo ok, 0, SI ES ERROR.
 */
//int esLetraConEspacio(char *pResultado);
/**
 * \brief valida que la cadena son solo letras
 * \param cadena es un puntero al espacio de memoria donde se dejara el
 resultado de la funcion
 * return Retorna 1 si todo ok, 0, SI ES ERROR.
 */
//int esSoloLetra(char *pResultado);

#include <stdio.h>
#include <stdlib.h>
#include "utnValidacion.h"

int main(void) {
	setbuf(stdout, NULL);
	char esSoloLetra[23] = "Letras";
	char letraConEspacio[23] = "Esletr conespacio";

	if(esLetra(esSoloLetra) == 1)
		printf("\nEs solo letra");
	else
		printf("\nNo es solo letra");

	if(esLetraConEspacio(letraConEspacio) == 1)
			printf("\nEs letra con espacio" );
		else
			printf("\nNo es letra con espacio");

	return EXIT_SUCCESS;
}
