/*
 ============================================================================
 Name        : 3_Ordenamiento_Carga_Secuencial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ordenamiento.h"
#define TAMEMPLEADOS 15
/*
 Ejercicio 6-3: Realizar un programa que permita el ingreso de datos de 15 empleados
 legajo (coincidente con el índice), edad, salario, sexo (1-Femenino, 2-Masculino, 3-No
 binario). Realizar carga secuencial. Calcular el sueldo promedio. Listar a los
 empleados no binarios.
 */
int main(void) {
	setbuf(stdout, NULL);
	int edad[TAMEMPLEADOS];
	float salario[TAMEMPLEADOS];
	int sexo[TAMEMPLEADOS];
	float acumSalario;
	int existeEmpleadoBinario = 0;

	//Carga secuencial de empleados
	for (int i = 0; i < TAMEMPLEADOS; i++) {

		for(int i = 0 ;i<20;i++)
		printf("\n");

		printf("\n=======================================");
		printf("\nCreando empleado legajo numero %d",i+1);
		printf("\n=======================================");

		do {
			printf("\n\nIngrese el salario: ");
			fflush(stdin);
			scanf(" %f", &salario[i]);

			if (salario[i] < 1)
				printf("\n***Error,%2.f no es un salario valido", salario[i]);
		} while (salario[i] < 1);

		do {
			printf("\nIngrese la edad: ");
			fflush(stdin);
			scanf(" %d", &edad[i]);

			if (edad[i] < 18)
				printf("\n***Error,%d no es una edad valido", edad[i]);
		} while (edad[i] < 18);

		do {
			printf("\n1-Femenino");
			printf("\n2-Masculino");
			printf("\n3-No binario");
			printf("\nIngrese el sexo: ");
			fflush(stdin);
			scanf(" %d", &sexo[i]);

			if(sexo[i]==3)
			existeEmpleadoBinario = 1;

			else if (sexo[i] > 3 || sexo[i] < 1)
				printf("\n***Error,la opción %d no es una opción válida (estas son 1, 2 o 3)",
						sexo[i]);

		} while (sexo[i] > 3 || sexo[i] < 1);

	}

	printf("\n\nMostrar promedio salarios");
	for (int i = 0; i < TAMEMPLEADOS; i++) {
		acumSalario += salario[i];
	}
	printf("\nEl promedio del salario es %2.f", acumSalario / TAMEMPLEADOS);


	printf("\n\nMostrar empleados no binarios");

	if(existeEmpleadoBinario == 0 )
		printf("\nNo se encontraron empleados no binario!");

	else{
		printf("\n|| LEGAJO ||     SEXO      || EDAD  || SALARIO ||");
		for (int i = 0; i < TAMEMPLEADOS; i++) {
				if (sexo[i] == 3) {
					printf("\n       %d     %s          %d         %2.f", i+1, "No binario", edad[i],
							salario[i]);
				}
			}
	}


	return EXIT_SUCCESS;
}

