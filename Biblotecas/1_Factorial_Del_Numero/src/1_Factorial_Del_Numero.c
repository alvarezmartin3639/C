/*
 ============================================================================
 Name        : 1_Factorial_Del_Numero.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 Ejercicio 4-1: Realizar un programa en el MAIN que permita calcular y mostrar el factorial de
 un número. Utilizar la función de PedirNumero de la ejercitación 3. Por ejemplo:
 5! = 5*4*3*2*1 = 120
 */

#include <stdio.h>
#include <stdlib.h>
#include "pedirNumero.h"

int main(void) {
	setbuf(stdout, NULL);
	float numeroPedido;

	numeroPedido = pedirNumero();
	printf("\n%.2f ", numeroPedido);

	return EXIT_SUCCESS;
}
