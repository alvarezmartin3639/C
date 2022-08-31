/*
 ============================================================================
 Name        : 5_Libretas_Universitarias.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 Ejercicio 2-5:
 Debemos generar el pedido de libretas universitarias a la imprenta para los alumnos
 al regreso a la presencialidad. De cada persona debemos obtener los siguientes
 datos:
 número de legajo (4 cifras sin ceros a la derecha),
 estado civil ('s' para soltero", 'c' para casado o 'v' viudo),
 edad (más de 17),
 año de ingreso (validar por favor)
 y género ('f' para femenino, 'm' para masculino, 'o' para no binario).
 NOTA: El precio por libreta universitaria es de $450.
 Se debe informar (solo si corresponde):
 a) La cantidad de personas mayores de 60 años.
 b) El legajo y edad de la mujer que ingreso hace más tiempo.
 c) Cuanto debe abonar la facultad por las libretas sin el descuento
 d) Si se solicitan mas de 5 libretas hay un 5% de descuento, si se solicitan más de
 10 libretas se hace 10%. Además, por cada alumno mayor de 60 años al valor original
 de la libreta se le hace un 25%. Informar los valores si corresponde.
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main(void) {

	setbuf(stdout, NULL);
	int numeroDeLegajo;
	int edad;
	int anioIngreso;
	int contadorPersonasMayoresDeSesenta;
	int contadorCantidadLegajosCreados;
	int legajoDeLaMujerMasAntigua;
	int ingresoMasAntiguoDeUnaMujer;
	int edadDeLaMujerMasAntigua;
	int precioFinalConDescuento;
	int acumuladorPrecioFinal;
	const int precioDeLibretaPorUnidad = 450;
	char estadoCivil;
	char genero;
	char deseaContinuar;
	char legajoImpresoConExito;

	contadorPersonasMayoresDeSesenta = 0;
	contadorCantidadLegajosCreados = 0;
	legajoDeLaMujerMasAntigua = 0;
	edadDeLaMujerMasAntigua = 0;
	acumuladorPrecioFinal = 0;
	ingresoMasAntiguoDeUnaMujer = 0;
	deseaContinuar = 'y';
	legajoImpresoConExito = 'n';

	//Comienzo de la carga
	do {

		printf("-------------------------------------------------");
		printf("\nSistema Ingreso De Libretas Universitarias");
		printf("\n-------------------------------------------------\n");
		printf("Rellenar con información del alumno...\n");

		do {
			printf("\n\nIngrese su numero de legajo: ");
			fflush(stdin);
			scanf("%d", &numeroDeLegajo);
			if (numeroDeLegajo < 1)
				printf(
						"\n***Error, %d no es un numero de legajo valido, este debe ser "
								"un numero mayor a 0***", numeroDeLegajo);
		} while (numeroDeLegajo < 0);

		do {
			printf("\nIngrese su estado civil [s/c/v]:");
			fflush(stdin);
			scanf("%c", &estadoCivil);
			if (estadoCivil != 's' && estadoCivil != 'c' && estadoCivil != 'v')
				printf(
						"\n***Error, %c no es un estado civil valido, este debe ser "
								"un caracter 's', 'c' o 'v'***", estadoCivil);
		} while (estadoCivil != 's' && estadoCivil != 'c' && estadoCivil != 'v');

		do {
			printf("\nIngrese su edad: ");
			fflush(stdin);
			scanf("%d", &edad);
			if (edad < 18)
				printf(
						"\n***Error, %d no es una edad valida, esta debe ser mayor a 17***",
						edad);
		} while (edad < 18);

		do {
			printf("\nIngrese su año de ingreso: ");
			fflush(stdin);
			scanf("%d", &anioIngreso);
			if (anioIngreso < 2000 || anioIngreso > 2022)
				printf(
						"\n***Error, %d no es un anio de ingreso valido, este debe ser "
								"un numero entre el 2000 y el 2023",
						anioIngreso);
		} while (anioIngreso < 2000 || anioIngreso > 2022);

		do {
			printf("\nIngrese su genero[f/m/o]: ");
			fflush(stdin);
			scanf("%c", &genero);
			if (genero != 'f' && genero != 'm' && genero != 'o')
				printf("\n***Error, %c no es un genero valido***", genero);

		} while (genero != 'f' && genero != 'm' && genero != 'o');

		for (int i = 0; i < 40; i++)
			printf("\n");

		printf("\n\n\n=======================================================");
		printf("\nNumero de legajo: %d", numeroDeLegajo);
		printf("\nEstado civil: %c", estadoCivil);
		printf("\nEdad: %d", edad);
		printf("\nAño de ingreso: %d", anioIngreso);
		printf("\nGenero: %c", genero);
		printf("\n=======================================================");
		printf("\n\n¿Desea impirmir este legajo?[y/n]: ");
		fflush(stdin);
		scanf("%c", &legajoImpresoConExito);

		//Confirmación de impresión
		if (legajoImpresoConExito == 'y') {

			if (genero == 'f'
					&& (anioIngreso < ingresoMasAntiguoDeUnaMujer
							|| ingresoMasAntiguoDeUnaMujer == 0)) {
				edadDeLaMujerMasAntigua = edad;
				legajoDeLaMujerMasAntigua = numeroDeLegajo;
			}

			if (edad > 60) {
				acumuladorPrecioFinal += precioDeLibretaPorUnidad * 25 / 100;
				contadorPersonasMayoresDeSesenta++;
			} else
				acumuladorPrecioFinal += precioDeLibretaPorUnidad;

			contadorCantidadLegajosCreados++;
		}

		for (int i = 0; i < 40; i++)
			printf("\n");

		do {
			printf("\n\n¿Desea impirimr un nuevo legajo?[y/n]: ");
			fflush(stdin);
			scanf("%c", &deseaContinuar);

			if (deseaContinuar != 'y' && deseaContinuar != 'n')
				printf(
						"\n***Error, %c no es una respuesta valida, esta debe ser 'y'  o 'n'",
						deseaContinuar);
		} while (deseaContinuar != 'y' && deseaContinuar != 'n');

		for (int i = 0; i < 40; i++)
			printf("\n");

	} while (deseaContinuar != 'n');

	//Calcular precio final por bulto
	precioFinalConDescuento = acumuladorPrecioFinal;
	if (contadorCantidadLegajosCreados > 5)
		precioFinalConDescuento = precioDeLibretaPorUnidad
				* contadorCantidadLegajosCreados * 5 / 100;
	else if (contadorCantidadLegajosCreados > 10)
		precioFinalConDescuento = precioDeLibretaPorUnidad
				* contadorCantidadLegajosCreados * 10 / 100;

	//Mostrar resultados

	printf("\n\n...............................................");
	if (contadorPersonasMayoresDeSesenta > 0)
		printf("\na) La cantidad de personas mayores  de 60 son %d.",
				contadorPersonasMayoresDeSesenta);
	else
		printf("\na) No se ingresaron personas mayores de 60.");

	if (genero == 'f')
		printf(
				"\nb) El legajo de la mujer con mas antiguedad de ingreso es %d y su edad es de %d años.",
				legajoDeLaMujerMasAntigua, edadDeLaMujerMasAntigua);
	else
		printf("\nb) No se ingresó una mujer en el sistema.");

	printf("\nc) Se debe abonar un total de $%d (sin descuento)",
			precioDeLibretaPorUnidad * contadorCantidadLegajosCreados);

	printf("\nd) Se debe abonar un total de $%d (aplicando descuento)",
			precioFinalConDescuento);
	printf("\n...............................................");

	return EXIT_SUCCESS;
}
