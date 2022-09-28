/*
 * utnValidacion.h
 *
 *  Created on: 12 sept 2022
 *      Author: kenyn
 */

#ifndef UTNVALIDACION_H_
#define UTNVALIDACION_H_

/**
 * \fn int getInt(int*)
 * \brief
 *
 * \param pResultado
 * \return
 */
int getInt(int *pResultado);

/**
 * \fn int getFloat(float*)
 * \brief
 *
 * \param pResultado
 * \return
 */
int getFloat(float *pResultado);

/**
 * \fn int getCharDeLetra(char*)
 * \brief
 *
 * \param pResultado
 * \return
 */
int getCharDeLetra(char *pResultado);

/**
 * \fn int getStringDeLetras(char*)
 * \brief
 *
 * \param pResultado
 * \return
 */

int getStringDeLetras(char *pResultado);

/**
 * \fn int getPedirInt(int*, char*, char*, int, int, int)
 * \brief
 *
 * \param pNumero
 * \param mensaje
 * \param mensajeError
 * \param minimo
 * \param maximo
 * \param reintentos
 * \return
 */

int getPedirInt(int *pNumero, char *mensaje, char *mensajeError, int minimo,
		int maximo, int reintentos);

/**
 * \fn int getStringDeLetras(char*)
 * \brief
 *
 * \param pResultado
 * \return
 */
int getAlfanumerico(char *pResultado);

/**
 * \fn int getPedirFloat(float*, char*, char*, float, float, int)
 * \brief
 *
 * \param pNumero
 * \param mensaje
 * \param mensajeError
 * \param minimo
 * \param maximo
 * \param reintentos
 * \return
 */
int getPedirFloat(float *pNumero, char *mensaje, char *mensajeError,
		float minimo, float maximo, int reintentos);

/**
 * \fn int getPedirCharDeLetra(char*, char*, char*, int, int, int)
 * \brief
 *
 * \param pChar
 * \param mensaje
 * \param mensajeError
 * \param minimo
 * \param maximo
 * \param reintentos
 * \return
 */
int getPedirCharDeLetra(char *pChar, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos);
/**
 * \fn int getPedirStringDeLetras(char*, char*, char*, int)
 * \brief
 *
 * \param pArrayChar
 * \param mensaje
 * \param mensajeError
 * \param reintentos
 * \return
 */
int getPedirStringDeLetras(char *pArrayChar, char *mensaje, char *mensajeError, int reintentos);


int getPedirAlfanumerico(char *pArrayChar, char *mensaje, char *mensajeError,
		int reintentos);

/**
 * \fn int esNumero(char*)
 * \brief
 *
 * \param pArrayChar
 * \return
 */
int esNumero(char *pArrayChar);

/**
 * \fn int esFlotante(char*)
 * \brief
 *
 * \param pArrayChar
 * \return
 */
int esFlotante(char *pArrayChar);

/**
 * \fn int esLetra(char*)
 * \brief
 *
 * \param pArrayChar
 * \return
 */
int esLetra(char *pArrayChar);

/**
 * \fn int esAlfanumerico(char*)
 * \brief
 *
 * \param cadena
 * \return
 */
int esAlfanumerico(char *cadena);

/**
 * \fn int deseaContinuar(char[], char[], char[])
 * \brief
 *
 * \param mensaje
 * \param condicionParaContinuar
 * \param condicionParaSalir
 * \return
 */
int deseaContinuar(char mensaje[60], char condicionParaContinuar[60],
		char condicionParaSalir[60]);

#endif /* UTNVALIDACION_H_ */
