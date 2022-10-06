/*
 ============================================================================
 Name        : TP_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utnArray.h"
#include "utnValidacion.h"
#include "utnCadenas.h"
#include "utnGUI.h"
#include "utnMenu.h"

#define TAMJUGADORES 22
#define TAMCONFEDERACION 6
#define TAMEQUIPOTITULAR 11
int main(void) {

	setbuf(stdout, NULL);
	int numeroCamiseta[TAMJUGADORES];
	//0=Sin carga, 1=Arquero, 2=Defensores, 3=Mediocampista, 4=Delanteros
	int posicion[TAMJUGADORES];
	//Conf Asia
	int contJugadoresAFC;
	//Conf África
	int contJugadoresCAF;
	//Conf zona del Norte
	int contJugadoresCONCACAF;
	//Conf Sudamerica
	int contJugadoresCONMEBOL;
	//Conf Europa
	int contJugadoresUEFA;
	//Conf Oceanía
	int contJugadoresOFC;
	//0=AFC, 1=CAF, 2=CONCACAF, 3=CONMEBOL, 4=UEFA, 5=OFC
	float promedioJugadoresEnConfederacion[TAMCONFEDERACION];
	//Array con los indices de los jugadores titulares
	int equipoTitular[TAMEQUIPOTITULAR];
	float costoMantenimiento;
	float cantidadDeRecargo;
	float costoHospedaje;
	float costoComida;
	float costoTransporte;
	int opcionElegida;
	int seRealizoCalculo;

	inicializacionDeVariables(&costoHospedaje, &costoComida, &costoTransporte,
			&costoMantenimiento, &contJugadoresAFC, &contJugadoresCAF,
			&contJugadoresCONCACAF, &contJugadoresCONMEBOL, &contJugadoresOFC,
			&contJugadoresUEFA, numeroCamiseta, posicion,
			TAMJUGADORES, equipoTitular, TAMEQUIPOTITULAR, &seRealizoCalculo);

	hardcodearMenu(&costoHospedaje, &costoComida, &costoTransporte,
			&contJugadoresAFC, &contJugadoresCAF, &contJugadoresCONCACAF,
			&contJugadoresCONMEBOL, &contJugadoresOFC, &contJugadoresUEFA,
			numeroCamiseta, posicion, TAMJUGADORES, &seRealizoCalculo);

	do {

		mostrarMenuPrincipal(&costoHospedaje, &costoComida, &costoTransporte,
				posicion, TAMJUGADORES);

		getPedirInt(&opcionElegida, "\n\nIngrese una opción:  ",
				"\n***Error, lo ingresado no es una opción válida, está debe ser un numero entre 1 y 5",
				1, 5, 2);

		switch (opcionElegida) {

		case 1:
			cargarCostos(&costoHospedaje, &costoComida, &costoTransporte, &seRealizoCalculo);
			break;

		case 2:
			cargarJugadores(posicion, numeroCamiseta, TAMJUGADORES,
					&contJugadoresAFC, &contJugadoresCAF,
					&contJugadoresCONCACAF, &contJugadoresCONMEBOL,
					&contJugadoresUEFA, &contJugadoresOFC, equipoTitular,
					TAMEQUIPOTITULAR,&seRealizoCalculo);
			break;

		case 3:
			realizarCalculos(posicion, equipoTitular,
					promedioJugadoresEnConfederacion, &costoMantenimiento,
					&cantidadDeRecargo, &seRealizoCalculo, contJugadoresAFC,
					contJugadoresCAF, contJugadoresCONCACAF,
					contJugadoresCONMEBOL, contJugadoresUEFA, contJugadoresOFC,
					costoComida, costoHospedaje, costoTransporte, TAMJUGADORES,
					TAMEQUIPOTITULAR, TAMCONFEDERACION);
			break;

		case 4:
			informarResultados(posicion, promedioJugadoresEnConfederacion,
					cantidadDeRecargo, costoComida, costoHospedaje,
					costoMantenimiento, costoTransporte, seRealizoCalculo,
					TAMJUGADORES);
			break;
		}

	} while (opcionElegida != 5);

	return EXIT_SUCCESS;
}
