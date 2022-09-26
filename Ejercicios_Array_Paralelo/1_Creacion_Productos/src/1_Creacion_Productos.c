/*
 ============================================================================
 Name        : 1_Creacion_Productos.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utnArray.h"
#include "utnGUI.h"
#include "utnValidacion.h"
#include "utnCadenas.h"
#define TAMPRODUCTOS 20

int main(void) {
	setbuf(stdout, NULL);
	char codigo[TAMPRODUCTOS][20];
	char modelo[TAMPRODUCTOS][10];
	int cantidad[TAMPRODUCTOS];
	float precio[TAMPRODUCTOS];
	int contProductosCargados = 0;
	char opcionElegida;

	//INICIALIZO ARRAYS
	incializarArrayInt(cantidad, TAMPRODUCTOS, 0);
	incializarArrayString(10, TAMPRODUCTOS, modelo, "0");
	incializarArrayFloat(precio, TAMPRODUCTOS, 0);

	strcpy(codigo[0], "b2b2");
	strcpy(modelo[0], "ropa");
	cantidad[0] = 2;
	precio[0] = 200.3;

	strcpy(codigo[1], "a3a3");
	strcpy(modelo[1], "aspiradora");
	cantidad[1] = 1;
	precio[1] = 300.3;

	strcpy(codigo[2], "d4a3");
	strcpy(modelo[2], "pala");
	cantidad[2] = 3;
	precio[2] = 400.3;

	contProductosCargados = 3;

	do {

		//Se ingresa y valida cada variable
		if (getPedirCharDeLetra(&opcionElegida, "\n\nA) Carga de productos "
				"\nB) Venta de productos "
				"\nC) Modificación del precio "
				" \nD) Modificar el modelo  "
				"\nE) Listar ordenado por código "
				" \nF) Listar datos de los productos con menos de 3 unidades "
				" \nG) Salir  "
				"\n\nIngrese una opción: ",
				"\n***Error, la opción es una letra entre 'a' y 'f'***\n", 'a',
				'z', 1) == 0) {

			switch (opcionElegida) {

			case 'a':

				do {

					char auxCodigo[20];
					char auxModelo[20];
					int auxCantidad;
					float auxPrecio;

					if (getPedirAlfanumerico(auxCodigo,
							"\nIngrese un codigo alfanumerico: ",
							"\n***Error, no ingresó un codigo alfanumerico valido***\n",
							2) == 0) {

						if (getPedirAlfanumerico(auxModelo,
								"\nIngrese un modelo: ",
								"\n***Error, o se ingresó un modelo valido!***\n",
								2) == 0) {

							if (getPedirInt(&auxCantidad,
									"\nIngrese una cantidad:",
									"\n***Error, no se ingresó una cantidad valida!***\n",
									0, 20, 2) == 0) {

								if (getPedirFloat(&auxPrecio,
										"\nIngrese una precio:",
										"\n***Error, no se ingresó un precio valido!***\n",
										0, 1000000, 2) == 0) {

									strcpy(codigo[contProductosCargados],
											auxCodigo);
									strcpy(modelo[contProductosCargados],
											auxModelo);
									cantidad[contProductosCargados] =
											auxCantidad;
									precio[contProductosCargados] = auxPrecio;
									contProductosCargados++;

								}
							}
						}
					}

				} while (deseaContinuar(
						"\n¿Desea seguir ingresado numeros?(si/no): ", "si",
						"no") == 1);

				break;

				//Venta producto
			case 'b':

				if (contProductosCargados == 0)
					printf("\n***Error, no se cargó ningun producto!***\n");
				else {

					int indiceMenu = 1;
					int indiceProductoSeleccionado;
					//Se guarda solamente el indice de los productos que tienen stock
					int indiceProductosDisponibles[TAMPRODUCTOS];
					int cantidadDelProductoComprado;
					char montoTotal[20];

					printf("\nIngrese un producto para vender: ");

					//Muestro los productos disponibles
					for (int i = 0; i < TAMPRODUCTOS; i++) {

						if (cantidad[i] != 0) {
							printf("\n%d) %s ", indiceMenu, modelo[i]);
							//Guardo los indices de los productos listados
							indiceProductosDisponibles[indiceMenu - 1] = i;
							indiceMenu++;
						}

					}

					if (getPedirInt(&indiceProductoSeleccionado,
							"\nIngrese el producto que desea vender: ",
							"\n***Error, ingresó una opción  invalida, esta debe ser un numero *** \n",
							1, indiceMenu, 3) == 0) {
						//Convierto la opción en indice
						indiceProductoSeleccionado--;

						//Accedo al array paralelo seleccionados en el menu, mediante la copia de su indice en indiceProductosDisponibles
						if (getPedirInt(&cantidadDelProductoComprado,
								formatearString(
										"\nIngrese la cantidad del producto (%s) que desea vender: ",
										"%s",
										modelo[indiceProductosDisponibles[indiceProductoSeleccionado]]),
								"\n***Error, ingresó una opción  invalida, esta debe ser un numero *** \n",
								1,
								cantidad[indiceProductosDisponibles[indiceProductoSeleccionado]],
								3) == 0) {

							//Convierte float a string
							gcvt(
									precio[indiceProductosDisponibles[indiceProductoSeleccionado]]
											* cantidadDelProductoComprado, 10,
									montoTotal);

							if (deseaContinuar(
									formatearString(
											"\nEl monto total es de %s , escriba 'confirmo' para confirmarla o 'cancelo' para cancelarla",
											"%s", montoTotal), "confirmo",
									"cancelo") == 1) {

								cantidad[indiceProductosDisponibles[indiceProductoSeleccionado]] -=
										cantidadDelProductoComprado;
								textoConEspera(
										"\nPago realizado con exito!, se lo devolverá al menú principal",
										2000);
							}
						}
					}
				}

				break;

			case 'c':

				if (contProductosCargados == 0)
					printf("\n***Error, no se cargó ningun producto!***\n");
				else {

					int indiceMenu = 1;
					int indiceProductosDisponibles[TAMPRODUCTOS];
					int indiceProductoSeleccionado;
					float auxPrecio;

					printf("\nSeleccione el producto");
					//Muestro los productos disponibles
					for (int i = 0; i < TAMPRODUCTOS; i++) {

						if (cantidad[i] != 0) {
							printf("\n%d) %s ", indiceMenu, modelo[i]);
							//Guardo los indices de los productos listados
							indiceProductosDisponibles[indiceMenu - 1] = i;
							indiceMenu++;
						}

					}

					if (getPedirInt(&indiceProductoSeleccionado,
							"\nIngrese el producto que desea modificar el precio: ",
							"\n***Error, ingresó una opción  invalida, esta debe ser un numero *** \n",
							1, indiceMenu, 3) == 0) {

						indiceProductoSeleccionado--;
						printf("\nEl precio actual del producto '%f'",
								precio[indiceProductosDisponibles[indiceProductoSeleccionado]]);

						if (getPedirFloat(&auxPrecio,
								"Ingrese el nuevo precio: ",
								"\nNo es un precio valido, este debe ser entre 1 y 100000",
								1, 100000, 2) == 0) {

							if (deseaContinuar(
									"\n¿Está seguro que desea cambiar el precio? (si/no)",
									"si", "no") == 1) {

								precio[indiceProductosDisponibles[indiceProductoSeleccionado]] =
										auxPrecio;

							}
						}
					}
				}

				break;

			case 'd':

				if (contProductosCargados == 0)
					printf("\n***Error, no se cargó ningun producto!***\n");
				else {

					int indiceMenu = 1;
					int indiceProductosDisponibles[TAMPRODUCTOS];
					int indiceProductoSeleccionado;
					char auxModelo[10];

					printf("\nSeleccione el producto");
					//Muestro los productos disponibles
					for (int i = 0; i < TAMPRODUCTOS; i++) {

						if (cantidad[i] != 0) {
							printf("\n%d) %s ", indiceMenu, modelo[i]);
							//Guardo los indices de los productos listados
							indiceProductosDisponibles[indiceMenu - 1] = i;
							indiceMenu++;
						}

					}

					if (getPedirInt(&indiceProductoSeleccionado,
							"\nIngrese el producto que desea modificar el modelo: ",
							"\n***Error, ingresó una opción  invalida, esta debe ser un numero *** \n",
							1, indiceMenu, 3) == 0) {

						indiceProductoSeleccionado--;

						if (getPedirAlfanumerico(auxModelo,
								"\nIngrese el nuevo modelo: ",
								"\n***Error, lo ingresado no corresponde a un modelo valido",
								3) == 0) {

							if (deseaContinuar(
									"\n¿Está seguro que desea cambiar el modelo? (si/no)",
									"si", "no") == 1) {

								strcpy(
										modelo[indiceProductosDisponibles[indiceProductoSeleccionado]],
										auxModelo);

							}
						}
					}
				}

				break;

			case 'e':

				ordenarAlfanumerico(codigo, TAMPRODUCTOS, 1);
				mostrarArrayString(codigo, TAMPRODUCTOS);

				break;

			case 'f':

				if (contProductosCargados > 0) {

					int indiceProductos = 1;

					printf(
							"\n===================================================");
					printf(
							"\nMostrando productos con menos de tres unididades");
					printf(
							"\n===================================================");

					for (int i = 0; i < TAMPRODUCTOS; i++) {

						if (strcmp(modelo[i], "0") != 0 && cantidad[i] < 3) {

							printf("\n\n*************************************");
							printf("\n Producto numero %d", indiceProductos);
							printf("\n*************************************");

							printf("\n Modelo : %s", modelo[i]);
							printf("\n Codigo : %s", codigo[i]);
							printf("\n Cantidad : %d", cantidad[i]);
							printf("\n Codigo : %.2f\n\n", precio[i]);

							indiceProductos++;

						}
					}
				}

				break;
			}

		}

	} while (opcionElegida != 'g');

	return EXIT_SUCCESS;
}
