/*
 * utnMostrar.h
 *
 *  Created on: 12 sept 2022
 *      Author: kenyn
 */

#ifndef UTNGUI_H_
#define UTNGUI_H_

/**
 * @fn int mostrarArrayInt(int[], int)
 * @brief muestra el array pasado por parametro uno a uno con un salto de linea
 *
 * @param enteros el array que se va a mostrar
 * @param tamEnteros el tamaño del array
 * @return -1 = error, 0 = sin error
 */
int mostrarArrayInt(int enteros[], int tamEnteros);

/**
 * @fn int mostrarArrayFloat(float[], int)
 * @brief  muestra el array pasado por parametro uno a uno con un salto de linea
 *
 * @param flotantes el array que se va a mostrar
 * @param tamFloat el tamaño del array
 * @return -1 = error, 0 = sin error
 */
int mostrarArrayFloat(float flotantes[], int tamFloat);

/**
 * @fn int mostrarArrayChar(char[], int)
 * @brief muestra el array pasado por parametro uno a uno con un salto de linea
 *
 * @param caracteres el array que se va a mostrar
 * @param tamCaracteres el tamaño del array
 * @return -1 = error, 0 = sin error
 */
int mostrarArrayChar(char caracteres[], int tamCaracteres);

/**
 * @fn int mostrarArrayString(char[][], int)
 * @brief muestra el array pasado por parametro uno a uno con un salto de linea
 *
 * @param texto el array que se va a mostrar
 * @param tamTexo el tamaño del array
 * @return -1 = error, 0 = sin error
 */
int mostrarArrayString(char texto[][50], int tamTexo);

/**
 * @fn void textoConEspera(char[], int)
 * @brief imprime un texto por consola y espera el tiempo pasado por parametro
 *
 * @param mensaje el array que se va a mostrar
 * @param seconds los segundos de espera
 */
void textoConEspera(char mensaje[60], int seconds) ;

/**
 * @fn void limpiarPantalla(void)
 * @brief hace saltos de linea para dejar de mostrar lo impreso en consola
 *
 */
void limpiarPantalla(void);

#endif /* UTNGUI_H_ */
