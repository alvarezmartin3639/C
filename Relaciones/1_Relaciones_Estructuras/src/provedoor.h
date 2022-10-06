/*
 * producto.h
 *
 *  Created on: 26 sept 2022
 *      Author: kenyn
 */

#ifndef PRODUCTO_H_
#define PRODUCTO_H_
#define TAMPRODUCTOS 300

typedef struct{

	char direccion[51];
	char barrio[51];

}eDireccion;


typedef struct {

	int idProveedor;
	char razonSocial[51];
	float precio;
	int estaVacio;
	eDireccion direccion;

} eProvedoor;


#endif /* PRODUCTO_H_ */
