/*
 ============================================================================
 Name        : 3-7_Funcion_Validar_Inputs.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 Ejercicio 3-7: Realizar un programa que: asigne a las variables numero1 y numero2
 los valores solicitados al usuario, valide los mismos entre 10 y 100, asigne a la
 variable operacion el valor solicitado al usuario, valide el mismo 's'-sumar, 'r'-restar,
 realice la operación de dichos valores a través de una función. Mostrar el resultado
 por pantalla.
 */
#include <stdio.h>
#include <stdlib.h>

int validarRangoNumerico(int numero, int minimo, int maximo);
int operacionesMatematicas(char operacion,int numeroUno, int numeroDos);

int main(void) {

	setbuf(stdout,NULL);
	int numeroUno;
	int numeroDos;

	char operacion;
	int errorEnInputs;

	do {
		errorEnInputs = 1;
		printf("\nIngrese un numero: ");
		fflush(stdin);
		scanf("%d", &numero);

		if (isdigit(numero) == 0) {
			printf("\n***Error, no se ingresó un numero***");
				errorEnInputs = 0;
		}

		if (errorEnInputs == 0 || !validarRangoNumerico(numero, 11, 101)) {
			printf("\n***Error, el numero ingresado no es uno entre 10 y 100");
			errorEnInputs = 0;
		}
	} while (errorEnInputs == 0);

	do{
		printf("\n¿Que operación desea hacer? [suma=s/resta=r]: ");
		fflush(stdin);
		scanf("%c",&operacion);
		if(operacion !='s' && operacion != 'n')
			printf("\n***Error, %c no es una opción valida, estas son 's' para la suma o 'r' para la resta***", operacion);

	}while(operacion != 's' && operacion != 'n');


	printf("\n");
	return EXIT_SUCCESS;
}


int validarRangoNumerico(int numero, int minimo, int maximo) {

	if (numero >= minimo && numero <= maximo)
		return 1;

	else
		return 0;


}

int operacionesMatematicas(char operacion, int numeroUno, int numeroDos){

	if(operacion =='s'){
		return numeroUno + numeroDos;
	}else if(operacion == 'r'){
		return numeroUno - numeroDos;
	}else{
		return NULL;
	}
}


