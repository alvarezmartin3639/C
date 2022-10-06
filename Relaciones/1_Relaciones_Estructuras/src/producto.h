/*
 * producto.h
 *
 *  Created on: 26 sept 2022
 *      Author: kenyn
 */

#ifndef PRODUCTO_H_
#define PRODUCTO_H_
#define TAMPRODUCTOS 300

typedef struct {

	int idProducto;
	int idProveedor;
	char descripcion[51];
	float precio;
	int estaVacio;

} eProducto;

#endif /* PRODUCTO_H_ */
