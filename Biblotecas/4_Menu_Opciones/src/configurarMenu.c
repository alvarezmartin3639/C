/*
 * configurarMenu.c
 *
 *  Created on: 4 sept 2022
 *      Author: kenyn
 */
#include "configurarMenu.h"

int mostrarMenuPrincipal() {

	int opcion;
	printf("\n=====================");
	printf("\nMenu Principal");
	printf("\n=====================");
	printf("\n1. Loguearse");
	printf("\n2. Comprar");
	printf("\n3. Ver mis compras");
	printf("\n4. Vender");
	printf("\n5. Salir");
	printf("\n\nIngrese una opción: ");
	fflush(stdin);
	sleep(1);
	scanf("%d", &opcion);
	return opcion;

}

int mostrarSubmenuVender() {

	int opcion;
	printf("\n1. Vender");
	printf("\n2. Hacer factura");
	printf("\n3. Volver atrás");
	printf("\n\n Ingrese una opción: ");
	fflush(stdin);
	scanf("%d", &opcion);
	return opcion;

}

int confirmarCierreSubmenuVender() {

	char confirmacionDeSalida = 'x';
	int opcion = 1;

	while (confirmacionDeSalida != 'y' && confirmacionDeSalida != 'n') {
		printf("\n¿Seguro que desea salir?[y/n]");
		fflush(stdin);
		scanf("%c", &confirmacionDeSalida);

		if (confirmacionDeSalida == 'n') {
			opcion = 0;
			confirmacionDeSalida = 'x';
		}
	}

	return opcion;
}

int venderProducto(int usuarioVendioAnteriormente,
		int usuarioComproAnteriormente) {

	if (usuarioVendioAnteriormente == 0 && usuarioComproAnteriormente == 1) {
		usuarioVendioAnteriormente = 1;
		printf("\nProductos vendidos con exito!\n");
	} else
		printf("\nNo existen productos disponbiles"
				" para vender\n");
	sleep(3);

	return usuarioVendioAnteriormente;
}

int loguearUsuario() {

	printf("\nUsuario logeado con exito!");
	sleep(2);
	return 1;
}

int comprarProducto() {

	printf("\nFelicidades por su compra!");
	return 1;

}

int verCompras(int usuarioComproAnteriormente) {

	if (usuarioComproAnteriormente == 1)
		printf("\nCompras....");
	else
		printf("\nNo se encontraron compras,"
				"compre algo antes de mostrarlo...\n");
	sleep(3);
	return usuarioComproAnteriormente;

}
