/*
 ============================================================================
 Name        : 5_.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/**
 Ejercicio 11-5: Utilizar aritmética de punteros. Dada la siguiente estructura:
 int legajo;
 char nombre[20];
 int edad;
 Realizar una función que cargue un array de 3 estudiantes.
 Recibe un puntero al array de estudiantes, lo carga.
 Retorna 0 si funcionó correctamente -1 mal.
 Una vez cargados los estudiantes mostrar el array cargado.
 */

#include <stdio.h>
#include <stdlib.h>
#include "utnValidacion.h"
#define TAMESTUDIANTES 3

typedef struct {

	int legajo;
	char nombre[20];
	int edad;

} eEstudiante;

eEstudiante cargarEstudiante(int *validacionDeFuncion, int *id);

int cargarEstudiantes(eEstudiante *estudiantes, int tamEstudiantes, int *id);

int mostrarEstudiantes(eEstudiante *estudiantes, int tamEstudiantes);

int main(void) {

	setbuf(stdout, NULL);
	eEstudiante estudiantes[TAMESTUDIANTES];
	int id = 1;

	cargarEstudiantes(estudiantes, TAMESTUDIANTES, &id);

	mostrarEstudiantes(estudiantes, TAMESTUDIANTES);

	return EXIT_SUCCESS;

}

eEstudiante cargarEstudiante(int *validacionDeFuncion, int *id) {

	eEstudiante auxEstudiante;

	*validacionDeFuncion = -1;

	if (validacionDeFuncion != NULL) {

		getPedirStringDeLetras(auxEstudiante.nombre, "\nIngrese nombre: ",
				"\nError", 1);

		getPedirInt(&auxEstudiante.edad, "\nIngrese edad: ", "\nError", 12, 70,
				1);

		auxEstudiante.legajo = *id;
		(*id)++;

		*validacionDeFuncion = 0;
	}

	return auxEstudiante;
}

int cargarEstudiantes(eEstudiante *estudiantes, int tamEstudiante, int *id) {

	int retorno = -1;

	if (estudiantes != NULL && tamEstudiante > 0) {

		for (int i = 0; i < tamEstudiante; i++) {

			*(estudiantes + i) = cargarEstudiante(&retorno, id);

			if (retorno != 0)
				break;

		}
	}

	return retorno;
}

int mostrarEstudiantes(eEstudiante *estudiantes, int tamEstudiantes) {

	int retorno = -1;

	if (estudiantes != NULL && tamEstudiantes > 0) {

		for (int i = 0; i < tamEstudiantes; i++) {

			printf("\n\nLegajo -> %d", (estudiantes + i)->legajo);
			printf("\nNombre -> %s", (estudiantes + i)->nombre);
			printf("\nEdad -> %d", (estudiantes + i)->edad);

		}

		retorno = 0;
	}

	return retorno;
}
