/*
 ============================================================================
 Name        : 3-3_Verificar_Par.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int verificarSiEsPar(int numeroParaVerificar);

int main(void) {
	if (verificarSiEsPar(2))
		printf("\nEs par");
	else
		printf("\nEs impar");

	return EXIT_SUCCESS;
}

int verificarSiEsPar(int numeroParaVerificar) {
	int retorno = EXIT_FAILURE;

	if (numeroParaVerificar % 2 != 0)
		retorno = EXIT_SUCCESS;

	return retorno;
}
