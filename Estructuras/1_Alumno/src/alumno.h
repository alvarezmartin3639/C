/*
 * alumno.h
 *
 *  Created on: 26 sept 2022
 *      Author: kenyn
 */

#ifndef ALUMNO_H_
#define ALUMNO_H_
#define TAMMATERIAS 4
typedef struct {

	char nombre[50];
	char materiasAprobadas[TAMMATERIAS][50];
	float sumaDeNotas;
	float promedio;

} eAlumno;

int cargarAlumno(eAlumno* alumno, char* nombre, char materiasAprobadas[][50], int tamMateriasAprobadas, float sumaDeNotas, float promedio);
int calcularPromedioDeNotas(eAlumno alumno, int cantExamenes);
int mostrarAlumno(eAlumno alumno );

#endif /* ALUMNO_H_ */
