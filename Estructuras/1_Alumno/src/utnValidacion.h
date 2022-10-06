/*
 * utnValidacion.h
 *
 *  Created on: 12 sept 2022
 *      Author: kenyn
 */

#ifndef UTNVALIDACION_H_
#define UTNVALIDACION_H_

/**
 * @fn int getInt(int*)
 * @brief pide por consola un int y lo valida
 *
 * @param pResultado puntero a la variable donde se va a guardar el numero
 * @return -1 = error inesperado, 0 = sin errores
 */
int getInt(int *pResultado);

/**
 * @fn int getFloat(float*)
 * @brief  pide por consola un float y lo valida
 *
 * @param pResultado puntero a la variable donde se va a guardar el numero
 * @return -1 = error inesperado, 0 = sin errores
 */
int getFloat(float *pResultado);

/**
 * @fn int getCharDeLetra(char*)
 * @brief  pide por consola un char solo de letras y lo valida
 *
 * @param pResultado puntero a la variable donde se va a guardar la cadena
 * @return -1 = error inesperado, 0 = sin errores
 */
int getCharDeLetra(char *pResultado);

/**
 * @fn int getStringDeLetras(char*)
 * @brief pide mediante un mensaje  por consola un string de letras y lo valida
 *
 * @param pResultado puntero a la variable donde se va a guardar la cadena
 * @return -1 = error inesperado, 0 = sin errores
 */
int getStringDeLetras(char *pResultado);

/**
 * @fn int getPedirInt(int*, char*, char*, int, int, int)
 * @brief  pide mediante un mensaje  por consola un int y lo valida
 *
 * @param pNumero puntero a la variable donde se va a guardar el numero
 * @param mensaje mensaje que se muestra al usuario al pedir el dato
 * @param mensajeError mensaje que se muestra al usuario al generarse un error con el minimo y maximo
 * @param minimo el numero minimo que el usuario puede elegir
 * @param maximo el numero maximo que el usuario puede elegir
 * @param reintentos
 * @return -1 = error inesperado, 0 = sin errores
 */
int getPedirInt(int *pNumero, char *mensaje, char *mensajeError, int minimo,
		int maximo, int reintentos);

/**
 * @fn int getAlfanumerico(char*)
 * @brief  pide por consola un int y lo valida
 *
 * @param pResultado puntero a la variable donde se va a guardar la cadena
 * @return -1 = error inesperado, 0 = sin errores
 */
int getAlfanumerico(char *pResultado);

/**
 * @fn int getPedirFloat(float*, char*, char*, float, float, int)
 * @brief  pide mediante un mensaje  por consola un float y lo valida
 *
 * @param pNumero puntero a la variable donde se va a guardar el numero
 * @param mensaje mensaje mensaje que se muestra al usuario al pedir el dato
 * @param mensajeError mensaje que se muestra al usuario al generarse un error con el minimo y maximo
 * @param minimo minimo el numero minimo que el usuario puede elegir
 * @param maximo maximo el numero maximo que el usuario puede elegir
 * @param reintentos cantidad de veces que se le permite al usuario ingresar mal el dato
 * @return  -1 = error inesperado, 0 = sin errores
 */
int getPedirFloat(float *pNumero, char *mensaje, char *mensajeError,
		float minimo, float maximo, int reintentos);

/**
 * @fn int getPedirCharDeLetra(char*, char*, char*, int, int, int)
 * @brief pide mediante un mensaje  por consola un int y lo valida
 *
 * @param pChar puntero a la variable donde se va a guardar la cadena
 * @param mensaje mensaje mensaje que se muestra al usuario al pedir el dato
 * @param mensajeError mensaje que se muestra al usuario al generarse un error con el minimo y maximo
 * @param minimo minimo el numero minimo que el usuario puede elegir
 * @param maximo maximo el numero maximo que el usuario puede elegir
 * @param reintentos  cantidad de veces que se le permite al usuario ingresar mal el dato
 * @return -1 = error inesperado, 0 = sin errores
 */
int getPedirCharDeLetra(char *pChar, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos);
/**
 * @fn int getPedirStringDeLetras(char*, char*, char*, int)
 * @brief pide mediante un mensaje  por consola un string solo de letras y lo valida
 *
 * @param pArrayChar puntero al array donde se va a guardar la cadena solo de letras
 * @param mensaje mensaje mensaje que se muestra al usuario al pedir el dato
 * @param mensajeError mensaje que se muestra al usuario al generarse un error al no validarse que sea solo letra
 * @param reintentos  cantidad de veces que se le permite al usuario ingresar mal el dato
 * @return  -1 = error inesperado, 0 = sin errores
 */
int getPedirStringDeLetras(char *pArrayChar, char *mensaje, char *mensajeError, int reintentos);

/**
 * @fn int getPedirAlfanumerico(char*, char*, char*, int)
 * @brief pide mediante un mensaje  por consola un string alfanumerico y lo valida
 *
 * @param pArrayChar puntero al array  donde se va a guardar la cadena alfanumerica
 * @param mensaje mensaje mensaje que se muestra al usuario al pedir el dato
 * @param mensajeError mensaje que se muestra al usuario al generarse un error al no validarse que sea alfanumerico
 * @param reintentos  cantidad de veces que se le permite al usuario ingresar mal el dato
 * @return  -1 = error inesperado, 0 = sin errores
 */
int getPedirAlfanumerico(char *pArrayChar, char *mensaje, char *mensajeError,
		int reintentos);

/**
 * @fn int esNumero(char*)
 * @brief valida si una cadena de caracteres es un numero (int)
 *
 * @param pArrayChar puntero al array que va a validar que sea numero
 * @return  -1 = error inesperado, 0 = sin errores
 */
int esNumero(char *pArrayChar);

/**
 * @fn int esFlotante(char*)
 * @brief valida si una cadena de caracteres es un numero (float)
 *
 * @param pArrayChar puntero al array que va a validar que sea numero
 * @return  -1 = error inesperado, 0 = sin errores
 */
int esFlotante(char *pArrayChar);

/**
 * @fn int esFlotanteSinDecimal(char*)
 * @brief valida si una cadena de caracteres es un numero (float sin decimales)
 *
 * @param cadena  puntero al array que va a validar que sea numero sin decimal
 * @return  -1 = error inesperado, 0 = sin errores
 */
int esFlotanteSinDecimal(char *cadena);

/**
 * @fn int esLetra(char*)
 * @brief valida si una cadena de caracteres contiene solo letras
 *
 * @param pArrayChar  puntero al array que va a validar que sea letra
 * @return  -1 = error inesperado, 0 = sin errores
 */
int esLetra(char *pArrayChar);

/**
 * @fn int esAlfanumerico(char*)
 * @brief valida si una cadena de caracteres contiene solo letras y numeros
 *
 * @param cadena  puntero al array que va a validar que sea alfanumerico
 * @return  -1 = error inesperado, 0 = sin errores
 */
int esAlfanumerico(char *cadena);

/**
 * @fn int elegirEntreOpciones(char[], char[], char[])
 * @brief Pide al usuario elegir entre dos opciones, devolviendo el numero de opción que eligió
 *
 * @param mensaje mensaje mensaje que se muestra al usuario al pedir el dato
 * @param opcionUno condición necesaria para salir de la función
 * @param opcionDos condición necesaria para salir de la función
 * @return  -1 = error inesperado, 1 = eligió la opción 1, 0 = eligió la opcion 2
 */
int elegirEntreOpciones(char mensaje[60], char opcionUno[60],
		char opcionDos[60]);

#endif /* UTNVALIDACION_H_ */
