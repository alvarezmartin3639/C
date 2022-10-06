/*
 * utnCadenas.h
 *
 *  Created on: 13 sept 2022
 *      Author: kenyn
 */

#ifndef UTNCADENAS_H_
#define UTNCADENAS_H_

int myGets(char* cadena, int longitud);

char* formatearString(char* str, char* a, char* b);

char* convertirFloatAString(double numeroParaConvertir);

void ConvertirTodoMayuscula(char cadena[], int tam);

void ConvertirTodoMinuscula(char cadena[], int tam);

void ConvertirPrimerLetraEnMayuscula(char cadena[], int tam);

void RepetirCadena(char mensajeParaRepetir[], int numeroDeVecesParaRepetir);

#endif /* UTNCADENAS_H_ */
