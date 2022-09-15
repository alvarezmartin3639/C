/*
 * utnValidacion.h
 *
 *  Created on: 12 sept 2022
 *      Author: kenyn
 */

#ifndef UTNVALIDACION_H_
#define UTNVALIDACION_H_

int getInt(int *pResultado);

int getFloat(float *pResultado);

int getCharDeLetra(char *pResultado);

int getStringDeLetras(char *pResultado);

int getPedirInt(int *pNumero, char *mensaje, char *mensajeError, int minimo,
		int maximo, int reintentos);

int getPedirFloat(float *pNumero, char *mensaje, char *mensajeError,
		float minimo, float maximo, int reintentos);

int getPedirCharDeLetra(char *pChar, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos);

int getPedirStringDeLetras(char *pArrayChar, char *mensaje, char *mensajeError, int reintentos);

int esNumero(char *pArrayChar);

int esFlotante(char *pArrayChar);

int esLetra(char *pArrayChar);

int deseaContinuar(char mensaje[60], char condicionParaContinuar[60],
		char condicionParaSalir[60]);

#endif /* UTNVALIDACION_H_ */