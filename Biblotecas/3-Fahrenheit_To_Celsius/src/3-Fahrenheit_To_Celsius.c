/*
 ============================================================================
 Name        : 3-Fahrenheit_A_Celsius.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 Ejercicio 4-3: Realizar un programa que permita la carga de temperaturas en Celsius y
 Fahrenheit, validando las temperaturas ingresadas estén entre el punto de congelación y de
 ebullición del agua para cada tipo de escala. Las validaciones se hacen en una biblioteca. Las
 funciones de conversión de Fahrenheit a Celsius y de Celsius a Fahrenheit se hacen en otra.
 */
#include <stdio.h>
#include <stdlib.h>
#include "validateRange.h"
#include "convertTemperatures.h"

int main(void) {
	setbuf(stdout,NULL);
	int option;
	float temperatureInput;
	char confirmacionSalida = 'x';
	do {
		printf("\n1- Ingresar Celsius.");
		printf("\n2- Ingresar Fahrenheit.");
		printf("\n3- Salir.");
		printf("\n\nIngrese una opción: ");
		fflush(stdin);
		scanf("%d", &option);

		switch (option) {

		case 1:
			printf("\nIngrese la nueva temperatura en Celsius: ");
			fflush(stdin);
			scanf("%f", &temperatureInput);

			if (validateFloatRange(temperatureInput, 0, 10))
				printf("\n%.2f(Celsius) son %.2f(Fahrenheit) ", temperatureInput,
						celsiusToFahrenheit(temperatureInput));
			else
				printf("\n***Error,%.2f es un numero invalido, este debe estar entre 0 y 100***", temperatureInput);
			break;

		case 2:
			printf("\nIngrese la nueva temperatura en Fahrenheit: ");
			fflush(stdin);
			scanf("%f", &temperatureInput);
			if (validateFloatRange(temperatureInput, 32, 210))
				printf("\n%.2f(Fahrenheit) son %.2f(Celsius) ", temperatureInput,
						fahrenheitToCelsius(temperatureInput));
			else
				printf("\n***Error,%.2f es un numero invalido, este debe estar entre 32 y 210***",temperatureInput);
			break;
			break;

		case 3:
			while (confirmacionSalida != 'y' || confirmacionSalida != 'n') {
				printf("\n¿Seguro que desea salir?[y/n]");
				fflush(stdin);
				scanf("%c", &confirmacionSalida);
			}

			if (confirmacionSalida == 'n'){
				option = 0;
				confirmacionSalida = 'x';
			}
			break;

		default:
			printf("\n***Error,%.2f no es una opción valida!***", temperatureInput);
			break;
		}
	} while (option != 3);

	return 0;
}