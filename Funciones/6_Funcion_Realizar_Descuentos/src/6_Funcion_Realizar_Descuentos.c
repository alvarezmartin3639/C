/*
 ============================================================================
 Name        : 6_Funcion_Realizar_Descuentos.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 Ejercicio 3-6: Realizar un programa que: asigne a la variable numero1 un valor
 solicitado al usuario, valide el mismo entre 10 y 100, realice un descuento del 5% a
 dicho valor a través de una función llamada realizarDescuento(). Mostrar el resultado
 por pantalla.
 */

#include <stdio.h>
#include <stdlib.h>

int realizarDescuento(int valorParaDescuento, int descuentoParaAplicar);

int main(void) {
	setbuf(stdout, NULL);
	int numero1;

	do {
		printf("\nIngrese un monto en pesos: ");
		fflush(stdin);
		scanf("%d", &numero1);

		if (numero1 < 11 || numero1 > 101)
			printf("\n***Error,%d no es un monto valido, este debe estar entre 10 y 100",
					numero1);
	} while (numero1 < 11 || numero1 > 101);

	printf("\nEl monto final es de %d", realizarDescuento(numero1, 5));

	return EXIT_SUCCESS;
}

int realizarDescuento(int valorParaDescuento, int descuentoParaAplicar) {
	return valorParaDescuento - valorParaDescuento * descuentoParaAplicar / 100;
}
