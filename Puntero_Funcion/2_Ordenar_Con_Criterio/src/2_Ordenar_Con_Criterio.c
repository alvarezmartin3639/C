/*
 ============================================================================
 Name        : 2_Ordenar_Con_Criterio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utnValidacion.h"

typedef struct {
	int precio;
	char marca[20];
	int id;
} eProducto;

int CompararPorMarca(eProducto*, eProducto*);

int Ordenador(eProducto*, int, int (*pFunc)(eProducto*, eProducto*));

int OrdenadorProducto(eProducto*, int, int (*pFunc)(void*, void*));

int CompararPorPrecio(eProducto*, eProducto*);

int ordenarGeneric(void *a, void *b);

int main(void) {

	setbuf(stdout, NULL);

	eProducto productos[4] = { { 150, "Playadito", 1 }, { 100, "Pampero", 2 }, {
			120, "Amanda", 3 }, { 180, "Rosamonte", 4 } };

	printf("\n\n MOSTRAR PRODUCTOS ORDENADOS POR PRECIO");
	Ordenador(productos, 4, &CompararPorPrecio);
	for (int i = 0; i < 4; i++)
		printf("\n%d", productos[i].precio);

	return EXIT_SUCCESS;
}

//Si es 0 son iguales, si es negativo 'a' < 'b', si es positivo 'a' > 'b'
int CompararPorMarca(eProducto *a, eProducto *b) {

	int retorno = -1;

	if (a != NULL && b != NULL)
		return strcmp(a->marca, b->marca);

	return retorno;
}

//Si es 0 son iguales, si es negativo 'a' < 'b', si es positivo 'a' > 'b'
//Tambien podria poner el swap en esta función (tendria que pasarle un indice de i o j), esto evitaria el uso de minimo 1 if en Ordenar, aunque no se si estaria bien encapsulado
int CompararPorPrecio(eProducto *a, eProducto *b) {

	int retorno = 0;

	if (a != NULL && b != NULL)
		retorno = a->precio - b->precio;

	return retorno;
}

int Ordenador(eProducto *productos, int tamProductos,
		int (*pFunc)(eProducto*, eProducto*)) {

	int retorno = -1;
	eProducto auxProducto;

	if (productos != NULL && tamProductos > 0 && pFunc != NULL)
		for (int i = 0; i < tamProductos - 1; i++) {
			for (int j = i + 1; j < tamProductos; j++) {
				if (pFunc(&productos[i], &productos[j]) > 0) {
					auxProducto = productos[i];
					productos[i] = productos[j];
					productos[j] = auxProducto;
					retorno = 0;
				}
			}
		}

	return retorno;
}

int OrdenadorProducto(eProducto *productos, int tamProductos,
		int (*pFunc)(void*, void*)) {

	int retorno = -1;
//	void *auxProducto;
//
//	if (productos != NULL && tamProductos > 0 && pFunc != NULL)
//		for (int i = 0; i < tamProductos - 1; i++) {
//			for (int j = i + 1; j < tamProductos; j++) {
//				if (pFunc(&productos[i], &productos[j]).id > 0) {
//					auxProducto = productos[i];
//					productos[i] = productos[j];
//					productos[j] = auxProducto;
//					retorno = 0;
//				}
//			}
//		}
	return retorno;
}

int ordenarGeneric(void *a, void *b) {

	int retorno = 0;

	if (a != NULL && b != NULL) {

		if (esLetra(a) && esLetra(b)) {
			retorno = strncmp((char*) a, (char*) b, strlen((char*) a));

		}

		else if (esNumero(a), esNumero(b)) {
			retorno = (int*) a - (int*) b;
		}

		else {
			return 0;
		}

	}

	return retorno;
}
