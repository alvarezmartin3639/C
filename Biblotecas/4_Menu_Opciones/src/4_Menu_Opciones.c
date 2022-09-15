/*
 ============================================================================
 Name        : 4_Menu_Opciones.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 Ejercicios 4-4:
 A. Hacer el menú de un programa en el MAIN con las siguientes opciones:
 1. Loguearse
 2. Comprar
 3. Ver mis compras
 4. Vender
 5. Salir
 */

#include "configurarMenu.h"

int main(void) {
	setbuf(stdout, NULL);
	int opcion = 0;
	int usuarioLogeado = 0;
	int usuarioCompro = 0;
	int usuarioVendio = 0;

	do {
		opcion = mostrarMenuPrincipal();

		if (opcion == 1 || usuarioLogeado == 1 || opcion == 5) {
			switch (opcion) {

			case 1:
				usuarioLogeado = loguearUsuario();
				break;

			case 2:
				usuarioCompro = comprarProducto();
				break;

			case 3:
				verCompras();
				break;

			case 4:
				do {
					opcion = 0;
					opcion = mostrarSubmenuVender();

					switch (opcion) {

					case 1:
						usuarioVendio = venderProducto(usuarioVendio,
								usuarioCompro);
						break;

					case 2:
						printf("\nFactura no implementada");
						break;

					default:
						printf("\n%d no es una opción valida!\n", opcion);
						sleep(3);
						break;
					}

				} while (opcion != 3);
			}

		} else {
			printf("\nDebe logearse antes de realizar otra acción...\n");
			sleep(3);
		}

	} while (opcion != 5);

	return EXIT_SUCCESS;
}
