/*
 * alumno.c
 *
 *  Created on: 26 sept 2022
 *      Author: kenyn
 */

#include "alumno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utnValidacion.h"
#include "utnArray.h"

int cargarAlumno(eAlumno* alumno, char *nombre, char materiasAprobadas[][50],
		int tamMateriasAprobadas, float sumaDeNotas, float promedio) {

	int retorno = -1;

	if (nombre != NULL && materiasAprobadas != NULL && sumaDeNotas > -1
			&& promedio > -1) {

		strcpy(alumno->nombre, nombre);
		for(int i=0; i<tamMateriasAprobadas;i++)
		strcpy(alumno->materiasAprobadas[i], materiasAprobadas[i]);
		alumno->sumaDeNotas = sumaDeNotas;
		alumno->promedio = promedio;
		retorno = 0;

	}

	return retorno;
}

int calcularPromedioDeNotas(eAlumno alumno, int cantExamenes) {

	int retorno = -1;

	alumno.promedio = alumno.sumaDeNotas / cantExamenes;
	retorno = 0;

	return retorno;
}

int mostrarAlumno(eAlumno alumno) {

	int retorno = -1;

	printf("\nNombre -> %s", alumno.nombre);
	for(int i =0; i<TAMMATERIAS;i++)
	printf("\nMaterias aprobadas -> %s",alumno.materiasAprobadas[i]);
	printf("\nSuma de notas -> %.2f", alumno.sumaDeNotas);
	printf("\nPromedio -> %.2f",alumno.promedio);

	return retorno;
}
