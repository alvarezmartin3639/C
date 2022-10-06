/*
 ============================================================================
 Name        : 4_Cargar_Estructura.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 Ejercicio 11-4: Utilizar aritmética de punteros. Dada la siguiente estructura:
 int legajo;
 char nombre[20];
 int edad;
 Realizar una función que cargue un array de 3 estudiantes. Recibe un entero. Retorna
 el estudiante dado de alta y por parámetro 0 si funcionó correctamente -1 mal. Una
 vez devuelto el estudiante cargarlo en una posición del array. Al final mostrar el array
 cargado.
 */

typedef struct {

	int legajo;
	char nombre[20];
	int edad;

} eEstudiante;

eEstudiante cargarEstudiante(int *esUnExito, int *legajo);
int mostrarEstudiantes(eEstudiante *estudiantes, int tamEstudiante);

#include <stdio.h>
#include <stdlib.h>
#include "utnValidacion.h"
#define TAMESTUDIANTES 3
int main(void) {

	setbuf(stdout, NULL);
	eEstudiante miEstudiantes[TAMESTUDIANTES];
	int esUnExito = 0;
	int legajo = 1;

	for (int i = 0; i < TAMESTUDIANTES; i++) {

		*(miEstudiantes + i) = cargarEstudiante(&esUnExito, &legajo);

	}

	mostrarEstudiantes(miEstudiantes, TAMESTUDIANTES);

	return EXIT_SUCCESS;
}

eEstudiante cargarEstudiante(int *esUnExito, int *legajo) {

	eEstudiante auxEstudiante;

	if (esUnExito == NULL || legajo == NULL)
		*esUnExito = 1;

	else if (getPedirStringDeLetras(auxEstudiante.nombre, "\nIngrese nombre: ",
			"\nERROR, nombre invalido...", 4) == 0
			&& getPedirInt(&auxEstudiante.edad, "\nIngrese edad: ",
					"\nERROR, edad invalida...", 13, 50, 1) == 0) {

		auxEstudiante.legajo = *legajo;
		(*legajo)++;
		*esUnExito = 0;

		//FALTA COMPLETAR
	}

	return auxEstudiante;
}

int mostrarEstudiantes(eEstudiante *estudiantes, int tamEstudiante) {

	int retorno = -1;

	if (estudiantes != NULL && tamEstudiante > 0) {

		for (int i = 0; i < tamEstudiante; i++) {

			printf("\n\nLegajo -> %d", (estudiantes + i)->legajo);
			printf("\n\nNombre -> %s", (estudiantes + i)->nombre);
			printf("\n\nEdad -> %d", (estudiantes + i)->edad);

		}

		retorno = 0;
	}

	return retorno;
}
