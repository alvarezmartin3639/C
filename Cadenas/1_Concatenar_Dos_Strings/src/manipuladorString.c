/*
 * manipuladorString.c
 *
 *  Created on: 12 sept 2022
 *      Author: kenyn
 */

#include "manipuladorString.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void FormarApellidoNombre(char* pNombre,char* pApellido,char* pCompleto){

	if(pNombre != NULL && pApellido != NULL && pCompleto != NULL){
		strcpy(pCompleto,pApellido);
		strcat(pCompleto," ,");
		strcat(pCompleto,pNombre);
	}
	else
		strcpy(pCompleto,"Error al formar el apellido");
}
