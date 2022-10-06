/*
 * empleado.h
 *
 *  Created on: 26 sept 2022
 *      Author: kenyn
 */

#ifndef EMPLEADO_H_
#define EMPLEADO_H_
#define TAMEMPLEADOS 300

typedef struct {

	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpity;
} eEmpleado;

/**
 * \fn int mostrarEmpleado(eEmpleado*, int)
 * \brief muestra un empleado con o sin cabecera
 *
 * \param empleado el puntero al empleado a mostrar
 * \param conCabecera  1 = se imprime cabecera
 * \return -1 = error, n = la cantidad de caracteres impresos por el sector
 */
int mostrarEmpleado(eEmpleado *empleado, int conCabecera);

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
int cargarEmpleado(eEmpleado *empleado, int id, char *name, char *lastName, float salary, int sector, int isEmpity);

/**
 * \fn int altaEmpleados(eEmpleado*, int, int*)
 * \brief crea empleados hasta que el usuario pida parar
 *
 * \param empleados el puntero al array de empleado
 * \param tamEmpleado el tamaño del array de empleado
 * \param contId el contador del ultimo id
 * \return -1 = error inesperado, 1 = error al cargar datos, 0 = sin errores
 */
int altaEmpleados(eEmpleado *empleados, int tamEmpleado, int *contId);

/**
 * \fn int mostrarEmpleados(eEmpleado*, int, int, int)
 * \brief	muestra todos los empleados del array pasado por parametro con o sin cabecera
 *
 * \param empleados	el array de empelados
 * \param tamEmpleado el tamaño del array de empleados
 * \param estaVacio  el valor del campo que hace referencia a si esta o no eliminado
 * \param conCabecera 1 = se imprime con cabecera
 * \return -1 = error inesperado, 1 = no hay empleados, 0 = se pudo mostrar mas de un empleado
 */
int mostrarEmpleados(eEmpleado *empleados, int tamEmpleado, int estaVacio, int conCabecera);

/**
 * \fn int modificarEmpleados(eEmpleado*, int)
 * \brief modifica los empleados pasados por parametro hasta que el usuario decida parar
 *
 * \param empleados el array con los empleados para modificar
 * \param tamEmpleado el tamaño del arary de empleados
 * \return -1 = error inesperado, 1 = no se modificó ningun empelado, 0 = se modificó un empleado
 */
int modificarEmpleados(eEmpleado *empleados, int tamEmpleado);

/**
 * \fn int eliminarEmpleados(eEmpleado*, int)
 * \brief  elimina empelados mediante su id hasta que el usuario desee parar
 *
 * \param empleados el array de empleados para borrar
 * \param tamEmpleado el tamaño del array de empleados
 * \return -1 = error inesperado, 1 = no se eliminó empelado, 0 = se eliminó al menos un empleado
 */
int eliminarEmpleados(eEmpleado *empleados, int tamEmpleado);

#endif /* EMPLEADO_H_ */
