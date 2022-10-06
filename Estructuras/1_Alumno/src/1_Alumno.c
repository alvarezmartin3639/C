/*
 ============================================================================
 Name        : 1_Alumno.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/**
 * Ejercicio 9-1: Crear la estructura Alumno (nombre, materias aprobadas, suma de
notas, promedio). Crear una función que permita cargar los datos de un alumno y
otra que los muestre. Una tercera función calculará el promedio de notas.
 */

#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"

int main(void) {
	setbuf(stdout,NULL);
	eAlumno alumno;
	char materiasAprobadas[3][50] = {"Matematica", "Lengua","laboratorio"};

	cargarAlumno(&alumno, "Juan Manuel", materiasAprobadas, 4, 6, calcularPromedioDeNotas(alumno, 3));
	mostrarAlumno(alumno);
	return EXIT_SUCCESS;
}
