/*
 ============================================================================
 Name        : Utn_Bibloteca.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utnArray.h"
#include "utnValidacion.h"
#include <string.h>

int main(void) {
	setbuf(stdout, NULL);

	int seSuperoLaPrueba = 1;

//	VALIDAR DATOS
//
//	printf("\nProbando float");
//	float pFlotante;
//	getPedirFloat(&pFlotante, "\nIngrese un numero flotante: ",
//			"No es un numero flotante valido", 0, 100, 2);
//	printf("%.2f", pFlotante);
//
//	printf("\nProbando desea continuar?");
//	if (getDeseaContinuar("\nDesea continuar?", "si", "no") == -1)
//		printf("\nNo quiso continuar");
//	else
//		printf("\nQuiso continuar");
//
//	printf("\nProbando caracter letra");
//	char pChar;
//	if (getCharDeLetra(&pChar) == 0) {
//		printf("\nEs letra");
//	} else
//		printf("\n NO es");
//	printf("%c", pChar);

//	printf("\nProbando pedir char de letras");
//	char pChar;
//	getPedirCharDeLetras(&pChar,"\nIngrese un char!","\nError",0,100,2);


		printf("\nProbando pedir string de letras");
		char pChar[55];
		getPedirStringDeLetras(pChar,"\nIngrese un string!","\nError",2);



//ARRAYS
//
//	printf("\nProbando Entero");
//	int enteros[5];
//	incializarArrayInt(enteros, 5, 0);
//	for(int i = 0; i<5 ; i++){
//		if(enteros[i] != 0)
//			seSuperoLaPrueba = 0;
//	}
//	if(seSuperoLaPrueba ==0)
//		printf("\nFracaso");
//	else
//		printf("\nExito!");

//	printf("\nProbando Flotante");
//	float flotantes[5];
//	incializarArrayFloat(flotantes, 5, 0);
//	for (int i = 0; i < 5; i++) {
//		if (flotantes[i] != 0)
//			seSuperoLaPrueba = 0;
//	}
//	if (seSuperoLaPrueba == 0)
//		printf("\nFracaso");
//	else
//		printf("\nExito!");

//	printf("\nProbando String");
//	char caracteres[5];
//	incializarArrayChar(caracteres, 5, 'c');
//	for (int i = 0; i < 5; i++) {
//		if (caracteres[i] != 'c')
//			seSuperoLaPrueba = 0;
//	}
//	if (seSuperoLaPrueba == 0)
//		printf("\nFracaso");
//	else
//		printf("\nExito!");

//	printf("\nProbando Array de string");
//	char string[5][30];
//	incializarArrayString(30, 5, string, "hola");
//	for (int i = 0; i < 5; i++) {
//		if (strcmp(string[i],"hola") !=0)
//			seSuperoLaPrueba = 0;
//	}
//	if (seSuperoLaPrueba == 0)
//		printf("\nFracaso");
//	else
//		printf("\nExito!");

//
	return EXIT_SUCCESS;
}
