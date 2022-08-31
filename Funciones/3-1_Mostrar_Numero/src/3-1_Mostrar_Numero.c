/*
 ============================================================================
 Name        : 3-1_Mostrar_Numero.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void mostrarNumero(int numeroParaMostrar);

int main(void) {
	mostrarNumero(1);
	return EXIT_SUCCESS;
}

void mostrarNumero(int numeroParaMostrar){
	printf("%d",numeroParaMostrar);
}
