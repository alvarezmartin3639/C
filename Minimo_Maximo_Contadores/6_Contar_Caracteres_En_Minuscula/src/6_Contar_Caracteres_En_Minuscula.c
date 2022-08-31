/*
 ============================================================================
 Name        : 6_Contar_Caracteres_En_Minuscula.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 Ejercicio 2-6:
 Ingresar 5 caracteres e informar cuantas letras m (minúsculas) se ingresaron.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);
	char inputLetter;
	int countUpperCase;
	int countLowerCase;
	int countNotALetter;

	countUpperCase = 0;
	countLowerCase = 0;
	countNotALetter = 0;

	for (int i = 0; i < 8; i++) {

		printf("\nIngrese una letra: ");
		fflush(stdin);
		scanf("%c", &inputLetter);

		if (inputLetter >= 'a' && inputLetter <= 'z')
			countLowerCase++;

		else if (inputLetter >= 'a' && inputLetter <= 'z')
			countUpperCase++;

		else
			countNotALetter++;
	}

	printf("\nSe ingresaron un total de %d letras minusculas", countLowerCase);

	return EXIT_SUCCESS;
}
