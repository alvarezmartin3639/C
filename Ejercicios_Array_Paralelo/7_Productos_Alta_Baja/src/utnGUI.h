/*
 * utnMostrar.h
 *
 *  Created on: 12 sept 2022
 *      Author: kenyn
 */

#ifndef UTNGUI_H_
#define UTNGUI_H_

int mostrarArrayInt(int enteros[], int tamEnteros);

int mostrarArrayFloat(float flotantes[], int tamFloat);

int mostrarArrayChar(char caracteres[], int tamCaracteres);

int mostrarArrayString(char texto[][50], int tamTexo);

void textoConEspera(char mensaje[60], int milisegundos) ;

void limpiarPantalla(void);

#endif /* UTNGUI_H_ */
