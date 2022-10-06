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

	char raza[51];

}eRaza;

typedef struct {

	int idMascota;
	int idDuenio;
	char nombre[51];
	char sexo[51];
	eRaza razaMascota;
	int estaVacio;

} eMascota;

#endif /* PRODUCTO_H_ */
