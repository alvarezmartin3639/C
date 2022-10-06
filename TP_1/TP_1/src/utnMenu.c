/*
 * utnMenu.c
 *
 *  Created on: 18 sept 2022
 *      Author: kenyn
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utnMenu.h"
#include "utnValidacion.h"
#include "utnArray.h"
#include "utnGUI.h"

int mostrarMenuPrincipal(float *costoHospedaje, float *costoComida,
		float *costoTransporte, int *posicion, int tamJugadores) {

	int retorno = -1;
	if (costoHospedaje != NULL && costoComida != NULL && costoTransporte != NULL
			&& posicion != NULL && tamJugadores > 0) {

		retorno = 0;
		limpiarPantalla();
		printf("\n               Menu Principal\n");
		printf("\n1. Ingreso de los costos de Mantenimiento");
		mostrarCostos(*costoHospedaje, *costoComida, *costoTransporte);
		printf("\n2.Carga de jugadores");
		mostrarPosicionesYCantidadDeJugadores(posicion, tamJugadores, 0);
		printf("\n3.Realizar todos los cálculos");
		printf("\n4.Informar todos los resultados");
		printf("\n5.Salir");

	}

	return retorno;
}

char* mostrarPosicion(int posicion) {

	char retorno[50] = "0";

	if (posicion > 0 && posicion < 5) {

		if (posicion == 1)
			strcpy(retorno, "Arquero");

		else if (posicion == 2)
			strcpy(retorno, "Defensor");

		else if (posicion == 3)
			strcpy(retorno, "Mediocampista");

		else
			strcpy(retorno, "Delantero");

	}

	return strdup(retorno);
}

char* mostrarConfederacion(int confederacion) {

	char retorno[50] = "0";

	if (confederacion > 0 && confederacion < 7) {

		if (confederacion == 1)
			strcpy(retorno, "AFC(Asia)");

		else if (confederacion == 2)
			strcpy(retorno, "CAF(Conf África)");

		else if (confederacion == 3)
			strcpy(retorno, "CONCACAF(zona del Norte)");

		else if (confederacion == 4)
			strcpy(retorno, "CONMEBOL(Sudamerica)");

		else if (confederacion == 5)
			strcpy(retorno, "UEFA(Europa)");

		else
			strcpy(retorno, "OFC(Conf oceanía)");

	}

	return strdup(retorno);
}

int inicializacionDeVariables(float *costoHospedaje, float *costoComida,
		float *costoTransporte, float *costoDeMantenimiento,
		int *contJugadoresAFC, int *contJugadoresCAF,
		int *contJugadoresCONCACAF, int *contJugadoresCONMEBOL,
		int *contJugadoresOFC, int *contJugadoresUEFA, int *numeroCamiseta,
		int *posicion, int tamJugadores, int *equipoTitular,
		int tamEquipoTitular, int *seRealizoCalculo) {

	*costoHospedaje = 0;
	*costoComida = 0;
	*costoTransporte = 0;
	*costoDeMantenimiento = 0;
	*contJugadoresAFC = 0;
	*contJugadoresCAF = 0;
	*contJugadoresCONCACAF = 0;
	*contJugadoresCONMEBOL = 0;
	*contJugadoresOFC = 0;
	*contJugadoresUEFA = 0;
	*seRealizoCalculo = 0;
	inicializarArrayInt(numeroCamiseta, tamJugadores, -1);
	inicializarArrayInt(equipoTitular, tamEquipoTitular, -1);
	return inicializarArrayInt(posicion, tamJugadores, -1);

}

void hardcodearMenu(float *costoHospedaje, float *costoComida,
		float *costoTransporte, int *contJugadoresAFC, int *contJugadoresCAF,
		int *contJugadoresCONCACAF, int *contJugadoresCONMEBOL,
		int *contJugadoresOFC, int *contJugadoresUEFA, int *numeroCamiseta,
		int *posicion, int tamJugadores, int *seRealizoCalculo) {

	*costoHospedaje = 100000;
	*costoComida = 20000;
	*costoTransporte = 50000;
	*contJugadoresAFC = 0;
	*contJugadoresCAF = 0;
	*contJugadoresCONCACAF = 0;
	*contJugadoresCONMEBOL = 0;
	*contJugadoresOFC = 0;
	*contJugadoresUEFA = 0;
	*seRealizoCalculo = 0;

	for (int i = 0; i < tamJugadores; i++) {

		numeroCamiseta[i] = i + 1;

		if (contarCantDeNumerosEnArrayInt(posicion, tamJugadores, 1) < 2) {
			posicion[i] = 1;
			*contJugadoresAFC += 1;

		}

		else if (contarCantDeNumerosEnArrayInt(posicion, tamJugadores, 2) < 8) {
			posicion[i] = 2;
			*contJugadoresCAF += 1;
		}

		else if (contarCantDeNumerosEnArrayInt(posicion, tamJugadores, 3) < 8) {
			posicion[i] = 3;
			*contJugadoresCONCACAF += 1;
		}

		else if (contarCantDeNumerosEnArrayInt(posicion, tamJugadores, 4) < 4) {
			posicion[i] = 4;
			*contJugadoresUEFA += 1;
		}

	}

}
int calcularNumeroDePosiciones(int *contArqueros, int *contDefensores,
		int *contMediocampistas, int *contDelanteros, int *posicion,
		int tamJugadores) {

	int retorno = -1;

	if (contArqueros != NULL && contDefensores != NULL
			&& contMediocampistas != NULL && contDelanteros != NULL
			&& posicion != NULL && tamJugadores > 0) {

		for (int i = 0; i < tamJugadores; i++) {

			if (posicion[i] != -1) {

				if (posicion[i] == 1)
					*contArqueros += 1;

				else if (posicion[i] == 2)
					*contDefensores += 1;

				else if (posicion[i] == 3)
					*contMediocampistas += 1;

				else
					*contDelanteros += 1;

			}
		}

		retorno = 0;
	}

	return retorno;
}

int mostrarPosicionesYCantidadDeJugadores(int *posicion, int tamJugadores,
		int mostrarIndices) {

	int retorno = -1;
	int contArqueros = 0;
	int contDefensores = 0;
	int contMediocampistas = 0;
	int contDelanteros = 0;

	retorno = calcularNumeroDePosiciones(&contArqueros, &contDefensores,
			&contMediocampistas, &contDelanteros, posicion, tamJugadores);

	if (mostrarIndices == 1) {

		printf("\n1. Arqueros -> %d", contArqueros);
		printf("\n2. Defensores -> %d", contDefensores);
		printf("\n3. Mediocampistas -> %d", contMediocampistas);
		printf("\n4. Delanteros -> %d", contDelanteros);

	} else {

		printf("\n Arqueros -> %d", contArqueros);
		printf("\n Defensores -> %d", contDefensores);
		printf("\n Mediocampistas -> %d", contMediocampistas);
		printf("\n Delanteros -> %d", contDelanteros);

	}

	return retorno;
}

int mostrarCostos(float costoHospedaje, float costoComida,
		float costoTransporte) {

	int retorno = -1;

	if (costoHospedaje < 0 || costoComida < 0 || costoTransporte < 0)
		retorno = 1;

	else {

		if (costoHospedaje == 0)
			printf("\n Costo de hospedaje -> $%.0f", costoHospedaje);
		else
			printf("\n Costo de hospedaje -> $%.2f", costoHospedaje);

		if (costoComida == 0)
			printf("\n Costo de comida -> $%.0f", costoComida);
		else
			printf("\n Costo de comida -> $%.2f", costoComida);

		if (costoTransporte == 0)
			printf("\n Costo de transporte -> $%.0f", costoTransporte);
		else
			printf("\n Costo de transporte -> $%.2f", costoTransporte);

		retorno = 0;
	}

	return retorno;
}

int cargarCostos(float *costoHospedaje, float *costoComida,
		float *costoTransporte, int* serRealizoCalculos) {

	int retorno = -1;

	int opcionElegida;
	float costo;

	if (costoHospedaje != NULL && costoComida != NULL && costoTransporte != NULL) {
		limpiarPantalla();
		printf("\n               Ingreso de los costos de Mantenimiento.\n");
		mostrarCostos(*costoHospedaje, *costoComida, *costoTransporte);
		printf("\n\n1. Costo de hospedaje");
		printf("\n2. Costo de comida");
		printf("\n3. Costo de transporte");

		if (getPedirInt(&opcionElegida, "\n\nIngrese una opción: ",
				"\n***Error, lo ingresado no es una opción válida, esta debe ser un numero entre 1 y 3",
				1, 3, 4) == 0) {

			if (getPedirFloat(&costo, "\nIngrese el nuevo gasto: ",
					"\n***Error, lo ingresado no es un costo válido, este debe ser un numero entre 1 y 10000000",
					1, 10000000, 4) == 0) {

				switch (opcionElegida) {

				case 1:
					*costoHospedaje += costo;
					break;

				case 2:
					*costoComida += costo;
					break;

				case 3:
					*costoTransporte += costo;
					break;

				}
				*serRealizoCalculos = 0;
			}
		}

		retorno = 0;
	}


	textoConEspera("\n\n\nSe lo devolverá al menú principal en 3 segundos...",
			3);
	return retorno;
}

int pedirPosicion(int *posicion, int tamJugadores, int *auxPosicion) {

	int retorno = -1;

	if (posicion != NULL && tamJugadores > 0) {

		if (getPedirInt(auxPosicion,
				"\nSeleccione la posición correspondiente al jugador: ",
				"\n***Error, lo ingresado no es una opción válida, está debe ser un numero entre 1 y 4\n",
				1, 4, 4) == 0) {

			switch (*auxPosicion) {

			case 1:

				if (contarCantDeNumerosEnArrayInt(posicion, tamJugadores, 1)
						> 1) {
					retorno = 1;
					textoConEspera(
							"\n***Error, se alcanzó los puestos de Arqueros maximos(2), eliga otra posición para el jugador***",
							2000);
				}

				break;

			case 2:

				if (contarCantDeNumerosEnArrayInt(posicion, tamJugadores, 2)
						> 7) {
					retorno = 1;
					textoConEspera(
							"\n***Error, se alcanzó los puestos de Defensores maximos(8), eliga otra posición para el jugador***",
							2000);
				}

				break;

			case 3:

				if (contarCantDeNumerosEnArrayInt(posicion, tamJugadores, 3)
						> 7) {
					retorno = 1;
					textoConEspera(
							"\n***Error, se alcanzó los puestos de Mediocampistas maximos(8), eliga otra posición para el jugador***",
							2000);
				}

				break;

			case 4:

				if (contarCantDeNumerosEnArrayInt(posicion, tamJugadores, 4)
						> 3) {
					retorno = 1;
					textoConEspera(
							"\n***Error, se alcanzó los puestos de Delanteros maximos(4), eliga otra posición para el jugador***",
							2000);
				}

				break;

				retorno = 0;
			}
		}
	}

	return retorno;
}

int pedirConfedereacion(int *contJugadoresAFC, int *contJugadoresCAF,
		int *contJugadoresCONCACAF, int *contJugadoresCONMEBOL,
		int *contJugadoresUEFA, int *contJugadoresOFC) {

	int retorno = -1;
	int auxConfederacion;

	if (contJugadoresAFC == NULL || contJugadoresCAF == NULL
			|| contJugadoresCONCACAF == NULL || contJugadoresCONMEBOL == NULL
			|| contJugadoresUEFA == NULL || contJugadoresOFC == NULL)
		retorno = 1;

	else {

		printf("\n               Carga de jugadores\n");
		printf("\n Confederaciónes seleccionables");
		printf("\n1. AFC(Asia)");
		printf("\n2. CAF(África)");
		printf("\n3. CONCACAF(zona del Norte) ");
		printf("\n4. CONMEBOL(Sudamérica)");
		printf("\n5. UEFA(Europa)");
		printf("\n6. OFC(Oceanía)");

		if (getPedirInt(&auxConfederacion,
				"\nSeleccione la Confederación correspondiente al jugador: ",
				"\n***Error, lo ingresado no es una opción válida, está debe ser un numero entre 1 y 6",
				1, 6, 4) == 0) {

			retorno = auxConfederacion;

			switch (auxConfederacion) {

			case 1:

				*contJugadoresAFC += 1;
				break;

			case 2:
				*contJugadoresCAF += 1;
				break;

			case 3:
				*contJugadoresCONCACAF += 1;
				break;

			case 4:
				*contJugadoresCONMEBOL += 1;
				break;

			case 5:
				*contJugadoresUEFA += 1;
				break;

			case 6:
				*contJugadoresOFC += 1;
				break;

			}
		}
	}

	return retorno;
}

int pedirTitularidad(int *equipoTitular, int *posicion, int tamEquipoTitular,
		int tamJugadores, int *contJugadoresAFC, int *contJugadoresCAF,
		int *contJugadoresCONCACAF, int *contJugadoresCONMEBOL,
		int *contJugadoresUEFA, int *contJugadoresOFC) {

	int esTitular = -1;

	if (contJugadoresAFC < 0 || contJugadoresCAF < 0
			|| contJugadoresCONCACAF < 0 || contJugadoresCONMEBOL < 0
			|| contJugadoresUEFA < 0 || contJugadoresUEFA < 0) {

		esTitular = 1;

	} else {

		esTitular = elegirEntreOpciones(
				"\n\nEscriba 'titular' si el jugador es titular o "
						"'suplente' si el jugador es suplente: ", "titular",
				"suplente");

		if (esTitular == 1
				&& verificarEspacioParaSerTitular(equipoTitular, posicion,
						tamEquipoTitular, tamJugadores) == 0) {

			if (elegirEntreOpciones(
					"\n***Error, se alcanzó el maximo de espacios disponibles en el "
							"equipo titular, escriba 'salir' para salir de la carga del jugador" " o 'suplente' para cargarlo como suplente ***",
					"salir", "suplente") == 1)
				esTitular = -1;

			else
				esTitular = 0;

		}

	}

	return esTitular;
}

int verificarEspacioParaSerTitular(int *equipoTitular, int *posicion,
		int tamEquipoTitular, int tamJugadores) {

	int espacioDisponibleEnEquipo = buscarIntEnArray(equipoTitular,
			tamEquipoTitular, -1);

	if (espacioDisponibleEnEquipo != -1) {

		if (buscarIntEnArray(posicion, tamJugadores, 1) < 2
				|| buscarIntEnArray(posicion, tamJugadores, 2) < 8
				|| buscarIntEnArray(posicion, tamJugadores, 3) < 8
				|| buscarIntEnArray(posicion, tamJugadores, 4) < 4)
			espacioDisponibleEnEquipo = 1;

	} else
		espacioDisponibleEnEquipo = 0;

	return espacioDisponibleEnEquipo;
}

int cargarJugadores(int posicion[], int numeroCamiseta[], int tamJugadores,
		int *contJugadoresAFC, int *contJugadoresCAF,
		int *contJugadoresCONCACAF, int *contJugadoresCONMEBOL,
		int *contJugadoresUEFA, int *contJugadoresOFC, int *equipoTitular,
		int tamEquipoTitular, int* seRealizoCalculo) {

	int retorno = -1;
	int auxConfederacion;
	int indiceDelNuevoJugador;
	int auxPosicion;
	int auxNumeroCamiseta;
	int esTitular;

	limpiarPantalla();
	printf("\n               Carga de jugadores\n");

	if (posicion == NULL || numeroCamiseta == NULL || tamJugadores < 0
			|| *contJugadoresAFC < 0 || *contJugadoresCAF < 0
			|| *contJugadoresCONCACAF < 0 || *contJugadoresCONMEBOL < 0
			|| *contJugadoresUEFA < 0 || *contJugadoresOFC < 0
			|| equipoTitular == NULL || tamEquipoTitular < 0)
		printf(
				"\n***Error, se produjo un error al intentar cargar un jugador, alguno de los datos es invalido, "
						"reviselos e intente nuevamente!***\n");

	else {

		do {

			printf("\nPosiciones seleccionables");
			mostrarPosicionesYCantidadDeJugadores(posicion, tamJugadores, 1);

			indiceDelNuevoJugador = buscarIntEnArray(posicion, tamJugadores,
					-1);

			if (indiceDelNuevoJugador == -1) {
				printf(
						"\n\n***Error, no existe una posición libre para registrar un nuevo jugador***\n");
				break;
			}

			else if (pedirPosicion(posicion, tamJugadores, &auxPosicion) != 0)

				printf(
						"\n\n***Se acabaron los reintentos u ocurrió un error inesperado al pedir posicion***\n");

			else if (getPedirInt(&auxNumeroCamiseta,
					"\n\nSeleccione el numero de camiseta correspondiente al jugador: ",
					"\n\n***Error, lo ingresado no es un numero de camiseta  válido, está debe ser un numero entre 1 y 100",
					1, 100, 4) != 0)

				printf(
						"\n***Se acabaron los reintentos u ocurrió un error inesperado al pedir el numero de la camiseta***\n");

			else if ((auxConfederacion = pedirConfedereacion(contJugadoresAFC,
					contJugadoresCAF, contJugadoresCONCACAF,
					contJugadoresCONMEBOL, contJugadoresUEFA, contJugadoresOFC))
					< 1)

				printf(
						"\n\n***Se acabaron los reintentos u ocurrió un error inesperado al pedir la confederación***\n");

			else {

				esTitular = pedirTitularidad(equipoTitular, posicion,
						tamEquipoTitular, tamJugadores, contJugadoresAFC,
						contJugadoresCAF, contJugadoresCONCACAF,
						contJugadoresCONMEBOL, contJugadoresUEFA,
						contJugadoresOFC);

				printf("\n               Mostrando al jugador %d", auxPosicion);
				printf("\n\n Posición -> %s ", mostrarPosicion(auxPosicion));
				printf("\n Numero de camiseta -> %d ", auxNumeroCamiseta);
				printf("\n Confederación -> %s ",
						mostrarConfederacion(auxConfederacion));

				printf("\n Estado de titularidad ->");
				if (esTitular == 1)
					printf(" Titular");
				else
					printf(" Suplente");

				if (elegirEntreOpciones(
						"\n\n¿Desea crear este jugador? (si/no): ", "si", "no")
						== 1) {

					posicion[indiceDelNuevoJugador] = auxPosicion;
					numeroCamiseta[indiceDelNuevoJugador] = auxNumeroCamiseta;
					textoConEspera("\nJugador creado con exito!!", 1);
					*seRealizoCalculo = 0;
					retorno = 0;
				} else
					textoConEspera("\nJugador no creado!", 2);

			}

		} while (elegirEntreOpciones(
				"\n\n¿Desea registrar otro jugador? (si/no)", "si", "no") == 1);
	}

	textoConEspera("\n\n\nSe lo devolverá al menú principal en 3 segundos...",
			3);

	return retorno;
}

int realizarCalculos(int *posicion, int *equipoTitular,
		float *promedioJugadoresEnConfederacion, float *costoMantenimiento,
		float *cantidadDeRecargo, int *seRealizoCalculo, int contJugadoresAFC,
		int contJugadoresCAF, int contJugadoresCONCACAF,
		int contJugadoresCONMEBOL, int contJugadoresUEFA, int contJugadoresOFC,
		float costoComida, float costoHospedaje, float costoTransporte,
		int tamJugadores, int tamEquipoTitular, int tamConfederacion) {

	int retorno = -1;

	int tamJugadoresCargados;
	limpiarPantalla();
	printf("\n               Realizar todos los cálculos.\n");

	if (posicion == NULL || equipoTitular == NULL
			|| promedioJugadoresEnConfederacion == NULL
			|| costoMantenimiento == NULL || cantidadDeRecargo == NULL
			|| seRealizoCalculo == NULL)
		retorno = 1;

	tamJugadoresCargados = tamJugadores
			- contarCantDeNumerosEnArrayInt(posicion, tamJugadores, -1);


	if (tamJugadoresCargados == 0)
		printf(
				"\n***Error, se debe cargar jugadores (opcion 2) antes de calcular***");

	if (costoComida == 0)
		printf(
				"\n***Error, no cargó los costos de la comida, ingreselos y vuelva a intentarlo***");
	if (costoHospedaje == 0)
		printf(
				"\n***Error, no cargó los costos del hospedaje, ingreselos y vuelva a intentarlo***");
	if (costoMantenimiento == 0)
		printf(
				"\n***Error, no cargó los costos de mantenimiento, ingreselos y vuelva a intentarlo***");
	if (costoTransporte == 0)
		printf(
				"\n***Error, no cargó los costos de transporte, ingreselos y vuelva a intentarlo***");

	if (tamJugadoresCargados > 0 && costoComida > 0 && costoHospedaje > 0
			&& costoTransporte > 0) {

		promedioJugadoresEnConfederacion[0] = (float) contJugadoresAFC
				/ tamJugadoresCargados;
		promedioJugadoresEnConfederacion[1] = (float) contJugadoresCAF
				/ tamJugadoresCargados;
		promedioJugadoresEnConfederacion[2] = (float) contJugadoresCONCACAF
				/ tamJugadoresCargados;
		promedioJugadoresEnConfederacion[3] = (float) contJugadoresCONMEBOL
				/ tamJugadoresCargados;
		promedioJugadoresEnConfederacion[4] = (float) contJugadoresUEFA
				/ tamJugadoresCargados;
		promedioJugadoresEnConfederacion[5] = (float) contJugadoresOFC
				/ tamJugadoresCargados;

		//b
		*costoMantenimiento = costoComida + costoHospedaje + costoTransporte;

		//Si es europa
		if (buscarIndiceMaximoArrayFloat(promedioJugadoresEnConfederacion,
				tamConfederacion) == 4) {

			*cantidadDeRecargo = *costoMantenimiento * 0.35;
		}

		*costoMantenimiento = costoComida + costoTransporte + costoHospedaje;

		*seRealizoCalculo = 1;
		retorno = 0;

	}

	textoConEspera("\n\n\nSe lo devolverá al menú principal en 3 segundos...",
			3);
	return retorno;
}

int informarResultados(int *posicion, float *promedioJugadoresEnConfederacion,
		float cantidadDeRecargo, float costoComida, float costoHospedaje,
		float costoMantenimiento, float costoTransporte, int seRealizoCalculo,
		int tamJugadores) {

	int retorno = -1;
	int tamJugadoresCargados = 0;

	tamJugadoresCargados = tamJugadores
			- contarCantDeNumerosEnArrayInt(posicion, tamJugadores, -1);

	limpiarPantalla();
	printf("\n               Informar todos los Resultados.");
	if (tamJugadoresCargados == tamJugadores && costoComida != 0
			&& costoHospedaje != 0 && costoMantenimiento != 0
			&& costoTransporte != 0 && seRealizoCalculo == 1 && posicion != NULL
			&& promedioJugadoresEnConfederacion != NULL
			&& cantidadDeRecargo > -1) {


		//0=AFC, 1=CAF, 2=CONCACAF, 3=CONMEBOL, 4=UEFA, 5=OFC
		printf("\n\n\nPorcentaje Uefa %.2f",
				promedioJugadoresEnConfederacion[4]);
		printf("\nPorcentaje Conmebol %.2f",
				promedioJugadoresEnConfederacion[3]);
		printf("\nPorcentaje Concacaf %.2f",
				promedioJugadoresEnConfederacion[2]);
		printf("\nPorcentaje Afc %.2f", promedioJugadoresEnConfederacion[0]);
		printf("\nPorcentaje Ofc %.2f", promedioJugadoresEnConfederacion[5]);
		printf("\nPorcentaje Caf %.2f", promedioJugadoresEnConfederacion[1]);
		printf(
				"\nel costo de mantenimiento era de %.2f y recibio un aumento de %.2f, su nuevo valor es de : %2.f",
				costoMantenimiento, cantidadDeRecargo,
				costoMantenimiento + cantidadDeRecargo);
		retorno = 0;

	}

	else {

		if (tamJugadoresCargados != tamJugadores)
			printf(
					"\n***Error, se debe cargar los %d jugadores y usted cargó %d***",
					tamJugadores, tamJugadoresCargados);
		if (costoComida == 0)
			printf(
					"\n***Error, no cargó los costos de la comida, ingreselos y vuelva a intentarlo***");
		if (costoHospedaje == 0)
			printf(
					"\n***Error, no cargó los costos del hospedaje, ingreselos y vuelva a intentarlo***");
		if (costoMantenimiento == 0)
			printf(
					"\n***Error, no cargó los costos de mantenimiento, ingreselos y vuelva a intentarlo***");
		if (costoTransporte == 0)
			printf(
					"\n***Error, no cargó los costos de transporte, ingreselos y vuelva a intentarlo***");

		if (seRealizoCalculo != 1)
			printf(
					"\n***Error, se debe realizar los calculos en la opción 3 antes de mostrarlos, realicelos y vuelva a intentarlo***");
		printf("\n");
		retorno = 1;
	}


	textoConEspera("\n\n\nSe lo devolverá al menú principal en 3 segundos...",
			3);
	return retorno;
}
