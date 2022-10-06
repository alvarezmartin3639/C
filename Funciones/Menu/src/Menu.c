/*
 ============================================================================
 Name        : Menu.c
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

int main(void) {
setbuf(stdout,NULL);
	char opcion;
	char seDecideSalir = 'x' ;
	int seInicio = 0;

	do{


		printf("\n=======================================");
		printf("\na)Iniciar");
		printf("\nb)Procesar");
		printf("\nc)Finalizar");
		printf("\nd)Salir\n");
		fflush(stdin);
		printf("\n=======================================");
		printf("\n\nElija una opción: ");
		scanf("%c", &opcion);

		for(int i = 0; i<20;i++)
		printf("\n");

		switch(opcion){

		case 'a':
			printf("\nIniciado!");
			seInicio = 1;
			break;

		case 'b':
			if(seInicio == 1)
			printf("\nProcesado!");
			else
				printf("\n Se debe inciar antes de procesar!");
			break;

		case 'c':
			if(seInicio == 1){
				printf("\nFinalizado");
				seInicio = 0;
			}
			else
				printf("\n Se debe inciar antes de finalizar!");
			break;

		case 'd':
			if(seInicio == 1){
				while(seDecideSalir != 's' && seDecideSalir != 'n'){
					printf("\n\nEstá seguro que desea salir?(s/n): ");
								fflush(stdin);
								scanf("%c", &seDecideSalir);
				}
			}else
				printf("\nSe debe iniciar antes de salir!");
			break;

		 default:
			printf("\nNo es %c  una opción válida!.",opcion);
			break;

		}
	}while(seDecideSalir != 's');

	return EXIT_SUCCESS;
}
