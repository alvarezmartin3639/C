/*
 * empleado.c
 *
 *  Created on: 26 sept 2022
 *      Author: kenyn
 */
#include "Empleado.h"

#include "utnValidacion.h"
#include "utnArray.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utnGUI.h"
#include <unistd.h>

/**
 * \fn int mostrarEmpleado(eEmpleado*, int)
 * \brief muestra un empleado con o sin cabecera
 *
 * \param empleado el puntero al empleado a mostrar
 * \param conCabecera  1 = se imprime cabecera
 * \return -1 = error, n = la cantidad de caracteres impresos por el sector
 */
int mostrarEmpleado(eEmpleado *empleado, int conCabecera) {

	int retorno = -1;

	if (empleado != NULL) {

		if (conCabecera == 1)
			printf("\n\n                  MUESTRA DE EMPLEADO\n");

		printf("\nId -> %d", empleado->id);
		printf("\nNombre -> %s", empleado->name);
		printf("\nApellido -> %s", empleado->lastName);
		printf("\nSalario -> %.2f", empleado->salary);
		retorno = printf("\nSector -> %d\n", empleado->sector);

	}

	return retorno;
}

/**
 * \fn int cargarEmpleado(eEmpleado*, int, char*, char*, float, int, int)
 * \brief carga los datos de un empleado con los pasados por parametro
 *
 * \param empleado el empleado al cual se le van a settear los datos
 * \param id	el id del empleado
 * \param name	el nombre del empleado
 * \param lastName	 el apellido del empleado
 * \param salary	 el salario del empleado
 * \param sector	 el sector del empleado
 * \param isEmpity	1= está disponible su espacio, 0 = no está disponible su espacio
 * \return -1 = error , 0 = sin errores
 */
int cargarEmpleado(eEmpleado *empleado, int id, char *name, char *lastName, float salary, int sector, int isEmpity) {

	int retorno = -1;

	if (empleado != NULL && name != NULL && lastName != NULL) {

		empleado->id = id;
		strcpy(empleado->name, name);
		strcpy(empleado->lastName, lastName);
		empleado->salary = salary;
		empleado->sector = sector;
		empleado->isEmpity = isEmpity;

		retorno = 0;
	}

	return retorno;
}

/**
 * \fn int altaEmpleados(eEmpleado*, int, int*)
 * \brief crea empleados hasta que el usuario pida parar
 *
 * \param empleados el puntero al array de empleado
 * \param tamEmpleado el tamaño del array de empleado
 * \param contId el contador del ultimo id
 * \param contEmpleadosActivos la cantidad de empleados activos dentro del sistema
 * \return -1 = error inesperado, 1 = error al cargar datos, 0 = sin errores
 */
int altaEmpleados(eEmpleado *empleados, int tamEmpleado, int *contId, int *contEmpleadosActivos) {

	int retorno = -1;
	int indiceDelEmpleado = -1;
	eEmpleado auxEmpleado;

	if (empleados == NULL || contId == NULL || tamEmpleado < 1 || contEmpleadosActivos == NULL)
		printf("\n***Error, se produjo un error en la carga de empleados al intentar acceder al menu***");

	else {

		do {

			limpiarPantalla();
			printf("\n\n                  CREAR EMPLEADO\n");

			retorno = 1;

			if ((indiceDelEmpleado = buscarIntEnArray(&empleados->isEmpity, tamEmpleado, 1)) == -1)
				printf("\n***Error, no existe empleado vacio***");

			else if (getPedirStringDeLetras(auxEmpleado.name, "\nIngrese el nombre: ",
					"\n***Error, nombre invalido, verifique" " que no tenga espacios y que contenga solo letras ***", 4) == -1)
				printf("\n***Error, se acabaron los re-intentos disponibles para ingresar un nombre***");

			else if (getPedirStringDeLetras(auxEmpleado.lastName, "\nIngrese el apellido: ",
					"\n*** Error, apellido invalido, verifique que no tenga espacios y que "
							"contenga solo letras ***", 4) == -1)
				printf("\n***Error, se acabaron los re-intentos disponibles para ingresar un apellido***");

			else if (getPedirFloat(&auxEmpleado.salary, "\nIngrese el salario: ",
					"\n***Error, salario invalido, " "verifique que sea un numero mayor a 0 y menor a 1000000 ***", 0, 100000, 4) == -1)
				printf("\n***Error, se acabaron los re-intentos disponibles para ingresar un salario***");

			else if (getPedirInt(&auxEmpleado.sector, "\nIngrese el sector: ",
					"\n***Error, nombre invalido, verifique" " que no tenga espacios y que contenga solo letras ***", 0, 6, 4) == -1)
				printf("\n***Error, se acabaron los re-intentos disponibles para ingresar un sector***");

			else {

				auxEmpleado.id = *contId + 1;
				limpiarPantalla();
				mostrarEmpleado(&auxEmpleado, 1);

				if (elegirEntreOpciones("\n¿Desea crear este emplado? ('si'/'no'): ", "si", "no") == 1) {

					*contId = *contId + 1;
					*contEmpleadosActivos = *contEmpleadosActivos + 1;
					auxEmpleado.isEmpity = 0;
					empleados[indiceDelEmpleado] = auxEmpleado;
					retorno = 0;

				}
			}

			if (retorno == 0)
				printf("\n\n¡Empleado creado con exito!...");
			else
				printf("\n\n¡Se canceló la creación del empleado!...");

		} while (elegirEntreOpciones("\n\n¿Desea crear un empleado nuevo? ('si'/'no'): ", "si", "no") == 1);

	}

	textoConEspera("\n\nVolviendo al menú principal en 3 segundos...", 3);
	return retorno;
}

/**
 * \fn int mostrarEmpleados(eEmpleado*, int, int, int)
 * \brief	muestra todos los empleados del array pasado por parametro con o sin cabecera
 *
 * \param empleados	el array de empelados
 * \param tamEmpleado el tamaño del array de empleados
 * \param estaVacio  el valor del campo que hace referencia a si esta o no eliminado
 * \param conCabecera 1 = se imprime con cabecera
 * \param contEmpelados un contador de empleados activos
 * \return -1 = error inesperado, 1 = no hay empleados, 0 = se pudo mostrar mas de un empleado
 */
int mostrarEmpleados(eEmpleado *empleados, int tamEmpleado, int estaVacio, int conCabecera, int contEmpleados) {

	int retorno = -1;

	if (conCabecera == 1)
		printf("\n\n                  MOSTRAR EMPLEADO\n");

	if (empleados == NULL)
		printf("\n***Error, se produjo un error en la carga de empleados al intentar acceder al menu***");

	else if (contEmpleados < 1)
		printf("\n***Error, se debe cargar empleados antes de mostrarlos***");

	else {

		retorno = 1;

		for (int i = 0; i < tamEmpleado; i++) {

			if (empleados[i].isEmpity == estaVacio) {

				mostrarEmpleado(&empleados[i], 1);

				retorno = 0;
			}
		}

	}

	textoConEspera("\n\nVolviendo al menú principal en 3 segundos...", 3);
	return retorno;
}

/**
 * \fn int modificarEmpleados(eEmpleado*, int)
 * \brief modifica los empleados pasados por parametro hasta que el usuario decida parar
 *
 * \param empleados el array con los empleados para modificar
 * \param tamEmpleado el tamaño del arary de empleados
 * \param contEmpelados un contador de empleados activos
 * \return -1 = error inesperado, 1 = no se modificó ningun empelado, 0 = se modificó un empleado
 */
int modificarEmpleados(eEmpleado *empleados, int tamEmpleado, int contEmpleados) {

	int retorno = -1;
	int id;
	int indiceDelEmpleado;
	int opcionElegida;
	int cambiosSinGuardar = 1;
	eEmpleado auxEmpleado;

	if (empleados == NULL || tamEmpleado < 0)
		printf("\n***Error, se produjo un error en la carga de empleados al intentar acceder al menu***");

	else if (contEmpleados < 1)
		printf("\n***Error, se debe cargar empleados antes de modificarlos***");

	else {

		retorno = 1;

		do {

			limpiarPantalla();
			printf("\n\n                  MODIFCACAR EMPLEADO\n");

			if (getPedirInt(&id, "\n\nIngrese el id del empleado para modificar: ", "\n***Error, no es un id valido***", 1, 99999, 4) == -1)
				printf("\n\n***Error, se acabaron los reintentos al ingresar un id valido***");

			//le paso la posición de memoria de emplado->id, de esta manera se comporta como un array int y no como un array empleado
			else if ((indiceDelEmpleado = buscarIntEnArray(&empleados->id, tamEmpleado, id)) == -1)
				printf("\n\n***Error, no existe un empleado con ese id***");

			else {

				//seteo para mostrar por primera vez el empleado
				auxEmpleado = empleados[indiceDelEmpleado];

				do {

					//muestro el empleado modificado
					mostrarEmpleado(&auxEmpleado, 1);

					if (getPedirInt(&opcionElegida,
							"\n1. Nombre" "\n2. Apellido" "\n3. Salario" " \n4. Sector" "\n5. Guardar cambios" "\n6 Salir" "\n\nIngrese una opción: ",
							"\n***Error, no es una opción valida***\n", 1, 6, 4) == -1)
						printf("\n***Error, se acabaron los reintentos al ingrsar una opción valida***");

					else {

						switch (opcionElegida) {

						case 1:

							if (getPedirStringDeLetras(auxEmpleado.name, "\nIngrese el nombre nuevo: ", "\n***Error, no es un nombre valido", 4) == -1)
								printf("\n***Error, no se pudo modificar el nombre***");

							else {

								printf("\n\nNombre modificado con exito!...");
								cambiosSinGuardar = 1;

							}

							break;

						case 2:

							if (getPedirStringDeLetras(auxEmpleado.lastName, "\nIngrese el apellido nuevo: ", "***Error, no es un apellido valido", 4) == -1)
								printf("\n***Error, no se pudo modificar el nombre***");

							else {

								printf("\n\nApellido modificado con exito!...");
								cambiosSinGuardar = 1;

							}

							break;

						case 3:

							if (getPedirFloat(&auxEmpleado.salary, "\nIngrese el salario nuevo: ", "***Error, no es un salario valido", 1, 10000, 4) == -1)
								printf("\n***Error, no se pudo modificar el salario***");

							else {

								printf("\n\nSalario modificado con exito!...");
								cambiosSinGuardar = 1;

							}

							break;

						case 4:

							if (getPedirInt(&auxEmpleado.sector, "\nIngrese el  sector  nuevo: ", "***Error, no es un sector  valido", 1, 10000, 4) == -1)
								printf("\n***Error, no se pudo modificar el sector***");

							else {

								printf("\n\nSector modificado con exito!...");
								cambiosSinGuardar = 1;

							}

							break;

						case 5:

							limpiarPantalla();
							printf("\n\nEmpleado sin mofidicar: ");
							mostrarEmpleado(&empleados[indiceDelEmpleado], 0);

							printf("\n\nEmpleado modificado: ");
							mostrarEmpleado(&auxEmpleado, 0);

							if (elegirEntreOpciones("\n¿Desea remplazar los datos en el empleado? ('si'/'no'): ", "si", "no") == 1) {

								empleados[indiceDelEmpleado] = auxEmpleado;
								printf("\n\nCambios guardados correctamente!");
								cambiosSinGuardar = 0;

							} else
								printf("\n\nNo se guardaron los cambios!...");

							break;

						case 6:

							limpiarPantalla();
							if (cambiosSinGuardar == 1
									&& elegirEntreOpciones("\n¿Está seguro que desea salir?, tiene datos sin guardar y estos se perderán ('si'/'no?): ", "si",
											"no") == 0) {

								//se cancela el cierre
								opcionElegida = 0;

							} else
								retorno = 0;

							break;

						}
					}

					sleep(2);
				} while (opcionElegida != 6);
			}

		} while (elegirEntreOpciones("\n¿Desea continuar modificado empleados? (si/no): ", "si", "no") == 1);

	}

	textoConEspera("\n\nVolviendo al menú principal en 3 segundos...", 3);
	return retorno;
}

/**
 * \fn int eliminarEmpleados(eEmpleado*, int)
 * \brief  elimina empelados mediante su id hasta que el usuario desee parar
 *
 * \param empleados el array de empleados para borrar
 * \param tamEmpleado el tamaño del array de empleados
 * \param contEmpleadosActivos un contador de empleados activos
 * \return -1 = error inesperado, 1 = no se eliminó empelado, 0 = se eliminó al menos un empleado
 */
int eliminarEmpleados(eEmpleado *empleados, int tamEmpleado, int *contEmpleadosActivos) {

	int retorno = -1;
	int id;
	int indiceDelEmpleado = -1;

	if (*contEmpleadosActivos < 1)
		printf("\n***Error, se debe cargar empleados antes de modificarlos!***");

	else if (empleados != NULL) {

		retorno = 1;

		do {

			limpiarPantalla();
			printf("\n\n                  ELIMINAR EMPLEADO\n");

			if (getPedirInt(&id, "\nIngrese el id del empleado que desea dar de baja", "\n***Error, el id es invalido", 1, 1000, 4) == -1)
				printf("\n***Error, se acabaron los re-intentos al pedir el id***");

			if ((indiceDelEmpleado = buscarIntEnArray(&empleados->id, tamEmpleado, id)) == -1 || empleados[indiceDelEmpleado].isEmpity == 1)
				printf("\n***Error, no existe un empleado con ese id***");

			else {

				limpiarPantalla();
				mostrarEmpleado(&empleados[indiceDelEmpleado], 1);

				if (elegirEntreOpciones("\n¡Desea eliminar este empleado? (si/no): ", "si", "no") == 1) {

					empleados->isEmpity = 1;
					*contEmpleadosActivos = *contEmpleadosActivos - 1;
					printf("\nEmpleado eliminado con exito!");

				}
			}

		} while (elegirEntreOpciones("\n¿Desea eliminar otro empleado? (si/no): ", "si", "no") == 1);

	}

	textoConEspera("\n\nVolviendo al menú principal en 3 segundos...", 3);
	return retorno;
}

int ordenarEmpleadoPorNombreYSector(eEmpleado *empleados, int tamEmpleados) {

	int retorno = -1;

	int i;
	int j;
	eEmpleado auxEmpleados;

	if (empleados != NULL) {

		for (i = 0; i < tamEmpleados - 1; i++) {
			for (j = i + 1; j < tamEmpleados; j++) {
				if (strcmp(empleados[i].name, empleados[j].name) > 0) {
					auxEmpleados = empleados[i];
					empleados[i] = empleados[j];
					empleados[j] = auxEmpleados;
				} else {
					if (strcmp(empleados[i].name, empleados[j].name) == 0) {
						if (empleados[i].sector > empleados[j].sector) {
							auxEmpleados = empleados[i];
							empleados[i] = empleados[j];
							empleados[j] = auxEmpleados;
						}
					}
				}

			}
		}

	}

	return retorno;

}
