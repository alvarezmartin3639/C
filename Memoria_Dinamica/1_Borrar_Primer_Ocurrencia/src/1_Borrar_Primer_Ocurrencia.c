/*
 ============================================================================
 Name        : 1_Borrar_Primer_Ocurrencia.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//---------------------------------------------------------------------------------------------

int borrarOcurrencia(int *pArray, int* tamArray, int numeroParaBorrar);

//---------------------------------------------------------------------------------------------

int main(void) {
	int *pNumeros;
	int tamNumeros = 10;
	/*
	 * Reservo memoria dinamicamente y asigno en su valor el numero de su indice
	 */
	if ((pNumeros = (int*) malloc(sizeof(int) * tamNumeros)) != NULL)
		for (int i = 0; i < 10; i++)
			*(pNumeros + i) = i;

	borrarOcurrencia(pNumeros, &tamNumeros, 5);

	printf("\nNo deberia aparecer el numero 5!\n");
	for(int i = 0 ; i < tamNumeros; i ++)
		printf("\n%d", *(pNumeros + i));

	free(pNumeros);
	return EXIT_SUCCESS;
}

//---------------------------------------------------------------------------------------------

int borrarOcurrencia(int *pArray, int* tamArray, int numeroParaBorrar) {
	int retorno = -1;
	int contNoCoindicencias = 0;
	int aux[*tamArray];
	int *auxRealloc;

	/*
	 * Recorro pArray, si pArray[i] no es el numero buscado lo guardo en auxArray[contIndiceAux]
	 * para luego remplazarlo
	 */
	if (pArray != NULL && tamArray != NULL ) {
		retorno = 0;
		for (int i = 0; i < *tamArray; i++) {
			if (*(pArray + i) != numeroParaBorrar) {
				*(aux + contNoCoindicencias) = *(pArray + i);
				contNoCoindicencias++;
			}
		}
		//Remplazo pArray por el array auxiliar con los numeros borrados
		for (int i = 0; i < contNoCoindicencias; i++) {
			*(pArray + i) = *(aux + i);
		}
		//Reasigno la memoria de pArray  y tamArray dependiendo cuantos numeros se borraron
		if ((auxRealloc = realloc(pArray, sizeof(int) * contNoCoindicencias))
				!= NULL){
			pArray = auxRealloc;
			*tamArray = contNoCoindicencias;
		}

	}
	return retorno;
}

//---------------------------------------------------------------------------------------------
