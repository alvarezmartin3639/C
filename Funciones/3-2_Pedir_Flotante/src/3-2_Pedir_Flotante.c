/*
 ============================================================================
 Name        : 3-2_Pedir_Flotante.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

float getFloat();

int main(void) {
	printf("%f",getFloat());
	return EXIT_SUCCESS;
}

float getFloat() {
	float numeroEscrito;
	fprintf("\nIngrese un numero del tipo flotante");
	fflush(stdin);
	scanf(" %f", &numeroEscrito);
	return numeroEscrito;
}
