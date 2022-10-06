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

	int idDuenio;
	char nombre[51];
	int edad;
	char sexo[51];
	int estaVacio;

} eProducto;

#endif /* PRODUCTO_H_ */
