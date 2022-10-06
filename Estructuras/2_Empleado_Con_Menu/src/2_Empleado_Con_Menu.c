/*
 ============================================================================
 Name        : 2_Empleado_Con_Menu.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 Ejercicio 9-2:Una empresa requiere un sistema para administrar su nómina de
 empleados. Se sabe que dicha nómina bajo ninguna circunstancia superara los 300
 empleados.
 El sistema deberá tener el siguiente menú de
 opciones:
 Ejercicio 9-3:
 1. ALTAS: Se debe permitir ingresar un empleado
 calculando automáticamente el número
 de Id. El resto de los campos se le pedirá al usuario.
 Ejercicio 9-4:
 2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar:
 Nombre o Apellido o Salario o Sector
 Ejercicio 9-5:
 3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
 Ejercicio 9-6:
 4. INFORMAR:
 1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
 2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utnGUI.h"
#include "Empleado.h"
#include "utnValidacion.h"

int main(void) {

	setbuf(stdout, NULL);
	eEmpleado empleados[TAMEMPLEADOS];
	int contId = 0;
	int contEmpleadosActivos = 0;
	int contEmpleadosSalarioMayorQuePromedio = 0;
	float acumSalarios = 0;
	int opcion;

	do {

		limpiarPantalla();
		getPedirInt(&opcion, "\n1. ALTAS \n2. MODIFICAR \n3. BAJA \n4 INFORMAR \n5. SALIR \n\nIngrese una opción: ",
				"\n***Error, no elegió una opción valida***", 1, 5, 4);

		switch (opcion) {

		case 1:
			altaEmpleados(empleados, TAMEMPLEADOS, &contId, &contEmpleadosActivos);
			break;

		case 2:
			modificarEmpleados(empleados, TAMEMPLEADOS, contEmpleadosActivos);
			break;

		case 3:
			eliminarEmpleados(empleados, TAMEMPLEADOS, &contEmpleadosActivos);
			break;

		case 4:
			do {

				getPedirInt(&opcion,
						"\n1. Listar empleados ordenados alfabéticamente por Apellido y Sector. \n2. Total, promedio y contador de empleados que superan los salarios promedio  \n3. Atras \n\nIngrese una opción: ",
						"\n***Error, no elegió una opción valida***", 1, 3, 4);

				switch (opcion) {

				case 1:

					ordenarEmpleadoPorNombreYSector(empleados, TAMEMPLEADOS);
					mostrarEmpleados(empleados, TAMEMPLEADOS, 0, 1, contEmpleadosActivos);

					break;

				case 2:

					for (int i = 0; i < TAMEMPLEADOS; i++)
						if (empleados[i].isEmpity == 0)
							acumSalarios += empleados[i].salary;

					for (int i = 0; i < TAMEMPLEADOS; i++)
						if (empleados[i].isEmpity == 0 && empleados[i].salary > acumSalarios / contEmpleadosActivos)
							contEmpleadosSalarioMayorQuePromedio++;

					printf("\n\nTotal: %.2f ", acumSalarios);
					printf("\n\nPromedio: %.2f ", acumSalarios / contEmpleadosActivos);
					printf("\n\nCantidad empleados con salario mayor al promedio: %d ", contEmpleadosSalarioMayorQuePromedio);

					break;
				}

			} while (opcion != 3);

			break;
		}

	} while (opcion != 5);

	return EXIT_SUCCESS;
}

