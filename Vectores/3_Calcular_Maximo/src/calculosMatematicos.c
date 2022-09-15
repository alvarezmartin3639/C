/*
 * calculosMatematicos.c
 *
 *  Created on: 8 sept 2022
 *      Author: kenyn
 */

int calcularMaximo(int numeros[], int tamNumeros, int* maximo){
	*maximo = 0;

	for(int i = 0; i<tamNumeros; i++){
		if(numeros[i] > *maximo)
	     *maximo= numeros[i];
	}

	return *maximo;
}


