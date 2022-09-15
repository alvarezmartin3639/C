/*
 ============================================================================
 Name        : 1_Concatenar_Dos_Strings.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
Ejercicio 7-1: Pedirle al usuario su nombre y apellido (en variables separadas, una
para el nombre y otra para el apellido). Ninguna de las dos variables se puede
modificar. Debemos lograr guardar en una tercer variable el apellido y el nombre con
el siguiente formato: Perez, Juan Ignacio usando la siguiente función
 */

#include <stdio.h>
#include <stdlib.h>
#include "manipuladorString.h"

int main(void) {
	setbuf(stdout,NULL);
	char nombre[30];
	char apellido[30];
	char nombreCompleto[60]="";

	printf("\nIngrese el nombre: ");
	fflush(stdin);
	scanf("%s",nombre);

	printf("\nIngrese el apellido: ");
	fflush(stdin);
	scanf("%s",apellido);

	printf("\nNombre: %s \nApellido:%s",nombre, apellido);

	FormarApellidoNombre(nombre, apellido, nombreCompleto);

	printf("\nNombre y apellido: %s", nombreCompleto);

	return EXIT_SUCCESS;
}
